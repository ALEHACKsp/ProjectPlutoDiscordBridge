#include "stdafx.h"
#include <functional>

namespace HookManager
{
	namespace Internal
	{
		char* HkGSay(Entity* entity, Team team, char* message)
		{

			OnSayCallback(entity, &team, message);
			return OriginalGSay(entity, team, message);
		}

		void * DetouFunction(BYTE * src, const BYTE * dst, const int len)
		{
			BYTE* jmp = (BYTE*)malloc(len + 5);
			DWORD dwBack;

			VirtualProtect(src, len, PAGE_EXECUTE_READWRITE, &dwBack);
			memcpy(jmp, src, len);

			jmp += len;
			jmp[0] = 0xE9;

			*(DWORD*)(jmp + 1) = (DWORD)(src + len - jmp) - 5;

			src[0] = 0xE9;
			*(DWORD*)(src + 1) = (DWORD)(dst - src) - 5;
			for (int i = 5; i < len; i++)
				src[i] = 0x90;
			VirtualProtect(src, len, dwBack, &dwBack);

			return (jmp - len);
		}
	}

	void InstallOnSay(std::function<void(Entity*, Team*, char*)> callback)
	{
		Internal::OnSayCallback = callback;
		Internal::OriginalGSay = (Internal::GSay)Internal::DetouFunction((BYTE*)0x0047E900, (BYTE*)Internal::HkGSay, 0x6);
	}
}

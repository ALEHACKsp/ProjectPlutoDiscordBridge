#pragma once
#include "Datatypes.h"
#include <functional>

namespace HookManager
{
	namespace Internal
	{
		using GSay = char* (__cdecl*)(Entity*, Team, char*);
		static std::function<void(Entity*, Team*, char*)> OnSayCallback;
		static GSay OriginalGSay;
		char* HkGSay(Entity* entity, Team team, char* message);


		void* DetouFunction(BYTE* src, const BYTE* dst, const int len);
	}

	void InstallOnSay(std::function<void(Entity*, Team*, char*)> callback);
}

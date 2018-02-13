#pragma once
namespace CommandManager
{
	namespace Internal
	{
		using SystemPrintPrototype = void(__cdecl*)(const char*);
		using SendServerCommandPrototype = DWORD(__cdecl*)(int a1, int a2, const char* msg, ...);

		extern SystemPrintPrototype SystemPrint;
		extern SendServerCommandPrototype SendServerCommand;
	}

	void Init();
	void Print(const char* msg);
	void SayAll(const char* msg);
}
#include "stdafx.h"
CommandManager::Internal::SystemPrintPrototype CommandManager::Internal::SystemPrint;
CommandManager::Internal::SendServerCommandPrototype CommandManager::Internal::SendServerCommand;
namespace CommandManager
{
	void Init()
	{
		Internal::SystemPrint = reinterpret_cast<Internal::SystemPrintPrototype>(0x004D8E80);
		Internal::SendServerCommand = reinterpret_cast<Internal::SendServerCommandPrototype>(0x004FD8E0);
	}

	void Print(const char* msg)
	{
		Internal::SystemPrint(msg);
	}

	void SayAll(const char* msg)
	{
		Internal::SendServerCommand(0, 0, "%c \"\x15%s\"", 84, msg);
	}
}

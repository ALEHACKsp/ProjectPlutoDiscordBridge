// PlutoBridge.cpp: Definiert die exportierten Funktionen für die DLL-Anwendung.
//

#include "stdafx.h"
#include <sio_client.h>

void OnSay(Entity* Entity, Team* team, char* message)
{
	if(!Network::Client.opened())
		return;

	sio::message::list args;

	args.push(Config::Key);
	args.push("Servername");
	args.push(Entity->Shared.Client->Session.Clientstate.Name); //name
	char buffer[32];
	sprintf_s(buffer, "%i", *team);
	args.push(buffer); //team
	args.push(message); //message

	Network::Client.socket()->emit("chat_message", args);
}

DWORD WINAPI InitThread(LPVOID arg)
{
	Config::ReadConfig();
	Network::Client.connect(Config::IP);
	return 0;
}


namespace PlutoBridge
{
	void Startup()
	{
		CreateThread(NULL, NULL, &InitThread, NULL, NULL, NULL);
		HookManager::InstallOnSay(OnSay);
	}
}

// PlutoBridge.cpp: Definiert die exportierten Funktionen für die DLL-Anwendung.
//

#include "stdafx.h"
#include <sio_client.h>

void OnSay(Entity* Entity, Team* team, char* message)
{
	if(!Network::Client.opened())
		return;

	sio::message::list args;

	std::string hostname((char*)0x01C6A3B8);

	auto hostname_start = hostname.find(R"(sv_hostname\)");
	auto hostname_end = hostname.find(R"(\sv_maxclients)");

	auto serverName = hostname.substr(hostname_start + 12 , hostname_end - (hostname_start + 12));

	char teambuffer[32];
	sprintf_s(teambuffer, "%i", Entity->Shared.Client->Session.Clientstate.CurrentTeam);

	args.push(Config::Key);
	args.push(serverName.c_str());
	args.push(Entity->Shared.Client->Session.Clientstate.Name); //name
	args.push(teambuffer); //team
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

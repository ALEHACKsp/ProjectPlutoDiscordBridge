#include "stdafx.h"

namespace Server
{
	std::string GetName()
	{
		std::string hostname((char*)0x01C6A3B8);

		auto hostname_start = hostname.find(R"(sv_hostname\)");
		auto hostname_end = hostname.find(R"(\sv_maxclients)");

		auto serverName = hostname.substr(hostname_start + 12, hostname_end - (hostname_start + 12));

		return serverName;
	}
}
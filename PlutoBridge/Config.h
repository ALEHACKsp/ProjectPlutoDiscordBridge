#pragma once
#include <string>

namespace Config
{
	namespace Internal
	{
		bool CreateConfig();
	}
	extern std::string Key;
	extern std::string Remote;

	bool ReadConfig();
}
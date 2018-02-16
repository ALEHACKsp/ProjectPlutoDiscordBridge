#include "stdafx.h"
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

std::string Config::Key;
std::string Config::Remote;

namespace Config
{
	bool Internal::CreateConfig()
	{
		nlohmann::json json;

		json["Key"] = "<yourkey>";
		json["Remote"] = "<yourremote>";
		json["Encrypted"] = false;

		std::ofstream file("config.json", std::ios::out);

		if(!file || !file.is_open())
		{
			CommandManager::Print("[PlutoBridge]::Could not create config.json!\n");
			return false;
		}

		file << json.dump().c_str() << std::endl;

		file.close();

		CommandManager::Print("[PlutoBridge]::Config.json created, edit it to your needs!\n");
		return true;
	}

	bool ReadConfig()
	{
		std::ifstream file("config.json");
		
		if(!file)
		{
			CommandManager::Print("[PlutoBridge]::Could not find config.json!\n");
			CommandManager::Print("[PlutoBridge]::Creating config.json...\n");
			return Internal::CreateConfig();
		}

		nlohmann::json json;

		file >> json;

		Key = json["Key"].get<std::string>();
		Remote = json["Remote"].get<std::string>();

		return true;
	}
}
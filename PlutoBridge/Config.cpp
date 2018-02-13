#include "stdafx.h"
#include <string>
#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>

std::string Config::Key;
std::string Config::Remote;

namespace Config
{
	void ReadConfig()
	{
		std::ifstream file("config.json");
		
		rapidjson::IStreamWrapper streamWrapper(file);
		rapidjson::Document json;

		json.ParseStream(streamWrapper);
		
		Key = json["Key"].GetString();
		Remote = json["Remote"].GetString();

		MessageBoxA(NULL, Key.c_str(), Remote.c_str(), 0);
	}
}
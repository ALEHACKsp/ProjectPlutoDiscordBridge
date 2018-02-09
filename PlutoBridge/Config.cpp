#include "stdafx.h"
#include <string>
#include <fstream>

std::string Config::Key;
std::string Config::IP;

namespace Config
{
	void ReadConfig()
	{
		std::ifstream file("config.txt");
		std::string myArray[2];
		if(file.is_open())
		{
			for (int i = 0; i < 2; ++i)
			{
				file >> myArray[i];
			}
		}

		Key = myArray[0];
		IP = myArray[1];
	}
}
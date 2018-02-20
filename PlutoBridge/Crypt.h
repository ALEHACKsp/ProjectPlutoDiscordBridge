#pragma once
namespace Crypt
{
	std::string Encrypt(std::string msg, std::string key);
	std::string Decrypt(std::string msg, std::string key);
}
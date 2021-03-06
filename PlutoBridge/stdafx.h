// stdafx.h: Includedatei für Standardsystem-Includedateien
// oder häufig verwendete projektspezifische Includedateien,
// die nur in unregelmäßigen Abständen geändert werden.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Selten verwendete Komponenten aus Windows-Headern ausschließen
// Windows-Headerdateien:
#include <windows.h>



// TODO: Hier auf zusätzliche Header, die das Programm erfordert, verweisen.
#include "PlutoBridge.h"
#include "HookManager.h"
#include "Datatypes.h"
#include "CommandManager.h"
#include "Network.h"
#include "Config.h"
#include "Server.h"
#include "Crypt.h"
#include <sio_client.h>
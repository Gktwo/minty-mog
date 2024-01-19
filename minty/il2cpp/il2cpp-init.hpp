#pragma once

#include <Windows.h>
#include <sstream>
#include <fstream>

#include "../utils/Logger.h"
#include "../config/ConfigManager.h"

// Define IL2CPP API function addresses
#define DO_API(a, r, n, p) r(*n) p
	#include "il2cpp-api-functions.h"
#undef DO_API

// Define function addresses
#define DO_APP_FUNC(a, r, n, p) r(*n) p
#define DO_TYPEDEF(a, n) n ## __Class** n ## __TypeInfo
#define DO_APP_FUNC_METHODINFO(a, n) struct MethodInfo ** n
namespace app {
	#include "il2cpp-types.h"
	#include "il2cpp-functions.h"
}
#undef DO_APP_FUNC
#undef DO_TYPEDEF
#undef DO_APP_FUNC_METHODINFO

// Define UnityPlayer functions
#define DO_UP_FUNC(a, r, n, p) r(*n) p
namespace app {
	#include "il2cpp-unityplayer-functions.h"
}
#undef DO_UP_FUNC

//#define SELECT_VERSION(VERSION, OS_OFFSET, CN_OFFSET) (VERSION == GameVersion::GLOBAL ? OS_OFFSET : CN_OFFSET)

//enum class GameVersion {
//	NONE,
//	CHINA
//};

//GameVersion getGameVersion() {
//	std::string execPath = config::getValue<std::string>("general", "execPath", "").getValue();
//
//	if (execPath.find("GenshinImpact.exe") != std::string::npos)
//		return GameVersion::GLOBAL;
//
//	if (execPath.find("YuanShen.exe") != std::string::npos)
//		return GameVersion::CHINA;
//	return GameVersion::NONE;
//}

uintptr_t baseAddress;
uintptr_t unityPlayerAddress;

VOID init_il2cpp() {
	//auto gameVersion = getGameVersion();

	//if (gameVersion != GameVersion::NONE)
	//	LOG_INFO("Detected %s version.", gameVersion == GameVersion::GLOBAL ? "GLOBAL" : "CHINA");
	//else {
	//	LOG_ERROR("Failed to detect any game version. If you sure that cheat has updated for current game version, and you downloaded the correct one.");
	//	system("pause");
	//	exit(0);
	//	return;
	//}

	while (baseAddress == (uint64_t) nullptr) {
		Sleep(1000);
		baseAddress = (uint64_t) GetModuleHandleA("GameAssembly.dll");

		if (GetModuleHandleA("GameAssembly.dll") != nullptr) {
			baseAddress = (uint64_t) GetModuleHandleA("GameAssembly.dll");
			unityPlayerAddress = (uint64_t) GetModuleHandleA("UnityPlayer.dll");
			LOG_DEBUG("GameAssembly ptr: %p", baseAddress);
			LOG_DEBUG("UnityPlayer ptr: %p", unityPlayerAddress);

			#define DO_API(a, r, n, p) n = (r (*) p)(baseAddress + a)
				#include "il2cpp-api-functions.h"
			#undef DO_API

			#define DO_APP_FUNC(a, r, n, p) n = (r (*) p)(baseAddress + a)
			#define DO_APP_FUNC_METHODINFO(a, n) n = (struct MethodInfo **)(baseAddress + a)
				#include "il2cpp-functions.h"
			#undef DO_APP_FUNC
			#undef DO_APP_FUNC_METHODINFO

			#define DO_TYPEDEF(a, b, n) n ## __TypeInfo = (n ## __Class**) (baseAddress + a)
				#include "il2cpp-types.h"
                #include "il2cpp-enum.h"

			#undef DO_TYPEDEF

			#define DO_UP_FUNC(a, r, n, p) n = (r (*) p)(unityPlayerAddress + a)
				#include "il2cpp-unityplayer-functions.h"
			#undef DO_UP_FUNC
		}
	}
}

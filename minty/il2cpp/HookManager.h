#pragma once

#include <windows.h>
#define WIN32_LEAN_AND_MEAN
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <codecvt>
#include <map>
#include "detours.h"
#pragma comment(lib, "il2cpp/detours.lib")

#define CALL_ORIGIN(function, ...) HookManager::call(function, __func__, __VA_ARGS__)

class HookManager {
public:
	template <typename Fn>
	static void install(Fn func, Fn handler) {
		enable(func, handler);
		holderMap[reinterpret_cast<void*>(handler)] = reinterpret_cast<void*>(func);
	}

	template <typename Fn>
	static Fn getOrigin(Fn handler, const char* callerName = nullptr) noexcept {
		if (holderMap.count(reinterpret_cast<void*>(handler)) == 0) {
			std::cout << "Origin not found for handler: " << callerName << ". Maybe racing bug." << std::endl;
			return nullptr;
		}
		return reinterpret_cast<Fn>(holderMap[reinterpret_cast<void*>(handler)]);
	}

	template <typename Fn>
	static void detach(Fn handler) noexcept {
		disable(handler);
		holderMap.erase(reinterpret_cast<void*>(handler));
	}

	template <typename RType, typename... Params>
	static RType call(RType(*handler)(Params...), const char* callerName = nullptr, Params... params) {
		auto origin = getOrigin(handler, callerName);
		if (origin != nullptr)
			return origin(params...);
		return RType();
	}

	static void detachAll() noexcept {
		for (const auto& [key, value] : holderMap) {
			disable(key);
		}
		holderMap.clear();
	}
private:
	inline static std::map<void*, void*> holderMap{};
	template <typename Fn>
	static void disable(Fn handler) {
		Fn origin = getOrigin(handler);
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourDetach(&(PVOID&)origin, handler);
		DetourTransactionCommit();
	}

	template <typename Fn>
	static void enable(Fn& func, Fn handler) {
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(&(PVOID&)func, handler);
		DetourTransactionCommit();
	}
};

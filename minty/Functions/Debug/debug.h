﻿#pragma once

#include "../FunctionIncludes.h"

namespace cheat {
    class Debug : public Function {
    public:
	ConfigField<bool> f_Enabled;
	ConfigField<bool> f_WipeEnemies;
	ConfigField<bool> f_time;

	Hotkey f_Hotkey;
	Hotkey f_Wipe;

	void GUI() override;
	void Outer() override;
	void Status() override;

	std::string getModule() override;

	static Debug& getInstance();

	Debug();
    };
}

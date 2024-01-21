
#pragma once

#include "../FunctionIncludes.h"

namespace cheat {
    class DemageHack : public Function {
    public:
	ConfigField<bool> f_Enabled;

	Hotkey f_Hotkey;
	ConfigField<bool> f_Multiplier;
	ConfigField<float> f_Multipliervalue;

	void GUI() override;
	void Outer() override;
	void Status() override;

	std::string getModule() override;

	static DemageHack& getInstance();

	DemageHack();
    };
}

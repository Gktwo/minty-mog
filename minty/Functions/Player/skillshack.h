#pragma once

#include "../FunctionIncludes.h"

namespace cheat {
	class SkillsHack : public Function {
	public:
		ConfigField<bool> f_Enabled;
		ConfigField<bool> f_SpecialSkill;

		Hotkey f_Hotkey;


		void GUI() override;
		void Outer() override;
		void Status() override;

		std::string getModule() override;

		static SkillsHack& getInstance();

		SkillsHack();
	};
}

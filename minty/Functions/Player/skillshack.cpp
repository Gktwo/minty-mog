#include "SkillsHack.h"

namespace cheat {
	static bool BattleLogic_BattleMatch__get_CanUseSpecialSkillAnytime_HookSkillsHack(app::BattleLogic_BattleMatch_o* __this);



	SkillsHack::SkillsHack() {
		f_Enabled = config::getValue("functions:SkillsHack", "enabled", false);
		f_Hotkey = Hotkey("functions:SkillsHack");
		f_SpecialSkill = config::getValue("functions:SkillsHack:SpecialSkill", "enabled", false);

		HookManager::install(app::BattleLogic_BattleMatch__get_CanUseSpecialSkillAnytime, BattleLogic_BattleMatch__get_CanUseSpecialSkillAnytime_HookSkillsHack);

	}

	SkillsHack& SkillsHack::getInstance() {
		static SkillsHack instance;
		return instance;
	}

	void SkillsHack::GUI() {
		ConfigCheckbox(_("SkillsHack"), f_Enabled, _("SkillsHack ."));


		if (f_Enabled.getValue()) {
			ImGui::Indent();
			ConfigCheckbox(_("SpecialSkill"), f_SpecialSkill, _("CanUseSpecialSkillAnytime"));
			f_Hotkey.Draw();
			ImGui::Unindent();
		}


	}

	void SkillsHack::Outer() {
		if (f_Hotkey.IsPressed())
			f_Enabled.setValue(!f_Enabled.getValue());
	}

	void SkillsHack::Status() {
		if (f_Enabled.getValue())
			ImGui::Text(_("SkillsHack"));
	}

	std::string SkillsHack::getModule() {
		return _("Player");
	}

	bool BattleLogic_BattleMatch__get_CanUseSpecialSkillAnytime_HookSkillsHack(app::BattleLogic_BattleMatch_o* __this) {
		auto& SkillsHack = SkillsHack::getInstance();


		if (SkillsHack.f_Enabled.getValue() && SkillsHack.f_SpecialSkill.getValue())
			return true;
			// app::BattleLogic_BattleLogic__set_CanUseSpecialSkillAnytime



		return CALL_ORIGIN(BattleLogic_BattleMatch__get_CanUseSpecialSkillAnytime_HookSkillsHack, __this);
	}


}

#include "SkillsHack.h"

namespace cheat {
	//static bool BattleLogic_BattleMatch__get_CanUseSpecialSkillAnytime_HookSkillsHack(app::BattleLogic_BattleMatch_o* __this);
	static void BattleLogic_Skills_SkillPerformer__RecordGiveSpecialPoint_Hook(app::BattleLogic_Skills_SkillPerformer_o* __this, app::BattleLogic_Models_BattleObject_o* a, float b, int32_t c, app::Network_SkillActionType_o d, app::Network_Utility_IEffectStatus_o* e, app::BattleLogic_Skills_SkillPerformer_CalculatedParameters_o f);


	SkillsHack::SkillsHack() {
		f_Enabled = config::getValue("functions:SkillsHack", "enabled", false);
		f_Hotkey = Hotkey("functions:SkillsHack");
		f_SpecialSkill = config::getValue("functions:SkillsHack:SpecialSkill", "enabled", false);

		//HookManager::install(app::BattleLogic_BattleMatch__get_CanUseSpecialSkillAnytime, BattleLogic_BattleMatch__get_CanUseSpecialSkillAnytime_HookSkillsHack);
		HookManager::install(app::BattleLogic_Skills_SkillPerformer__RecordGiveSpecialPoint, BattleLogic_Skills_SkillPerformer__RecordGiveSpecialPoint_Hook);
	}

	SkillsHack& SkillsHack::getInstance() {
		static SkillsHack instance;
		return instance;
	}

	void SkillsHack::GUI() {
		ImGui::SeparatorText(_("SkillsHack"));
		ConfigCheckbox(_("SkillsHack"), f_Enabled, _("SkillsHack ."));


		if (f_Enabled.getValue()) {
			ImGui::Indent();
			ConfigCheckbox(_("Specialpoint"), f_SpecialSkill, _("Specialpoint"));
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



	void BattleLogic_Skills_SkillPerformer__RecordGiveSpecialPoint_Hook(app::BattleLogic_Skills_SkillPerformer_o* __this, app::BattleLogic_Models_BattleObject_o* a, float b, int32_t c, app::Network_SkillActionType_o d, app::Network_Utility_IEffectStatus_o* e, app::BattleLogic_Skills_SkillPerformer_CalculatedParameters_o f) {
		auto& SkillsHack = SkillsHack::getInstance();

		if (SkillsHack.f_Enabled.getValue() && SkillsHack.f_SpecialSkill.getValue())
		{
			LOG_DEBUG("int c = %d", c);
			c = 100;

			LOG_DEBUG("float b = %f", b);
		}


		CALL_ORIGIN(BattleLogic_Skills_SkillPerformer__RecordGiveSpecialPoint_Hook, __this, a, b, c, d, e, f);
	}

}

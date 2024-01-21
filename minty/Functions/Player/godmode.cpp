#include "GodMode.h"

namespace cheat {
	static void BattleLogic_Skills_SkillPerformer__RecordDamage_Hook(app::BattleLogic_Skills_SkillPerformer_o* __this, float a, app::Network_SkillActionType_o b, bool c, app::BattleLogic_Skills_SkillPerformer_CalculatedParameters_o d, app::BattleLogic_Models_BattleObject_o* e, app::BattleLogic_Models_BattleObject_o* f, app::Network_Utility_SkillUsingStatus_o* g, bool h, float i);
	//static void BattleLogic_Skills_SkillPerformer__RecordMiss_Hook(app::BattleLogic_Skills_SkillPerformer_o* __this, app::Network_SkillActionType_o a, app::BattleLogic_Models_BattleObject_o* b, app::BattleLogic_Models_BattleObject_o* c, bool d);

	GodMode::GodMode() {

		f_Enabled = config::getValue("functions:GodMode", "enabled", false);
		f_Hotkey = Hotkey("functions:GodMode");


		//HookManager::install(app::BattleLogic_Skills_SkillPerformer__RecordMiss, BattleLogic_Skills_SkillPerformer__RecordMiss_Hook);

		f_Miss = config::getValue("functions:GodMode:Miss", "enabled", false);

		f_Zero = config::getValue("functions:GodMode:Zero", "enabled", false);
		f_Multiplier = config::getValue("functions:GodMode:Multiplier", "enabled", false);
		f_Multipliervalue = config::getValue("functions:GodMode:Multiplier", "value", 5.0f);
		HookManager::install(app::BattleLogic_Skills_SkillPerformer__RecordDamage, BattleLogic_Skills_SkillPerformer__RecordDamage_Hook);
	}

	GodMode& GodMode::getInstance() {
		static GodMode instance;
		return instance;
	}

	void GodMode::GUI() {
		ImGui::SeparatorText(_("GodMode"));
		ConfigCheckbox(_("God Mode"), f_Enabled, _("Enables god mode, i.e. no incoming damage ."));
		ImGui::SameLine();
		f_Hotkey.Draw();


		if (f_Enabled.getValue()) {
			ImGui::Indent();
			//ConfigCheckbox(_("Miss Mode"), f_Miss, _("Miss all the upcoming damage ."));
			ConfigCheckbox(_("Zero Value Mode"), f_Zero, _("Zero damage received ."));
			ConfigCheckbox(_("Multiplier Mode"), f_Multiplier, _("Multiplier Mode ."));
			if (f_Multiplier.getValue()) {
				ConfigSliderFloat(_("Multiplier value"), f_Multipliervalue, 1.0f, 100.0f, _("Change the value of damage taken by the character"));
			}
			ImGui::Unindent();
		}


	}

	void GodMode::Outer() {
		if (f_Hotkey.IsPressed())
			f_Enabled.setValue(!f_Enabled.getValue());


	}

	void GodMode::Status() {
		if (f_Enabled.getValue()) {
			std::string status = "GodMode";
			if (f_Zero.getValue()) 
				status += " | Zero";
			else
				if (f_Multiplier.getValue()) {
					std::string multiplierValueStr = std::to_string(f_Multipliervalue.getValue());
					status += (" | Multiplier | " + multiplierValueStr);
				}
			ImGui::Text(_(status.c_str()));

		}

	}

	std::string GodMode::getModule() {
		return _("Player");
	}

	void BattleLogic_Skills_SkillPerformer__RecordDamage_Hook(app::BattleLogic_Skills_SkillPerformer_o* __this, float a, app::Network_SkillActionType_o b, bool c, app::BattleLogic_Skills_SkillPerformer_CalculatedParameters_o d, app::BattleLogic_Models_BattleObject_o* e, app::BattleLogic_Models_BattleObject_o* f, app::Network_Utility_SkillUsingStatus_o* g, bool h, float i) {
		auto& GodMode = GodMode::getInstance();


		if (GodMode.f_Enabled.getValue() && app::BattleLogic_Models_BattleObject__get_Team(e) == app::BattleTeams__Enum::Bravo && app::BattleLogic_Models_BattleObject__get_Team(f) == app::BattleTeams__Enum::Alpha)
			if (GodMode.f_Multiplier.getValue())
				a = a / GodMode.f_Multipliervalue.getValue();
			else if (GodMode.f_Zero.getValue())
				a = 0.0f;




		return CALL_ORIGIN(BattleLogic_Skills_SkillPerformer__RecordDamage_Hook, __this, a, b, c, d, e, f, g, h, i);
	}



}

#include "GodMode.h"

namespace cheat {
    static void BattleLogic_Skills_SkillPerformer__RecordDamage_Hook(app::BattleLogic_Skills_SkillPerformer_o* __this, float a, app::Network_SkillActionType_o b, bool c, app::BattleLogic_Skills_SkillPerformer_CalculatedParameters_o d, app::BattleLogic_Models_BattleObject_o* e, app::BattleLogic_Models_BattleObject_o* f, app::Network_Utility_SkillUsingStatus_o* g, bool h, float i);

    GodMode::GodMode() {
	f_Enabled = config::getValue("functions:GodMode", "enabled", false);
	f_Hotkey = Hotkey("functions:GodMode");
	HookManager::install(app::BattleLogic_Skills_SkillPerformer__RecordDamage, BattleLogic_Skills_SkillPerformer__RecordDamage_Hook);
	f_Multiplier = config::getValue("functions:GodMode:Multiplier", "enabled", false);
	f_Multipliervalue = config::getValue("functions:GodMode:Multiplier", "value", 5.0f);
    }

    GodMode& GodMode::getInstance() {
	static GodMode instance;
	return instance;
    }

    void GodMode::GUI() {
	ConfigCheckbox(_("God Mode"), f_Enabled, _("Enables god mode, i.e. no incoming damage ."));


	if (f_Enabled.getValue()) {
	    ImGui::Indent();
	    ConfigCheckbox(_("Multiplier Mode"), f_Multiplier, _("Multiplier Mode ."));
	    f_Hotkey.Draw();
	    ImGui::Unindent();
	}

	if (f_Multiplier.getValue()) {
	    ImGui::Indent();
	    ConfigSliderFloat(_("Multiplier value"), f_Multipliervalue, 1.0f, 100.0f, _("Change the value of damage taken by the character"));
	    ImGui::Unindent();
	}
    }

    void GodMode::Outer() {
	if (f_Hotkey.IsPressed())
	    f_Enabled.setValue(!f_Enabled.getValue());
    }

    void GodMode::Status() {
	if (f_Enabled.getValue())
	    ImGui::Text(_("GodMode"));
    }

    std::string GodMode::getModule() {
	return _("Player");
    }

    void BattleLogic_Skills_SkillPerformer__RecordDamage_Hook(app::BattleLogic_Skills_SkillPerformer_o* __this, float a, app::Network_SkillActionType_o b, bool c, app::BattleLogic_Skills_SkillPerformer_CalculatedParameters_o d, app::BattleLogic_Models_BattleObject_o* e, app::BattleLogic_Models_BattleObject_o* f, app::Network_Utility_SkillUsingStatus_o* g, bool h, float i) {
	auto& GodMode = GodMode::getInstance();


	if (GodMode.f_Enabled.getValue()&& app::BattleLogic_Models_BattleObject__get_Team(e) == app::BattleTeams__Enum::Bravo && app::BattleLogic_Models_BattleObject__get_Team(f) == app::BattleTeams__Enum::Alpha)
	    if (GodMode.f_Multiplier.getValue())
	    {
		a = a / GodMode.f_Multipliervalue.getValue();
	    }
	    else
	    {
		{
		    a = 0.0f;
		}
	    }


	return CALL_ORIGIN(BattleLogic_Skills_SkillPerformer__RecordDamage_Hook, __this, a, b, c, d, e, f, g, h, i);
    }




}

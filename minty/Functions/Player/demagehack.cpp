#include "DemageHack.h"

namespace cheat {
    static void BattleLogic_Skills_SkillPerformer__RecordDamage_Hook1(app::BattleLogic_Skills_SkillPerformer_o* __this, float a, app::Network_SkillActionType_o b, bool c, app::BattleLogic_Skills_SkillPerformer_CalculatedParameters_o d, app::BattleLogic_Models_BattleObject_o* e, app::BattleLogic_Models_BattleObject_o* f, app::Network_Utility_SkillUsingStatus_o* g, bool h, float i);



    DemageHack::DemageHack() {
	f_Enabled = config::getValue("functions:DemageHack", "enabled", false);
	f_Hotkey = Hotkey("functions:DemageHack");
	f_Multiplier = config::getValue("functions:DemageHack:Multiplier", "enabled", false);
	f_Multipliervalue = config::getValue("functions:DemageHack:Multiplier", "value", 5.0f);
	HookManager::install(app::BattleLogic_Skills_SkillPerformer__RecordDamage, BattleLogic_Skills_SkillPerformer__RecordDamage_Hook1);

    }

    DemageHack& DemageHack::getInstance() {
	static DemageHack instance;
	return instance;
    }

    void DemageHack::GUI() {
	ConfigCheckbox(_("DemageHack"), f_Enabled, _("DemageHack ."));


	if (f_Enabled.getValue()) {
	    ImGui::Indent();
	    ConfigCheckbox(_("Multiplier"), f_Multiplier, _("DemageHack ."));
	    f_Hotkey.Draw();
	    ImGui::Unindent();
	}

	if (f_Multiplier.getValue()) {
	    ImGui::Indent();
	    ConfigSliderFloat(_("Multiplier value"), f_Multipliervalue, 1.0f, 100.0f, _("Change the value of damage "));
	    ImGui::Unindent();
	}
    }

    void DemageHack::Outer() {
	if (f_Hotkey.IsPressed())
	    f_Enabled.setValue(!f_Enabled.getValue());
    }

    void DemageHack::Status() {
	if (f_Enabled.getValue())
	    ImGui::Text("DemageHack");
    }

    std::string DemageHack::getModule() {
	return _("Player");
    }

    void BattleLogic_Skills_SkillPerformer__RecordDamage_Hook1(app::BattleLogic_Skills_SkillPerformer_o* __this, float a, app::Network_SkillActionType_o b, bool c, app::BattleLogic_Skills_SkillPerformer_CalculatedParameters_o d, app::BattleLogic_Models_BattleObject_o* e, app::BattleLogic_Models_BattleObject_o* f, app::Network_Utility_SkillUsingStatus_o* g, bool h, float i) {
	auto& DemageHack = DemageHack::getInstance();


	if (DemageHack.f_Enabled.getValue() && app::BattleLogic_Models_BattleObject__get_Team(e) == 0 && app::BattleLogic_Models_BattleObject__get_Team(f) == 1)
	    if (DemageHack.f_Multiplier.getValue())
	    {
		a = a * DemageHack.f_Multipliervalue.getValue();
	    }
	    else
		a = a * 9999.0;



	return CALL_ORIGIN(BattleLogic_Skills_SkillPerformer__RecordDamage_Hook1, __this, a, b, c, d, e, f, g, h, i);
    }


}

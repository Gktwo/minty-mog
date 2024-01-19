#include "Debug.h"

namespace cheat {
    //static void BattleLogic_BattleMatch__Update_Hook(app::BattleLogic_BattleMatch_o* __this);

    Debug::Debug() {
	f_Enabled = config::getValue("functions:Debug", "enabled", false);
	f_WipeEnemies = config::getValue("functions:WipeEnemies", "enabled", false);
	f_Hotkey = Hotkey("functions:Debug");
	f_Wipe = Hotkey("functions:Wipe");
	//HookManager::install(app::BattleLogic_BattleMatch__Update, BattleLogic_BattleMatch__Update_Hook);
	f_time = config::getValue("functions:time", "enabled", false);
    }

    Debug& Debug::getInstance() {
	static Debug instance;
	return instance;
    }

    void Debug::GUI() {
	ConfigCheckbox(_("IsPause"), f_Enabled, _("Debug ."));
	ConfigCheckbox(_("WipeEnemies"), f_WipeEnemies, _("Debug ."));
	ConfigCheckbox(_("time"), f_time, _("Debug ."));


	if (f_time.getValue()) {
	    ImGui::Indent();
	    ImGui::Unindent();
	}
	if (f_Enabled.getValue()) {
	    ImGui::Indent();
	    f_Hotkey.Draw();
	    ImGui::Unindent();
	}

	if (f_WipeEnemies.getValue()) {
	    ImGui::Indent();
	    ImGui::Text("Wipe:");
	    ImGui::SameLine();
	    f_Wipe.Draw();
	    ImGui::Unindent();
	}
    }


    void Debug::Outer() {
	if (f_Hotkey.IsPressed())
	    f_Enabled.setValue(!f_Enabled.getValue());
    }

 //   void Debug::Outer() {
	//if (f_Wipe.IsPressed())
	//    f_Enabled.setValue(!f_Enabled.getValue());
 //   }

    void Debug::Status() {
	if (f_Enabled.getValue())
	    ImGui::Text(_("Debug"));
    }

    std::string Debug::getModule() {
	return _("Debug");
    }




 //   void BattleLogic_BattleMatch__Update_Hook(app::BattleLogic_BattleMatch_o* __this) {
	//auto& Debug = Debug::getInstance();


	//if (Debug.f_WipeEnemies.getValue()&& Debug.f_Wipe.IsPressed())
	//{
	//    app::BattleLogic_BattleMatch__WipeEnemies(__this);
	//    LOG_DEBUG("Enemies Wiped");
	//}


	//return CALL_ORIGIN(BattleLogic_BattleMatch__Update_Hook, __this);
 //   }

}

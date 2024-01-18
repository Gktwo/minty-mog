#include "Debug.h"

namespace cheat {
    //static void BattleLogic_BattleLogic__Update_Hook(app::BattleLogic_BattleLogic_o* __this);

    Debug::Debug() {
	f_Enabled = config::getValue("functions:Debug", "enabled", false);
	f_Hotkey = Hotkey("functions:Debug");
	//HookManager::install(app::BattleLogic_BattleLogic__Update, BattleLogic_BattleLogic__Update_Hook);

    }

    Debug& Debug::getInstance() {
	static Debug instance;
	return instance;
    }

    void Debug::GUI() {
	ConfigCheckbox(_("Debug"), f_Enabled, _("Debug ."));


	if (f_Enabled.getValue()) {
	    ImGui::Indent();
	    f_Hotkey.Draw();
	    ImGui::Unindent();
	}
    }

    void Debug::Outer() {
	if (f_Hotkey.IsPressed())
	    f_Enabled.setValue(!f_Enabled.getValue());
    }

    void Debug::Status() {
	if (f_Enabled.getValue())
	    ImGui::Text("Debug");
    }

    std::string Debug::getModule() {
	return _("Debug");
    }




 //   void BattleLogic_BattleLogic__Update_Hook(app::BattleLogic_BattleLogic_o* __this) {
	//auto& Debug = Debug::getInstance();

	//if (Debug.f_Enabled.getValue())
	//{
	//    app::Time_set_timeScale(10.0f);
	//    Debug.f_Enabled.setValue(false);
	//    LOG_DEBUG("Timer");
	//}

	//return CALL_ORIGIN(BattleLogic_BattleLogic__Update_Hook, __this);
 //   }

}

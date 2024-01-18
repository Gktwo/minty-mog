#include "GodMode.h"

namespace cheat {
    //static void );

    GodMode::GodMode() {
	f_Enabled = config::getValue("functions:GodMode", "enabled", false);
	f_Hotkey = Hotkey("functions:GodMode");
	//HookManager::install();

    }

    GodMode& GodMode::getInstance() {
	static GodMode instance;
	return instance;
    }

    void GodMode::GUI() {
	ConfigCheckbox(_("God Mode"), f_Enabled, _("Enables god mode, i.e. no incoming damage ."));


	if (f_Enabled.getValue()) {
	    ImGui::Indent();
	    f_Hotkey.Draw();
	    ImGui::Unindent();
	}
    }

    void GodMode::Outer() {
	if (f_Hotkey.IsPressed())
	    f_Enabled.setValue(!f_Enabled.getValue());
    }

    void GodMode::Status() {
	if (f_Enabled.getValue())
	    ImGui::Text("GodMode");
    }

    std::string GodMode::getModule() {
	return _("Player");
    }






}

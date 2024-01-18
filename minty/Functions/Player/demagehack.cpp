#include "DemageHack.h"

namespace cheat {



    DemageHack::DemageHack() {
	f_Enabled = config::getValue("functions:DemageHack", "enabled", false);
	f_Hotkey = Hotkey("functions:DemageHack");




    }

    DemageHack& DemageHack::getInstance() {
	static DemageHack instance;
	return instance;
    }

    void DemageHack::GUI() {
	ConfigCheckbox(_("DemageHack"), f_Enabled, _("DemageHack ."));


	if (f_Enabled.getValue()) {
	    ImGui::Indent();
	    f_Hotkey.Draw();
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




 

}

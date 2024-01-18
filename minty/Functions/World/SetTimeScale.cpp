﻿#include "SetTimeScale.h"

namespace cheat {
    static void Global_Update1_Hook(app::UnityEngine_EventSystems_EventSystem_o* __this, app::MethodInfo* method);

    SetTimeScale::SetTimeScale() {
	f_Enabled = config::getValue("functions:SetTimeScale", "enabled", false);
	f_Hotkey = Hotkey("functions:SetTimeScale");
	f_Speed = config::getValue("functions:SetTimeScale", "speed value", 5.0f);
	HookManager::install(app::Global_Update, Global_Update1_Hook);

    }

    SetTimeScale& SetTimeScale::getInstance() {
	static SetTimeScale instance;
	return instance;
    }

    void SetTimeScale::GUI() {
	ConfigCheckbox(_("Game Speed"), f_Enabled, _("Change game speed ."));


	if (f_Enabled.getValue()) {
	    ImGui::Indent();
	    ConfigSliderFloat(_("speed value"), f_Speed, 1.0f, 20.0f, _("Change the value of game speed"));
	    f_Hotkey.Draw();
	    ImGui::Unindent();
	}
    }

    void SetTimeScale::Outer() {
	if (f_Hotkey.IsPressed())
	    f_Enabled.setValue(!f_Enabled.getValue());
    }

    void SetTimeScale::Status() {
	if (f_Enabled.getValue())
	    ImGui::Text("SetTimeScale");
    }

    std::string SetTimeScale::getModule() {
	return _("World");
    }




    void Global_Update1_Hook(app::UnityEngine_EventSystems_EventSystem_o* __this, app::MethodInfo* method) {
	auto& SetTimeScale = SetTimeScale::getInstance();


	app::Time_set_timeScale(SetTimeScale.f_Enabled.getValue() ? SetTimeScale.f_Speed.getValue() : 1.0f);
	//LOG_DEBUG("SetTimeScale");
	return CALL_ORIGIN(Global_Update1_Hook, __this,method);
    }

}
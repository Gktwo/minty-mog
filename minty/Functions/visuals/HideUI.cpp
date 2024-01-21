#include "HideUI.h"

namespace cheat {
	static void Global_Update2_Hook(app::UnityEngine_EventSystems_EventSystem_o* __this, app::MethodInfo* method);

	HideUI::HideUI() : Function() {
		f_Enabled = config::getValue("functions:HideUI", "enabled", false);
		f_ui_1 = config::getValue("functions:HideUI:ui_1", "enabled", false);
		f_ui_2 = config::getValue("functions:HideUI:ui_2", "enabled", false);
		f_ui_3 = config::getValue("functions:HideUI:ui_3", "enabled", false);
		f_Hotkey = Hotkey("functions:HideUI");

		HookManager::install(app::Global_Update, Global_Update2_Hook);
	}

	HideUI& HideUI::getInstance() {
		static HideUI instance;
		return instance;
	}

	void HideUI::GUI() {
		ImGui::SeparatorText(_("HideUI"));
		ConfigCheckbox(_("Hide UI"), f_Enabled, _("Hide in-game UI."));

		if (f_Enabled.getValue()) {
			ImGui::Indent();
			f_Hotkey.Draw();
			ConfigCheckbox(_("GlobalMenu"), f_ui_1, _("Hide in-game UI."));
			ConfigCheckbox(_("GlobalHeader"), f_ui_2, _("Hide in-game UI."));
			ConfigCheckbox(_("HomeWindow"), f_ui_3, _("Hide in-game UI."));
			ImGui::Unindent();
		}
	}

	void HideUI::Outer() {
		if (f_Hotkey.IsPressed())
			f_Enabled.setValue(!f_Enabled.getValue());
	}

	void HideUI::Status() {
		if (f_Enabled.getValue())
			ImGui::Text("Hide UI");
	}

	std::string HideUI::getModule() {
		return _("Visuals");
	}

	app::GameObject* ui_1{};
	app::GameObject* ui_2{};
	app::GameObject* ui_3{};

	//GlobalMenu(Clone)
	//GlobalHeader(Clone)
	//HomeWindow(Clone)

	void Global_Update2_Hook(app::UnityEngine_EventSystems_EventSystem_o* __this, app::MethodInfo* method) {
		auto& hideUI = HideUI::getInstance();

		if (hideUI.f_Enabled.getValue() && hideUI.f_ui_1.getValue()) {
			if (ui_1 == nullptr)
				ui_1 = app::GameObject_Find(string_to_il2cppi("/GlobalMenu(Clone)"));


			if (ui_1->fields._.m_CachedPtr != nullptr)
				app::GameObject_SetActive(ui_1, false);

		}
		else {
			if (ui_1 != nullptr) {
				if (ui_1->fields._.m_CachedPtr != nullptr) {
					app::GameObject_SetActive(ui_1, true);

					ui_1 = nullptr;
				}
			}
		}

		if (hideUI.f_Enabled.getValue() && hideUI.f_ui_2.getValue()) {
			if (ui_2 == nullptr)
				ui_2 = app::GameObject_Find(string_to_il2cppi("/GlobalHeader(Clone)"));

			if (ui_2->fields._.m_CachedPtr != nullptr)
				app::GameObject_SetActive(ui_2, false);

		}
		else {
			if (ui_2 != nullptr) {
				if (ui_2->fields._.m_CachedPtr != nullptr) {
					app::GameObject_SetActive(ui_2, true);

					ui_2 = nullptr;
				}
			}
		}

		if (hideUI.f_Enabled.getValue() && hideUI.f_ui_3.getValue()) {
			if (ui_3 == nullptr)
				ui_3 = app::GameObject_Find(string_to_il2cppi("/HomeWindow(Clone)"));

			if (ui_3->fields._.m_CachedPtr != nullptr)
				app::GameObject_SetActive(ui_3, false);

		}
		else {
			if (ui_3 != nullptr) {
				if (ui_3->fields._.m_CachedPtr != nullptr) {
					app::GameObject_SetActive(ui_3, true);

					ui_3 = nullptr;
				}
			}
		}

		CALL_ORIGIN(Global_Update2_Hook, __this, method);
	}
}

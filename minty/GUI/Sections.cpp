#include "../functions/about/About.h"
#include "../functions/settings/Settings.h"

#include "../functions/player/godmode.h"
#include "../functions/player/demagehack.h"
#include "../functions/player/skillshack.h"
#include "../functions/world/SetTimeScale.h"
#include "../functions/world/BattleMatch.h"

#include "../functions/visuals/HideUI.h"

#include "../functions/visuals/UnlockFPS.h"


#include "../functions/debug/Debug.h"


std::vector<std::string> ModuleOrder = {
    _("About"),
    _("Player"),
    _("World"),
    _("Visuals"),
    _("Settings"),
    _("Debug")

};

void Init() {
    INIT_FUNC(About);

    INIT_FUNC(GodMode);
    INIT_FUNC(DemageHack);
    //INIT_FUNC(SkillsHack);
    INIT_FUNC(SetTimeScale);
    INIT_FUNC(BattleMatch);


    INIT_FUNC(Settings);

    INIT_FUNC(Debug);



    INIT_FUNC(HideUI);


    INIT_FUNC(UnlockFPS);




}

void Outer() {
    for (auto& func : functions)
        func->Outer();
}

void Status() {
    auto& settings = cheat::Settings::getInstance();

    if (!settings.f_Status.getValue())
        return;

    ImGuiWindowFlags flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize |
        ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoFocusOnAppearing;

    if (!settings.f_StatusMove.getValue())
        flags |= ImGuiWindowFlags_NoMove;

    ImGui::Begin(_("Status"), nullptr, flags);

    auto windowWidth = ImGui::GetWindowSize().x;
    auto& about = cheat::About::getInstance();
    std::string version = about.mVersion;

    ImGui::PushStyleColor(ImGuiCol_Text, { 0.17f, 0.63f, 0.45f, 1.00f });
    ImGui::Text("Minty-MOG %s", version);
    ImGui::PopStyleColor();
    ImGui::Separator();
    for (auto& feature : functions)
        feature->Status();
    ImGui::End();
}

void DrawSection(const std::string& moduleName) {
    for (auto& func : functions) {
        if (func->getModule() != moduleName)
            continue;

        func->GUI();
    }
}

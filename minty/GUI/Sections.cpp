#include "../functions/about/About.h"
#include "../functions/settings/Settings.h"

#include "../functions/player/godmode.h"
#include "../functions/player/demagehack.h"
#include "../functions/world/SetTimeScale.h"

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
  INIT_FUNC(SetTimeScale);



  INIT_FUNC(Settings);

  INIT_FUNC(Debug);



 INIT_FUNC(HideUI);


 INIT_FUNC(UnlockFPS);

 


}

void Outer() {
  for (auto& func : functions)
    func->Outer();
}

void DrawSection(const std::string& moduleName) {
  for (auto& func : functions) {
    if (func->getModule() != moduleName)
      continue;

    func->GUI();
  }
}

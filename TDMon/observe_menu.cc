#include <TDMon/observe_menu.h>

namespace tdmon {
void ObserveMenu::init(tgui::GuiSFML& gui) {}
SupportedApplicationStateChanges ObserveMenu::update() {
  return SupportedApplicationStateChanges::kNull;
}
void ObserveMenu::cleanup(tgui::GuiSFML& gui) {}
SupportedApplicationStateTypes ObserveMenu::getApplicationStateType() const {
  return SupportedApplicationStateTypes::kObserveMenu;
}
}  // namespace tdmon

#include "main_menu.h"

namespace tdmon {
void MainMenu::init(tgui::GuiSFML& gui) {
  main_menu_group_ = tgui::Group::create();
  main_name_label_ = tgui::Label::create(kApplicationNameLabelText);
  main_name_label_->setTextSize(40);
  main_menu_group_->add(main_name_label_);

  gui.add(main_menu_group_);
}

void MainMenu::update() {}

void MainMenu::cleanup(tgui::GuiSFML& gui) { gui.remove(main_menu_group_); }

const std::string MainMenu::kApplicationNameLabelText =
    "Technical Debt Monsters!";

const std::string MainMenu::kViewMascotButtonText = "Show my TD monster";

const std::string MainMenu::kConnectToDataSourcesButtonText = "Setup";
}  // namespace tdmon

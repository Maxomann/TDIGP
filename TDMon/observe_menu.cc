#include <TDMon/constants.h>
#include <TDMon/observe_menu.h>

namespace tdmon {
void ObserveMenu::init(tgui::GuiSFML& gui) {
  observe_menu_group_ = tgui::Group::create();

  back_button_ = tgui::Button::create(Constants::kBackButtonText);
  back_button_->setPosition(0, 0);
  back_button_->setSize(100, 50);
  back_button_->setTextSize(Constants::kButtonFontSize);
  back_button_->onPress.connect([&]() {
    next_application_state_change_ =
        SupportedApplicationStateChanges::kMainMenu;
  });
  observe_menu_group_->add(back_button_);

  refresh_button_ = tgui::Button::create(Constants::kRefreshButtonText);
  refresh_button_->setPosition("parent.width - width", 0);
  refresh_button_->setSize(100, 50);
  refresh_button_->setTextSize(Constants::kButtonFontSize);
  refresh_button_->onPress.connect([&]() { refreshTdMon(); });
  observe_menu_group_->add(refresh_button_);

  tdmon_picture_ = tgui::Picture::create();
  tdmon_picture_->setPosition(50, 100);
  tdmon_picture_->setSize(400, 400);
  observe_menu_group_->add(tdmon_picture_);

  tdmon_data_label_ = tgui::Label::create("No data");
  tdmon_data_label_->setTextSize(Constants::kLabelFontSize);
  tdmon_data_label_->setPosition(0, 520);
  observe_menu_group_->add(tdmon_data_label_);

  gui.add(observe_menu_group_);
}

SupportedApplicationStateChanges ObserveMenu::update() {
  return next_application_state_change_;
}

void ObserveMenu::cleanup(tgui::GuiSFML& gui) {
  gui.remove(observe_menu_group_);
}

SupportedApplicationStateTypes ObserveMenu::getApplicationStateType() const {
  return SupportedApplicationStateTypes::kObserveMenu;
}
void ObserveMenu::refreshTdMon() { throw std::logic_error("not implemented"); }
}  // namespace tdmon

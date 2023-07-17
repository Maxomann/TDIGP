#pragma once

#include <TDMon/application_state.h>
#include <TDMon/constants.h>

#include <string>

namespace tdmon {
template <class SetupApplicationStateType>
class MainMenu : public ApplicationState {
 public:
  // Inherited via ApplicationState
  void init(tgui::GuiSFML& gui) override {
    main_menu_group_ = tgui::Group::create();
    main_name_label_ =
        tgui::Label::create(Constants::kApplicationNameLabelText);
    main_name_label_->setTextSize(Constants::kHeadingFontSize);
    main_name_label_->setPosition("(parent.width - width) / 2", 20.0f);
    main_menu_group_->add(main_name_label_);

    button_layout_ = tgui::VerticalLayout::create();
    button_layout_->setSize({"70%", 200.0f});
    button_layout_->setPosition("(parent.size - size) / 2");

    view_mascot_button_ =
        tgui::Button::create(Constants::kViewMascotButtonText);
    view_mascot_button_->setTextSize(Constants::kButtonFontSize);
    button_layout_->add(view_mascot_button_);
    connect_to_data_sources_button_ =
        tgui::Button::create(Constants::kConnectToDataSourcesButtonText);
    connect_to_data_sources_button_->setTextSize(Constants::kButtonFontSize);
    button_layout_->add(connect_to_data_sources_button_);

    // insert space *after* the buttons have been added
    button_layout_->insertSpace(1, 0.5f);
    main_menu_group_->add(button_layout_);

    gui.add(main_menu_group_);
  }
  std::unique_ptr<ApplicationState> update() override { return nullptr; }
  void cleanup(tgui::GuiSFML& gui) override { gui.remove(main_menu_group_); }

 private:
  tgui::Group::Ptr main_menu_group_ = nullptr;
  tgui::Label::Ptr main_name_label_ = nullptr;

  tgui::VerticalLayout::Ptr button_layout_ = nullptr;
  tgui::Button::Ptr view_mascot_button_ = nullptr;
  tgui::Button::Ptr connect_to_data_sources_button_ = nullptr;
};
}  // namespace tdmon

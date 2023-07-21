/*********************************
 *
 * TD-Mon - Copyright 2023 (c) Kay Leon Gonschior
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the “Software”), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED “AS IS”,
 * WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *********************************/

#pragma once

#include <TDMon/application_state.h>
#include <TDMon/td_mon_cache.h>
#include <TDMon/td_mon_factory.h>

namespace tdmon {
class ObserveMenu : public ApplicationState {
 public:
  static const std::string kLowLevelTexturePath;
  static const std::string kMediumLevelTexturePath;
  static const std::string kHighLevelTexturePath;

  ObserveMenu(TdMonCache& tdmon_cache, TdMonFactory& tdmon_factory);

  // Inherited via ApplicationState
  void init(tgui::GuiSFML& gui) override;
  SupportedApplicationStateChanges update() override;
  void cleanup(tgui::GuiSFML& gui) override;
  SupportedApplicationStateTypes getApplicationStateType() const override;

 private:
  TdMonCache& tdmon_cache_;
  TdMonFactory& tdmon_factory_;

  sf::Texture tdmon_visual_representation_;

  SupportedApplicationStateChanges next_application_state_change_ =
      SupportedApplicationStateChanges::kNull;

  tgui::Group::Ptr observe_menu_group_ = nullptr;
  tgui::Button::Ptr back_button_ = nullptr;
  tgui::Button::Ptr refresh_button_ = nullptr;

  tgui::Picture::Ptr tdmon_picture_ = nullptr;  // todo

  tgui::Label::Ptr tdmon_data_label_ = nullptr;

  void refreshTdMon(bool prefer_cache = false);
};
}  // namespace tdmon

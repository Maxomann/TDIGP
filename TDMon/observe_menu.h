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
/**
 * @brief The observe menu application state. Responsible for displaying the
 * td-mon from cache and updating it from the td-mon factory passed in the
 * constructor, if requested by the click of a button.
 */
class ObserveMenu : public ApplicationState {
 public:
  /**
   * @brief The constructor.
   * @param tdmon_cache The td-mon cache to load and store the td-mon
   * @param tdmon_factory The td-mon factory to use for the creation of new
   * td-mon instances
   */
  ObserveMenu(TdMonCache& tdmon_cache, TdMonFactory& tdmon_factory);

  // Inherited via ApplicationState

  /**
   * @brief Implementation of the init function from ApplicationState.
   * Initializes the gui and gui callbacks.
   * @param gui The gui.
   */
  void init(tgui::GuiSFML& gui) override;

  /**
   * @brief Implementation of the update function from ApplicationState
   * @return The application state to change to
   */
  SupportedApplicationStateChanges update() override;

  /**
   * @brief Implementation of the cleanup function from ApplicationState.
   * Removes the gui elements that were added in init()
   * @param gui The gui
   */
  void cleanup(tgui::GuiSFML& gui) override;

  /**
   * @brief Get this classes application state type
   * @return The application state type
   */
  SupportedApplicationStateTypes getApplicationStateType() const override;

 private:
  /**
   * @brief A reference to the TdMonCache to use for load/save
   */
  TdMonCache& tdmon_cache_;

  /**
   * @brief A reference to the TdMonFactory to use when creating new td-mons
   */
  TdMonFactory& tdmon_factory_;

  /**
   * @brief The currently used texture for the visual representation of the
   * td-mon
   */
  sf::Texture tdmon_visual_representation_;

  /**
   * @brief Store the next application state change to be requested in update().
   * kNull by default (stay in this state). Ui callbacks may change this value
   * dependin on which button is pressed.
   */
  SupportedApplicationStateChanges next_application_state_change_ =
      SupportedApplicationStateChanges::kNull;

  /**
   * @brief The observe menu group ui element
   */
  tgui::Group::Ptr observe_menu_group_ = nullptr;
  /**
   * @brief The back button ui element
   */
  tgui::Button::Ptr back_button_ = nullptr;
  /**
   * @brief The refresh button ui element
   */
  tgui::Button::Ptr refresh_button_ = nullptr;

  /**
   * @brief The td-mon picture ui element
   */
  tgui::Picture::Ptr tdmon_picture_ = nullptr;

  /**
   * @brief The td-mon data label ui element. Used to display multiple lines of
   * text, containing all relevant information about the td-mon, as well as, the
   * timestamp for its last update
   */
  tgui::Label::Ptr tdmon_data_label_ = nullptr;

  /**
   * @brief Private function to refresh the td-mon (load from cache or create a
   * new one from factory)
   * @param prefer_cache true, if the cache should be preferred over creating a
   * new td-mon from factory. If no cache is available, or prefer_cache ==
   * false, a new td-mon is created from factory
   */
  void refreshTdMon(bool prefer_cache = false);
};
}  // namespace tdmon

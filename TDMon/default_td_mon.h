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

#include <TDMon/td_mon.h>

namespace tdmon {
/**
 * @brief Implementation of the default TD-Mon. Has fixed paths to textures and
 * level caps for different version of the textures.
 */
class DefaultTdMon : public TdMon {
 public:
  /**
   * @brief This classes type identifier string. (Required for
   * serialization/deserialization of classes derived form TdMon)
   */
  static const std::string kTypeIdentifierString;

  /**
   * @brief The key string for the attack value when serializing this class to
   * json
   */
  static const std::string kAttackKeyString;
  /**
   * @brief The key string for the defense value when serializing this class to
   * json
   */
  static const std::string kDefenseKeyString;
  /**
   * @brief The key string for the speed value when serializing this class to
   * json
   */
  static const std::string kSpeedKeyString;

  /**
   * @brief The relative path to the texture for the "weakest" form of the
   * TD-Mon
   */
  static const std::string kPathToTex0;
  /**
   * @brief The realtive path to the texture for the "medium" form of the TD-Mon
   */
  static const std::string kPathToTex1;
  /**
   * @brief The relative path to the texture for the "strong" form of the TD-Mon
   */
  static const std::string kPathToTex2;

  /**
   * @brief If a TD-Mons level is bigger than or equal to kLevelCap1, it will return it's
   * "medium" form texture in getTexturePath()
   */
  static const unsigned int kLevelCap1 = 10;
  /**
   * @brief If a TD-Mons level is bigger than or equal to kLevelCap2, it will return it's
   * "strong" form texture in getTexturePath()
   */
  static const unsigned int kLevelCap2 = 20;

  /**
   * @brief The constructor.
   * @param attack_value The attack value for this td-mon
   * @param defense_value The defense value for this td-mon
   * @param speed_value The speed value for this td-mon
   */
  DefaultTdMon(unsigned int attack_value, unsigned int defense_value,
               unsigned int speed_value);

  // Inherited via TdMon

  /**
   * @brief Get the level. This is calculated as the average of attack, defense
   * and speed using integer devision (rounded towards zero).
   * @return The level
   */
  unsigned int getLevel() const override;
  /**
   * @brief Get the attack value
   * @return The attack value
   */
  unsigned int getAttackValue() const override;
  /**
   * @brief Get the defense value
   * @return The defense value
   */
  unsigned int getDefenseValue() const override;
  /**
   * @brief Get the speed value
   * @return The speed value
   */
  unsigned int getSpeedValue() const override;

  /**
   * @brief Serialize this object to json. This includes attack, defense and
   * speed values, as well as a type identifier string stored with key:
   * DefualtTdMon::kJsonTypeIdentifierKey
   * @return The json.
   */
  nlohmann::json toJson() const override;

  /**
   * @brief Create a new DefaultTdMon from json
   * @param json The json to create from
   * @return The created object
   */
  static std::unique_ptr<TdMon> fromJson(nlohmann::json json);

  /**
   * @brief Get the current texture path. This may change depending on the level
   * of the td-mon. See static class variables kLevelCap1 and kLevelCap2.
   * @return The relative texture path.
   */
  const std::string& getTexturePath() const override;

 private:
  /**
   * @brief The attack value
   */
  unsigned int attack_value_ = 0;
  /**
   * @brief The defense value
   */
  unsigned int defense_value_ = 0;
  /**
   * @brief The speed value
   */
  unsigned int speed_value_ = 0;
};
}  // namespace tdmon

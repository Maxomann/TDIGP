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
class DefaultTdMon : public TdMon {
 public:
  static const std::string kTypeIdentifierString;

  static const std::string kAttackKeyString;
  static const std::string kDefenseKeyString;
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
   * @brief If a TD-Mons level is bigger than kLevelCap1, it will return it's
   * "medium" form texture in getTexturePath()
   */
  static const unsigned int kLevelCap1 = 10;
  /**
   * @brief If a TD-Mons level is bigger than kLevelCap2, it will return it's
   * "strong" form texture in getTexturePath()
   */
  static const unsigned int kLevelCap2 = 20;

  DefaultTdMon(unsigned int attack_value, unsigned int defense_value,
               unsigned int speed_value);

  // Inherited via TdMon
  unsigned int getLevel() const override;
  unsigned int getAttackValue() const override;
  unsigned int getDefenseValue() const override;
  unsigned int getSpeedValue() const override;

  nlohmann::json toJson() const override;
  static std::unique_ptr<TdMon> fromJson(nlohmann::json json);

  const std::string& getTexturePath()const override;

 private:
  unsigned int attack_value_ = 0;
  unsigned int defense_value_ = 0;
  unsigned int speed_value_ = 0;
};
}  // namespace tdmon

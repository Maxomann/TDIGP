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

#include <nlohmann/json.hpp>

namespace tdmon {
/**
 * @brief The technical debt monster interface. The purpose of this interface is
 * to represent a technical debt monster with its unique attack, defense and
 * speed values. It also allows requesting the currently appropriate display
 * texture for the TdMon, as well as, serialize it to json.
 */
class TdMon {
 public:
  /**
   * @brief Json key to use for storing the type of the derived classes when
   * serializing to json. Storin that information is needed to allow for
   * deserialization of the correct derived class.
   */
  static const std::string kJsonTypeIdentifierKey;

  /**
   * @brief Virtual default destructor to allow deletion of derived classes
   * from a pointer to this base class
   */
  virtual ~TdMon() = default;

  /**
   * @brief Get the current level of the td-mon
   * @return The level
   */
  virtual unsigned int getLevel() const = 0;

  /**
   * @brief Get the attack value of this td-mon
   * @return The attack value
   */
  virtual unsigned int getAttackValue() const = 0;

  /**
   * @brief Get the defense value of this td-mon
   * @return The defense value
   */
  virtual unsigned int getDefenseValue() const = 0;

  /**
   * @brief Get the speed value of this td-mon
   * @return The speed value
   */
  virtual unsigned int getSpeedValue() const = 0;

  /**
   * @brief Serialize this td-mon to json
   * @return The td-mon in json format
   */
  virtual nlohmann::json toJson() const = 0;

  /**
   * @brief Get the path to the texture representing the current visual of the
   * TD-Mon.
   *
   * This path can change, for example depending on the level of the TD-Mon.
   * @return Path to the texture, relative to the application
   */
  virtual const std::string& getTexturePath() const = 0;
};
}  // namespace tdmon

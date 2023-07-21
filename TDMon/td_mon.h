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
 * @brief The technical debt monster
 */
class TdMon {
 public:
  static const std::string kJsonTypeIdentifierKey;

  virtual ~TdMon() = default;

  virtual unsigned int getLevel() const = 0;

  virtual unsigned int getAttackValue() const = 0;
  virtual unsigned int getDefenseValue() const = 0;
  virtual unsigned int getSpeedValue() const = 0;

  virtual nlohmann::json toJson() const = 0;

  /**
   * @brief Get the path to the texture representing the current visual of the TD-Mon.
   * 
   * This path can change, for example depending on the level of the TD-Mon.
   * @return Path to the texture, relative to the application
  */
  virtual const std::string& getTexturePath()const = 0;
};
}  // namespace tdmon

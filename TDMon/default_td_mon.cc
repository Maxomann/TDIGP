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

#include <TDMon/default_td_mon.h>

namespace tdmon {
tdmon::DefaultTdMon::DefaultTdMon(unsigned int attack_value,
                                  unsigned int defense_value,
                                  unsigned int speed_value)
    : attack_value_(attack_value),
      defense_value_(defense_value),
      speed_value_(speed_value) {}

unsigned int tdmon::DefaultTdMon::getLevel() const {
  // calculate level as the average value of attack, defense and speed
  // integer division: result of the division is rounded towards 0
  return (attack_value_ + defense_value_ + speed_value_) / 3;
}

unsigned int tdmon::DefaultTdMon::getAttackValue() const {
  return attack_value_;
}

unsigned int tdmon::DefaultTdMon::getDefenseValue() const {
  return defense_value_;
}

unsigned int tdmon::DefaultTdMon::getSpeedValue() const { return speed_value_; }

nlohmann::json tdmon::DefaultTdMon::toJson() const {
  nlohmann::json json;
  json[kJsonTypeIdentifierKey] = kTypeIdentifierString;

  json[kAttackKeyString] = attack_value_;
  json[kDefenseKeyString] = defense_value_;
  json[kSpeedKeyString] = speed_value_;

  return json;
}

std::unique_ptr<TdMon> DefaultTdMon::fromJson(nlohmann::json json) {
  return std::make_unique<DefaultTdMon>(
      json.at(kAttackKeyString).get<unsigned int>(),
      json.at(kDefenseKeyString).get<unsigned int>(),
      json.at(kSpeedKeyString).get<unsigned int>());
}

const std::string& DefaultTdMon::getTexturePath()const {
  if (getLevel() >= kLevelCap2) {
    return kPathToTex2;
  } else if (getLevel() >= kLevelCap1) {
    return kPathToTex1;
  } else {
    return kPathToTex0;
  }
}

const std::string DefaultTdMon::kTypeIdentifierString = "DefaultTdMon";
const std::string DefaultTdMon::kAttackKeyString = "Attack";
const std::string DefaultTdMon::kDefenseKeyString = "Defense";
const std::string DefaultTdMon::kSpeedKeyString = "Speed";

const std::string DefaultTdMon::kPathToTex0 = "./data/tex0.png";
const std::string DefaultTdMon::kPathToTex1 = "./data/tex1.png";
const std::string DefaultTdMon::kPathToTex2 = "./data/tex2.png";

}  // namespace tdmon

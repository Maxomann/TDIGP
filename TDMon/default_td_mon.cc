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

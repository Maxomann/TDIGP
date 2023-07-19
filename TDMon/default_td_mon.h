#pragma once

#include <TDMon/td_mon.h>

namespace tdmon {
class DefaultTdMon : public TdMon {
 public:
  static const std::string kTypeIdentifierString;

  static const std::string kAttackKeyString;
  static const std::string kDefenseKeyString;
  static const std::string kSpeedKeyString;

  DefaultTdMon(unsigned int attack_value, unsigned int defense_value,
               unsigned int speed_value);

  // Inherited via TdMon
  unsigned int getLevel() const override;
  unsigned int getAttackValue() const override;
  unsigned int getDefenseValue() const override;
  unsigned int getSpeedValue() const override;

  nlohmann::json toJson() const override;
  static std::unique_ptr<TdMon> fromJson(nlohmann::json json);

 private:
  unsigned int attack_value_ = 0;
  unsigned int defense_value_ = 0;
  unsigned int speed_value_ = 0;

};
}  // namespace tdmon

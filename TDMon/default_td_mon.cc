#include "default_td_mon.h"

tdm::DefaultTdMon::DefaultTdMon(unsigned int attack_value,
                                unsigned int defense_value,
                                unsigned int speed_value)
    : attack_value_(attack_value),
      defense_value_(defense_value),
      speed_value_(speed_value) {}

unsigned int tdm::DefaultTdMon::getLevel() const {
  // calculate level as the average value of attack, defense and speed
  // integer division: result of the division is rounded towards 0
  return (attack_value_ + defense_value_ + speed_value_) / 3;
}

unsigned int tdm::DefaultTdMon::getAttackValue() const { return attack_value_; }

unsigned int tdm::DefaultTdMon::getDefenseValue() const {
  return defense_value_;
}

unsigned int tdm::DefaultTdMon::getSpeedValue() const { return speed_value_; }

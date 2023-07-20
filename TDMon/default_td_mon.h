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
  static const unsigned int kLevelCap1 = 20;
  /**
   * @brief If a TD-Mons level is bigger than kLevelCap2, it will return it's
   * "strong" form texture in getTexturePath()
   */
  static const unsigned int kLevelCap2 = 50;

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

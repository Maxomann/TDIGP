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

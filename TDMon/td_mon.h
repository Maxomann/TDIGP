#pragma once

namespace tdmon {
/**
 * @brief The technical debt monster
 */
class TdMon {
 public:
  virtual ~TdMon() = default;

  virtual unsigned int getLevel() const = 0;

  virtual unsigned int getAttackValue() const = 0;
  virtual unsigned int getDefenseValue() const = 0;
  virtual unsigned int getSpeedValue() const = 0;
};
}  // namespace tdmon

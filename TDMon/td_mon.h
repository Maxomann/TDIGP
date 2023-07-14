#pragma once

namespace tdmon {
class TdMon {
 public:
  virtual ~TdMon() = default;

  virtual unsigned int getLevel() const = 0;

  virtual unsigned int getAttackValue() const = 0;
  virtual unsigned int getDefenseValue() const = 0;
  virtual unsigned int getSpeedValue() const = 0;
};
}  // namespace tdmon

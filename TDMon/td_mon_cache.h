#pragma once

#include <TDMon/td_mon.h>

#include <chrono>
#include <memory>

namespace tdmon {
class TdMonCache {
 public:
  virtual void storeOnDisk() const = 0;
  virtual void loadFromDisk() = 0;
  virtual bool existsOnDisk() const = 0;

  virtual void updateCache(std::unique_ptr<TdMon> data) = 0;

  virtual bool hasCache() const = 0;
  virtual TdMon* getCache() const = 0;

  /**
   * @brief Get the timestamp when the cache was last updated.
   * @return The microseconds since UNIX epoch when the chache was last updated.
   */
  virtual std::chrono::microseconds getLastUpdatedTimestamp() const = 0;
};
}  // namespace tdmon

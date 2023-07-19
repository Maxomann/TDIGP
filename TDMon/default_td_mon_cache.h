#pragma once

#include <TDMon/td_mon.h>
#include <TDMon/td_mon_cache.h>

#include <chrono>

namespace tdmon {
class DefaultTdMonCache : public TdMonCache {
 public:
  static const std::string kCacheFilePath;

  static const std::string kTimestampKeyString;

  // Inherited via TdMonCache
  void storeOnDisk() const override;
  void loadFromDisk() override;
  bool existsOnDisk() const override;

  void updateCache(std::unique_ptr<TdMon> data) override;
  TdMon* getCache() const override;
  bool hasCache() const override;

  std::chrono::seconds getLastUpdatedTimestamp() const override;

 private:
  std::unique_ptr<TdMon> cache_ = nullptr;

  std::chrono::seconds last_updated_timestamp_ = std::chrono::seconds(0);
};
}  // namespace tdmon

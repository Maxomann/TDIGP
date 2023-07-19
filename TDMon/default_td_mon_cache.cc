#include <TDMon/default_td_mon.h>
#include <TDMon/default_td_mon_cache.h>

#include <fstream>

namespace tdmon {
void DefaultTdMonCache::storeOnDisk() const {
  std::ofstream file(kCacheFilePath);
  if (!file.is_open()) {
    throw std::exception("cannot open cache file to write cache to disk");
  }

  nlohmann::json json = cache_->toJson();
  // append timestamp
  json[kTimestampKeyString] = last_updated_timestamp_.count();

  file << json;
}

void DefaultTdMonCache::loadFromDisk() {
  nlohmann::json json;
  std::ifstream file(kCacheFilePath);
  if (!file.is_open()) {
    throw std::exception("cannot open cache file to read cache from disk");
  }

  file >> json;

  // deserialize
  if (json[TdMon::kJsonTypeIdentifierKey] ==
      DefaultTdMon::kTypeIdentifierString) {
    // deserialize default td-mon
    cache_ = DefaultTdMon::fromJson(json);
    // deserialize lsat updated timestamp
    last_updated_timestamp_ =
        std::chrono::seconds(json.at(kTimestampKeyString).get<long long>());
  } else {
    throw std::exception(
        "td-mon type not suppoted for deserialization in DefaultTdMonCache");
  }
}

void DefaultTdMonCache::updateCache(std::unique_ptr<TdMon> data) {
  cache_ = std::move(data);

  // update the "last updated" timestamp to the current seconds since Unix epoch
  last_updated_timestamp_ = std::chrono::duration_cast<std::chrono::seconds>(
      std::chrono::system_clock::now().time_since_epoch());
}

TdMon* DefaultTdMonCache::getCache() const { return cache_.get(); }

std::chrono::seconds DefaultTdMonCache::getLastUpdatedTimestamp() const {
  return last_updated_timestamp_;
}
bool DefaultTdMonCache::hasCache() const { return cache_ != nullptr; }

bool DefaultTdMonCache::existsOnDisk() const {
  return std::filesystem::exists(std::filesystem::path(kCacheFilePath));
}

const std::string DefaultTdMonCache::kCacheFilePath = "./cache.json";
const std::string DefaultTdMonCache::kTimestampKeyString = "_timestamp";

}  // namespace tdmon

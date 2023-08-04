/*********************************
 *
 * TD-Mon - Copyright 2023 (c) Kay Leon Gonschior
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the “Software”), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED “AS IS”,
 * WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *********************************/

#include <TDMon/default_td_mon.h>
#include <TDMon/default_td_mon_cache.h>

#include <fstream>

namespace tdmon {
void DefaultTdMonCache::storeOnDisk() const {
  if (!hasCache()) {
    throw std::exception("cannot store empty cache");
  }

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
    last_updated_timestamp_ = std::chrono::microseconds(
        json.at(kTimestampKeyString).get<long long>());
  } else {
    throw std::exception(
        "td-mon type not suppoted for deserialization in DefaultTdMonCache");
  }
}

void DefaultTdMonCache::updateCache(std::unique_ptr<TdMon> data) {
  cache_ = std::move(data);

  // update the "last updated" timestamp to the current seconds since Unix epoch
  last_updated_timestamp_ =
      std::chrono::duration_cast<std::chrono::microseconds>(
          std::chrono::system_clock::now().time_since_epoch());
}

TdMon* DefaultTdMonCache::getCache() const { return cache_.get(); }

std::chrono::microseconds DefaultTdMonCache::getLastUpdatedTimestamp() const {
  return last_updated_timestamp_;
}

bool DefaultTdMonCache::hasCache() const { return cache_ != nullptr; }

bool DefaultTdMonCache::existsOnDisk() const {
  return std::filesystem::exists(std::filesystem::path(kCacheFilePath));
}

const std::string DefaultTdMonCache::kCacheFilePath = "./cache.json";
const std::string DefaultTdMonCache::kTimestampKeyString = "_timestamp";

}  // namespace tdmon

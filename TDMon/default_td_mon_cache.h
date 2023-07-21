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

#pragma once

#include <TDMon/td_mon.h>
#include <TDMon/td_mon_cache.h>

#include <chrono>

namespace tdmon {
/**
 * @brief The default implementation of the TdMonCache. This implementation
 * currently only supports serialization/deserialization of DefaultTdMon
 * objects
 */
class DefaultTdMonCache : public TdMonCache {
 public:
  /**
   * @brief The path to the cache file location on disk.
   */
  static const std::string kCacheFilePath;

  /**
   * @brief The json key for the timestamp value.
   */
  static const std::string kTimestampKeyString;

  // Inherited via TdMonCache

  /**
   * @brief Stores the current cache to disk
   */
  void storeOnDisk() const override;

  /**
   * @brief Loads the current cache from disk
   */
  void loadFromDisk() override;

  /**
   * @brief Check whether the cache exists on disk
   * @return true if "./cache.json" exists
   */
  bool existsOnDisk() const override;

  /**
   * @brief Update the cache with data. Note that this does not yet write the
   * cache to disk. It only updates the internal cache.
   * @param data The td-mon to store in cache.
   */
  void updateCache(std::unique_ptr<TdMon> data) override;
  /**
   * @brief Get the currently cache td-mon
   * @return A pointer to the td-mon. Returns nullptr if no internal cache exists.
  */
  TdMon* getCache() const override;
  /**
   * @brief Check whether an internal cache exists
   * @return true if it does
  */
  bool hasCache() const override;

  /**
   * @brief Get the timestamp of when the cache was last updated
   * @return The timestamp in microseconds since unix epoch
  */
  std::chrono::microseconds getLastUpdatedTimestamp() const override;

 private:
  /**
   * @brief The cache
  */
  std::unique_ptr<TdMon> cache_ = nullptr;

  /**
   * @brief The timestamp when the cache was last updated in microseconds since unix epoch.
  */
  std::chrono::microseconds last_updated_timestamp_ =
      std::chrono::microseconds(0);
};
}  // namespace tdmon

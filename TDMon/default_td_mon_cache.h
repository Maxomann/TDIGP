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

  std::chrono::microseconds getLastUpdatedTimestamp() const override;

 private:
  std::unique_ptr<TdMon> cache_ = nullptr;

  std::chrono::microseconds last_updated_timestamp_ =
      std::chrono::microseconds(0);
};
}  // namespace tdmon

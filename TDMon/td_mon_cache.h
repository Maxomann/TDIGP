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

#include <chrono>
#include <memory>

namespace tdmon {
/**
 * @brief Interface for storage container classes which allow storing of a
 * td-mon, as well as, serialization/deserialization to a file on disk. Also
 * stores the timestamp when it was last modified. The purpose of the TdMonCache
 * is to allow viewing of a previously generated TdMon without regenerating it
 * from a factory. This removes the need to enter login information (like Jira
 * username and password) every time one starts the application to view their
 * TdMon.
 */
class TdMonCache {
 public:
  /**
   * @brief Store this cache to disk
   *
   * Stores the currently cached td-mon, as well as a timestamp indicating when
   * the cache was last changed. Cache must contain a td-mon (not be empty) when
   * calling this method.
   */
  virtual void storeOnDisk() const = 0;

  /**
   * @brief Load the cache from disk.
   *
   * Overrides the current cache with the cache from disk.
   */
  virtual void loadFromDisk() = 0;

  /**
   * @brief Check whether a cache file exists on disk.
   * @return true, if a file exists. false otherwise.
   */
  virtual bool existsOnDisk() const = 0;

  /**
   * @brief Update the cache with new td-mon data. Overrides the current cache.
   * Also updates the "last-modified" timestamp to the current system time.
   * @param data
   */
  virtual void updateCache(std::unique_ptr<TdMon> data) = 0;

  /**
   * @brief Check whether a cache is loaded currently.
   * @return true, if a loaded cache exists. false otherwise.
   */
  virtual bool hasCache() const = 0;

  /**
   * @brief Get the current cache.
   * @return ptr to the td mon stored in the cache. nullptr, if cache is empty.
   */
  virtual TdMon* getCache() const = 0;

  /**
   * @brief Get the timestamp when the cache was last updated.
   * @return The microseconds since UNIX epoch when the chache was last updated.
   */
  virtual std::chrono::microseconds getLastUpdatedTimestamp() const = 0;
};
}  // namespace tdmon

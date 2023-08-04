#include <TDMon/default_td_mon.h>
#include <TDMon/default_td_mon_cache.h>
#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>
#include <thread>
#include <chrono>

namespace tdmon {
// GENERAL INFO:
// Usually I would create a TdMonMock class to test a container object like the
// DefaultTdMonCache. In this case, the DefaultTdMonCache only works with the
// DefaultTdMon (because of serialization/deserialization), therefore I use
// DefaultTdMon directly. If any tests for DefaultTdMonCache fail, please make
// sure that all DefaultTdMon tests pass before investigating the error.

/**
 * @brief Test, if the cache stores to disk correctly. Note: Does not validate
 * the correctness of data that is serialized in DefaultTdMon::toJson().
 */
TEST(DefaultTdMonCache, StoresToDiskCorrectly) {
  // delete possibly existing cache file
  std::filesystem::remove(DefaultTdMonCache::kCacheFilePath);

  // if this fails, there is an error within the test function
  if (std::filesystem::exists(DefaultTdMonCache::kCacheFilePath)) {
    throw std::exception("cache file must not exists before continuing");
  }

  DefaultTdMonCache cache;
  cache.updateCache(std::make_unique<DefaultTdMon>(100, 200, 300));
  cache.storeOnDisk();

  EXPECT_TRUE(std::filesystem::exists(DefaultTdMonCache::kCacheFilePath));

  std::ifstream file(DefaultTdMonCache::kCacheFilePath);
  if (!file.is_open()) {
    throw std::exception("cannot open cache file");
  }

  nlohmann::json json;
  file >> json;
  file.close();

  // check for the json has the correct size
  EXPECT_EQ(json.size(), 5);

  // chech if the json contains a timestamp field
  EXPECT_TRUE(json.contains(DefaultTdMonCache::kTimestampKeyString));
}

/**
 * @brief Test, if the cache loads the correct data from disk.
 */
TEST(DefaultTdMonCache, LoadsFromDiskCorrectly) {
  // delete possibly existing cache file
  std::filesystem::remove(DefaultTdMonCache::kCacheFilePath);

  // if this fails, there is an error within the test function
  if (std::filesystem::exists(DefaultTdMonCache::kCacheFilePath)) {
    throw std::exception("cache file must not exists before continuing");
  }

  // put this in scope to not accidentally access td_mon later on
  {
    DefaultTdMon td_mon(100, 200, 300);
    nlohmann::json json = td_mon.toJson();
    json[DefaultTdMonCache::kTimestampKeyString] = 12345;

    std::ofstream file(DefaultTdMonCache::kCacheFilePath);
    if (!file.is_open()) {
      throw std::exception("cannot open cache file to write to");
    }
    file << json;
    file.close();
  }

  if (!std::filesystem::exists(DefaultTdMonCache::kCacheFilePath)) {
    throw std::exception(
        "cache file must exists before allowing cache to read from disk");
  }

  DefaultTdMonCache cache;
  cache.loadFromDisk();

  EXPECT_EQ(cache.getLastUpdatedTimestamp(), std::chrono::microseconds(12345));

  TdMon* read_td_mon = cache.getCache();
  EXPECT_NE(read_td_mon, nullptr);

  EXPECT_EQ(read_td_mon->getAttackValue(), 100);
  EXPECT_EQ(read_td_mon->getDefenseValue(), 200);
  EXPECT_EQ(read_td_mon->getSpeedValue(), 300);
}

/**
 * @brief Test, if the cache detects the existance (or absence) of a cache file
 * on disk correctly.
 */
TEST(DefaultTdMonCache, DetectsExistanceOfCacheOnDiskCorrectly) {
  // delete possibly existing cache file
  std::filesystem::remove(DefaultTdMonCache::kCacheFilePath);

  // if this fails, there is an error within the test function
  if (std::filesystem::exists(DefaultTdMonCache::kCacheFilePath)) {
    throw std::exception("cache file must not exists before continuing");
  }

  DefaultTdMonCache cache;
  EXPECT_FALSE(cache.existsOnDisk());

  // create cache file on disk
  {
    std::ofstream file(DefaultTdMonCache::kCacheFilePath);
    if (!file.is_open()) {
      throw std::exception("cannot open cache file to write to");
    }
    file << "test";
    file.close();
  }

  EXPECT_TRUE(cache.existsOnDisk());

  // clean up to not leave invalid cache file on disk
  std::filesystem::remove(DefaultTdMonCache::kCacheFilePath);
}

/**
 * @brief Test, if the cache is updated and the new data is returned in
 * subsequent calls to getCache()
 */
TEST(DefaultTdMonCache, UpdatesAndGetsCacheCorrectly) {
  DefaultTdMonCache cache;

  EXPECT_EQ(cache.getCache(), nullptr);

  // put this in scope to not accidentally access new_cache_data later
  {
    cache.updateCache(std::make_unique<DefaultTdMon>(100, 200, 300));

    TdMon* new_cache_data = cache.getCache();

    EXPECT_NE(new_cache_data, nullptr);

    EXPECT_EQ(new_cache_data->getAttackValue(), 100);
    EXPECT_EQ(new_cache_data->getDefenseValue(), 200);
    EXPECT_EQ(new_cache_data->getSpeedValue(), 300);
  }

  // put this in scope to not accidentally access new_cache_data later
  {
    cache.updateCache(std::make_unique<DefaultTdMon>(700, 800, 900));

    TdMon* new_cache_data = cache.getCache();

    EXPECT_NE(new_cache_data, nullptr);

    EXPECT_EQ(new_cache_data->getAttackValue(), 700);
    EXPECT_EQ(new_cache_data->getDefenseValue(), 800);
    EXPECT_EQ(new_cache_data->getSpeedValue(), 900);
  }
}

/**
 * @brief Test, if the internal cache (or absence thereof) is returned correctly
 */
TEST(DefaultTdMonCache, DetectsWhetherInternalCacheExistsCorrectly) {
  DefaultTdMonCache cache;

  EXPECT_FALSE(cache.hasCache());

  cache.updateCache(std::make_unique<DefaultTdMon>(100, 200, 300));

  EXPECT_TRUE(cache.hasCache());
}

/**
 * @brief Test, if the timestamp is changed on update. The timestamp is not
 * tested for "correctness", since it is very difficult (maybe even impossible)
 * to get the same timestamp that was generated inside the updateCache() later
 * on. At least, I don't know a way to do this using google test.
 */
TEST(DefaultTdMonCache, ChangesTimestampOnUpdate) {
  DefaultTdMonCache cache;

  EXPECT_EQ(cache.getLastUpdatedTimestamp(), std::chrono::microseconds(0));

  cache.updateCache(std::make_unique<DefaultTdMon>(100, 200, 300));

  std::chrono::microseconds timestamp0 = cache.getLastUpdatedTimestamp();

  EXPECT_NE(timestamp0, std::chrono::microseconds(0));

  // sleep for 10 milliseconds to make sure the timestamp changes
  std::this_thread::sleep_for(std::chrono::milliseconds(10));

  // update with same data, doesent't matter
  cache.updateCache(std::make_unique<DefaultTdMon>(100, 200, 300));

  std::chrono::microseconds timestamp1 = cache.getLastUpdatedTimestamp();

  EXPECT_NE(timestamp1, std::chrono::microseconds(0));
  // check if timestamp is different (has been changed)
  EXPECT_NE(timestamp0, timestamp1);
}

}  // namespace tdmon

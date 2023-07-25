#include <TDMon/default_td_mon.h>
#include <gtest/gtest.h>

#include <string>

namespace tdmon {
/**
 * @brief Test, if attack, defense and speed values are returned correctly
 * depending on the values given in the constructor.
 */
TEST(DefaultTdMon, StoresValuesCorrectly) {
  DefaultTdMon td_mon(100, 200, 300);

  EXPECT_EQ(td_mon.getAttackValue(), 100);
  EXPECT_EQ(td_mon.getDefenseValue(), 200);
  EXPECT_EQ(td_mon.getSpeedValue(), 300);
}

/**
 * @brief Test, if the level is calculated correctly from the given attack,
 * defense and speed values.
 */
TEST(DefaultTdMon, CalculatesLevelCorrectly) {
  {
    DefaultTdMon td_mon(0, 0, 0);
    EXPECT_EQ(td_mon.getLevel(), 0);
  }

  {
    DefaultTdMon td_mon(100, 100, 100);
    EXPECT_EQ(td_mon.getLevel(), 100);
  }

  {
    DefaultTdMon td_mon(1, 2, 3);
    EXPECT_EQ(td_mon.getLevel(), 2);
  }

  {
    DefaultTdMon td_mon(2, 2, 3);
    EXPECT_EQ(td_mon.getLevel(), 2);
  }

  {
    DefaultTdMon td_mon(2, 2, 4);
    EXPECT_EQ(td_mon.getLevel(), 2);
  }

  {
    DefaultTdMon td_mon(2, 2, 5);
    EXPECT_EQ(td_mon.getLevel(), 3);
  }
}

/**
 * @brief Test, if serialization to json works correctly
 */
TEST(DefaultTdMon, SerializesToJsonCorrectly) {
  {
    DefaultTdMon td_mon(100, 200, 300);
    const nlohmann::json json = td_mon.toJson();

    // check the size of the json object
    EXPECT_EQ(json.size(), 4);

    EXPECT_EQ(json.at(DefaultTdMon::kJsonTypeIdentifierKey).get<std::string>(),
              DefaultTdMon::kTypeIdentifierString);

    EXPECT_EQ(json.at(DefaultTdMon::kAttackKeyString).get<unsigned int>(), 100);
    EXPECT_EQ(json.at(DefaultTdMon::kDefenseKeyString).get<unsigned int>(),
              200);
    EXPECT_EQ(json.at(DefaultTdMon::kSpeedKeyString).get<unsigned int>(), 300);
  }
}

/**
 * @brief Test, if deserializing from json works correctly
 */
TEST(DefaultTdMon, CreatesFromJsonCorrectly) {
  nlohmann::json json = nlohmann::json::object();
  json[DefaultTdMon::kAttackKeyString] = 400;
  json[DefaultTdMon::kDefenseKeyString] = 500;
  json[DefaultTdMon::kSpeedKeyString] = 600;

  std::unique_ptr<TdMon> td_mon = DefaultTdMon::fromJson(json);

  EXPECT_EQ(td_mon->getAttackValue(), 400);
  EXPECT_EQ(td_mon->getDefenseValue(), 500);
  EXPECT_EQ(td_mon->getSpeedValue(), 600);
}

/**
 * @brief Test, if the correct texture path is returned for different levels
 * (low, medium, high)
 */
TEST(DefaultTdMon, ReturnsCorrectTexturePathForLevels) {
  // create tdmon of level kLevelCap - 1
  DefaultTdMon low(DefaultTdMon::kLevelCap1 - 1, DefaultTdMon::kLevelCap1 - 1,
                   DefaultTdMon::kLevelCap1 - 1);

  // create tdmon of level kLevelCap2 - 1
  DefaultTdMon med(DefaultTdMon::kLevelCap2 - 1, DefaultTdMon::kLevelCap2 - 1,
                   DefaultTdMon::kLevelCap2 - 1);

  // create tdmon of level kLevelCap2
  DefaultTdMon high(DefaultTdMon::kLevelCap2, DefaultTdMon::kLevelCap2,
                    DefaultTdMon::kLevelCap2);

  EXPECT_EQ(low.getTexturePath(), DefaultTdMon::kPathToTex0);
  EXPECT_EQ(med.getTexturePath(), DefaultTdMon::kPathToTex1);
  EXPECT_EQ(high.getTexturePath(), DefaultTdMon::kPathToTex2);
}
}  // namespace tdmon

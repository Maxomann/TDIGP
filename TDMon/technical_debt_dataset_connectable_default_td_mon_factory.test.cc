#define SQLITECPP_COMPILE_DLL  // this is a workaround for
                               // https://github.com/SRombauts/SQLiteCpp/issues/432

#include <SQLiteCpp/SQLiteCpp.h>
#include <TDMon/technical_debt_dataset_connectable_default_td_mon_factory.h>
#include <gtest/gtest.h>

#include <filesystem>
#include <memory>
#include <string>

namespace tdmon {
/**
 * @brief The path to the database containing test data
 */
const std::string kTestDbPath = "./test.db";

/**
 * @brief Helper function. Create the database containing test data on disk, if
 * it does not exist. Ensures that the database contains the correct test data.
 */
void ensureTestDbExistsAndContainsCorrectData() {
  const std::string test_data_sql =
      "BEGIN TRANSACTION;DROP TABLE IF EXISTS \"JIRA_ISSUES\";CREATE TABLE IF "
      "NOT EXISTS \"JIRA_ISSUES\" (\"KEY\"	INTEGER NOT "
      "NULL,\"TYPE\"	TEXT NOT NULL,\"ASSIGNEE\"	TEXT NOT "
      "NULL,\"RESOLUTION_DATE\"	TEXT NOT NULL,\"REPORTER\"	TEXT NOT "
      "NULL,\"WATCH_COUNT\"	INTEGER NOT NULL);INSERT INTO \"JIRA_ISSUES\" "
      "VALUES (1,'Test','Human1','','Human1',1);INSERT INTO \"JIRA_ISSUES\" "
      "VALUES (2,'Documentation','Human1','2000-01-01','Human1',1);INSERT INTO "
      "\"JIRA_ISSUES\" VALUES "
      "(3,'Test','Human2','2000-01-01','Human1',1);INSERT INTO \"JIRA_ISSUES\" "
      "VALUES (4,'Test','Human1','2000-01-01','Human2',1);INSERT INTO "
      "\"JIRA_ISSUES\" VALUES "
      "(5,'Test','Human3','2000-01-01','Human1',5);INSERT INTO \"JIRA_ISSUES\" "
      "VALUES (6,'Other','Human1','2000-01-01','Human1',100);COMMIT;";

  // write test db
  SQLite::Database db(kTestDbPath,
                      SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

  db.exec(test_data_sql);
}

/**
 * @brief Helper function. Remove test db, if it exists on disk
 */
void ensureTestDbDoesNotExists() { std::filesystem::remove(kTestDbPath); }

/**
 * @brief Test, if sqlite data is parsed correctly. Test data is selected to
 * contain variation and to cover edge cases. See
 * ensureTestDbExistsAndContainsCorrectData for test data string.
 */
TEST(TechnicalDebtDatasetConnectableDefaultTdMonFactory, ParsesDataCorrectly) {
  ensureTestDbExistsAndContainsCorrectData();

  TechnicalDebtDatasetConnectableDefaultTdMonFactory factory;
  factory.setDatabasePath(kTestDbPath);
  factory.setUserIdentifier("Human1");

  std::unique_ptr<TdMon> td_mon = factory.create();

  // check if the returned values are equal to the correct ones when parsing the
  // data
  EXPECT_EQ(td_mon->getAttackValue(), 2);
  EXPECT_EQ(td_mon->getDefenseValue(), 4);
  EXPECT_EQ(td_mon->getSpeedValue(), 8);

  // level is not parsed, and therefore does not need to checked
  // EXPECT_EQ(td_mon->getLevel(), 0);
}

/**
 * @brief Test, if connection to tadabase is only reported as established, when
 * the database actually exists
 */
TEST(TechnicalDebtDatasetConnectableDefaultTdMonFactory,
     ConnectsToDataSourcesOnlyIfDbExists) {
  // ensure the database does not exist on disk
  ensureTestDbDoesNotExists();

  TechnicalDebtDatasetConnectableDefaultTdMonFactory factory;
  factory.setUserIdentifier("Human1");
  factory.setDatabasePath(kTestDbPath);

  bool fails = false;
  try {
    factory.connectToDataSources();
  } catch (std::exception e) {
    fails = true;
  }
  EXPECT_TRUE(fails);
  EXPECT_FALSE(factory.isConnectedToDataSources());

  // create the database
  ensureTestDbExistsAndContainsCorrectData();

  factory.connectToDataSources();

  EXPECT_TRUE(factory.isConnectedToDataSources());
}

/**
 * @brief Test, if the factory requires access information to be complete.
 */
TEST(TechnicalDebtDatasetConnectableDefaultTdMonFactory,
     RequiresCompleteAccessInformation) {
  TechnicalDebtDatasetConnectableDefaultTdMonFactory factory;
  EXPECT_FALSE(factory.isRequiredDataAccessInformationAvailable());

  factory.setDatabasePath(kTestDbPath);

  EXPECT_FALSE(factory.isRequiredDataAccessInformationAvailable());

  factory.setUserIdentifier("Human1");

  EXPECT_TRUE(factory.isRequiredDataAccessInformationAvailable());
}
}  // namespace tdmon

#define SQLITECPP_COMPILE_DLL  // this is a workaround for
                               // https://github.com/SRombauts/SQLiteCpp/issues/432
#include <SQLiteCpp/SQLiteCpp.h>
#include <TDMon/default_td_mon.h>
#include <TDMon/technical_debt_dataset_connectable_default_td_mon_factory.h>

#include <iostream>
#include <memory>

namespace tdmon {
std::unique_ptr<TdMon>
TechnicalDebtDatasetConnectableDefaultTdMonFactory::create() {
  SQLite::Database db(path_to_db_.string(), SQLite::OPEN_READONLY);

  unsigned int attack_value = 0;
  unsigned int defense_value = 0;
  unsigned int speed_value = 0;

  // Calculate attack value
  {
    SQLite::Statement attack_query(
        db,
        "SELECT COUNT(key) FROM JIRA_ISSUES WHERE (type='Test' OR type='Documentation') "
        "AND assignee=? AND resolution_date IS NOT ''"
        " ORDER BY reporter DESC");
    // bind the chosen user_identifier to the db query
    attack_query.bind(1, user_identifier_);

    // the query only produces one result, so the loop is only entered once
    while (attack_query.executeStep()) {
      int count = attack_query.getColumn(0);
      attack_value = count;
    }
  }

  // Calculate defense value
  {
    SQLite::Statement defense_query(db,
                                    "SELECT COUNT(key) FROM JIRA_ISSUES WHERE "
                                    "(type='Test' OR type='Documentation') "
                                    "AND reporter=?");
    // bind the chosen user_identifier to the db query
    defense_query.bind(1, user_identifier_);

    // the query only produces one result, so the loop is only entered once
    while (defense_query.executeStep()) {
      int count = defense_query.getColumn(0);
      defense_value = count;
    }
  }

  // Calculate speed value
  {
    SQLite::Statement speed_query(
        db,
        "SELECT SUM(watch_count) FROM JIRA_ISSUES WHERE (type='Test' OR "
        "type='Documentation') AND assignee=? ORDER BY "
        "reporter DESC");
    // bind the chosen user_identifier to the db query
    speed_query.bind(1, user_identifier_);

    // the query only produces one result, so the loop is only entered once
    while (speed_query.executeStep()) {
      int count = speed_query.getColumn(0);
      speed_value = count;
    }
  }

  return std::make_unique<DefaultTdMon>(attack_value, defense_value, speed_value);
}

void TechnicalDebtDatasetConnectableDefaultTdMonFactory::
    connectToDataSources() {
  // this step succeeds, if a connection to the database on disk can be
  // established (just to make sure connection to database is possible, this
  // step is more relvant when connecting to an external API like Jira, etc...)
  SQLite::Database db(path_to_db_.string(), SQLite::OPEN_READONLY);

  // this statement is not reached, if the above statement throws an
  // exception (in case the connection to the database cannot be
  // established)
  connected_ = true;
}

bool TechnicalDebtDatasetConnectableDefaultTdMonFactory::
    isRequiredDataAccessInformationAvailable() {
  return !path_to_db_.empty() && user_identifier_ != "";
}

bool TechnicalDebtDatasetConnectableDefaultTdMonFactory::
    isConnectedToDataSources() {
  return connected_;
}

void TechnicalDebtDatasetConnectableDefaultTdMonFactory::setDatabasePath(
    std::filesystem::path path) {
  path_to_db_ = std::move(path);
}

void TechnicalDebtDatasetConnectableDefaultTdMonFactory::setUserIdentifier(
    std::string identifier) {
  user_identifier_ = std::move(identifier);
}

}  // namespace tdmon

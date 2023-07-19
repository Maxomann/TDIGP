#include <SQLiteCpp/SQLiteCpp.h>
#include <TDMon/default_td_mon.h>
#include <TDMon/technical_debt_dataset_connectable_default_td_mon_factory.h>

#include <memory>

namespace tdmon {
std::unique_ptr<TdMon>
TechnicalDebtDatasetConnectableDefaultTdMonFactory::create() {
  //throw std::logic_error("not implemented");

  // TODO TODO!!!

  // parse db content

  // create DefaultTdMon from it

  return std::make_unique<DefaultTdMon>(100, 101, 102);
}
void TechnicalDebtDatasetConnectableDefaultTdMonFactory::
    connectToDataSources() {
  // this step succeeds, if a connection to the database on disk can be
  // established (just to make sure connection to database is possible, this
  // step is more relvant when connecting to an external API like Jira, etc...)
  SQLite::Database db(path_to_db_.string());

  connected_ = true;
}

bool TechnicalDebtDatasetConnectableDefaultTdMonFactory::
    isRequiredDataAccessInformationAvailable() {
  return !path_to_db_.empty();
}

bool TechnicalDebtDatasetConnectableDefaultTdMonFactory::
    isConnectedToDataSources() {
  return connected_;
}

void TechnicalDebtDatasetConnectableDefaultTdMonFactory::setDatabasePath(
    std::filesystem::path path) {
  path_to_db_ = path;
}
}  // namespace tdmon

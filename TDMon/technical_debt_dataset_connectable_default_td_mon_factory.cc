#include <TDMon/default_td_mon.h>
#include <TDMon/technical_debt_dataset_connectable_default_td_mon_factory.h>

#include <memory>

namespace tdmon {
std::unique_ptr<TdMon>
TechnicalDebtDatasetConnectableDefaultTdMonFactory::create() {
  throw std::logic_error("not implemented");

  // parse db content

  // create DefaultTdMon from it

  return std::make_unique<DefaultTdMon>(0, 0, 0);
}
void TechnicalDebtDatasetConnectableDefaultTdMonFactory::
    connectToDataSources() {
  throw std::logic_error("not implemented");
  // check if db exists on disk
}

bool TechnicalDebtDatasetConnectableDefaultTdMonFactory::
    isRequiredDataAccessInformationAvailable() {
  return false;
}

bool TechnicalDebtDatasetConnectableDefaultTdMonFactory::
    isConnectedToDataSources() {
  return false;
}

void TechnicalDebtDatasetConnectableDefaultTdMonFactory::setDatabasePath(
    std::filesystem::path path) {}
}  // namespace tdmon

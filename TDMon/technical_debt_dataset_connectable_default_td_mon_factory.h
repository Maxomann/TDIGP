#pragma once

#include <TDMon/connectable_to_data_sources.h>
#include <TDMon/td_mon_factory.h>
#include <TDMon/technical_debt_dataset_access_information_container.h>

#include <filesystem>

namespace tdmon {
class TechnicalDebtDatasetConnectableDefaultTdMonFactory
    : public TdMonFactory,
      public ConnectableToDataSources,
      public TechnicalDebtDatasetAccessInformationContainer {
 public:
  // Inherited via TdMonFactory
  std::unique_ptr<TdMon> create() override;

  // Inherited via ConnectableToDataSources
  void connectToDataSources() override;
  bool isRequiredDataAccessInformationAvailable() override;
  bool isConnectedToDataSources() override;

  // Inherited via TechnicalDebtDatasetAccessInformationContainer
  void setDatabasePath(std::filesystem::path path) override;

  private:
  std::filesystem::path path_to_db_;

  bool connected_ = false;
};
}  // namespace tdmon

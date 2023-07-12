#pragma once

#include<filesystem>
#include<TDMon/connectable_to_data_sources.h>

namespace tdm {
class ConnectableToTechnicalDebtDatasetDatabase : public ConnectableToDataSources {
 public:
  virtual ~ConnectableToTechnicalDebtDatasetDatabase() = default;

  virtual void setDatabasePath(std::filesystem::path path) = 0;
};
}  // namespace tdm

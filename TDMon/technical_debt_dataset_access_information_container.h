#pragma once

#include<filesystem>

namespace tdmon {
class TechnicalDebtDatasetAccessInformationContainer {
 public:
  virtual ~TechnicalDebtDatasetAccessInformationContainer() = default;

  virtual void setDatabasePath(std::filesystem::path path) = 0;
};
}  // namespace tdmon

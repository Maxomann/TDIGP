#pragma once

#include<filesystem>

namespace tdm {
class TechnicalDebtDatasetAccessInformationContainer {
 public:
  virtual ~TechnicalDebtDatasetAccessInformationContainer() = default;

  virtual void setDatabasePath(std::filesystem::path path) = 0;
};
}  // namespace tdm

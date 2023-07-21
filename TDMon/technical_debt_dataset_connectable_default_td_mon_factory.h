/*********************************
 *
 * TD-Mon - Copyright 2023 (c) Kay Leon Gonschior
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the �Software�), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED �AS IS�,
 * WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *********************************/

#pragma once

#include <TDMon/connectable_to_data_sources.h>
#include <TDMon/td_mon_factory.h>
#include <TDMon/technical_debt_dataset_access_information_container.h>

#include <filesystem>
#include <string>

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
  void setUserIdentifier(std::string identifier) override;
  void setDatabasePath(std::filesystem::path path) override;

  private:
  std::filesystem::path path_to_db_;
   std::string user_identifier_;

  bool connected_ = false;
};
}  // namespace tdmon

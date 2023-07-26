/*********************************
 *
 * TD-Mon - Copyright 2023 (c) Kay Leon Gonschior
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the “Software”), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED “AS IS”,
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
/**
 * @brief The implementation for a td-mon factory which can be connected to the
 * technical debt dataset
 */
class TechnicalDebtDatasetConnectableDefaultTdMonFactory
    : public TdMonFactory,
      public ConnectableToDataSources,
      public TechnicalDebtDatasetAccessInformationContainer {
 public:
  // Inherited via TdMonFactory

  /**
   * @brief Create the td-mon
   * @return The td-mon
   */
  std::unique_ptr<TdMon> create() override;

  // Inherited via ConnectableToDataSources

  /**
   * @brief Opens the sqlite database from disk. Then closes it again. This
   * function closes the database again, because a sqlite databse does not need
   * to be kept open when not reading from it.
   */
  void connectToDataSources() override;

  /**
   * @brief Get whether the path to the sqlite database, as well as, the
   * required user-identifier for parsing the databse are available
   * @return true, if the required information is available
   */
  bool isRequiredDataAccessInformationAvailable() override;

  /**
   * @brief Returns true, if opening the database succeeded in
   * connectToDataSources(). Due to the way, that sqlite databases work, this
   * class is assumed to be connected to the database, if the database was
   * opened once before. This does not mean that the database is currently open.
   * @return true, if connectToDataSources() was completed successfully before.
   */
  bool isConnectedToDataSources() override;

  // Inherited via TechnicalDebtDatasetAccessInformationContainer

  /**
   * @brief Set the user identifier whose issues to use when parsing the
   * technical debt dataset.
   * @param identifier The user-identifier string
   */
  void setUserIdentifier(std::string identifier) override;

  /**
   * @brief Set the path to the technical debt dataset sqlite database on disk
   * @param path The path to the sqlite databse.
   */
  void setDatabasePath(std::filesystem::path path) override;

 private:
  /**
   * @brief The path to the sqlite database on disk
   */
  std::filesystem::path path_to_db_;

  /**
   * @brief The user-identifier string whose issues to use when parsing the
   * technical debt dataset.
   */
  std::string user_identifier_;

  /**
   * @brief True, if openening the database succeeded in connectToDataSources
   */
  bool connected_ = false;
};
}  // namespace tdmon

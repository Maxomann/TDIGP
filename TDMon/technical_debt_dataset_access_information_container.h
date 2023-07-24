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

#include <filesystem>

namespace tdmon {
/**
 * @brief Interface class for any implementation which stores access information
 * to the technical debt dataset.
 *
 * Information needed to access the technical debt dataset is: the path to the
 * sqlite database on disk; the user-identifier to parse the data for (the
 * dataset contains data for many different maintainers, but td-mon is intended
 * to parse the data for one person.
 */
class TechnicalDebtDatasetAccessInformationContainer {
 public:
  /**
   * @brief Virtual default destructor to allow deletion of derived classes
   * from a pointer to this base class
   */
  virtual ~TechnicalDebtDatasetAccessInformationContainer() = default;

  /**
   * @brief Set the user-identifier to parse the dataset for
   * @param identifier The user-identifier
  */
  virtual void setUserIdentifier(std::string identifier) = 0;

  /**
   * @brief Set the path to the technical debt dataset on disk.
   * @param path The path. Any valid std::filesystem::path is allowed.
  */
  virtual void setDatabasePath(std::filesystem::path path) = 0;
};
}  // namespace tdmon

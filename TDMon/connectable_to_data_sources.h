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

namespace tdmon {
/**
 * @brief Interface for any class that supports connection to one or multiple
 * data source(s) (sql database, Jira, etc...). Its purpose is to allow
 * checking, if all required login information is available in the implementing
 * class, connecting to data sources and checking the current status of the
 * connection (connected or disconnected).
 */
class ConnectableToDataSources {
 public:
  /**
   * @brief Virtual default destructor to allow deletion of derived classes
   * from a pointer to this base class.
   */
  virtual ~ConnectableToDataSources() = default;

  /**
   * @brief Establish a connection to the data sources.
   */
  virtual void connectToDataSources() = 0;

  /**
   * @brief Get whether the required access information is available. This might
   * be login information like username and password, or a path to a sql
   * database for example.
   * @return true if available
   */
  virtual bool isRequiredDataAccessInformationAvailable() = 0;

  /**
   * @brief Get whether the object is currently connected to the data sources.
   * @return true if currently connected
   */
  virtual bool isConnectedToDataSources() = 0;
};
}  // namespace tdmon

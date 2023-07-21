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

#include <TDMon/core.h>
#include <TDMon/main_menu.h>
#include <TDMon/observe_menu.h>
#include <TDMon/technical_debt_dataset_connectable_default_td_mon_factory.h>
#include <TDMon/technical_debt_dataset_setup_menu.h>
#include <TDMon/default_td_mon_cache.h>

/**
 * @brief The program entry point. This function cannot be placed into the tdmon
 * namespace.
 * @return The program exit code. Always 0 in this application.
 */
int main() {
  // using 'typename' is important here for type deduction
  tdmon::Core<
      typename tdmon::TechnicalDebtDatasetConnectableDefaultTdMonFactory,
      typename tdmon::DefaultTdMonCache,
      typename tdmon::MainMenu,
      typename tdmon::TechnicalDebtDatasetSetupMenu<
          typename tdmon::TechnicalDebtDatasetConnectableDefaultTdMonFactory>,
      typename tdmon::ObserveMenu>
      core;
  core.run();

  return 0;
}

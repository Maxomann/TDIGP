#include <TDMon/core.h>
#include <TDMon/main_menu.h>
#include <TDMon/observe_menu.h>
#include <TDMon/technical_debt_dataset_connectable_default_td_mon_factory.h>
#include <TDMon/technical_debt_dataset_setup_menu.h>

/**
 * @brief The program entry point. This function cannot be placed into the tdmon
 * namespace.
 * @return The program exit code. Always 0 in this application.
 */
int main() {
  // using 'typename' is important here for type deduction
  tdmon::Core<
      typename tdmon::TechnicalDebtDatasetConnectableDefaultTdMonFactory,
      typename tdmon::MainMenu,
      typename tdmon::TechnicalDebtDatasetSetupMenu<
          typename tdmon::TechnicalDebtDatasetConnectableDefaultTdMonFactory>,
      typename tdmon::ObserveMenu>
      core;
  core.run();

  return 0;
}

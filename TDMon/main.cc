#include <TDMon/core.h>
#include <TDMon/main_menu.h>
#include <TDMon/setup_menu.h>
#include <TDMon/observe_menu.h>

/**
 * @brief The program entry point. This function cannot be placed into the tdmon
 * namespace.
 * @return The program exit code. Always 0 in this application.
 */
int main() {
  // using 'typename' is important here for type deduction
  tdmon::Core<typename tdmon::MainMenu, typename tdmon::SetupMenu, typename tdmon::ObserveMenu> core;
  core.run();

  return 0;
}

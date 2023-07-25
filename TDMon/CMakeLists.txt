add_executable(TDMon "core.h"  "td_mon.h" "td_mon.cc" "connectable_to_data_sources.h" "technical_debt_dataset_access_information_container.h" "td_mon_factory.h" "default_td_mon.h" "default_td_mon.cc"  "application_state.h" "main_menu.h" "main_menu.cc" "technical_debt_dataset_setup_menu.h" "constants.h" "constants.cc" "main.cc" "observe_menu.h" "observe_menu.cc" "technical_debt_dataset_connectable_default_td_mon_factory.h" "technical_debt_dataset_connectable_default_td_mon_factory.cc" "td_mon_cache.h" "default_td_mon_cache.h" "default_td_mon_cache.cc")

target_link_libraries(TDMon PRIVATE
sfml-graphics sfml-window sfml-network sfml-audio
tgui
nlohmann_json::nlohmann_json
SQLiteCpp
)

# remove the old data dir before copying the new one
add_custom_command(
	TARGET TDMon PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E remove_directory "$<TARGET_FILE_DIR:TDMon>/data"
)

# copy the data dir to the output directory in PRE_BUILD step
add_custom_command(
	TARGET TDMon PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	"${CMAKE_SOURCE_DIR}/data/" "$<TARGET_FILE_DIR:TDMon>/data"
)


# ---------------- UNIT TESTS ----------------

enable_testing()
include(GoogleTest)

add_executable(
  TDMonTests
  "default_td_mon.test.cc"
)

target_link_libraries(
  TDMonTests
  GTest::gtest_main
)

gtest_discover_tests(TDMonTests)

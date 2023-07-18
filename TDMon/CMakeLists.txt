add_executable(TDMon "core.h" "td_item.h" "td_mon.h" "connectable_to_data_sources.h" "technical_debt_dataset_access_information_container.h" "td_mon_factory.h" "default_td_mon.h" "default_td_mon.cc" "dummy_default_td_mon_factory.h" "application_state.h" "main_menu.h" "main_menu.cc" "technical_debt_dataset_setup_menu.h" "technical_debt_dataset_setup_menu.cc" "constants.h" "constants.cc" "main.cc" "observe_menu.h" "observe_menu.cc" "technical_debt_dataset_connectable_default_td_mon_factory.h" "technical_debt_dataset_connectable_default_td_mon_factory.cc")

target_link_libraries(TDMon PRIVATE
sfml-graphics sfml-window sfml-network sfml-audio
tgui
nlohmann_json::nlohmann_json
)

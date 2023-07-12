add_executable(TDMon "core.h" "core.cc" "td_item.h" "td_mon.h" "connectable_to_data_sources.h" "connectable_to_technical_debt_dataset_databse.h" "td_mon_factory.h" "default_td_mon.h" "default_td_mon.cc")

target_link_libraries(TDMon PRIVATE
sfml-graphics sfml-window sfml-network sfml-audio
tgui
nlohmann_json::nlohmann_json
)

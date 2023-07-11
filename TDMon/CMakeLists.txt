add_executable(TDMon core.h core.cc "td_item.h" "td_mon.h")

target_link_libraries(TDMon PRIVATE
sfml-graphics sfml-window sfml-network sfml-audio
tgui
nlohmann_json::nlohmann_json
)

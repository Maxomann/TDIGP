add_executable(TDMon core.h core.cpp   "ITDItem.h")

target_link_libraries(TDMon PRIVATE
sfml-graphics sfml-window sfml-network sfml-audio
tgui
nlohmann_json::nlohmann_json
)

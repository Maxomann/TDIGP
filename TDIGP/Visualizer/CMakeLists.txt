add_executable(TDIGPVisualizer main.cpp)

target_link_libraries(TDIGPVisualizer PRIVATE
	TDIGPCore
	sfml-graphics sfml-window sfml-network sfml-audio
	tgui
	nlohmann_json::nlohmann_json
)

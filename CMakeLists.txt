cmake_minimum_required(VERSION 3.15)
project(TDMon)
set(CMAKE_CXX_STANDARD 20)


find_package(SFML 2 COMPONENTS system window graphics network CONFIG REQUIRED)
find_package(TGUI CONFIG REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(Lua REQUIRED)
find_package(sol2 CONFIG REQUIRED)

add_subdirectory(TDMon)

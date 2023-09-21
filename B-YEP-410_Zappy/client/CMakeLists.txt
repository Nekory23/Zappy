cmake_minimum_required(VERSION 3.17)
project(ZAPPY_2021)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

include_directories(cmake_modules)

set(PATH_MODULE_Irrlicht "${CMAKE_MODULE_PATH}/IrrLicht")
set(Irrlicht_DIR "${CMAKE_MODULE_PATH}/Irrlicht")
include_directories(cmake_modules/Irrlicht)
include_directories(cmake_modules/Irrlicht/include)
find_package(Irrlicht REQUIRED)
link_libraries(${Irrlicht_LIBRARIES})

include_directories(include)
include_directories(include/Irrlicht)

add_executable(zappy_gui
    include/Client.hpp
    include/Graph.hpp
    include/IScreen.hpp
    include/Screen.hpp
    src/Main.cpp
    src/EventReciever.cpp
    src/Core.cpp
    src/Game.cpp
    src/Menu.cpp
    src/Graph.cpp
)

target_link_libraries(zappy_gui ${Irrlicht_LIBRARIES})

target_compile_options(zappy_gui PRIVATE -g3)

get_target_property(ZAPPY_EXE_PATH zappy_gui CMAKE_RUNTIME_OUTPUT_DIRECTORY)
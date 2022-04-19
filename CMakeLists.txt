cmake_minimum_required(VERSION 3.21)
project(qt_test2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/danila/Qt/6.2.4/macos/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(qt_test2 main.cpp StudentCalculator.cpp StudentCalculator.h Database.cpp Database.h Student.cpp
        Student.h)

target_link_libraries(qt_test2
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        )


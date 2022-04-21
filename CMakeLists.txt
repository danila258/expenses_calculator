cmake_minimum_required(VERSION 3.21)
project(student-calculator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(
        Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(student-calculator main.cpp UI.cpp StudentCalculator.h StudentsDatabase.cpp StudentsDatabase.h Student.h
        Slots.cpp CalculatorFunctions.cpp FileEditTable.cpp FileEditTable.h)

target_link_libraries(
        student-calculator
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets)
cmake_minimum_required(VERSION 3.16)

project(
        colorsource
        DESCRIPTION "Widget for sending colors"
        HOMEPAGE_URL "kszk.bme.hu"
        LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(
        Qt6
        COMPONENTS Widgets
        REQUIRED)

add_executable(${PROJECT_NAME} WIN32 src/colorsender.cpp src/colorsender.h
        src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets
        muebtransmitter)

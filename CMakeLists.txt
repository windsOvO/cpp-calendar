cmake_minimum_required(VERSION 3.16)
project(cpp_project)

# resource file use qmake to compile
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_project main.cpp timeclass/date.cpp timeclass/date.h timeclass/myTime.cpp timeclass/myTime.h gui/MainWindow.cpp gui/MainWindow.h gui/DigitalTime.cpp gui/DigitalTime.h)

# qt configuration
set (CMAKE_PREFIX_PATH "/usr/local/Cellar/qt/5.14.1/lib/cmake")

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

target_link_libraries(cpp_project Qt5::Widgets)


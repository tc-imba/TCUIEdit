cmake_minimum_required(VERSION 3.6)
project(TCUIEdit)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#打开Qt的MOC功能和UI文件处理功能
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(STATUS "current platform: Linux ")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "current platform: Windows")
    set(CMAKE_PREFIX_PATH "D:\\Qt\\Qt5.7.0\\5.7\\mingw53_32")
ELSE ()
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

#find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
#find_package(Qt5Gui REQUIRED)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -mwindows)

add_subdirectory(core bin)

set(SOURCE_FILES main.cpp mainwindow.cpp)
add_executable(TCUIEdit ${SOURCE_FILES})

# qt5_use_modules(TCUIEdit Core Widgets Gui)
target_link_libraries(TCUIEdit Qt5::Widgets core)

cmake_minimum_required(VERSION 3.6)
project(TCUIEdit)

include(CMakeConfig.txt)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Open moc and uic support of CMake
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

MESSAGE(STATUS "***************************************************")
MESSAGE(STATUS "* CMakeFile by tc-imba")
MESSAGE(STATUS "* Last Updated: 2016-12-26")
MESSAGE(STATUS "* Compilation Mode: " ${CMAKE_BUILD_TYPE})
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(STATUS "* Current Platform: Linux")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "* Current Platform: Windows")
    # Disable the console on Windows
    IF (NOT (CMAKE_BUILD_TYPE STREQUAL Debug))
        MESSAGE(STATUS "* Console is disabled Under " ${CMAKE_BUILD_TYPE} " Mode on Windows")
        set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -mwindows)
    ENDIF ()
ELSE ()
    MESSAGE(STATUS "* Current Platform: ${CMAKE_SYSTEM_NAME}")
    MESSAGE(STATUS "* Warning: Platform unsupported")
ENDIF ()
MESSAGE(STATUS "***************************************************")


#find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
#find_package(Qt5Gui REQUIRED)

add_subdirectory(src/core core)
add_subdirectory(src/components)
add_subdirectory(src/view view)


add_dependencies(property_browser core)
add_dependencies(view property_browser core)

set(SOURCE_FILES src/main.cpp src/view/mainwindow.cpp)
add_executable(TCUIEdit ${SOURCE_FILES})

# qt5_use_modules(TCUIEdit Core Widgets Gui)
target_link_libraries(TCUIEdit Qt5::Widgets view core property_browser)


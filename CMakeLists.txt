cmake_minimum_required(VERSION 3.6)
project(TCUIEdit)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Open moc and uic support of CMake
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(STATUS "+-------------------------+")
    MESSAGE(STATUS "| Current Platform: Linux |")
    MESSAGE(STATUS "+-------------------------+")
    # Set it to the Qt path
    set(CMAKE_PREFIX_PATH "/opt/Qt5.7.0/5.7/gcc_64")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "+---------------------------+")
    MESSAGE(STATUS "| Current Platform: Windows |")
    MESSAGE(STATUS "+---------------------------+")
    # Set it to the Qt path
    set(CMAKE_PREFIX_PATH "D:\\Qt\\Qt5.7.0\\5.7\\mingw53_32")
    # Disable the console on Windows
    IF (NOT (CMAKE_BUILD_TYPE STREQUAL Debug))
        MESSAGE(STATUS "Console is disabled Under " ${CMAKE_BUILD_TYPE} " Mode")
        set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -mwindows)
    ENDIF ()
ELSE ()
    MESSAGE(STATUS "+------------------------------+")
    MESSAGE(STATUS "| Current Platform unsupported |")
    MESSAGE(STATUS "+------------------------------+")
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF ()

#find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
#find_package(Qt5Gui REQUIRED)

add_subdirectory(core)
add_subdirectory(view)

set(SOURCE_FILES main.cpp mainwindow.cpp)
add_executable(TCUIEdit ${SOURCE_FILES})

# qt5_use_modules(TCUIEdit Core Widgets Gui)
target_link_libraries(TCUIEdit Qt5::Widgets core view)

cmake_minimum_required(VERSION 3.6)
project(TCUIEdit)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#打开Qt的MOC功能和UI文件处理功能
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)


set(CMAKE_PREFIX_PATH "D:\\Qt\\Qt5.7.0\\5.7\\mingw53_32")
#find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
#find_package(Qt5Gui REQUIRED)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -mwindows)

set(SOURCE_FILES main.cpp mainwindow.cpp core/UIProject.cpp core/UIMap.cpp core/UIPackage.cpp core/UIException.cpp core/UIBase.cpp)
add_executable(TCUIEdit ${SOURCE_FILES})

# qt5_use_modules(TCUIEdit Core Widgets Gui)
target_link_libraries(TCUIEdit Qt5::Widgets)

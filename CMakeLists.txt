cmake_minimum_required(VERSION 3.5)

project(Coookies VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    src/main.cpp
    gui/mainwindow.cpp
    gui/mainwindow.h
    gui/sqwindow.h
    gui/SquaredScene.h
    src/squaredhero.h
    src/squaredhero.cpp
    gui/SquaredScene.cpp
    gui/SqWindow.cpp
    gui/ui_sqwindow.h
    gui/ui_sqwindow_1.h
    gui/ui_mainwindow.h
    gui/settingwindow.h
    gui/settingwindow.cpp
    src/programmsettings.cpp
    src/programmsettings.h
    gui/ui_settingwindow.h
    gui/mainwindow.ui
    gui/sqwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Coookies
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET CookiesV3 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Coookies SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Coookies
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Coookies PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Coookies PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Coookies
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Coookies)
endif()

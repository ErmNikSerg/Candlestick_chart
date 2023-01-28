cmake_minimum_required(VERSION 3.5)

project(Stock_Exchange VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Charts)

set(PROJECT_SOURCES
        src/main.cpp
        src/mainwindow.h            src/mainwindow.cpp
        src/stock_quotes_chart.h    src/stock_quotes_chart.cpp
        src/main_dialog.h           src/main_dialog.cpp
        src/datareader.h            src/datareader.cpp
        src/dateandtime_dialog.h    src/dateandtime_dialog.cpp
        src/fileverification.h      src/fileverification.cpp
        src/plottingchart_dialog.h  src/plottingchart_dialog.cpp
        src/analisys_dialog.h       src/analisys_dialog.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Stock_Exchange
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Stock_Exchange APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Stock_Exchange SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Stock_Exchange
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Stock_Exchange PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Stock_Exchange PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(Stock_Exchange PRIVATE Qt${QT_VERSION_MAJOR}::Charts)

set_target_properties(Stock_Exchange PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Stock_Exchange
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Stock_Exchange)
endif()

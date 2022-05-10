cmake_minimum_required(VERSION 3.14)

project(avdan-os-file-manager VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick Svg Xml Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick Svg Xml Gui Widgets)

set(PROJECT_SOURCES
        main.cpp
        qml.qrc
		backendclass.h
		backendclass.cpp
		favouritelistmodel.h
		favouritelistmodel.cpp
		favouritelist.h
		favouritelist.cpp
		disklist.cpp
		disklist.h
		disklistmodel.cpp
		disklistmodel.h
		pinned.cpp
		pinned.h
		pinnedmodel.cpp
		pinnedmodel.h
		recents.h
		recents.cpp
		recentsmodel.cpp
		recentsmodel.h
		tagged.cpp
		tagged.h
		taggedmodel.cpp
		taggedmodel.h
	)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
	qt_add_executable(avdan-os-file-manager
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET aos-file-manager-newui APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(aos-file-manager-newui SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(aos-file-manager-newui
          ${PROJECT_SOURCES}
        )
    endif()
endif()

target_compile_definitions(aos-file-manager-newui
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(aos-file-manager-newui
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)

set_target_properties(aos-file-manager-newui PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(aos-file-manager-newui)
    qt_finalize_executable(aos-file-manager-newui)
endif()

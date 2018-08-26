cmake_minimum_required(VERSION 3.10)
project(timerApplication)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CURRENT_DIR ON)

set(SOURCES
        main.cpp
        mainwindow.cpp
        Time.cpp
        Date.cpp
        )

set(HEADERS
        mainwindow.h
        Observer.h
        Time.h Date.h)

set(PROJECT_UI
        mainwindow.ui)


qt5_wrap_ui(project_headers_wrapped ${PROJECT_UI})
qt5_wrap_cpp(project_sources_moc ${HEADERS})

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES}
        ${project_sources_moc} ${project_headers_wrapped})

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets)





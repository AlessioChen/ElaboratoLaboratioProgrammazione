cmake_minimum_required(VERSION 3.10)
project(timerApplication)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CURRENT_DIR ON)

set(QT5 NEED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)


set(SOURCES
        main.cpp
        mainwindow.cpp
        Time.cpp
        Date.cpp
        Counter.cpp
        MyClock.cpp
        TimerDisplay.cpp
        )

set(HEADERS
        mainwindow.h
        Observer.h
        Time.h
        Date.h
        Counter.h
        MyClock.h
        TimerDisplay.h)

set(PROJECT_UI
        mainwindow.ui)


qt5_wrap_ui(project_headers_wrapped ${PROJECT_UI})
qt5_wrap_cpp(project_sources_moc ${HEADERS})

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES}
        ${project_sources_moc} ${project_headers_wrapped})

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)







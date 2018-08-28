cmake_minimum_required(VERSION 3.10)
project(timerApplication)

set(CMAKE_AUTOMOC ON)                   #crea i file _moc ogni volta che incontra la macro Q_OBJECT
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)                   #aggiunge il file ui per la creazione della finestra interattiva
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(SOURCES
        main.cpp
        mainwindow.cpp
        Time.cpp
        Date.cpp
        Counter.cpp
        MyClock.cpp
        TimerDisplay.cpp
        mainwindow.h
        Observer.h
        Time.h
        Date.h
        Counter.h
        MyClock.h
        TimerDisplay.h
        mainwindow.ui
        )

add_executable(${PROJECT_NAME} ${SOURCES})


set(QT5 NEED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)


target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)







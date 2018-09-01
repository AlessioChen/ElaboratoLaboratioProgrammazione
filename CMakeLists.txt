cmake_minimum_required(VERSION 3.10)
project(timerApplication)

set(CMAKE_AUTOMOC ON)                   #crea i file _moc ogni volta che incontra la macro Q_OBJECT
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)                   #aggiunge il file ui per la creazione della finestra interattiva
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

enable_testing()
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
        mainwindow.ui)

set(TEST_CLASSES
        Test/TimeTest.cpp
        Test/TimeTest.h
        Test/TimeTest_main.cpp
        Time.h
        Time.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
add_executable(Test_time ${TEST_CLASSES})


set(QT5 NEED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Test REQUIRED)


target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} Qt5::Test)

target_link_libraries(Test_time Qt5::Core)
target_link_libraries(Test_time Qt5::Test)











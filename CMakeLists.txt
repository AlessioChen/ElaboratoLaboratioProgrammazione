cmake_minimum_required(VERSION 3.10)
project(timerApplication)

set(CMAKE_AUTOMOC ON)                   #crea i file _moc ogni volta che incontra la macro Q_OBJECT
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)                   #aggiunge il file ui per la creazione della finestra interattiva
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

enable_testing()
set(SOURCES

        Time.cpp
        Date.cpp
        Counter.cpp
        MyClock.cpp
        TimerDisplay.cpp
        Observer.h
        Time.h
        Date.h
        Counter.h
        MyClock.h
        TimerDisplay.h
        )

set(TEST_TIME
        Test/TimeTest.cpp
        Test/TimeTest.h
        Test/TimeTest_main.cpp
        ${SOURCES})

set(TEST_DATE
        Test/DateTest.cpp
        Test/DateTest.cpp
        Test/DateTest_main.cpp
        ${SOURCES})
set(TEST_DISPLAY
        Test/DisplayTest.h
        Test/DisplayTest.cpp
        Test/DisplayTest_main.cpp
        ${SOURCES})


add_executable(${PROJECT_NAME} ${SOURCES} main.cpp mainwindow.cpp mainwindow.h mainwindow.ui)
add_executable(Test_time ${TEST_TIME})
add_executable(Test_date ${TEST_DATE})
add_executable(Test_display ${TEST_DISPLAY})

set(QT5 NEED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Test REQUIRED)


target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Test)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

target_link_libraries(Test_time Qt5::Core)
target_link_libraries(Test_time Qt5::Widgets)
target_link_libraries(Test_time Qt5::Test)


target_link_libraries(Test_date Qt5::Core)
target_link_libraries(Test_date Qt5::Widgets)
target_link_libraries(Test_date Qt5::Test)

target_link_libraries(Test_display Qt5::Core)
target_link_libraries(Test_display Qt5::Test)
target_link_libraries(Test_display Qt5::Gui)
target_link_libraries(Test_display Qt5::Widgets)







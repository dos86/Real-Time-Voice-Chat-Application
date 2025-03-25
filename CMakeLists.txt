cmake_minimum_required(VERSION 3.10)
project(VoiceChatApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Multimedia Network)

add_executable(VoiceChatApp
    src/AudioCapture.cpp
    src/AudioPlayback.cpp
    src/Client.cpp
    src/Server.cpp
    src/MainWindow.cpp
    main.cpp
)

target_link_libraries(VoiceChatApp
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Multimedia
    Qt5::Network
)

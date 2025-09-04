cmake_minimum_required(VERSION 3.30)
project(3DViewer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets OpenGLWidgets)
find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME}
  src/main.cc
  src/mainwindow.cc
  include/mainwindow.h
)

target_link_libraries(${PROJECT_NAME}
  Qt6::Core
  Qt6::Widgets
  Qt6::OpenGLWidgets
  OpenGL::GL
)

target_include_directories(${PROJECT_NAME}
  PRIVATE include
)

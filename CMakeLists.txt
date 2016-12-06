cmake_minimum_required(VERSION 3.6)
project(veri_yapilari_ucuncu_odev)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
set(SOURCE_FILES src/main.cpp src/kuyruk.cpp include/kuyruk.h)
add_executable(veri_yapilari_ucuncu_odev ${SOURCE_FILES})
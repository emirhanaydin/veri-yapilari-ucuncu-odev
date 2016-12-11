cmake_minimum_required(VERSION 3.6)
project(veri_yapilari_ucuncu_odev)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
set(SOURCE_FILES src/main.cpp src/kuyruk.cpp include/kuyruk.h src/dosya.cpp include/dosya.h src/dugum.cpp include/dugum.h src/ikiliAramaAgaci.cpp include/ikiliAramaAgaci.h include/hata.h)
add_executable(veri_yapilari_ucuncu_odev ${SOURCE_FILES})
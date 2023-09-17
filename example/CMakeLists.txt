cmake_minimum_required(VERSION 3.10)

project(TimerExample
    VERSION 1.0.0 
    LANGUAGES CXX
    DESCRIPTION "Timer example that uses timer defined in library." 
    HOMEPAGE_URL "git."
)

# Isimlendirme
set(APP_NAME example)

# Kaynak ve oluþturma dizinlerini otomatik olarak baslik dosyasi dizinine ekler
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Windows icin bir kac ek tanimlama
if(WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()    

# Uygulama olarak bu projeyi ekliyoruz
add_executable(${APP_NAME} main.cpp)

# Kutuphaneleri baglayalim
target_link_libraries(${APP_NAME} PRIVATE timers spdlog::spdlog_header_only)

target_include_directories(${APP_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)
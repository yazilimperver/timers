cmake_minimum_required(VERSION 3.10)

add_subdirectory(ext/spdlog-1.x)
add_subdirectory(example)

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/ext/spdlog-1.x/build)

project(Timers 
    VERSION 1.0.0 
    LANGUAGES CXX
    DESCRIPTION "Simple collection of timers developed in modern C++." 
    HOMEPAGE_URL "git."
)


find_package(spdlog REQUIRED)

# Isimlendirme
set(LIB_NAME timers)

# Baslik dosyalari
set(HEADER_FILES
	chrono_util.h
	fps_timer.h
	sleep_util.h
	stop_watch.h
    stoppable_timer.h
	timestamp.h
    threaded_timer.h
)

# Baslik dosya grubu (VS altindaki filtre gibi)
source_group("Header Files" FILES ${HEADER_FILES})

# Kaynak kod dosyalari
set(SOURCE_FILES
    fps_timer.cpp
	sleep_util.cpp
    stop_watch.cpp
    timestamp.cpp
    stoppable_timer.cpp
    threaded_timer.cpp
 )

# Kaynak dosya grubu (VS altindaki filtre gibi)
source_group("Source Files" FILES ${SOURCE_FILES})

# Kaynak ve oluþturma dizinlerini otomatik olarak baslik dosyasi dizinine ekler
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Windows icin bir kac ek tanimlama
if(WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()    

# Statik kutuphane olarak bu projeyi ekliyoruz
add_library(${LIB_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES})

# Kutuphaneleri baglayalim
target_link_libraries(${LIB_NAME} PRIVATE spdlog::spdlog_header_only)

# Baslik dosyalarinin yolunu ekleyelim
target_include_directories(${LIB_NAME} PRIVATE .)
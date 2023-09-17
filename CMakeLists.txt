cmake_minimum_required(VERSION 3.25)

include(source_code/Libraries/pico_sdk_import.cmake)
project(Morse)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

pico_sdk_init()

add_executable(
        Morse source_code/main.cpp
        source_code/Translate/Translate.h
        source_code/Translate/Translate.cpp
        source_code/Config/config.h
        source_code/Sound/Sound.h
        source_code/Sound/Sound.cpp
        config.cpp
)
pico_enable_stdio_usb(Morse 1)
pico_enable_stdio_uart(Morse 0)
pico_add_extra_outputs(Morse)
target_link_libraries(Morse pico_stdlib)
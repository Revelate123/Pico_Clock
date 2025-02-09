cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(my_project)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project

# add a compilation subdirectory
add_subdirectory(lib/Config)
add_subdirectory(lib/e-Paper)
add_subdirectory(lib/Fonts)
add_subdirectory(lib/GUI)


# add a header directory
include_directories(examples)
include_directories(./lib/Config)
include_directories(./lib/GUI)
include_directories(./lib/e-Paper)

add_executable(clock main.c)

# enable usb output, disable uart output
pico_enable_stdio_usb(clock 1)
pico_enable_stdio_uart(clock 0)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(clock)

pico_add_extra_outputs(clock)

target_link_libraries(clock pico_stdlib ePaper GUI Fonts Config hardware_spi)



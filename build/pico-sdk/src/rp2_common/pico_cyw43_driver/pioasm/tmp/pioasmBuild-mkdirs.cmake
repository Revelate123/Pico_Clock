# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/thomas/Documents/Structural/pico/pico-sdk/tools/pioasm"
  "/home/thomas/Documents/Structural/pico/blinker/build/pioasm"
  "/home/thomas/Documents/Structural/pico/blinker/build/pioasm-install"
  "/home/thomas/Documents/Structural/pico/blinker/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/tmp"
  "/home/thomas/Documents/Structural/pico/blinker/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/pioasmBuild-stamp"
  "/home/thomas/Documents/Structural/pico/blinker/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src"
  "/home/thomas/Documents/Structural/pico/blinker/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/pioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/thomas/Documents/Structural/pico/blinker/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/pioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/thomas/Documents/Structural/pico/blinker/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/pioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()

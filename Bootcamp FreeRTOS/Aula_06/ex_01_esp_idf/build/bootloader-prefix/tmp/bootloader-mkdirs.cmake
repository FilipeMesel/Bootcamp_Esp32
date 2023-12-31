# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/esp/esp-idf/components/bootloader/subproject"
  "C:/xampp/htdocs/Bootcamp_Esp32/Bootcamp FreeRTOS/Aula_06/ex_01_esp_idf/build/bootloader"
  "C:/xampp/htdocs/Bootcamp_Esp32/Bootcamp FreeRTOS/Aula_06/ex_01_esp_idf/build/bootloader-prefix"
  "C:/xampp/htdocs/Bootcamp_Esp32/Bootcamp FreeRTOS/Aula_06/ex_01_esp_idf/build/bootloader-prefix/tmp"
  "C:/xampp/htdocs/Bootcamp_Esp32/Bootcamp FreeRTOS/Aula_06/ex_01_esp_idf/build/bootloader-prefix/src/bootloader-stamp"
  "C:/xampp/htdocs/Bootcamp_Esp32/Bootcamp FreeRTOS/Aula_06/ex_01_esp_idf/build/bootloader-prefix/src"
  "C:/xampp/htdocs/Bootcamp_Esp32/Bootcamp FreeRTOS/Aula_06/ex_01_esp_idf/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/xampp/htdocs/Bootcamp_Esp32/Bootcamp FreeRTOS/Aula_06/ex_01_esp_idf/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/xampp/htdocs/Bootcamp_Esp32/Bootcamp FreeRTOS/Aula_06/ex_01_esp_idf/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()

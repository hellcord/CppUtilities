cmake_minimum_required (VERSION 3.8)

project ("CppUtilities")

include(Cmake/CompileOptions.cmake)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

add_subdirectory(External)

cmake_minimum_required (VERSION 3.8)

project ("cpp_utilities")

if(NOT DEFINED BUILD_CPP_UTILITIES_UNIT_TESTS)
	set(BUILD_CPP_UTILITIES_UNIT_TESTS true)
endif()

if(NOT DEFINED BUILD_CPP_UTILITIES_DYNAMIC)
	set(BUILD_CPP_UTILITIES_DYNAMIC false)
endif()

if(NOT DEFINED BUILD_CPP_UTILITIES_ENGINE)
	set(BUILD_CPP_UTILITIES_ENGINE true)
endif()

include(cmake/compile_options.cmake)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

add_subdirectory(external)

add_subdirectory(cpp_utilities)

if(${BUILD_CPP_UTILITIES_UNIT_TESTS})
	add_subdirectory(unit_tests)
endif()

if(${BUILD_CPP_UTILITIES_ENGINE})
	add_subdirectory(engine)
endif()
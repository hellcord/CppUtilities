
file (GLOB CPP_UTILITIES_INCLUDES include/*.hpp include/*.h)
file (GLOB CPP_UTILITIES_SRC src/*.cpp)

if(${BUILD_CPP_UTILITIES_DYNAMIC})
	add_library(cpp_utilities SHARED ${CPP_UTILITIES_INCLUDES} ${CPP_UTILITIES_SRC})
else()
	add_library(cpp_utilities STATIC ${CPP_UTILITIES_INCLUDES} ${CPP_UTILITIES_SRC})
endif()

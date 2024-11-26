
file (GLOB ENGINE_INCLUDES src/*.hpp src/*.h)
file (GLOB ENGINE_SOURCES src/*.cpp src/*.c)

if(WIN32)
	add_executable(engine WIN32 ${ENGINE_INCLUDES} ${ENGINE_SOURCES})
	target_link_libraries(engine PRIVATE "d3d12.lib" "dxgi.lib" "d3dcompiler.lib")
else()
	add_executable(engine ${ENGINE_INCLUDES} ${ENGINE_SOURCES})
endif()

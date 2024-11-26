#pragma once
#include <cstdint>

namespace engine
{

struct Window
{
	Window(const char* className, const char* windowName, void* hInstance);
	~Window();

	std::uint8_t m_data[8];
};

//-- returns true if exit is requested
bool updateWindow(Window& window);

} //-- engine

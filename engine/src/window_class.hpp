#pragma once
#include <cstdint>

namespace engine
{

struct alignas(8) WindowClass
{
	WindowClass(const char* className, void* hInstance);
	~WindowClass();

	uint8_t m_data[80] = {0};
};

} //-- engine

#pragma once
#include <cstdint>

#define ENGINE_TARGET_PLATFORM_WINDOWS 1
#define ENGINE_TARGET_PLATFORM_UNIX 2

#if defined(_MSC_VER)
	#define ENGINE_TARGET_PLATFORM ENGINE_TARGET_PLATFORM_WINDOWS
#elif defined(__unix__)
	#define ENGINE_TARGET_PLATFORM ENGINE_TARGET_PLATFORM_UNIX
#else
	#error Unknown Target Platform
#endif

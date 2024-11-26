#include "window.hpp"
#include "config.hpp"

#if ENGINE_TARGET_PLATFORM == ENGINE_TARGET_PLATFORM_WINDOWS
#define NOMINMAX

#include <Windows.h>
#endif

namespace engine
{

Window::Window(const char* className, const char* windowName, void* hInstance)
{
#if ENGINE_TARGET_PLATFORM == ENGINE_TARGET_PLATFORM_WINDOWS

	*reinterpret_cast<HWND*>(m_data) = CreateWindowEx(WS_EX_APPWINDOW, className, windowName, WS_VISIBLE | WS_SYSMENU, 50, 50, 720, 480, nullptr, nullptr, reinterpret_cast<HINSTANCE>(hInstance), nullptr);

#endif
}

Window::~Window()
{
#if ENGINE_TARGET_PLATFORM == ENGINE_TARGET_PLATFORM_WINDOWS
	DestroyWindow(*reinterpret_cast<HWND*>(m_data));
#endif
}

bool updateWindow(Window& window)
{
#if ENGINE_TARGET_PLATFORM == ENGINE_TARGET_PLATFORM_WINDOWS

	bool exitRequested = false;

	HWND windowHandle = *reinterpret_cast<HWND*>(window.m_data);
	MSG message = {};
	while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
	{
		switch (message.message)
		{
		case WM_DESTROY:
		case WM_CLOSE:
		case WM_QUIT:
			exitRequested = true;
		}

		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return exitRequested;

#elif ENGINE_TARGET_PLATFORM == ENGINE_TARGET_PLATFORM_UNIX
	return true;
#endif
}

} //-- engine

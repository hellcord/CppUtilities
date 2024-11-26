#include "window_class.hpp"
#include "config.hpp"

#if ENGINE_TARGET_PLATFORM == ENGINE_TARGET_PLATFORM_WINDOWS
#define NOMINMAX

#include <Windows.h>
#endif

namespace engine
{
namespace
{

#if ENGINE_TARGET_PLATFORM == ENGINE_TARGET_PLATFORM_WINDOWS
LRESULT windowProc(
	HWND hWnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
#endif

} //-- unnamed

WindowClass::WindowClass(const char* className, void* hInstance)
{
#if ENGINE_TARGET_PLATFORM == ENGINE_TARGET_PLATFORM_WINDOWS

	static_assert(sizeof(m_data) >= sizeof(WNDCLASSEX), "Buffer is not big enough for window class");

	WNDCLASSEX* wndClass = reinterpret_cast<WNDCLASSEX*>(m_data);

	*wndClass = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW, windowProc, 0, 0, reinterpret_cast<HINSTANCE>(hInstance), nullptr, nullptr, nullptr, nullptr, className, nullptr };

	RegisterClassEx(wndClass);

#endif
}

WindowClass::~WindowClass()
{
#if ENGINE_TARGET_PLATFORM == ENGINE_TARGET_PLATFORM_WINDOWS

	WNDCLASSEX* wndClass = reinterpret_cast<WNDCLASSEX*>(m_data);
	UnregisterClass(wndClass->lpszClassName, wndClass->hInstance);

#endif
}

} //-- engine

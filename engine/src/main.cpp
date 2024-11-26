#include "config.hpp"
#include "window_class.hpp"
#include "window.hpp"

#include <iostream>

static constexpr const char* C_WINDOW_CLASS_NAME = "DefaultWindowClass";

#if ENGINE_TARGET_PLATFORM == ENGINE_TARGET_PLATFORM_WINDOWS

#define NOMINMAX
#include <Windows.h>

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
#else
int main(int argc, char* argv[])
#endif
{
	engine::WindowClass wndClass(C_WINDOW_CLASS_NAME, nullptr);

	engine::Window window(C_WINDOW_CLASS_NAME, "Window", nullptr);

	while (!engine::updateWindow(window))
	{
	}
}

#pragma once

#include <SFML/Graphics.hpp>
#include <core/event.hpp>

namespace pe {

	typedef struct __WindowSettings {
	public:
		int width;
		int height;
		bool fullscreen;
		bool vsync;
	} WindowSettings;

	WindowSettings defaultWindowConfig();
	//void getWindowSize(int* width, int* height);

	class Window {
	public:
		Window(WindowSettings config);
        void addEventHandler(EventHandler *eventHandler);

        static sf::RenderWindow* render;
	};
	
}
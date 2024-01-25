#include <core/window.hpp>
#include <core/assets.hpp>
#include <core/clock.hpp>
#include <core/scene.hpp>

pe::WindowSettings pe::defaultWindowConfig() {
	pe::WindowSettings config;
	config.width = 800;
	config.height = 600;
	config.fullscreen = false;
	config.vsync = true;

	return config;
}

pe::Window::Window(WindowSettings config) {
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 3;
	settings.minorVersion = 3;

	int wndStyle = sf::Style::Default;
	if(config.fullscreen == true) {
		wndStyle = sf::Style::Fullscreen;
	}

	render = new sf::RenderWindow(sf::VideoMode(config.width, config.height), "Test window", wndStyle, settings);
	render->setVerticalSyncEnabled(config.vsync);

	render->setActive(true);
	AssetsManager::assets = new AssetsManager();
}

void pe::Window::addEventHandler(EventHandler *eventHandler) {
	while(render->isOpen()) {
		sf::Event event;
        while (render->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                render->close();
			else if(event.type == sf::Event::KeyReleased) {
				eventHandler->input(event.key.scancode);
			}
        }
		Clock::timeUpdate();

		render->clear(sf::Color(200, 200, 200));
		Scene::current->draw();
		eventHandler->tick();
		render->display();
	}
}

sf::RenderWindow* pe::Window::render = nullptr;
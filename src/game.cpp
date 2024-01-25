#include <core/window.hpp>
#include <core/event.hpp>
#include <core/assets.hpp>
#include <core/clock.hpp>
#include <core/input.hpp>
#include <core/scene.hpp>
#include <render/sprite.hpp>
#include <render/texture.hpp>
#include <components/components.hpp>

#include <iostream>

pe::Window *window;

class PlayerMovement : public Component {
	float m_speedPlayer;
public:
	PlayerMovement() {
		m_speedPlayer = 100.0f;
	}

	void update() override {
		if(Input::isKeyPressed(22)) {
			gameObject->position.y -= m_speedPlayer * Clock::deltaTime();
		}
		if(Input::isKeyPressed(18)) {
			gameObject->position.y += m_speedPlayer * Clock::deltaTime();
		}
		if(Input::isKeyPressed(0)) {
			gameObject->position.x -= m_speedPlayer * Clock::deltaTime();
		}
		if(Input::isKeyPressed(3)) {
			gameObject->position.x += m_speedPlayer * Clock::deltaTime();
		}
	}
};

class Game : public EventHandler {
public:
	Game() {
		Texture::TextureConfig config_texture = Texture::defaultTextureConfig();
		config_texture.texturePath = "assets/test.jpg";
		Texture *texture = new Texture(config_texture);

		AssetsManager::assets->LoadTexture("test", texture);

		Sprite::SpriteConfig config = Sprite::defaultSpriteConfig();
		config.texture = AssetsManager::assets->GetTexture("test");

		Sprite *sprite = new Sprite(config);
		sprite->addComponent<PlayerMovement>();
		
		Scene *test = new Scene();
		test->addChild(sprite);
	}

	void tick() override {
	}
};

int main()
{
	pe::WindowSettings config = pe::defaultWindowConfig();
	window = new pe::Window(config);
	
	Game *game = new Game();
	window->addEventHandler(game);

	return EXIT_SUCCESS;
}

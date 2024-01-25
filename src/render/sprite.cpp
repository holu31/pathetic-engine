#include <render/sprite.hpp>
#include <core/window.hpp>

Sprite::SpriteConfig Sprite::defaultSpriteConfig() {
	Sprite::SpriteConfig config;
	Texture::TextureConfig configTexture = Texture::defaultTextureConfig();
	config.texture = new Texture(configTexture);

	return config;
}

Sprite::Sprite(SpriteConfig config) {
	this->rSprite = new sf::Sprite();
	this->config = config;

	this->r_layer = 0;

	rSprite->setTexture(config.texture->m_texture);
}

void Sprite::draw() {
	Node::draw();

	rSprite->setPosition(position.x, position.y);

	sf::Texture::bind(&config.texture->m_texture);
	pe::Window::render->draw(*rSprite);
	sf::Texture::bind(NULL);
}
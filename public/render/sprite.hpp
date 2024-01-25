#pragma once

#include <SFML/Graphics.hpp>
#include <core/node.hpp>
#include <render/texture.hpp>

#include <string>

class Sprite : public Node {
	sf::Sprite *rSprite;
public:
	typedef struct __SpriteConfig {
		Texture *texture;
	} SpriteConfig;
	static SpriteConfig defaultSpriteConfig();

	SpriteConfig config;
	
	Sprite(SpriteConfig config);
	void draw() override;
};
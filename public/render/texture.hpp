#pragma once

#include <SFML/Graphics.hpp>

#include <string>

class Texture {
public:
    sf::Texture m_texture;

    typedef struct __TextureConfig {
		std::string texturePath;
		bool smooth;
		bool repeated;
	} TextureConfig;
	static TextureConfig defaultTextureConfig();

    Texture(TextureConfig config);
};
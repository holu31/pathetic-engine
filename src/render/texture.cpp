#include <render/texture.hpp>

#include <iostream>

Texture::TextureConfig Texture::defaultTextureConfig() {
    Texture::TextureConfig config;
	config.smooth = true;
	config.repeated = false;
	config.texturePath = "";

	return config;
}

Texture::Texture(Texture::TextureConfig config) {
    if(!config.texturePath.empty())
        m_texture.loadFromFile(config.texturePath);

    m_texture.setSmooth(config.smooth);
	m_texture.setRepeated(config.repeated);
}
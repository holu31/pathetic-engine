#include <core/assets.hpp>

AssetsManager::AssetsManager() {
    AssetsManager::assets = this;
}

void AssetsManager::LoadTexture(std::string name, Texture *texture) {
    m_textures[name] = texture;
}

Texture *AssetsManager::GetTexture(std::string name) {
    return m_textures[name];
}

AssetsManager* AssetsManager::assets = nullptr;
#pragma once

#include <render/texture.hpp>

#include <map>
#include <string>

class AssetsManager {
    std::map<std::string, Texture*> m_textures;
public:
    AssetsManager();
    static AssetsManager *assets;

    void LoadTexture(std::string name, Texture *texture);
    Texture *GetTexture(std::string name);
};
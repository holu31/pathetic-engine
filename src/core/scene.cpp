#include <core/scene.hpp>
#include <render/sprite.hpp>

#include <iostream>

Scene::Scene() {
    if(Scene::current == nullptr)
        Scene::current = this;
}

void Scene::load() {
    Scene::current = this;
}

Layer *Scene::m_childrens(Node *object) {
    Layer *layers = new Layer[MAX_LAYER];

    for (auto child : object->children()) {
        if (child->r_layer > MAX_LAYER)
            layers[MAX_LAYER].nodes.push_back(child);
        else
            layers[child->r_layer].nodes.push_back(child);
        
        if(child->children().size() > 0) {
            Layer *tmpLayers = m_childrens(child);
            for(int i = 0; i < MAX_LAYER; i++) {
                for(int j = 0; j < tmpLayers[i].nodes.size(); j++)
                    layers[i].nodes.push_back(tmpLayers->nodes[j]);
            }
        }
    }
    return layers;
}

void Scene::draw() {
    Layer *layers = m_childrens(this);
    for(int i = 0; i < MAX_LAYER; i++) {
        for(int j = 0; j < layers[i].nodes.size(); j++)
            layers[i].nodes[j]->draw();
    }
}

Scene *Scene::current = nullptr;
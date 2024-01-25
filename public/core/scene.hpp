#pragma once

#include <core/node.hpp>

#define MAX_LAYER 32

struct Layer {
    std::vector<Node*> nodes;
};

class Scene : public Node {
    Layer *m_childrens(Node *object);
public:
    static Scene *current;
    Scene();

    void load();
    void draw() override;
};
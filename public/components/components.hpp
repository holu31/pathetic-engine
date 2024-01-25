#pragma once

class Node;

class Component {
public:
    Node *gameObject = nullptr;
    Component() {}
    
    virtual void update() {}
};
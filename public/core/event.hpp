#pragma once

class EventHandler {
public:
    EventHandler() {}
    
    virtual void tick() {}
    virtual void input(int key) {}
};
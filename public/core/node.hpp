#pragma once

#include <vector>
#include <math/vector2.hpp>
#include <components/components.hpp>

class Node {

	Node* m_parent = nullptr;
	std::vector<Node*> m_children{};
	std::vector<Component*> m_components{};

public:
	Node();
	virtual ~Node();

	Vector2 position;
	int r_layer;

	Node* parent() const;
	void reparent(Node*);

	std::vector<Node*> children() const;
	bool hasChild(Node*) const;

	void addChild(Node*);

	void removeChild(Node*);

	template<typename T>
	void addComponent() {
		T *component = new T();
		component->gameObject = this;
		m_components.push_back(component);
	}

	virtual void draw();
};
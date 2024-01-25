#include <core/node.hpp>

Node::Node() {}
Node::~Node() {}

Node* Node::parent() const {
	return m_parent;
}

void Node::reparent(Node* newParent) {
	if (m_parent)
		m_parent->m_children.erase(std::find(m_parent->m_children.begin(),
			m_parent->m_children.end(), this));

	m_parent = newParent;
	newParent->m_children.push_back(this);
}

std::vector<Node*> Node::children() const {
	return { m_children };
}

bool Node::hasChild(Node* child) const {
	return std::count(m_children.begin(), m_children.end(), child);
}

void Node::addChild(Node* child) {
	child->reparent(this);
}

void Node::removeChild(Node* child) {
	child->reparent(nullptr);
}

void Node::draw() {
	/*for (auto child : m_children)
		child->draw();*/

	for (auto component : m_components)
		component->update();
}
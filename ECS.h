#ifndef ECS_H
#define ECS_H
// Note: this header file contains a lot of code I'm not super familiar with,
// so I made notes on all the parts I didn't know as well for reference.


#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

// Forward declartion
class Component;
class Entity;

// Create ComponentID as an alias for size_t
using ComponentID = std::size_t;


// Return the next available ID
inline ComponentID getComponentTypeID() {
	// Declare the static memory, so it is initialized only once
	static ComponentID lastID = 0;
	// Add 1 to the previous ID value and return
	return lastID++;
}

// Get the ID for each individual type
template<typename T>
inline ComponentID getComponentID() noexcept {
	static ComponentID typeID = getComponentTypeID();
	return typeID;
}
// The idea is that the above is run exactly once for each type of component
// that an object can have. This generates a unique set of ID values for each
// component

// Max number of components possible in any object
constexpr std::size_t maxComponents = 32;
// Note: a constexpr is a value that gets evaluated at compile time and plugged
// in for the expression.

// Bitset that holds whether or not a specific component is active in an object
using ComponentBitSet = std::bitset<maxComponents>;
// Array of pointers to the specific components that a given object has
using ComponentArray = std::array<Component*, maxComponents>;

/*
Component Class

Each component is a different feature that the things in our game can have.
*/
class Component {
public:
	Entity* entity;

	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}
	virtual ~Component() {}
};

/*
Entity Class

An entity is made up of components and each component adds a feature to the 
entity. 
*/
class Entity {
private:
	bool active = true;
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;
public:
	void update() {
		// Python-like loop through vector specific to the STL
		// Reads as: for every c in components, do something, in this case, go to the
		// whatever c points to and call update
		for (auto& c : components) c->update();
		for (auto& c : components) c->draw();
	}
	void draw() {}

	// Check if active
	bool isActive() { return active; }
	// Set to inactive, i.e. flag for clean up
	void destroy() { active = false; }

	// Check if a particular component is attached to this entity
	template<typename T>
	bool hasComponent() const {
		return componentBitSet[getComponentID<T>]
	}

	// Add a component to the entity
	template<typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs) {
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity* this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));
	}


};
#endif
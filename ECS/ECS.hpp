#pragma once 

#include <vector>
#include <bitset>
#include <memory>
#include <algorithm>


class Component;
class Entity;

constexpr size_t max_components = 32;

using ComponentID = std::size_t;
using component_bitset = std::bitset<max_components>;
using component_array = std::array<Component*, max_components>;

inline ComponentID get_unique_id() noexcept{
	static ComponentID id{0u};
	return id++;
}

template <typename T> inline ComponentID get_component_id() noexcept{
	static ComponentID id{get_unique_id()};
	return id;
}

class Component{
public:
	Entity * entity;
	virtual void init(){};
	virtual void update(){};
	virtual void draw(){};
};

class Entity {
private:
	bool active = true;
	std::vector<std::unique_ptr<Component>> components;
	component_array componentArray;
	component_bitset componentBitset;

public:

	bool is_active() const { return active; };
	bool destroy() { active = false; };

	void update(){
		for (auto& c : components) c-> update();
	}

	void draw(){
		for (auto& c : components) c-> draw();
	}

	template <typename T> bool has_component() const { return componentBitset[get_component_id<T>()]; }

	template <typename T, typename ...TArgs> T& add_component(TArgs&&... mArgs){
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{c};
		components.emplace_back(std::move(uPtr));

		componentBitset[get_component_id<T>()] = true;
		componentArray[get_component_id<T>()] = c;

		c->init();

		return *c;
	}

	template <typename T> T& get_component() const{
		auto ptr = componentArray[get_component_id<T>()];
		return *static_cast<T*>(ptr); 
	}
};


class Manager{
private:
	std::vector<std::unique_ptr<Entity>> entities;
public:
	void update(){ for (auto& e : entities) e->update(); };
	void draw(){ for (auto& e : entities) e->draw(); };
	void refresh(){
		entities.erase(std::remove_if(std::begin(entities), std::end(entities), 
			[](const std::unique_ptr<Entity> & entity){
				return !entity->is_active();
			}), std::end(entities));
	}
	Entity& add_entity(){
		Entity* e = new Entity();
		std::unique_ptr<Entity> uPtr{e};
		entities.emplace_back(std::move(uPtr));
		return *e;
	}
};
#include "Entity.h"
#include "Map.h"
#include "Log.h"
#include "Game.h"
#include <string> 

void Entity::move(int x, int y) {
	if (x < 0 || y < 0 || x >= MAP_WIDTH || y >= MAP_HEIGHT)
		return;
	if (Map::get_cell(x, y) != EMPTY)
		return;

	MapCoord lastPos = Entity::pos;
	pos.x = x;
	pos.y = y;
	Map::place_at_cell(x, y, this->type);
	Map::place_at_cell(lastPos, EMPTY);
}

void Entity::move(const MapCoord& c) {
	//move(c.x, c.y);
	move(this->pos.x + c.x, this->pos.y + c.y);
}

bool Entity::is_player() {
	return this->type == PLAYER;
}

void Entity::eval_ai() {
	if (!this->isAiControlled)
		return;

	if (Game::random_choice(40))
		move(Game::random_direction()); // NOTE: This might choose out of bound location, causing wasted movement
}

const std::string Entity::describe() {
	std::string ret;
	if (this->name != "")
		ret += "It's name is " + this->name + "\n";
	switch (this->type)
	{
	case GNOME:
		ret += "It's a small creature wearing a pointy red hat. It's a GNOME\n";
		break;
	case WALL:
		ret += "It's a wall\n";
		break;
	default:
		ret += "You don't know this entity\n";
		break;
	}
	if (!this->isAiControlled) {
		ret += "It seems not to have a mind of its own\n";
	}
	return ret;
}

Entity::Entity() { 
	type = EMPTY; 
	pos = MapCoord(0, 0); 
	isAiControlled = false;
}

Entity::Entity(MapCoord c, EntityType t, bool ai, std::string n) {
	pos = c;
	type = t;
	isAiControlled = ai;
	name = n;
	if (n == "") {
		// TODO: Roll for a name
	}
}

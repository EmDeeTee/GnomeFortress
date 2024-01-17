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

Entity::Entity() { 
	type = EMPTY; 
	pos = MapCoord(0, 0); 
	isAiControlled = false;
}

Entity::Entity(MapCoord c, EntityType t, bool ai) {
	pos = c;
	type = t;
	isAiControlled = ai;
}

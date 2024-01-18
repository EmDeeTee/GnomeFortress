#ifndef GAME_H
#define GAME_H

#include <list>
#include "Entity.h"

class Game {
public:
	static void update();
	static void input();
	static size_t append_entity(Entity e);
	static MapCoord direction_from_int(int i);
	static MapCoord random_direction();
	static bool random_choice(int chance);
	static const MapCoord prompt_direction(); // Ask the player for direction
	static void examine(const MapCoord& c); // Examine an entity near the player
	static void build(const MapCoord& c); // Build an entity
private:
	static void _update_win32();
	static void _update_linux();
};

#endif
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
private:
	static void _update_win32();
	static void _update_linux();

	static std::list<Entity> entities; // Player is not a part of this list
};

#endif
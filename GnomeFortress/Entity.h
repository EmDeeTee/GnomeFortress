#ifndef ENTITY_H
#define ENTITY_H

#include <random>

#include "MapCoord.h"

enum EntityType {
	EMPTY = '.',
	GNOME = 'g',
	PLAYER = 'P'
};

class Entity {
public:
	MapCoord pos;
	EntityType type;
	void move(int x, int y);
	void move(const MapCoord& c);
	bool is_player();
	void eval_ai();

	Entity();
	Entity(MapCoord c, EntityType t, bool ai);
private:
	bool isAiControlled;
};

#endif 

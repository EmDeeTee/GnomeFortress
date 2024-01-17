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
	std::string name;

	void move(int x, int y);
	void move(const MapCoord& c);
	bool is_player();
	void eval_ai();
	const std::string describe();
	bool isAiControlled;

	Entity();
	Entity(MapCoord c, EntityType t, bool ai, std::string n = "");
private:
};

#endif 

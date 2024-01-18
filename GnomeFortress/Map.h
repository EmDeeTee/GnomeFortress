#ifndef MAP_H
#define MAP_H

#include "MapCoord.h"
#include "Entity.h"
#include <list>

static const int MAP_HEIGHT = 6;
static const int MAP_WIDTH = 20;

class Map {
public:
	static char cells[MAP_WIDTH][MAP_HEIGHT];
	static std::list<Entity> entities; // Player is not a part of this list

	static void place_at_cell(int x, int y, EntityType type);
	static void place_at_cell(MapCoord c, EntityType type); // NOTE: Maybe this should be `const MapCoord& c`
	static const char get_cell(int x, int y); 
	static const char get_cell(MapCoord c); // NOTE: Maybe this should be `const MapCoord& c`
	static Entity& get_entity_in_cell(int x, int y);
	static Entity& get_entity_in_cell(MapCoord c); // NOTE: Maybe this should be `const MapCoord& c`
	static bool get_is_cell_empty(int x, int y);
	static bool get_is_cell_empty(const MapCoord& c);
	static MapCoord get_center();
	static void draw();
	static void init();
};

#endif
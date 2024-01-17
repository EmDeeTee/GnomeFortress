#ifndef MAP_H
#define MAP_H

#include "MapCoord.h"
#include "Entity.h"

static const int MAP_HEIGHT = 6;
static const int MAP_WIDTH = 20;

class Map {
public:
	static char cells[MAP_WIDTH][MAP_HEIGHT];

	static void place_at_cell(int x, int y, EntityType type);
	static void place_at_cell(MapCoord c, EntityType type);
	static const char get_cell(int x, int y); 
	static MapCoord get_center();
	static void draw();
	static void init();
};

#endif
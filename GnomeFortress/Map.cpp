#include <stdio.h>
#include "Map.h"
#include "Player.h"

char Map::cells[MAP_WIDTH][MAP_HEIGHT];

void Map::place_at_cell(int x, int y, EntityType type) {
	cells[x][y] = type;
}

void Map::place_at_cell(MapCoord c, EntityType type) {
	cells[c.x][c.y] = type;
}

const char Map::get_cell(int x, int y) {
	return cells[x][y];
}

void Map::draw() {
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int ii = 0; ii < MAP_WIDTH; ++ii) {
			putchar(get_cell(ii,i));
		}
		printf("\n");
	}
	printf("\n");
}

void Map::init() {
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int ii = 0; ii < MAP_WIDTH; ++ii) {
			place_at_cell(ii, i, EMPTY);
		}
	}
}

MapCoord Map::get_center() {
	return MapCoord(MAP_WIDTH/2, MAP_HEIGHT/2);
}

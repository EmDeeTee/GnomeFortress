#include <stdio.h>
#include "Map.h"
#include "Player.h"

char Map::cells[MAP_WIDTH][MAP_HEIGHT];
std::list<Entity> Map::entities = std::list<Entity>();

void Map::place_at_cell(int x, int y, EntityType type) {
	cells[x][y] = type;
}

void Map::place_at_cell(MapCoord c, EntityType type) {
	cells[c.x][c.y] = type;
}

const char Map::get_cell(int x, int y) {
	return cells[x][y];
}

const char Map::get_cell(MapCoord c) {
	return get_cell(c.x, c.y);
}

Entity& Map::get_entity_in_cell(int x, int y) {
	for (auto& entity : entities) {
		if (entity.pos == MapCoord(x, y)) {
			return entity;
		}
	}
}

Entity& Map::get_entity_in_cell(MapCoord c) {
	return get_entity_in_cell(c.x, c.y);
}

bool Map::get_is_cell_empty(int x, int y) {
	return cells[x][y] == EMPTY;
}

bool Map::get_is_cell_empty(const MapCoord& c) {
	return get_is_cell_empty(c.x, c.y);
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

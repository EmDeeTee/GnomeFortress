#include "MapCoord.h"

MapCoord::MapCoord(int x, int y) {
	this->x = x;
	this->y = y;
}

MapCoord::MapCoord() {
	this->x = 0;
	this->y = 0;
}


bool operator==(const MapCoord& l, const MapCoord& r) {
	return (l.x == r.x) && (l.y == r.y);
}

MapCoord operator+(const MapCoord& l, const MapCoord& r) {
	return MapCoord(l.x + r.x, l.y + r.y);
}
#ifndef MAPCOORD_H
#define MAPCOORD_H

class MapCoord {
public:
	int x, y;
	MapCoord(int x, int y);
	MapCoord();

	friend bool operator==(const MapCoord& l, const MapCoord& r);
	MapCoord operator+(const MapCoord& o);
};

#endif 

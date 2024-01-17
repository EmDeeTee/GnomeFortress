#ifndef PLAYER_H
#define PLAYER_H

#include "MapCoord.h"
#include "Entity.h"

class Player {
public:
	static Entity& get_player();
private:
	static Entity player;
};

#endif
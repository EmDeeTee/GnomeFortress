#include "Player.h"
#include "Map.h"

Entity Player::player = Entity(Map::get_center(), PLAYER, false);

Entity& Player::get_player() {
	return player;
}

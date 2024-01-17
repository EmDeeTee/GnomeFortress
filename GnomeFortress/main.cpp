#include "GnomeFortress.h"
#include "Map.h"
#include "Player.h"
#include "Game.h"
#include "Log.h"

using namespace std;

int main() {
	Log::init();
	Map::init();
	Map::place_at_cell(Map::get_center(), PLAYER); // NOTE: I hate this. This should not be here
	Game::append_entity(Entity(MapCoord(2, 0), GNOME, true, "Kok"));
	Game::append_entity(Entity(MapCoord(5, 1), GNOME, false));
	Game::random_choice(90);
	Game::input();
	return 0;
}

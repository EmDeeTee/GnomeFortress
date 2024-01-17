#include <iostream>
#include <thread>

#include "Game.h"
#include "Map.h"
#include "Player.h"
#if WIN32
	#include <conio.h>
#endif 

static const int UPDATE_DELAY = 100;

std::list<Entity> Game::entities = std::list<Entity>();

void Game::update() {
    for (auto& entity : entities) {
        entity.eval_ai();
    }
    Map::draw();
}

void Game::_update_win32() {
    while (true) {
        Entity& player = Player::get_player();
        if (_kbhit()) {  
            char key = _getch();  

            if (key == 'w') {
                player.move(player.pos.x, player.pos.y - 1);
            }
            if (key == 's') {
                player.move(player.pos.x, player.pos.y + 1);
            }
            if (key == 'a') {
                player.move(player.pos.x - 1, player.pos.y);
            }
            if (key == 'd') {
                player.move(player.pos.x + 1, player.pos.y);
            }
            if (key == 'e') { // examine
                auto c = Map::get_cell(player.pos.x, player.pos.y - 1);
                if (c == EMPTY)
                    printf("There is nothing to examine");
                else
                    if (c == GNOME)
                        printf("You see a gnome");
                getch();
            }
        }

        printf("Player position: %i, %i", player.pos.x, player.pos.y);
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_DELAY));
        system("cls");
        update();
    }
}

void Game::_update_linux() {
}

void Game::input() {
#if WIN32
    _update_win32();
#elif
    _update_linux();
#endif 
}

/// <summary>
/// returns index of the entity and places it in the world
/// </summary>
size_t Game::append_entity(Entity e) {
    entities.push_back(e);
    Map::place_at_cell(e.pos.x, e.pos.y, e.type);
    e.pos = MapCoord(e.pos.x, e.pos.y);
    size_t index = entities.size() - 1;

    return index;
}

/// <summary>
/// 1 = up
/// 2 = down
/// 3 = left
/// 4 = right
/// </summary>
MapCoord Game::direction_from_int(int i) {
    if (i == 1)
        return MapCoord(0, -1);
    if (i == 2)
        return MapCoord(0, 1);
    if (i == 3)
        return MapCoord(-1, 0);
    if (i == 4)
        return MapCoord(1, 0);

    throw std::invalid_argument("i was not in range 1-4");
}

MapCoord Game::random_direction() {
    std::random_device rd;
    std::mt19937 gen(rd()); // NOTE: Those generators should probably be some private field
    std::uniform_int_distribution<> distr(1, 4);



    return direction_from_int(distr(gen));
}

bool Game::random_choice(int chance) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 100);

    return distr(gen) < chance;
}


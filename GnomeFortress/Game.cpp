#include <iostream>
#include <thread>
#include <format>

#include "Game.h"
#include "Map.h"
#include "Player.h"
#if WIN32
	#include <conio.h>
#endif 
#include "Log.h"
#include <string>

static const int UPDATE_DELAY = 200;

void Game::update() {
    for (auto& entity : Map::entities) {
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
            if (key == 'e') {
                examine();
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
    Map::entities.push_back(e);
    Map::place_at_cell(e.pos.x, e.pos.y, e.type);
    e.pos = MapCoord(e.pos.x, e.pos.y);
    size_t index = Map::entities.size() - 1;

    Log::write(
        "Game::append_entity: name=" + e.name
        + " ai=" 
        + std::to_string(e.isAiControlled) 
        + " index=" + std::to_string(index) 
    );

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

void Game::examine() {
    printf("examine\nw - up\ns - down\na - left\nd - right\n");
    char c = getch();
    MapCoord dir = MapCoord(0, -1); // UP by default
    switch (c)
    {
    case 'w':
        dir = MapCoord(0, -1);
        break;
    case 's':
        dir = MapCoord(0, 1);
        break;
    case 'a':
        dir = MapCoord(-1, 0);
        break;
    case 'd':
        dir = MapCoord(1, 0);
        break;
    default:
        break;
    }
    MapCoord targetCell = Player::get_player().pos + dir;
    auto target = Map::get_cell(targetCell);
    if (target == EMPTY)
        printf("There is nothing to examine\n");
    else {
        Entity& e = Map::get_entity_in_cell(targetCell);
        printf(e.describe().c_str());
    }
    getch();
}


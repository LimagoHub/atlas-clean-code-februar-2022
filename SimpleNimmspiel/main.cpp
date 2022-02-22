#include <iostream>

#include "clients/game_client.h"
#include "games/takegame/take_game_impl.h"

int main() {
    take_game_impl game;
    game_client client{game};
    client.run();
    return 0;
}

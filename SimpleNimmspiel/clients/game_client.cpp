//
// Created by JoachimWagner on 21.02.2022.
//

#include "game_client.h"

game_client::game_client(game &game) : game_(game) {}

void game_client::run() {
    game_.play();
}

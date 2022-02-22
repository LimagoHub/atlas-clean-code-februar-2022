//
// Created by JoachimWagner on 21.02.2022.
//

#pragma once
#include "../games/game.h"

class game_client {

private:
    game &game_;

public:
    game_client(game &game);
    void run() ;
};





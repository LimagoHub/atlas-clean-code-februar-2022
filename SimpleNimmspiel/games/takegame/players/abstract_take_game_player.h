//
// Created by JoachimWagner on 22.02.2022.
//

#pragma once

#include "../../players/abstract_game_player.h"
class abstract_take_game_player: public abstract_game_player<int,int>{

public:
    abstract_take_game_player(std::string name):abstract_game_player(name) {}

};





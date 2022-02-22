//
// Created by JoachimWagner on 22.02.2022.
//

#pragma once

#include <iostream>
#include "abstract_take_game_player.h"
class oma_player :public  abstract_take_game_player{
public:
    oma_player(const std::string &name) : abstract_take_game_player(name) {}

    int do_turn(const int &board) const override {
        return 1;
    }
};





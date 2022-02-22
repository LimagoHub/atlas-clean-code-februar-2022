//
// Created by JoachimWagner on 22.02.2022.
//

#pragma once

#include <iostream>
#include "abstract_take_game_player.h"
class computer_player :public  abstract_take_game_player{
public:
    computer_player(const std::string &name) : abstract_take_game_player(name) {}

    int do_turn(const int &stoneCount) const override {
        const std::vector turns {3,1,1,2};
        int turn = turns[stoneCount % 4];
        std::cout << get_name() << " nimmt " << turn << " Steine." << std::endl;
        return turn;
    }
};





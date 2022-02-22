//
// Created by JoachimWagner on 22.02.2022.
//

#pragma once
#include <iostream>
#include "abstract_take_game_player.h"
class human_player :public abstract_take_game_player{
public:
    human_player(const std::string &name) : abstract_take_game_player(name) {}

    int do_turn(const int &stoneCount) const override {
        int result;
        std::cout << "Es gibt " << stoneCount << " Steine. Bitte nehmen Sie 1,2 oder 3.";
        std::cin >> result;
        return result;
    }


};





//
// Created by JoachimWagner on 22.02.2022.
//

#pragma once

#include "game_player.h"

template<class BOARD, class TURN>
class abstract_game_player: public game_player<BOARD,TURN>{
    std::string name;

public:
    abstract_game_player(std::string name):name(name) {}



    std::string get_name() const noexcept override {
        return name;
    }
};





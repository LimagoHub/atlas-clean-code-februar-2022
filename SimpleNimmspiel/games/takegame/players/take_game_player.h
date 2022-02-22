//
// Created by JoachimWagner on 22.02.2022.
//

#pragma once
// Contract
#include <string>
#include "../../players/game_player.h"
class take_game_player :public game_player<int, int>{

public:
    virtual int do_turn(int stoneCount) const = 0;
    virtual std::string get_name() const noexcept = 0;
};





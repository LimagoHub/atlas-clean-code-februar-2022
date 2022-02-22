//
// Created by JoachimWagner on 21.02.2022.
//

#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include "../../games/abstract_game.h"
#include "players/take_game_player.h"

class take_game_impl : public  abstract_game<int,int>{

protected:
    bool is_turn_valid() const override {
        return getTurn() >= 1 && getTurn() <= 3;
    }
    void updateBoard() override { setBoard(getBoard() - getTurn()) ; }

    bool is_game_over() const noexcept override{ // Operation
        return getBoard() <= 0 || get_players().empty();
    }
public:
    take_game_impl()   {
        setBoard(23);
    }




};









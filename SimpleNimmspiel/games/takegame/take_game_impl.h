//
// Created by JoachimWagner on 21.02.2022.
//

#pragma once
#include <iostream>
#include <vector>
#include "../../games/game.h"

class take_game_impl : public  game{
private:
    int stoneCount;
    bool game_over;

    void human_turn() {
        int turn;
        while(true) {
            std::cout << " Es gibt " << stoneCount << " Steine. Bitte nehmen Sie 1, 2 oder 3!" << std::endl;
            std::cin >> turn;
            if(turn >= 1 && turn <= 3) break;
            std::cout << "Ungueltiger Zug" << std::endl;
        }
        stoneCount -= turn;
    }
    void computer_turn() {
        if(stoneCount < 1) {
            game_over = true;
            std::cout << "Du Loser" << std::endl;
            return;
        }

        if(stoneCount == 1) {
            game_over = true;
            std::cout << "Du hast nur Glueck gehabt" << std::endl;
            return;
        }

        const std::vector turns {3,1,1,2};
        int turn = turns[stoneCount % 4];
        std::cout << "Computer nimmt " << turn << " Steine." << std::endl;
        stoneCount -= turn;
    }
    void play_next_round() {
        human_turn();
        computer_turn();
    }
public:
    take_game_impl() : stoneCount(23), game_over(false) {}

    void play() noexcept override {
        while(! game_over) {
            play_next_round();
        }
    }


};





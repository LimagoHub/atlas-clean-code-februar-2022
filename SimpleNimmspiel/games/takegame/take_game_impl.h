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
    int turn;

    bool is_game_over() const noexcept{ // Operation
        return stoneCount <= 0;
    }

    void human_turn() {
        if(is_game_over()) return;

        while(true) {
            std::cout << " Es gibt " << stoneCount << " Steine. Bitte nehmen Sie 1, 2 oder 3!" << std::endl;
            std::cin >> turn;
            if(turn >= 1 && turn <= 3) break;
            std::cout << "Ungueltiger Zug" << std::endl;
        }
        terminate_turn("Human");
    }
    void computer_turn() {
        if(is_game_over()) return;

        const std::vector turns {3,1,1,2};
        turn = turns[stoneCount % 4];
        std::cout << "Computer nimmt " << turn << " Steine." << std::endl;

        terminate_turn("Computer");
    }

    void terminate_turn(std::string playerName) { // Integration
        updateBoard();
        check_losing(playerName);
    }

    void check_losing(const std::string &playerName) const {
        if(is_game_over())
            std::cout << playerName << " hat verloren." << std::endl;


    }

    void updateBoard() { stoneCount -= turn; }

    void play_next_round() { // Integration
        human_turn();
        computer_turn();
    }

public:
    take_game_impl() : stoneCount(23) {}

    void play() noexcept override {
        while(! is_game_over()) {
            play_next_round();
        }
    }


};





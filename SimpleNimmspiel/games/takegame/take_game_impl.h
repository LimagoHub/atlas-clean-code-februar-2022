//
// Created by JoachimWagner on 21.02.2022.
//

#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include "../../games/game.h"
#include "players/take_game_player.h"

class take_game_impl : public  game{
private:

    static const std::string LOSING_MESSAGE;
    static const std::string ERROR_MESSAGE;
    std::vector<take_game_player *> players;
    take_game_player *current_player;
    int stoneCount;
    int turn;

    void play_next_round() {
        for(auto  player : get_players()) {
            current_player = player;
            execute_players_turn();
        }
    }

    void execute_players_turn() { // Integration
        if(is_game_over()) return;
        invoke_players_turn();
        terminate_turn();
    }



    void invoke_players_turn()  {

        do {
            turn = current_player->do_turn(stoneCount);
        } while(players_turn_is_invalid());

    }



    bool players_turn_is_invalid() const {
        if (is_turn_valid()) {
            return false;
        }
        print(ERROR_MESSAGE);
        return true;
    }




    void terminate_turn() { // Integration
        updateBoard();
        check_losing();
    }

    void check_losing() const {
        if(is_game_over())
            printf(LOSING_MESSAGE,current_player->get_name());


    }
    bool is_turn_valid() const {
        return turn >= 1 && turn <= 3;
    }

    void updateBoard() { stoneCount -= turn; }


    bool is_game_over() const noexcept{ // Operation
        return stoneCount <= 0 || get_players().empty();
    }



    // TO Do Refactoren
    void print(std::string message) const{
        std::cout << message << std::endl;
    }
    void printf(std::string format ,std::string message) const{
        char buffer[100];
        sprintf(buffer, format.c_str(), message.c_str());
        print(buffer);
    }
    void printf(std::string format ,int value) const{
       printf(format, std::to_string(value));
    }
    int readInt() const{
        int result;
        std::cin >> result;
        return result;
    }
protected:

    const std::vector<take_game_player *> &get_players() const;

public:
    take_game_impl() : stoneCount(23) {}

    void add_player(take_game_player *player) {
        players.push_back(player);
    }
    void play() noexcept override {
        while(! is_game_over()) {
            play_next_round();
        }
    }


};


const std::string take_game_impl::LOSING_MESSAGE{"%s hat verloren"};
const std::string take_game_impl::ERROR_MESSAGE{"Ungueltiger Zug"};

const std::vector<take_game_player *> &take_game_impl::get_players() const {
    return players;
}




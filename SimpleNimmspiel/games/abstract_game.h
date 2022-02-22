//
// Created by JoachimWagner on 22.02.2022.
//

#pragma once

#include "game.h"
#include "players/game_player.h"
template<class BOARD, class TURN>
class abstract_game: public game {

    static const std::string LOSING_MESSAGE;
    static const std::string ERROR_MESSAGE;

    std::vector<game_player<BOARD,TURN> *> players;

    game_player<BOARD,TURN> *current_player;

    BOARD board;
    TURN turn;

    void play_next_round() {
        for(auto  player : get_players()) {
            play_single_turn(player);
        }
    }

    void play_single_turn(game_player<BOARD,TURN> * player) {
        current_player = player;
        execute_players_turn();
    }

    void execute_players_turn() { // Integration
        if(init_turn()) return;
        invoke_players_turn();
        terminate_turn();
    }

    bool init_turn() const{
        if(is_game_over())
            return true;
        prepare();
        return false;
    }
    void invoke_players_turn()  {

        do {
            turn = current_player->do_turn(board);
        } while(players_turn_is_invalid());

    }
    void terminate_turn() { // Integration
        updateBoard();
        check_losing();
    }
    bool players_turn_is_invalid() const {
        if (is_turn_valid())
            return false;
        print(ERROR_MESSAGE);
        return true;
    }
    void check_losing() const {
        if(is_game_over())
            printf(LOSING_MESSAGE,current_player->get_name());
    }

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

    virtual void prepare() const{
        // OK
    }

    game_player<BOARD, TURN> *getCurrentPlayer() const {
        return current_player;
    }

    void setBoard(BOARD board) {
        abstract_game::board = board;
    }

    void setTurn(TURN turn) {
        abstract_game::turn = turn;
    }


    BOARD getBoard() const {
        return board;
    }

    TURN getTurn() const {
        return turn;
    }




    const std::vector<game_player<BOARD,TURN> *> &get_players() const{
        return players;
    }
    virtual void updateBoard() =0;
    virtual bool is_game_over() const = 0;
    virtual bool is_turn_valid() const =0;
public:
    abstract_game() {}

    void add_player(game_player<BOARD,TURN> *player) {
        players.push_back(player);
    }
    void play() noexcept override {
        while(! is_game_over()) {
            play_next_round();
        }
    }
};
template<class BOARD, class TURN> const std::string abstract_game<BOARD, TURN>::LOSING_MESSAGE{"%s hat verloren"};
template<class BOARD, class TURN> const std::string abstract_game<BOARD, TURN>::ERROR_MESSAGE{"Ungueltiger Zug"};





//
// Created by JoachimWagner on 22.02.2022.
//

#pragma once

template<class BOARD, class TURN>
class game_player {
public:
    virtual TURN do_turn(const BOARD &board) const = 0;
    virtual std::string get_name() const noexcept = 0;
};





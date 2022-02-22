#include <iostream>

#include "clients/game_client.h"
#include "games/takegame/take_game_impl.h"
#include "games/takegame/players/human_player.h"
#include "games/takegame/players/computer_player.h"
int main() {
    human_player fritz{"Fritz"};
    computer_player hal{"Computer"};
    take_game_impl game;
    game.add_player(&fritz);
    game.add_player(&hal);
    game_client client{game};
    client.run();
    return 0;
}

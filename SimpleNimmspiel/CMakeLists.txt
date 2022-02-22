cmake_minimum_required(VERSION 3.17)
project(SimpleNimmspiel)

set(CMAKE_CXX_STANDARD 17)

add_executable(SimpleNimmspiel main.cpp games/game.h clients/game_client.cpp clients/game_client.h games/takegame/take_game_impl.h games/takegame/players/take_game_player.h games/takegame/players/abstract_take_game_player.h games/takegame/players/human_player.h games/takegame/players/computer_player.h games/abstract_game.h games/players/game_player.h games/players/abstract_game_player.h games/takegame/players/oma_player.h)

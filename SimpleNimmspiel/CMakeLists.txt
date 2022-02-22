cmake_minimum_required(VERSION 3.20)
project(SimpleNimmspiel)

set(CMAKE_CXX_STANDARD 17)

add_executable(SimpleNimmspiel main.cpp games/game.h clients/game_client.cpp clients/game_client.h games/takegame/take_game_impl.h)

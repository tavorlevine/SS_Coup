#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include "Player.hpp"


namespace coup{
    class Player;
    class Game{
    public:
        std::vector <std::string> all_players;
        size_t whoTor; // who play now
        size_t numOfPlayers;
        std::string win;
        std::vector<Player*> myPlayers; // details of players
        Player* coupFlag; // player out of game because of coup act
        bool gameStart;
        Game();
        ~Game();
        std::string turn();
        std::string winner();
        std::vector<std::string> players();
        void addPlayer(Player* player);
        void whatTor();
    };
    
};
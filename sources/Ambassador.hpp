#include <iostream>
#include <stdexcept>
#include "Game.hpp"
#include "Player.hpp"

#define COINS_TRANSFER 1
#define COINS_STEAL 2

namespace coup{
    class Ambassador : public Player {
        public:
        Ambassador(Game& game, std::string name): Player(game, name){
            this->the_role = "Ambassador";
        }
        ~Ambassador(){}
        void transfer(Player& from, Player& to);
        void block(Player& player);
        
    };
};
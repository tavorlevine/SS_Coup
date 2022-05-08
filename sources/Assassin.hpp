#include <iostream>
#include <stdexcept>
#include "Game.hpp"
#include "Player.hpp"

#define COINS_COUP_AS 3

namespace coup{
    class Assassin: public Player {
    public:
        Assassin(Game& game, std::string name): Player(game, name){
            this->the_role = "Assassin";
        }
        ~Assassin(){}
        void coup(Player& player);
        
    };
};
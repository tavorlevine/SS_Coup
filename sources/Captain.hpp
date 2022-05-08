#include <iostream>
#include <stdexcept>
#include "Game.hpp"
#include "Player.hpp"

namespace coup{
    class Captain: public Player{
    public:
        Captain(Game& game, std::string name):Player(game,name){
            this->the_role = "Captain";
        }
        ~Captain(){}
        void block(Player& player);
        void steal(Player& player);
    };    
    
};
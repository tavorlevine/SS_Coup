#include <iostream>
#include <stdexcept>
#include "Game.hpp"
#include "Player.hpp"
// #include "Assassin.hpp"
 
namespace coup{
    class Contessa: public Player{
    public:
        Contessa(Game& game, std::string name):Player(game, name){
            this->the_role = "Contessa";
        }
        ~Contessa(){}
        void block(Player& as);
    };
    
};
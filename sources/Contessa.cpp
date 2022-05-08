#include "Player.hpp"
#include "Contessa.hpp"
#include "Assassin.hpp"

namespace coup{
    void Contessa::block(Player& as){ //Player player
        if(!(this->inGame)){
            throw std::runtime_error("you are not in the game");
        }
        if(as.getPriviusTurn() != "coupAs"){
            throw std::runtime_error("contessa can block only coup act");
        }
        this->game->coupFlag->setInGame(true);
        this->game->numOfPlayers++;
    }
};
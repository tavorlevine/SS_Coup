#include "Duke.hpp"

namespace coup{
    void Duke::block(Player& player){        
        if(player.getPriviusTurn() != "foreign_aid"){
            throw std::runtime_error("Duke can block only foreign_aid action");
        }
        player.setCoins(-1*COINS_FA_PLAYER); 
        this->coins() ;
    }
    void Duke::tax(){
        if(this->game->turn() != this->getName()){
            return throw std::runtime_error("not your turn");
        }
        if(this->coins() >= MAX_COINS_PLAYER){
            throw std::runtime_error("you must do coup this turn");
        }        
        this->setCoins(COINS_TAX);
        this->setPriviusTurn("tax");
        while(true){
            this->game->whoTor++;
            if (this->game->whoTor == this->game->myPlayers.size()){
                this->game->whoTor = 0;
            }    
            if ((*this->game->myPlayers.at(this->game->whoTor)).getInGame()){
                break;
            }
        }
        if(!(this->game->gameStart)){
            this->game->gameStart = true;
        }  
    }
};
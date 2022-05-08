#include "Player.hpp"
#include "Ambassador.hpp"

namespace coup{
    void Ambassador::block(Player& player){
        if(!(this->inGame)){
            throw std::runtime_error("you are not in the game");
        }
        if(player.getPriviusTurn() != "steal"){
            throw std::runtime_error("Ambassador can block only steal act");
        }
        player.setCoins(-1*COINS_STEAL);
        player.getStealFlag()->setCoins(COINS_STEAL);
        player.getStealFlag()->setInGame(true);
        this->game->numOfPlayers++;
    }
    void Ambassador::transfer(Player& from, Player& to){
        if(this->game->turn() != this->getName()){
            return throw std::runtime_error("not your turn");
        }
        if (from.coins() < COINS_TRANSFER){
            return throw std::runtime_error("cant transfer 0 coins");
        }    
        from.setCoins(-1*COINS_TRANSFER);
        to.setCoins(COINS_TRANSFER);
        this->setPriviusTurn("transfer");
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
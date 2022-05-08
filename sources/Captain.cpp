#include "Captain.hpp"
#include "Player.hpp"

namespace coup{
    void Captain::block(Player& player){
        if(!this->inGame){
            throw std::runtime_error("you are not in the game");
        }
        if(player.getPriviusTurn() != "steal"){
            throw std::runtime_error("Caption can block only steal act");
        }
        player.setCoins(-2);
        player.getStealFlag()->setCoins(2);
        player.getStealFlag()->setInGame(true);
        this->game->numOfPlayers++;        
    }
    void Captain::steal(Player& player){
        if(!(this->inGame)){
            throw std::runtime_error("you are not in the game anymore");
        }
        if(this->game->turn() != this->getName()){
            return throw std::runtime_error("not your turn");
        }
        if(player.coins() < 2){
            int playersCoins = player.coins();
            player.setCoins(-1*(playersCoins));
            this->setCoins(playersCoins);
        }
        else{
            player.setCoins(-2);
            this->setCoins(2);
        }
        this->setPriviusTurn("steal");
        while(true){
            this->game->whoTor++;
            if (this->game->whoTor == this->game->myPlayers.size()){
                this->game->whoTor = 0;
            }    
            if ((*this->game->myPlayers.at(this->game->whoTor)).getInGame()){
                break;
            }
        }
        this->stealFlag = &player;
          
    }
}
#include "Assassin.hpp"

namespace coup{
    void Assassin::coup(Player& player){
        if(!(this->inGame)){
            throw std::runtime_error("you are not in the game anymore");
        }
        if(this->game->turn() != this->getName()){
            return throw std::runtime_error("not your turn!");
        }
        if(this->coins()>= COINS_COUP_PLAYER){
            Player::coup(player);
            return;
        }
        if(this->coins() < COINS_COUP_AS){
            return throw std::runtime_error("assassin need 3 coins to do coup");
        }
        if(player.getInGame()){
            player.setInGame(false);
        }
        else{
            return throw std::runtime_error("cant do coup on player thet not in the game");
        }    
        this->setCoins(-1* COINS_COUP_AS); // -3
        this->privius_turn = "coupAs";        
        while(true){
            this->game->whoTor++;
            if (this->game->whoTor == this->game->myPlayers.size()){
                this->game->whoTor = 0;
            }    
            if ((*this->game->myPlayers.at(this->game->whoTor)).getInGame()){
                break;
            }
        }
        this->game->numOfPlayers--;
        this->game->coupFlag = &player;
        if(!(this->game->gameStart)){
            this->game->gameStart = true;
        }
    }
    
}
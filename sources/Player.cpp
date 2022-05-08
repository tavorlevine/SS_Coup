#include "Player.hpp"

namespace coup{
    Player::Player(Game& game, std::string& name){
            this->game = &game;
            if (this->game->gameStart){
                throw std::runtime_error("cant create players after the game id begin");
            }
            this->name = name;
            this->my_coins = 0;
            this->inGame = true;
            this->game->numOfPlayers++;
            this->game->all_players.push_back(name);
            this->privius_turn = "this is the start";
            this->stealFlag = NULL;
            this->game->addPlayer(this);
            this->startGame();
        }
    void Player::foreign_aid(){
        if(this->game->numOfPlayers == 1){
            return throw std::runtime_error("the game need 2-6 players to play");
        }
        if(this->game->turn() != this->getName()){
            return throw std::runtime_error("not your turn");
        }
        if(this->coins() >= MAX_COINS_PLAYER){
            return throw std::runtime_error("you must play coup this turn");
        }
        this->my_coins += 2;
        this->privius_turn = "foreign_aid";
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
    void Player::income(){
        if(this->game->numOfPlayers == 1){
            return throw std::runtime_error("the game need 2-6 players to play");
        }
        if(this->game->turn() != this->getName()){
            return throw std::runtime_error("not your turn");
        }
        if(this->coins() >= MAX_COINS_PLAYER){
            return throw std::runtime_error("you must play coup this turn");
        }
        this->setCoins(1);
        this->setPriviusTurn("income");
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
    int Player::coins() const { 
        return this->my_coins;
    }
    std::string Player::role(){
        return this->the_role;
    }
    void Player::coup(Player& player){
        if(!this->inGame){
            throw std::runtime_error("you are not in the game");
        }
        if(this->game->turn() != this->getName()){
            return throw std::runtime_error("not your turn");
        }
        if(this->coins() < COINS_COUP_PLAYER){
            throw std::runtime_error("not enough coins for coup");
        }
        if(player.getInGame()){
            player.setInGame(false);
        }
        else {
            throw std::runtime_error("cant do coup on player that not in the game");
        }
        this->setPriviusTurn("coup");
        this->setCoins(-1*COINS_COUP_PLAYER);
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
    void Player::startGame(){
        if (this->game->numOfPlayers > MAX_PLAYER){
            throw std::runtime_error("need to be 2-6 players in the game to start");
        }
    }
}
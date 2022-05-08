#pragma once
#include <iostream>
#include <stdexcept>
#include "Game.hpp"

#define MAX_COINS_PLAYER 10
#define COINS_COUP_PLAYER 7
#define COINS_FA_PLAYER 2
#define MAX_PLAYER 6


namespace coup{
    class Game;
    class Player{
    protected:
        Game *game;
        std::string name;
        std::string the_role;
        int my_coins;
        bool inGame;
        std::string privius_turn;
        Player* stealFlag; // i steal from someone
    public:
        Player(Game& game, std::string& name);
        ~Player(){}
        void setCoins(int num){
            this->my_coins += num;
        }
        std::string getName(){
            return this->name;
        }
        void income();
        std::string getPriviusTurn(){
            return this->privius_turn;
        }
        void setPriviusTurn(std::string role){
            this->privius_turn = role;
        }
        bool getInGame(){
            return this->inGame;
        }
        void setInGame(bool life){
            this->inGame = life;
        }
        int coins() const;
        std::string role();
        void coup(Player& player);
        Player* getStealFlag(){
            return this->stealFlag;
        }
        void startGame();
        void foreign_aid();
    };
};
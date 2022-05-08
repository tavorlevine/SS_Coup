// #pragma once
#include "Game.hpp"

namespace coup{
    Game::Game(){
        std::vector <std::string> names;
        this->all_players = names;
        this->win = "!";
        this->whoTor = 0;
        this->numOfPlayers = 0;
        this->coupFlag = NULL;
        this->myPlayers = {};
        this->gameStart = false;
    }
    Game::~Game(){}
    std::string Game::winner(){
        // if (win == "!"){
        //     throw std::runtime_error("The game doesnt end yet");
        // }
        // return win;
        if (this->numOfPlayers > 1){
            throw std::runtime_error("The game doesnt end yet");
        }
        if (!this->gameStart){
            throw std::runtime_error("the game doesnt start");
        }
        for(size_t i=0; i<this->myPlayers.size(); i++){
            if ((*this->myPlayers.at(i)).getInGame()){
                this->win = (*this->myPlayers.at(i)).getName();
            }
        }
        return this->win;        
    }
    std::vector<std::string> Game::players(){
        std::vector<std::string> tmp = {};
        for(size_t i =0; i<this->myPlayers.size(); i++){
            if ((*this->myPlayers.at(i)).getInGame()){
                tmp.push_back((*this->myPlayers.at(i)).getName());
            }
        }
        return tmp;
    }
    std::string Game::turn(){
        return (*this->myPlayers.at(whoTor)).getName();
    }
    void Game::addPlayer(Player* player){
        this->myPlayers.push_back(player);
    }
    void Game::whatTor(){
        
    }
}
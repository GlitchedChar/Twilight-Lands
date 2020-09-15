#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <vector>
#include "User.h"
using namespace std;

//CS1300 Fall 2019
//Author: Char Donaldson
//Recitation: 105 - Michael Bradshaw

/*Algorithim:
    Declaration of constructors, functions and variables for Enemy class
    */

class Enemy{
    
    public: //enemy functions fill the stats of the enemy (str, dex, etc)
        Enemy();
        void rat();
        void goblin();
        void shredder();
        void beefBoy();
        void knight();
        void dragon();
        void final(User user);
        void spawn();
        void setHealth(int h1);
        int getHealth();
        string getName();
        void takeDamage(double dam);
        double getDamage();
        int getDex();
        int getReward();
        int getCurrency(); //returns cash reward
    
    private:
        int attack;
        int speed;
        int end;
        double health;
        int reward;
        int currency;
        string name;
        int spawnChance;
    
};
#endif //error reducer
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "Enemy.h"
using namespace std;
//CS1300 Fall 2019
//Author: Char Donaldson
//Recitation: 105 - Michael Bradshaw

/*Algorithim:
Defines constructors and functions from Enemy.h */

/* Private:
    int attack;
    int speed;
    int charisma;
    int end;
    string name;
*/


    Enemy::Enemy(){
        //This is probably not going to be used
        attack = 0;
        speed = 0; //speed of enemy (who attacks first)
        end = 0; //end doesn't really matter
        health = 0; //health is replacement for end to make things easier
        reward = 0;
        name = "";
    }
    void Enemy::rat(){
        attack = 6;
        speed = 8;
        health = 15;
        name = "Giant Rat";
        
        reward = 20;
        currency = 3;
    }
    void Enemy::goblin(){
        attack = 8;
        speed = 9;
        health = 26;
        name = "Bulky Goblin";
        
        reward = 25;
        currency = 3;
    }
    void Enemy::shredder(){
        attack = 13;
        speed = 10;
        health = 15;
        name = "Bloodthirsty Shredder";
        
        reward = 30;
        currency = 5;
    }
    void Enemy::beefBoy(){ //BEEF BOY
        attack = 3;
        speed = 12;
        health = 40;
        name = "Beef Boy";
        
        reward = 60;
        currency = 4;
    }
    void Enemy::knight(){
        attack = 11;
        speed = 13;
        health = 28;
        name = "Possessed Knight";
        
        reward = 40;
        currency = 6;
    }
    void Enemy::dragon(){
        attack = 10;
        speed = 12;
        health = 32;
        name = "Adolescent Dragon";
        
        reward = 45;
        currency = 6;
    }
    void Enemy::final(User user){ //FINAL BOSS
        
        speed = 100; //NO RUNNING
        int char1 = user.getChar();
        if(char1 > 16 && user.getLevel() > 7){
            attack = char1 - 1;
            if(user.getLevel() > 8){
                attack = char1;
            }
        }
        if(user.getStr() > 17 && user.getLevel() > 7){
            attack = user.getStr() - 4;
        }
        else{
            attack = 15; //low level players are gonna get CLOBBERED
        }

        int userEnd = user.getEnd();
        
        if(user.canUseSpells() == true && user.getLevel() > 8 && user.getChar() > 14){
            health = (6 * userEnd) + 10; //balancing, as high level spells are overpowered
        }
        else{
            health = (5 * userEnd) - 30; //balancing
        }

        name = "Unmaker";
        reward = 100;
        currency = 150;
    }
    void Enemy::spawn(){
    
    spawnChance = rand() % 8;   //makes a random integer between 1 and 7
    //This will determine enemy spawned
    }
    
    void Enemy::setHealth(int h1){
        health = h1;
    }
    int Enemy::getHealth(){
        return health;
    }
    //attack IS ALL AN ENEMY NEEDS TO CALCULATE THEIR ATTACK
    string Enemy::getName(){
        return name;
    }

    void Enemy::takeDamage(double dam){
        health = health - dam;
    }
    double Enemy::getDamage(){
        return attack;
        }

    int Enemy::getDex(){
    return speed;
    }
    int Enemy::getReward(){
        return reward;
    }
    int Enemy::getCurrency(){
        return currency;
    }
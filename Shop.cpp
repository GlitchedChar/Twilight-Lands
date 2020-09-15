#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "Shop.h"
using namespace std;
//CS1300 Fall 2019
//Author: Char Donaldson
//Recitation: 105 - Michael Bradshaw

/*Algorithim:
Defines constructors and functions from Shop.h */


/* private:
    int req; //requirement for charisma, pass/fail
    string item1;
    string item2;
*/
    Shop::Shop(){
        req = 6; //default charisma requirement
        shopName = "Error! MissingShop";
    }
    void Shop::setReq(int n1){
        req = n1;
    }
    void Shop::setName(string name){
        shopName = name;
    }
    string Shop::getName(){
        return shopName;
    }
    
    bool Shop::charCheck(int n1){
        if(n1 >= req){
            canShop = true;
            return true;
            
        }
        if(n1 < req){
            canShop = false;
            return false;
        }
    }
    
    void Shop::setRarity(int r1){
        rarity = r1;
    }
    int Shop::getRarity(){
        return rarity;
    }
    string Shop::items(){
        
        //items will be used in the buy_stuff function
        
    }
    void Shop::setShopkeeper(string shopk){ //name of shopkeeper
        shopkeeper = shopk;
    } 
    string Shop::getShopkeeper(){ //returns shopkeeper
        return shopkeeper;
    }
    void Shop::setCurrency(int req){//sets currency needed to buy at shop
        currencyReq = req;
    }
    int Shop::getCurrency(){
        return currencyReq;
    }
    void Shop::setPower(int p1){ //POWER OF POTION SOLD AT SHOP
        power = p1;
    } 
    int Shop::getPower(){
        return power;
    }
    int Shop::getReq() {
        return req;
    }
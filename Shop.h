#ifndef SHOP_H
#define SHOP_H
#include <string>
#include <vector>
using namespace std;

//CS1300 Fall 2019
//Author: Char Donaldson
//Recitation: 105 - Michael Bradshaw

/*Algorithim:
    Declaration of constructors, functions and variables for User class
    */

class Shop{
    
    public: //enemy functions fill the stats of the enemy (str, dex, etc)
        Shop();
        void setReq(int n1);
        void setName(string name);
        string getName();
        bool charCheck(int n1);
        string items();
        void setRarity(int r1);
        int getRarity();
        void setShopkeeper(string shopk); //name of shopkeeper
        string getShopkeeper(); //returns shopkeeper
        void setCurrency(int req); //currency requirement
        int getCurrency();
        void setPower(int p1); //POWER OF POTION
        int getPower();
        int getReq();
    
    private:
        int req; //requirement for charisma, pass/fail
        string item1;
        string item2;
        string shopName;
        bool canShop;
        int rarity;
        string shopkeeper;
        int currencyReq;
        int power;
    
};
#endif //error reducer
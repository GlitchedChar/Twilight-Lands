#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "User.h"
using namespace std;
//CS1300 Fall 2019
//Author: Char Donaldson
//Recitation: 105 - Michael Bradshaw

/*Algorithim:
Defines constructors and functions from User.h */

    User::User(){ //basic constructor, not actually used, really
        dex = 0;
        charisma = 0;
        endurance = 0;
        hp = 1;
        xp = 0;
        //level = 1;
        username = "";
        use_spells = false;
    }
    void User::name(string n1){
        username = n1;
    }
    string User::getName(){
        return username;
    }
        
    void User::attack(){
        //fight function
    }
    
    
    void User::setSpell(string spell1){ //SETS USER'S SPELL
        
        spell = spell1;
    }
    
    string User::getSpell(){
        return spell;
    }

    int User::itemCount(){ //healing item
        //fight function

        return item;
        // if(hp < 12){
        //     hp = hp + (hp * 0.70);
        // }
        // else if(hp > 12){
        //     hp = hp + (hp * 0.50);
        // }
    }
    void User::addItem(int i1){ //adds parameter amount of items to player's item stash (healing potions)

        item = item + i1;
    }
    double User::useItem(){
        if(item > 0){
        hp = hp + (endurance * 1.5); //calculates hp gained from item
        item--;
        }
        return hp;
    }


    void User::setHP(int num){
        hp = num;
    }
    int User::getHP(){
        return hp;
    }
    void User::setLevel(int lvl){
        level = lvl;
    }
    int User::getLevel(){
        return level;
    }

    //These functions set the stats of the character to their desired class! Stats are self explanatory.
    void User::mage(){ //mage class
        strength = 4;
        dex = 6;
        charisma = 13;
        endurance = 7;
        xp = 0;
        level = 1;
        use_spells = true;
        user_class = "Mage";
        //string User::username = "";
        weapon_power = 3;
        weapon = "Old Staff";
    
    } 
    
    void User::paladin(){ //paladin class, can use magic (for some reason) AND melee (why did I make this a character class???!?!?!)
        strength = 11;
        dex = 6;
        charisma = 11;
        endurance = 9;
        xp = 0;
        level = 1;
        use_spells = true;
        user_class = "Paladin";
        weapon_power = 4; //calcs dmg in Attack.cpp
        weapon = "Bronze Sword";
    }
    void User::assassin(){ //dark assassin class
        strength = 9;
        dex = 16;
        charisma = 16; //THIS IS WORTHLESS LMAO
        endurance = 8;
        xp = 0;
        level = 1;
        use_spells = false;
        user_class = "Dark Assassin";
        weapon_power = 6;
        weapon = "Swift Claws";
    }
    void User::barb(){ //barbarian class, basically a tank
        strength = 13;
        dex = 2;
        charisma = 2;
        endurance = 14;
        xp = 0;
        level = 1;
        use_spells = false;
        user_class = "Barbarian";
        weapon_power = 5;
        weapon = "Large Axe"; //can't use shops, must rely on OP stats to get kills
    }
    //add more classes here (I can't think of any right now)
    
    
    void User::setxp(int n1){ //sets user's xp
        xp = n1;
    }
    int User::getxp(){ //returns xp
        return xp;
    }
    
    void User::setEnd(int n1){ //these all set stats, used in levelling up
        endurance = n1; //which will be used in the fight function
    }
    void User::setStr(int n1){
        strength = n1;
    }
    void User::setDex(int n1){
        dex = 0;
        dex = n1;
    }
    void User::setChar(int n1){ //sets char
        charisma = n1;
    }
    int User::getEnd(){ //returns end
        return endurance;
    }
    int User::getStr(){ //All of these are self explanatory!!!!!!!!!!!!
        return strength;
    }
    int User::getDex(){
        return dex;
    }
    int User::getChar(){
        return charisma;
    }
    
    void User::setWeapon(string w1){
        weapon = w1;
    }
    string User::getWeapon(){
        return weapon;
    }
    int User::getWeaponPower(){
        return weapon_power;
    }

    double User::getCharMod(){
        double charMod = charisma * 0.1; //calculates char damage
        return charMod;
    }
    double User::getStrMod(){ //sets strength modifier
        double strMod = strength * 0.22;
        return strMod;
    }
    string User::getClass(){ //return class name
        return user_class;
    }

    void User::takeDamage(double dam){ //user takes damage
        hp = hp - dam;
    }
    bool User::canUseSpells(){ //sets if user can use spells or not (depends on class)

        if(use_spells == false){
            return false;
        }
        else{
            return true;
        }
    }
    void User::addHP(double health){ //adds hp to total
        hp = hp + health;
    }
    void User::setMapCount(int c){
        mapCount = c;
    }
    int User::getMapCount(){ //number of times map has been printed
        return mapCount;
    }
    void User::setFightReturn(int fight){ //this is needed because the fight function has to save a number
        fightreturn = fight;
    }
    int User::getFightReturn(){
        return fightreturn;
    }
    void User::setKillCount(int kill1){ //counter of amount of kills by user
        killCount = kill1;
    }
    int User::getKillCount(){ //returns count
        return killCount;
    }
    void User::setCurrency(int c1){ //currency for buying items
        currency = c1;
    }
    void User::addCurrency(int c2){
        currency = currency + c2;
    }
    int User::getCurrency(){
        return currency;
    }
    void User::setFightCount(int f1){
        fightCount = f1;
    }
    int User::getFightCount(){
        return fightCount;
    }
    void User::setPotion1(int p1){
        potion1 = p1;
    }
    int User::getPotion1(){
        return potion1;
    }
    void User::setPotion2(int p2){
        potion2 = p2;
    }
    int User::getPotion2(){
        return potion2;
    }
    void User::setPotion3(int p2){
        potion3 = p2;
    }
    int User::getPotion3(){
        return potion3;
    }
    void User::setPotion4(int p2){
        potion4 = p2;
    }
    int User::getPotion4(){
        return potion5;
    }
    void User::setPotion5(int p2){
        potion5 = p2;
    }
    int User::getPotion5(){
        return potion5;
    }
    void User::setDead(bool d1){ //sets player death
        dead = d1;
    }
    bool User::isDead(){
        return dead;
    }
    void User::setFilename(string filen){
        fileName = filen;
    }
    string User::getFilename(){
        return fileName;
    }
    void User::setDeathEnemy(string en1){ //enemy that kills user
        deathEnemy = en1;
    }
    string User::getDeathEnemy(){
        return deathEnemy;
    }
    void User::setUserNumber(int num1){ //extra stuff
        userNumber = num1;
    }
    int User::getUserNumber(){
        return userNumber;
    }
    void User::setPronoun(string pro){ //
        pronoun = pro;
    }
    string User::getPronoun(){
        return pronoun;
    }

    void User::setFinalBoss(bool y1){ //sets 
        onFinalBoss = y1;
    }
    bool User::onFinal(){
        return onFinalBoss;
    }
    void User::setBossDead(bool y1){
        isBossDead = y1;
    }
    bool User::getBossDead(){
        return isBossDead;
    }
    void User::setEnding(int e1){
        ending = e1;
    }
    int User::getEnding(){
        return ending;
    }

    void User::setShopSteal(int st1){
        shopSteal = st1;
    }
    int User::getShopSteal(){
        return shopSteal;
    }
    bool User::canShop(){
        return cShop;
    }
    void User::setCanShop(bool iShop){
        cShop = iShop;
    }
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "Attack.h"
using namespace std;
//CS1300 Fall 2019
//Author: Char Donaldson
//Recitation: 105 - Michael Bradshaw

/*Algorithim:
Defines constructors and functions from Attack.h */
    Attack::Attack(){
        enemy = "";
        regen = 0;
    }
    double spork(){ //this is exclusively for damage control! THIS IS FOR SPELLS!!
    //spork because of errors
    srand(time(NULL));
        vector<double> r1{0.7, 0.9, 1.0, 1.0, 1.0, 1.1, 1.1, 1.2, 1.2, 1.2, 1.2, 1.2, 1.4};
        int in1 = rand() % r1.size(); //picks random number from r1
        double rans = r1[in1]; //a random value taken from r1
    return rans;
    }
    double Attack::randomA(){
        //These values are the random values that affect damage
        //0.7 is a bad hit, 1.4 is critical
        srand(time(NULL));
        vector<double> r1{0.7, 0.8, 0.8, 0.9, 1.0, 1.0, 1.0, 1.0, 1.1, 1.1, 1.2, 1.4};
        int in1 = rand() % r1.size(); //picks random number from r1
        ran = r1[in1]; //a random value taken from r1
        
        return ran;
    }
    void Attack::setEnemy(string en1){
        enemy = en1;
    }
    string Attack::getEnemy(){
        return enemy;
    }
    
    /* THESE FOLLOWING FUNCTIONS DO NOT NECESSARILY FIT IN THE LIBRARY, BUT THEY
    WILL BE USED IN THE MAIN FIGHT FUNCTION. They may just be copy pasted into 
    the functions, as they work better as standalone functions and less of a
    attackobject.getDamage() function. */

    // int Attack::getDamage(int at, int power){ //returns damage from melee
    //     //at = strength, weap = weapon modifier
        
    //         //THIS IS MADE FOR WITH PARAMETERS!
        
    //     //damage = Weapon damage* strength modifier * randomness factor
    //     damage = (at * power) * ran;
    //     return damage;
    // } 
    
    //THIS IS CAUSING ISSUES:
    double Attack::getSpellDamage(double ch){ //returns damage from spell
        //charisma and spell dmg
        
        //sdamage = Spell power * charisma modifier * randomness factor
        sdamage = (ch * sdamage) * 1.2; //BALANCE THIS - * num

        double ran = spork();
        sdamage = sdamage * ran;
        return sdamage;
    }
    int Attack::getXP(){
        //Placeholder for fight function
        return 0;
    }
    
void Attack::setSpell(int spellpower){ //spellpower = level??
        //spell name, attack power
        
        //set spellname, sdamage
    switch(spellpower){

        case 1 :{
            sdamage = 4;
            spellname = "Ember";
            break;
        }
        case 2 :{
            sdamage = 4;
            spellname = "Psychic Fist";
            break;
        }
        case 3 : {
            sdamage = 5;
            spellname = "Focus Energy";
            break;
        }
        case 4 :{ //unchanged, damage increased
            sdamage = 5;
            spellname = "Harsh Energy";
            break;
        }
        case 5 :{
            sdamage = 5;
            spellname = "Bone Breaker";
            break;
        }
        case 6 :{ //just going to make this default for now...
            sdamage = 6;
            spellname = "Blood Reflection";
            regen = 2; //health regen?
            break;
        }
        case 7 : {
            sdamage = 7;
            spellname = "Meat Melter";
            regen = 4; //health regen?
            break;
        }
        case 8 : {
            sdamage = 8;
            spellname = "Flesh Consumer";
            regen = 6; //health regen?
            break;
        }
        case 9 : {
            sdamage = 9;
            spellname = "Devour";
            break;
        }
        case 10 : {
            sdamage = 12;
            spellname = "Disintegration of Matter";
            break;
        }
        default : {
            sdamage = 5;
            spellname = "Mystery Spell";
            break;
        }
    }


        //spellname = spname;
        //spow = at1;
    }

    void Attack::setHealSpell(int spellpower){
        
        switch(spellpower){
            case 1 : {
                healSpellName = "Heal Wounds";
                regen = 8; //buffed to 8 because Mages are weak at level 1-2
                break;
            }
            case 3 : {
                healSpellName = "Restore Life";
                regen = 12;
                break;

            }
            case 5 : {
                healSpellName = "Mend Flesh";
                regen =14;
                break;

            }
            case 9 : {
                healSpellName = "Uplifting Breath";
                regen = 20;
                break;

            }
        }
    }//sets regen

    int Attack::getRegen(){
        return regen;
    }

void Attack::setDamage(int str, int dam){ //CHECK IF OUTPUTS ARE CORRECT!!!!!!!!!!

    atpow = str * dam;
    damage = atpow;// * ran;
    //damage is what is needed
}
 int Attack::getDamage(){ //returns damage from melee
        //at = strength, weap = weapon modifier
        
         //THIS IS MADE FOR WITH PARAMETERS!
        
     //damage = Weapon damage* strength modifier * randomness factor
    return damage;
} 

void Attack::setStrength(int str){
strength = str;
}
string Attack::getSpellName(){
    return spellname;
}
string Attack::getHealSpellName(){
    return healSpellName;
}
void Attack::setCount(int c1){
    count = c1;
}



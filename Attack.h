#ifndef ATTACK_H
#define ATTACK_H
#include <string>
#include <vector>
#include "Enemy.h"
#include "User.h"
using namespace std;

//CS1300 Fall 2019
//Author: Char Donaldson
//Recitation: 105 - Michael Bradshaw

/*Algorithim:
    Declaration of constructors, functions and variables for Attack class */

//PLEASE READ: This class WILL be expanded when the main fight() function is created!
//HOWEVER, I will create as many functions as I see fit now!
//Just a note that this will probably be expanded upon once the actual game is being made!
//Hope you understand, and message me if you have any questions :)

//PS some of the functions in these headers are blank, these are just there in case they
//are needed later, although not all of them will be. They rely more on the main functions!
class Attack{
    
    public: 
        Attack();
        void setEnemy(string en1);
        int getDamage(); //returns damage from melee //(int at, int power)
        
        double getSpellDamage(double ch); //returns damage from spell NEEDS CHAR MODIFER!!
        int getXP(); //get xp gained from encounter
        string getEnemy();
        double randomA(); //randomizer for attacks
        // int bash();
        // int slash();
        void setDamage(int str, int dam); //sets atpow, spellname
        void setSpell(int spellpower); //sets spow
        void setHealSpell(int spellpower); //sets regen
        void setStrength(int str);
        string getSpellName();
        string getHealSpellName();
        int getRegen();
        void setCount(int count);
        double spor();


    
    private:
        string enemy;
        string spellname;
        string healSpellName;
        int atpow; //melee power
        int spow; //spell power
        int damage;
        int sdamage; //spell damage
        double ran; //random value from V V V
        int strength;
        double ranMod;
        int regen;
        int count;
        
    
};
#endif //error reducer
#ifndef ATTACK_H
#define ATTACK_H
#include <string>
#include <vector>
#include "Enemy.h"
#include "User.h"
using namespace std;

//CS1300 Fall 2019
//Author: Char Donaldson
//Recitation: 105 - Michael Bradshaw

/*Algorithim:
    Declaration of constructors, functions and variables for Attack class */

//PLEASE READ: This class WILL be expanded when the main fight() function is created!
//HOWEVER, I will create as many functions as I see fit now!
//Just a note that this will probably be expanded upon once the actual game is being made!
//Hope you understand, and message me if you have any questions :)

//PS some of the functions in these headers are blank, these are just there in case they
//are needed later, although not all of them will be. They rely more on the main functions!
class Attack{
    
    public: 
        Attack();
        void setEnemy(string en1);
        int getDamage(); //returns damage from melee //(int at, int power)
        
        double getSpellDamage(double ch); //returns damage from spell NEEDS CHAR MODIFER!!
        int getXP(); //get xp gained from encounter
        string getEnemy();
        double randomA(); //randomizer for attacks
        // int bash();
        // int slash();
        void setDamage(int str, int dam); //sets atpow, spellname
        void setSpell(int spellpower); //sets spow
        void setHealSpell(int spellpower); //sets regen
        void setStrength(int str);
        string getSpellName();
        string getHealSpellName();
        int getRegen();
        void setCount(int count);
        double spor();


    
    private:
        string enemy;
        string spellname;
        string healSpellName;
        int atpow; //melee power
        int spow; //spell power
        int damage;
        int sdamage; //spell damage
        double ran; //random value from V V V
        int strength;
        double ranMod;
        int regen;
        int count;
        
    
};
#endif //error reducer

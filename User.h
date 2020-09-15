#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
using namespace std;

//CS1300 Fall 2019
//Author: Char Donaldson
//Recitation: 105 - Michael Bradshaw

/*Algorithim:
    Declaration of constructors, functions and variables for User class
*/

class User{
    
    public: //enemy functions fill the stats of the enemy (str, dex, etc)
        User();
        void name(string n1);
        string getName();
        void attack();
        string getSpell();
        void setSpell(string spell1); //sets user's spell
        int itemCount(); //heal item
        void setHP(int num); //used to change variables down below
        int getHP();
        void setLevel(int lvl);
        int getLevel();
        void mage(); //spelling sorceror is too hard
        void paladin();
        void assassin(); //dark assassin
        void barb(); //barbarian
        void levelUp();
        void setxp(int n1);
        int getxp();
        void setEnd(int n1);
        void setStr(int n1);
        void setDex(int n1);
        void setChar(int n1);
        int getEnd();
        int getStr();
        int getDex();
        int getChar();
        void setWeapon(string w1);
        string getWeapon();
        int getWeaponPower();
        double getCharMod();
        double getStrMod();
        string getClass();
        void addItem(int i1);
        double useItem();
        void takeDamage(double dam); //Damage taker
        bool canUseSpells();
        void addHP(double health);
        void setCount(int c1);
        void setMapCount(int c);
        int getMapCount();
        void setFightReturn(int fight); //fight() needs to return an int, but it can't... so this fixes that
        int getFightReturn();
        void setKillCount(int kill1);
        int getKillCount();
        void setCurrency(int c1);
        void addCurrency(int c2);
        int getCurrency();
        #pragma region fightCount //REGIONS
        void setFightCount(int f1);
        int getFightCount();
        #pragma endregion
        void setPotion1(int p1);
        int getPotion1();
        void setPotion2(int p2);
        int getPotion2();
        void setPotion3(int p2);
        int getPotion3();
        void setPotion4(int p2);
        int getPotion4();
        void setPotion5(int p2);
        int getPotion5();
        void setDead(bool d1);
        bool isDead();
        void setFilename(string filen);
        string getFilename();
        // void setFilename2(string filen);
        // string getFilename2();
        void setDeathEnemy(string en1);
        string getDeathEnemy();
        void setUserNumber(int num1);
        int getUserNumber();
        void setPronoun(string pro);
        string getPronoun();
        void setFinalBoss(bool y1);
        bool onFinal();
        void setBossDead(bool y1);
        bool getBossDead();
        void setEnding(int e1);
        int getEnding();
        void setShopSteal(int st1);
        int getShopSteal();
        bool canShop();
        void setCanShop(bool iShop);
        
    private:
        int strength = 0;
        int dex = 0;
        int charisma = 0;
        int endurance = 0;
        int hp = 2;
        int xp = 0; //total exp held by user
        int level = 1; //level
        string username;
        bool use_spells;
        string user_class; //class
        int weapon_power;
        string weapon;
        string spell;
        int item = 2; //amount of heal items
        int count; //counts number of battles
        int mapCount = 0;
        int fightreturn;
        int killCount;
        int currency = 0; //currency for buying items, starts at 0
        int fightCount = 0;

        int potion1 = 0;
        int potion2 = 0;
        int potion3 = 0;
        int potion4 = 0;
        int potion5 = 0;

        bool dead = false;
        string fileName;
        string deathEnemy;
        int userNumber;
        string pronoun;
        bool onFinalBoss = false;
        bool isBossDead = false;
        int ending = 1;
        int shopSteal = 0;
        bool cShop = true; //default true
    
};
#endif //error reducer
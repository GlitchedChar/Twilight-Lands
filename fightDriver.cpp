#include <iostream>
#include <string>
#include <algorithm>
#include <fstream> //file
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
//Colors:
#define BOLDRED     "\033[1m\033[31m"      /* Bold red text */
#define BOLD     "\033[1m\033[10m"      /* Bold test (white default)*/
#define BOLDBLUE     "\033[1m\033[34m"      /* Bold light blue*/
#define BOLDPINK     "\033[1m\033[35m"      /* Bold light blue*/
#define PINK     "\033[35m"      /* Bold light blue*/
#define COLOR2     "\033[1m\033[35m"      /* Bold light blue*/
#define YELLOW  "\033[33m"      /* Yellow */ //#define YELLOW  "\033[33m"      /* Yellow */
#define GREEN   "\033[32m"      /* Green */
#define CYAN    "\033[36m"      /* Cyan */
#define RED     "\033[31m"      /* Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BLUE  "\x1B[34m" //34m - 33m = yellow
#define Black  "\033[30m"
#define Blue "\033[34m"
#define Magenta  "\033[35m"
#define LightGray "\033[37m"
#define DarkGray "\033[90m"
#define LightRed  "\033[91m"
#define LightGreen "\033[92m"
#define LightYellow "\033[93m"
#define LightBlue "\033[94m"
#define LightMagenta "\033[95m"
#define LightCyan   "\033[96m"
#define White "\033[97m"
#define RESET   "\033[0m"
#include "Shop.h"
#include "Attack.h"
using namespace std;

//CS1300 Fall 2019
//Author: Char Donaldson
//Recitation: 105 - Michael Bradshaw

//README:
//Many of the input lines use 'cin', which causes the game to be able to break. You have been warned!
//To run code *in VSCode* (cmd does not like the colors) type: g++ fightDriver.cpp Attack.cpp Enemy.cpp Shop.cpp User.cpp
//then ./a.exe
//Have fun and good luck!

//1.0 changelog:
//Ending actually works, all 3 are working!
//Paladin has been buffed, Char and Str are now 11. End is 9
//Barbarian Dex nerfed
//Mage spells rebalanced, early spells are too weak.
//Mage healing spells buffed, level 1 spell was too weak

//1.01 changelog:
//Fixed bug where shopkeeper constantly stated "We don't have that."
//Cleaned up code, added additional comments
//Added option to steal from shops, giving Dexterity trait more value.
    //If player fails a Dex check, they awkwardly trip and lose gold.
    // Succeedingleads to a random amount of level 4 potions
    //If player attempts and fails to steal 3 times, they are banned from all shops
//Added additional quips flair, and polishing.


//Takes vector and selects & returns random variable
int randomizer(vector <int> inp) {
    srand(time(NULL)); //Decides random output regarding input name, not really serious or anything
    int in2 = rand() % inp.size(); //picks random number from inp

    return inp[in2]; //a random value taken from inp
}


//takes input pronoun, which is default "they"/"she", and converts to other versions of that pronoun, which is outputted. Used in intro and outro of game.
vector <string> getPro2(User user, int num1){ 
    string pro2;
    vector <string> pro3;

    if(user.getPronoun() == "they" && num1 == 1){ //0
        pro2 = "them";
        pro3.push_back("they"); //0
        pro3.push_back("them"); //1
        pro3.push_back("their"); //2
        pro3.push_back("They"); //3
        pro3.push_back("Them"); //4
        pro3.push_back("Their"); //5
    }
    if(user.getPronoun() == "she" && num1 == 1){
        pro2 = "her";
        pro3.push_back("she"); //0
        pro3.push_back("her"); //1
        pro3.push_back("her"); //2
        pro3.push_back("She");
        pro3.push_back("Her");
        pro3.push_back("Her");
    }
    else if(user.getPronoun() == "he" && num1 == 1){
        pro2 = "him";
        pro3.push_back("he"); //0
        pro3.push_back("him"); //1
        pro3.push_back("his"); //2
        pro3.push_back("He");
        pro3.push_back("Him");
        pro3.push_back("His");
    }

    //defunct:
    if(user.getPronoun() == "they" && num1 == 2){
        pro2 = "their";

    }
    if(user.getPronoun() == "she" && num1 == 2){
        pro2 = "her";
    }
    else if(user.getPronoun() == "he" && num1 == 2){
        pro2 = "his";
    }


    if(user.getPronoun() == "they" && num1 == 3){
        pro2 = "They";
    }
    if(user.getPronoun() == "she" && num1 == 3){
        pro2 = "She";
    }
    else if(user.getPronoun() == "he" && num1 == 3){
        pro2 = "He";
    }

    if(user.getPronoun() == "they" && num1 == 4){
        pro2 = "Their";
    }
    if(user.getPronoun() == "she" && num1 == 4){
        pro2 = "Her";
    }
    else if(user.getPronoun() == "he" && num1 == 4){
        pro2 = "His";
    }

    // s
    return pro3;
}

//Basic input for user to set their character's name and class
//This is the first function that is used in main()
User characterCreation(User user){
    cout << endl << endl << endl;
    // cout << LightCyan << "TEST TEST" << RESET << endl; //testing text colors
    // cout << Magenta << "TEST TEST2" << RESET << endl;
    // cout << DarkGray << "Dark Gray" << RESET << endl;
    // cout << LightGray << "Light Gray" << RESET << endl;

    srand(time(NULL));
    int userNum = rand() % 666 + 13;
    user.setUserNumber(userNum);


    for(int n = 0; n < 1; n++){ //for loop requirements gotta be met somehow
        cout << "/home/jovyan/user/Twi1.2/app3/user" << userNum << ".cpp" << endl;
        cout << "loading..." << endl << endl;
        cout << "version loaded: 1.0_12/8/19" << endl;
    }
    
    bool fileDone = false;
    while(fileDone != true){
        
        cout << "enter file name" << endl;
        string file1;
        cin >> file1;
        if(file1 == "e"){ //debug bypass
            user.setFilename("test.txt");
            cout << "debug bypass: file set to Test.txt" << endl;
            fileDone = true;
        }
        cout << endl << endl << endl << endl << endl << "make sure your first name is printed in the file." << endl;
        cout << endl << file1 << " is the correct file?" << endl;
        cout << "1. yes" << endl;
        cout << "2. no" << endl;
        int yes;
        cin >> yes;
        if(yes == 1){
            user.setFilename(file1); //SETS FILE TO BE READ
            fileDone = true;
        }
        else{
            
        }
    }

    cout << endl << "..." << endl << endl;
    cout << "Welcome to the Twilight Lands." << endl;
    cout << "Please state your character's name:" << endl;
    string name;
    cin >> name;
    if(name == "e"){
        return user;
    }

    srand(time(NULL)); //Decides random output regarding input name, not really serious or anything
    int randum;
    vector<int> r2{1, 1, 1, 2, 2, 2, 3};
    int in2 = rand() % r2.size(); //picks random number from r2
    randum = r2[in2]; //a random value taken from r2

    //DEBUG:
    if(name == "char" || name == "Char" || name == "Max" || name == "max"){ //DEBUG - cut the wait!
        cout << RED << "welcome back." << RESET << endl;
        user.name("Max");
        //user.barb();
        user.mage();
        //user.assassin();
        //user.mage();
        user.setPronoun("she");

        //user.setChar(16);
        //user.setDex(20);
        user.setLevel(9);
        user.setxp(769);
        user.setEnd(15);
        user.setChar(19);
        user.setPotion1(3);
        user.setPotion4(3);
        user.setPotion5(6);
        return user;    
    }
    //easter egg:
    if(name == "michael" || name == "Michael" || name == "Mike" || name == "michael bradshaw" || name == "Michael Bradshaw" || name == "Michael bradshaw" || name == "michael Bradshaw" || name == "Brad"){
        cout << RED << "the gods do not take a liking to this name. they have given you a better one." << RESET << endl;
        user.name("Mr. Meatball Man");
        name = "Mr. Meatball Man"; //THIS IS A JOKE THAT MAKES LITERALLY NO SENSE PLEASE DON'T GET MAD AT ME
        cout << RED << "your new name is " << user.getName() << "." << RESET << endl << endl;
    }
    else{
        switch(randum){
        case 1 : {
            cout << "..." << endl;
        cout << "Thank you." << endl << endl << endl;
        break;
        }
        case 2 : {
            cout << "Interesting. What a peculiar choice for a name." << endl << endl;
            break;
        }
        case 3 : {
            cout << "Interesting. Is " << name << " your real name?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            int iName;
            cin >> iName;

            switch(iName){
                case 1 : {
                        cout << "Interesting choice. Moving on..." << endl << endl;
                        break;
                    }
                case 2 : {
                        cout << RED << "interesting." << RESET << endl << endl;
                        //cout << "Interesting choice. Moving on..." << endl;
                        break;
                    }
            }
        }
        }
    }
    user.name(name); //sets name
    cout << "Please select " << name << "'s pronouns" << endl;
    cout << "1. They/them" << endl;
    cout << "2. She/her" << endl;
    cout << "3. He/him" << endl;
    int pro;
    cin >> pro;

    switch(pro){
        case 1 : {
            user.setPronoun("they");
            break;
        }
        case 2 : {
            user.setPronoun("she");
            break;
        }
        case 3 : {
            user.setPronoun("he");
            break;
        }
        default : {
            user.setPronoun("they");
            break;
        }
    }
    cout << "Set to " << user.getPronoun() << "." << endl << endl;
    
    user.setPotion1(2); //giving them 2 potions to start out
    
    // cout << "PRONOUN TEST: " << endl;
    // vector <string> pro_1 = getPro2(user, 1); //they, he

    // string pro1 = pro_1[0]; //they
    // string pro2 = pro_1[1];  //them
    // string pro3 = pro_1[2];  //their
    // string pro4 = pro_1[3]; //They
    // string pro5 = pro_1[4]; //Them
    // string pro6 = pro_1[5]; //Their
    // cout << pro1 << endl;
    // cout << pro2 << endl;
    // cout << pro3 << endl;
    // cout << pro4 << endl;
    // cout << pro5 << endl;
    // cout << pro6 << endl;

    int inp = -1;
    while(inp != 1){

    cout << "Please state the class " << name << " will be:" << endl;
    cout << "1. Paladin - Rounded class with the ability to use spells and melee attacks." << endl;
    cout << "2. Barbarian - Class with a large amount of health and attack power, with low dexterity and charisma." << endl;
    cout << "3. Mage - Powerful spellcaster with starting health." << endl;
    cout << "4. Dark Assassin - Swift but deadly glass cannon. Great charisma guarantees good prices at shops, although " << endl;
    cout << "                   you may want to stick to running..." << endl;
   
    int clas;
    cin >> clas;
    cout << "Thank you..." << endl;
    cout << "..." << endl;
    cout << "..." << endl;
    cout << "..." << endl;

    
    switch(clas){ //okay, this could be done with a function... but this is easier
        case 1 : { //Paladin
            user.paladin();
            inp = 1;
            break;
        }
        case 2 :{ //Barbarian
            user.barb();
            user.setPotion4(1); //gives barbs an extra potion, because they probably need it
            inp = 1;
            break;
        }
        case 3 : { //Mage
            user.mage();
            inp = 1;
            break;
        }
        case 4 : { //Dark Assassin
            user.assassin();
            inp = 1;
            break;
        }
        case 6 :{
            cout << YELLOW << "debug exit" << RESET << endl;
            inp = 1;
            break;
        }
        default : {
            cout << "Select a valid input." << endl;
            break;
        }
    }

    } //END OF WHILE
    
    vector <string> pro2 = getPro2(user, 1); //pronoun #1
    string pro_2 = pro2[1];

    // cout << "You have chosen for " << user.getName() << " to be a " << RESET << user.getClass() << RESET << "!" << endl << endl;
    // cout << RED << "you must protect " << pro_2 << " life at all costs. this world does not forgive mistakes." << endl;
    // cout << RED << "the fate of " << user.getName() << " rests in your hands." << RESET << endl;
    // cout << "Good luck." << endl << endl;

    user.setxp(0); //resets xp debug
    int input2 = 0;
    while(input2 != 1 && input2 != 6){
        cout << "/home/jovyan/user/Twi1.2/app3/user" << userNum << ".cpp" << endl << endl;
        cout << "loading user" << userNum << ".cpp" << endl;
        cout << endl << "[version   /0.98.3x   information]: " << endl;
        cout << " - IMPORTANT : inputs that are not numeric are not recognized by terminal, except on overworld. typing characters will break the file..." << endl;
        //cout << "fixed /10.v/e/" << endl;
        //cout << "console does not recognize characters... u/$jng them will b.&/.k game..." << endl;
        cout << " - we recognize this may be frustrat ngg, alth0gu t0o m&x&/ny options w/11,,br&#,&x_gv1/,2&" << endl;
        cout << " - thank you for your understanding." << endl << endl;
        cout << "press 1 to proceed" << endl << endl;
        cin >> input2;
        if(input2 != 1){
        cout << "please press 1 to proceed" << endl << endl;
        cin >> input2;
        }
        if(input2 == 6){
            return user;
        }
    }
//looks messed up, but prints nicely:
    cout << YELLOW << R"(

##      ## ######## ##        ######   #######  ##     ## ########   ########  #######    ######## ##     ## ########   
##  ##  ## ##       ##       ##    ## ##     ## ###   ### ##            ##    ##     ##      ##    ##     ## ##         
##  ##  ## ##       ##       ##       ##     ## #### #### ##            ##    ##     ##      ##    ##     ## ##         
##  ##  ## ######   ##       ##       ##     ## ## ### ## ######        ##    ##     ##      ##    ######### ######     
##  ##  ## ##       ##       ##       ##     ## ##     ## ##            ##    ##     ##      ##    ##     ## ##         
##  ##  ## ##       ##       ##    ## ##     ## ##     ## ##            ##    ##     ##      ##    ##     ## ##         
###  ###   ######## ########  ######   #######  ##     ## ########      ##     #######       ##    ##     ## ########   

                                                        

8888888 8888888888 `8.`888b                 ,8'  8 8888 8 8888          8 8888     ,o888888o.    8 8888        8 8888888 8888888888
      8 8888        `8.`888b               ,8'   8 8888 8 8888          8 8888    8888     `88.  8 8888        8       8 8888      
      8 8888         `8.`888b             ,8'    8 8888 8 8888          8 8888 ,8 8888       `8. 8 8888        8       8 8888      
      8 8888          `8.`888b     .b    ,8'     8 8888 8 8888          8 8888 88 8888           8 8888        8       8 8888      
      8 8888           `8.`888b    88b  ,8'      8 8888 8 8888          8 8888 88 8888           8 8888        8       8 8888      
      8 8888            `8.`888b .`888b,8'       8 8888 8 8888          8 8888 88 8888           8 8888        8       8 8888      
      8 8888             `8.`888b8.`8888'        8 8888 8 8888          8 8888 88 8888   8888888 8 8888888888888       8 8888      
      8 8888              `8.`888`8.`88'         8 8888 8 8888          8 8888 `8 8888       .8' 8 8888        8       8 8888      
      8 8888               `8.`8' `8,`'          8 8888 8 8888          8 8888    8888     ,88'  8 8888        8       8 8888      
      8 8888                `8.`   `8'           8 8888 8 888888888888  8 8888     `8888888P'    8 8888        8       8 8888      
                                                                                                                                   
8 8888                  .8.          b.             8 8 888888888o.        d888888o.                                               
8 8888                 .888.         888o.          8 8 8888    `^888.   .`8888:' `88.                                             
8 8888                :88888.        Y88888o.       8 8 8888        `88. 8.`8888.   Y8                                             
8 8888               . `88888.       .`Y888888o.    8 8 8888         `88 `8.`8888.                                                 
8 8888              .8. `88888.      8o. `Y888888o. 8 8 8888          88  `8.`8888.                                                
8 8888             .8`8. `88888.     8`Y8o. `Y88888o8 8 8888          88   `8.`8888.                                               
8 8888            .8' `8. `88888.    8   `Y8o. `Y8888 8 8888         ,88    `8.`8888.                                              
8 8888           .8'   `8. `88888.   8      `Y8o. `Y8 8 8888        ,88'8b   `8.`8888.                                             
8 8888          .888888888. `88888.  8         `Y8o.` 8 8888    ,o88P'  `8b.  ;8.`8888                                             
8 888888888888 .8'       `8. `88888. 8            `Yo 8 888888888P'      `Y8888P ,88P'                                             	
)" << RESET << '\n';
    int input3 = 0;

    while(input3 != 1){
        cout << BOLD << CYAN << "Press 1 to begin!" << endl;
        cin >> input3;
    }
    return user;

}
int playerX = 0; //global variables, makes print map SO much easier!
int playerY = 0; //user starts out at 0,0

bool encounterChance(User user){ //calculates if player encounters an enemy in a [+]. Enemy spawned depends on spawnEnemy()
    //user parameter in case I want to add other obstacles later on (like more mobs spawning if you're higher level, etc)

    int randum; //random value is picked from vector to decide is mob is spawned
    srand(time(NULL)); //resets val
    vector<int> r2{1, 1, 1, 2, 2, 2, 2, 2, 2, 2,};
    int in2 = rand() % r2.size(); //picks random number from r2
    randum = r2[in2]; //a random value taken from r2

    if(randum == 1){ //if 1 is picked, no mob spawned
        return false;
    }
    if(randum == 2){ //if 2, mob spawned
        return true;
    }

}
const int x = 10, y = 14; //const because they don't change
//The map used to be about 5x7 tiles, now it's 10x14... because I added another layer on the bottom 5 minutes ago!

//tiles:
//[+] normal
//[-] safe area, no mobs spawn
//[~] water
//[S] shop
//[B] boss
string showMap[x][y] = { //this is the map!! Hand made by me
    {"[C]", "[-]","[S]","[-]","[+]","[+]", "[-]","[+]","[+]","[+]","[-]","[+]","[+]","[-]"},
    {"[-]", "[-]","[-]","[+]","[-]","[+]","[-]","[-]","[+]","[+]","[+]","[+]","[+]","[-]"},
    {"[-]", "[-]","[+]","[+]","[+]","[+]","[+]","[-]","[+]","[+]","[S]","[+]","[-]","[+]"},
    {"[-]", "[-]","[+]","[+]","[+]","[+]","[S]","[+]","[+]","[+]","[+]","[+]","[+]","[+]"},
    {"[-]", "[+]","[-]","[+]","[+]","[+]","[+]","[+]","[~]","[+]","[~]","[+]","[+]","[+]"},
    {"[+]", "[S]","[-]","[-]","[+]","[+]","[+]","[+]","[+]","[~]","[~]","[~]","[+]","[+]"},
    {"[~]", "[+]","[+]","[+]","[-]","[+]","[-]","[~]","[~]","[~]","[~]","[+]","[+]","[~]"},
    {"[~]", "[~]","[+]","[+]","[-]","[S]","[~]","[~]","[~]","[~]","[+]","[+]","[~]","[~]"},
    {"[~]", "[~]","[~]","[+]","[+]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[+]","[~]"},
    {"[~]", "[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[+]","[B]","[~]"}
};

//This function colors the map based on each location! Very self explanatory
void printMap(User user){
    
    cout << endl << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl << endl;
    cout << " You are at (" << playerX << ','<< playerY << ")"; //COUTS COORDS
    cout << LightCyan << " |  Player level = " << user.getLevel() << RESET << endl;
    for(int i = 0; i < x; i++){
        for(int n = 0; n < y; n++){
            if(showMap[i][n] =="[@]"){  //PLAYER CHARACTER
                cout << BOLD << Magenta << showMap[i][n] << RESET;
                //cout << "TEST";
            }
            else if(showMap[i][n] == "[+]"){//determines color of tiles
                cout << GREEN << showMap[i][n] << RESET;
                }
            else if(showMap[i][n] =="[S]"){ //SHOP
                cout << YELLOW << showMap[i][n] << RESET;
                //cout << "TEST2";
            }
            else if(showMap[i][n] =="[-]"){ //SAFE SPOT
                cout << DarkGray << showMap[i][n] << RESET;
            }
            else if(showMap[i][n] =="[B]"){ //FINAL BOSS
                cout << BOLDRED << showMap[i][n] << RESET;
            }
            else if(showMap[i][n] == "[C]"){ //HOME
                cout << BOLDGREEN << showMap[i][n] << RESET;
                
            }
            else if(showMap[i][n] == "[~]"){ //WATER            THIS WILL BE ADDED LATER, IF POSSIBLE!
                cout << BLUE << showMap[i][n] << RESET;
                
            }
            
            else{
            cout << showMap[i][n];
            }
            
        }
        cout << endl;
        
    }
    // int mapC = user.getMapCount() + 1; //makes sure player begins in correct spot (may not be needed)
    // cout << YELLOW << "You have opened the map " << mapC << " times!" << RESET << endl; //DEBUG!
    // user.setMapCount(mapC);
}

//Function has player travel
//coords are global to make things easy, so they may transfer between functions
int travel(User user){
    char input; //input deciding where to go
    string temp = showMap[playerY][playerX]; // [+]
    showMap[playerY][playerX] = "[@]"; // Where player is
    printMap(user);
bool travel1 = true;

while(travel1 == true){
    cin >> input; //player input

    // if(user.getMapCount() == 0){
    //     cout << YELLOW << "You are home (" << BOLDGREEN << "[H]" << RESET << YELLOW << "). Use WASD to move!" << RESET << endl;
    // }
    

    if(input == 's' && playerY < x - 1){ //s goes down
        showMap[playerY][playerX] = temp; //reassigns player position to temp
        playerY++; //Y is increased (because, going down)
        temp = showMap[playerY][playerX]; //reset

                    if(showMap[playerY][playerX] == "[+]"){ //tests if enemy spawns in [+] space. MUST check before player moves!!
                        //cout << YELLOW << "TEST 3!!!!!!" << RESET << endl; //DEBUG
                        bool spawnMob = false;

                        spawnMob = encounterChance(user);
                    if(spawnMob == true){
                        //cout << YELLOW << "ENEMY SPAWNS!" << endl; //DEBUG
                        travel1 = false;
                        return 2;
                    }
                    else{
                        cout << "Nothing appears in the grass..." << endl;
                        }
                        } //end of [+] spawner
                    if(showMap[playerY][playerX] == "[~]"){
                        cout << BLUE << "the water sucks you in..." << endl; //DEBUG
                        cout << BOLDRED << "An enemy attacks you!" << RESET << endl;
                        return 2;
                    }
                    if(showMap[playerY][playerX] == "[S]"){
                //cout << YELLOW << "You have encountered a shop!" << RESET << endl;
               return 3;
                }
                if(showMap[playerY][playerX] == "[B]"){
                        cout << BOLDRED << endl << endl << endl << endl << endl << endl << "You walk into a frighteningly dark cave..." << RESET << endl; //DEBUG
                        
                        return 5;
                    }
        showMap[playerY][playerX] = "[@]"; //prints player position
        printMap(user); //map is printed
    }

    if(input == 'd' && playerX < y - 1){ //d goes right
        showMap[playerY][playerX] = temp;
        playerX++;
        temp = showMap[playerY][playerX];

                if(showMap[playerY][playerX] == "[+]"){ //tests if enemy spawns in [+] space. MUST check before player moves!!
                //cout << YELLOW << "TEST 3!!!!!!" << RESET << endl; //DEBUG
                bool spawnMob = false;
                spawnMob = encounterChance(user);
            if(spawnMob == true){
                //cout << YELLOW << "ENEMY SPAWNS!" << endl; //DEBUG
                travel1 = false;
                return 2;
            }
            else{
                cout << "Nothing appears in the grass..." << endl;
                }
                } //end of [+] spawner
            if(showMap[playerY][playerX] == "[~]"){
                        cout << BLUE << "the water sucks you in..." << endl; //DEBUG
                        cout << BOLDRED << "An enemy attacks you!" << RESET << endl;
                        return 2;
                }
                if(showMap[playerY][playerX] == "[B]"){
                        cout << RED << "You walk into a frighteningly dark cave..." << RESET << endl; //DEBUG
                        
                        return 5;
                    }
                if(showMap[playerY][playerX] == "[S]"){
                //cout << YELLOW << "You have encountered a shop!" << RESET << endl;
                return 3;
            }
        showMap[playerY][playerX] = "[@]";
        printMap(user);
    }

    if(input == 'w' && playerY > 0){ //w goes up
        showMap[playerY][playerX] = temp;
        playerY--; //going UP
        temp = showMap[playerY][playerX];
                if(showMap[playerY][playerX] == "[+]"){ //tests if enemy spawns in [+] space. MUST check before player moves!!
                //cout << YELLOW << "TEST 3!!!!!!" << RESET << endl; //DEBUG
                bool spawnMob = false;

                spawnMob = encounterChance(user);
            if(spawnMob == true){
                //cout << YELLOW << "ENEMY SPAWNS!" << endl; //DEBUG
                travel1 = false;
                return 2;
            }
            else{
                cout << "Nothing appears in the grass..." << endl;
                }
                } //end of [+] spawner
            if(showMap[playerY][playerX] == "[~]"){
                        cout << BLUE << "the water sucks you in..." << endl; //DEBUG
                        cout << BOLDRED << "An enemy attacks you!" << RESET << endl;
                        return 2;
                    }
                    if(showMap[playerY][playerX] == "[B]"){
                        cout << RED << "You walk into a frighteningly dark cave..." << RESET << endl; //DEBUG
                        
                        return 5;
                    }
            if(showMap[playerY][playerX] == "[S]"){
                //cout << YELLOW << "You have encountered a shop!" << RESET << endl;
                return 3;
            }

        showMap[playerY][playerX] = "[@]";
        printMap(user);
    }

    if(input == 'a' && playerX > 0){ //a goes left
        showMap[playerY][playerX] = temp;
        playerX--;
        temp = showMap[playerY][playerX];

                if(showMap[playerY][playerX] == "[+]"){ //tests if enemy spawns in [+] space. MUST check before player moves!!
                
                bool spawnMob = false;

                spawnMob = encounterChance(user);
            if(spawnMob == true){
                //cout << YELLOW << "ENEMY SPAWNS!" << endl; //DEBUG
                travel1 = false;
                return 2;
            }
            else{
                cout << "Nothing appears in the grass..." << endl;
                }
                } //end of [+] spawner
                if(showMap[playerY][playerX] == "[~]"){
                        cout << BLUE << "the water sucks you in..." << endl; //DEBUG
                        cout << BOLDRED << "An enemy attacks you!" << RESET << endl;
                        return 2;
                    }
            if(showMap[playerY][playerX] == "[S]"){
                //cout << YELLOW << "You have encountered a shop!" << RESET << endl;
                return 3;
            }
            if(showMap[playerY][playerX] == "[B]"){
                        cout << RED << "You walk into a frighteningly dark cave..." << RESET << endl; //DEBUG
                        
                        return 5;
                    }
        showMap[playerY][playerX] = "[@]";
        printMap(user);
    }
    if(input == 'e'){ //kills program
        cout << RED << "DEBUG EXIT" << RESET << endl;
        travel1 = false;
        return 6;
        break;
        }
    //checks for enemy:
    //     if(showMap[playerY][playerX] == "[+]"){
    //     cout << YELLOW << "TEST 3!!!!!!" << RESET << endl;
    //     bool spawnMob = false;

    //     spawnMob = encounterChance(user);
    // if(spawnMob == true){
    //     cout << YELLOW << "ENEMY SPAWNS!" << endl;
    //     travel1 = false;
    //     return 2;
    // }
    // else{
    //     cout << "Nothing appears in the grass..." << endl;
    //     }
    //     } //end of [+] spawner
    }
}


Enemy spawnEnemy(User user){ //spawns a randomized enemy for the player to fight
    //lvl makes sure enemy spawned is not too OP
    int lvl = user.getLevel();
    //cout << lvl << endl;
    Enemy en;
    int randum = 1;

    if(lvl > 5){
    srand(time(NULL));
    vector<int> r2{3, 3, 3, 4, 5, 5, 5, 6, 6};
    int in2 = rand() % r2.size(); //picks random number from r2
    randum = r2[in2]; //a random value taken from r2
    }
    //hardcoded spawns for levels 1-4
    //ensures player doesn't die immediately
    //If the player is level 5 for above, normal spawn rates occur

switch(lvl){
        case 1 : {
            srand(time(NULL));
            randum = 1;
            break;

        }
        case 2 : {
            srand(time(NULL));
            randum = rand() % 3 + 1; //random between 1 (rat) and 2 (goblin)
            //randum = rand()%((4 - 1) + 1);
            break;
        }
        case 3 : {
            srand(time(NULL));
            randum = 2;
            break;
        }
        case 4 : {
            srand(time(NULL));
            randum = rand() % 3 + 1; //between 1 and 4
            break;
        }
        case 5 : {
            srand(time(NULL));
            randum = rand() % 3 + 2; //between 2 and 5
            break;
        }
    }

    //switch sets enemy type (stats) based on input and then breaks
    switch(randum){
        case 1 :{ //rat
            en.rat(); //sets enemy type
            return en;
            break;
        }
        case 2 :{ //goblin
            en.goblin();
            return en;
            break;
        }
        case 3 :{ //shedder
            en.shredder();
            //cout << "Shredder" << endl;
            return en;
            break;
        }
        case 4 : { //BEEF BOY
            en.beefBoy();
            return en;
            break;
        }
        case 5 : { //Possessed Knight
            en.knight();
            return en;
            break;
        }
        case 6 :{ //dragon
            en.dragon();
            return en;
            break;
        }
        default : { //if function breaks, rat spawns!
            en.rat();
            return en;
            break;
        }
    }
    return en;
}

double spor(){ //this is exclusively for damage control!
//sporadic
    srand(time(NULL));
        vector<double> r1{0.7, 0.8, 0.8, 0.9, 1.0, 1.0, 1.0, 1.0, 1.1, 1.1, 1.2, 1.4};
        int in1 = rand() % r1.size(); //picks random number from r1
        double rans = r1[in1]; //a random value taken from r1
    return rans;
}

Attack setHeal(int lvl){ //sets regen (heal spell based on power, look into setHealSpell() in attack.cpp)
    Attack attack;
if(lvl == 1 || lvl == 2){
        attack.setHealSpell(1);
    }
    if(lvl == 3 || lvl == 4 ){
        attack.setHealSpell(3);
    }
    if(lvl == 5 || lvl == 6 || lvl == 7){
        attack.setHealSpell(5);
    }
    if(lvl >= 8){
        attack.setHealSpell(8);
    }
    return attack;
}

/*level 2 = 45
3 = 45
4 = 70
5 = 90
6 = 100
7 = 100
8 = 120
9 = 150
10 = 200
*/

int calcLevel(int exp){
    int lvl = 1;
    if(exp >= 44 && lvl < 79){ //level 2
        lvl = 2;
    }
    if(exp >= 79 && lvl < 149){ //level 3
        lvl = 3;
    }
    if(exp >= 149 && lvl < 239){
        lvl = 4;
    }
    if(exp >= 149 && lvl < 219){
        lvl = 5;
    }
    if(exp >= 219 && lvl < 329){
        lvl = 6;
    }
    if(exp >= 329 && lvl < 439){
        lvl = 7;
    }
    if(exp >= 439 && lvl < 559){
        lvl = 8;
    }
    if(exp >= 559 && lvl < 800){
        lvl = 9;
    }
    if(exp >= 800){ //level 10 is hard to achieve because you become overpowered as hell
        lvl = 10;
    }
    // if(exp > 1200){
    //     lvl = 11;
    // }

    return lvl;
}

//Dialogue for final boss:
string finalOut(){
    string out1;
    
    srand(time(NULL));
        vector<double> r1{1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
        int in1 = rand() % r1.size(); //picks random number from r1
        int rans = r1[in1]; //a random value taken from r1
    
    switch(rans){
        case 1 : {
            out1 = "i love watching you bleed";
            break;
        }
        case 2 : {
            out1 = "your pain will be over soon";
            break;
        }
        case 3 : {
            out1 = "your smile is so erotic.";
            break;
        }
        case 4 : {
            out1 = "your taste will forever remain in my mouth";
            break;
        }
        case 5 : {
            out1 = "i love you";
            break;
        }
        case 6 : {
            out1 = "i want you";
            break;
        }
        case 7 : {
            out1 = "please";
            break;
        }
        case 8 : {
            out1 = "yes. yes. yes. yes. yes. yes. yes.";
            break;
        }
        case 9 : {
            out1 = "...";
            break;
        }
        case 10 : {
            out1 = "you look tired. so tired.";
            break;
        }
        case 11 : {
            out1 = "please keep staring at me";
            break;
        }
        case 12 : {
            out1 = "your eyes look amazingly beautiful";
            break;
        }
        case 13 : {
            out1 = "you are my angel";
            break;
        }
        default : {
            out1 = "you are my angel";
            break;
        }
    }
    return out1;
}

//Input: user playing game
//spawns randomized enemy (based on level), user may fight the enemy, take potions for health, or attempt to run
//fighting relies on class and stats
//fight is type User class, since it has to return the user in order to retain stats
//function goes on until user runs, kills enemy, or dies 
//main() will then decide what happens (print ending, go back to map, etc)

User fight(User user){
    
    //SETTING HEALTH
    if (user.getFightCount() == 0){

        int hp = user.getEnd() * 2 + 2;
        user.setHP(hp);

    }
    else{
        //int addhp = user.getEnd() * 2; //makes user have less health at beginning of battle
        //user.addHP(addhp); //MAY BE TOO HARSH
        int hp = user.getEnd() * 2 + 2;
        user.setHP(hp);
    }
    double regen = 0;
    bool die = false;

    int fightC = user.getFightCount() + 1; //counter for healing user
    user.setFightCount(fightC);

    bool bash = false; //if bash, chance at higher damage
    int input;
    bool run = false; //this will end the battle
    int win = 0;
    //loop will run until user runs or wins
    int lvl = user.getLevel(); //player level stored in int
    //cout << lvl << endl;
    Enemy en;
    en = spawnEnemy(user); //sets enemy to stats set in spawnEnemy()
    bool onFinal = user.onFinal();
    if(onFinal == true){ //sets final boss
        en.final(user);
    }
    
    string enName = en.getName();
    int count = 0; //counter for turns
    string weapon = user.getWeapon();

    //SETTING DAMAGE  
    double strength = user.getStrMod(); //sets strength modifier
    double charisma = user.getCharMod(); //sets char mod

    double weaponDamage = user.getWeaponPower(); //sets weapon power

   
    Attack attack;
    attack = setHeal(lvl);
    attack.setSpell(lvl);                                                                         //setSpell with level
    attack.setDamage(strength, weaponDamage); //strength, weapon mod

    int healCount = 0; //COUNTS TIMES HEAL SPELL HAS BEEN USED

    double meleeDamage = attack.getDamage();
    
    //attack.setSpell(lvl); //sets spell according to level
    double spellDamage = attack.getSpellDamage(charisma); //sets spell damage according to charisma modifier

    string a_ = "a ";    //correct grammar matters~!
    if(en.getName() == "Adolescent Dragon"){
        a_ = "an "; //"an" if dragon (below)
    }

    if(onFinal == true){
        cout << RESET << endl << "loading..." << endl << endl;
        cout << "/home/jovyan/user/Twi1.2/app1/player/fate/user" << user.getUserNumber() << ".cpp" << endl;
        cout << "error: [" << user.getUserNumber() << ".cpp]" << endl;
        cout << "'option' " << RED << "[9]" << RESET << " unexpected variable" << endl;

        //FILE READING FOR PLAYER'S NAME
        
        string fileName = user.getFilename();
        int userNum = user.getUserNumber();
        bool isOpen = false;

        ifstream file1(fileName); //opens file, saves as "file1"
        while(isOpen == false){
        ifstream file1(fileName); //opens file, saves as "file1"

        if(file1.is_open()){ //check if file is OPEN and EXISTS
        isOpen = true;
        cout <<endl << endl << "/home/jovyan/Twi4/" << userNum << "/fate1/" << fileName << endl;
        cout << fileName << " opened succesfully" << endl << endl;
        }
        else{
            isOpen = false;
            cout << endl << "given file could not be opened" << endl << "enter new file name" << endl << endl;
            cin >> fileName;
            if(fileName == "test"){
                isOpen = true;

            }
        }
    }

    string line;
    int placement = 0;
    string playerName; //name of the person PLAYING the game

    while(getline(file1, line)){
        if(line != ""){
            playerName = line; //saves name
        }
    }
    file1.close();
        //Leadup to final boss:
        int input3 = 5;
        while(input3 != 9){
        cout << endl << "press 9 to continue" << endl << endl;
        cin >> input3;
        }

        cout << RED << endl << endl << "i have been waiting for you, " << playerName << "." << endl << endl;

        //cout << RED << "and... " << playerName << endl;

        int input4 = 5;
        while(input4 != 9){
        cout << "i have watched you grow stronger through " << user.getName() << "." << endl;
        

            if(lvl > 5 && lvl < 9){
                cout << "powerful, even." << endl;
            }
            if(lvl >= 9){
                cout << "become... godlike." << endl << RESET;
            }
            cin >> input4; //must input 9

        }
        

    
    int input5 = 5;
        while(input5 != 9){
            cout << RED << endl << endl << "i am so happy to see you before me." << endl;
            cout << "so... so happy..." << endl << RESET;
            cin >> input5;
        }
    
        cout << endl << endl << endl << endl << endl << RED << "it seems you are enjoying this." << endl ;
        cout << "please, let me fix that for you." << endl << endl;
        cout << RESET << user.getUserNumber() << ".cpp <<< [override] 'option' " << RED << "[9]" << RESET << " deletion." << endl;
        cout << "Are you sure? This action is permanent." << endl;

        int input6 = 5;
        while(input6 != 9){
            cout << RESET << endl << "9. yes" << endl;
            cin >> input6;
        }
        cout << "loading..." << endl << endl;
        int input7 = 5;
        while(input7 != 9){
        cout << "'option' [9] deleted" << endl << endl;
        cin >> input7;
        }

        cout << RED << endl << "finally." << endl << endl;
        int input8 = 5;
        while(input8 != 9){
        cout << RED << "i hope you enjoy this." << endl << RESET;
        cin >> input8;
        }
        
        
    cout << RED << endl << "your blood..." << endl;
    cout << "it looks delicious." << endl << endl;

    int input9 = 5;
        while(input9 != 9){
        cout << RESET << "..." << endl;
        cin >> input9;
        }

    } //end of final boss leadup
    else{
        if(count == 0){
        cout << endl << "You have encountered " << a_ << BOLDRED <<  enName << "!" << RESET << endl; 
        }
    }
    
    while(run == false || win != 1 ||  en.getHealth() <= 0 || die != true){ //combat loops until player runs, player wins, enemy dies or player dies

        if(user.onFinal() == false){ //different menu with final boss
        cout << endl << CYAN << "== What will you do? ==" << RESET << endl;
        cout << GREEN << user.getName() << "'s HP: " << BOLDGREEN <<  user.getHP() << RESET << YELLOW << " / XP: " << user.getxp() << " / Level: " << user.getLevel() << endl;
        cout << Magenta << "Str: " << BOLDPINK << user.getStr()<< RESET << Magenta << " Chr: " << BOLDPINK << user.getChar() << RESET << Magenta << " Class: " << BOLDPINK << user.getClass() << RESET << endl;
        cout << RED << en.getName() << "'s health: " << BOLDRED << en.getHealth() << RESET << endl;
        int numPotions = user.getPotion1() + user.getPotion2() + user.getPotion3() + user.getPotion4() + user.getPotion5();
        cout << LightMagenta << "Potions: " << BOLD << numPotions << " " << RESET;
        cout << BLUE << "Turn number: " << CYAN << BOLD << count << RESET <<  endl;
        //BLUE << " / Potions: " << CYAN << user.itemCount() << RESET <<
        //cout << LightMagenta << "Potions: " << user.getPotion1() << " Green / " << user.getPotion2() << " Blue / " << user.getPotion3() << " Purple / " << user.getPotion4() << " Red / " << user.getPotion5() << " Gold" << RESET << endl;
        
        cout << "1. Melee attack" << endl;
        cout << "2. Use spell" << endl;
        cout << "3. Use potion" << endl;
        cout << "4. Attempt escape" << endl;
        cout << "9. End program" << endl; //9 so no accidental clicks
        cin >> input; //player input
        }
        if(user.onFinal() == true){ //Final boss battle menu:
        string finalO = finalOut();
        cout << endl << RED << finalO << RESET << endl;
        cout << RED << user.getName() << "'s HHgP: " << RED <<  user.getHP() << RESET << RED << " / exxP: " << "??" << " / LElLVV: " << user.getLevel() << endl;
        //cout << RED << "str: " << RED << user.getStr()<< RED << " chr: " << RED << user.getChar() << RED << RED << " class: " << RED << user.getClass() << RED << endl;
        //cout << RED << en.getName() << "'s blood: " << RED << en.getHealth() << RED << endl;
        int numPotions = user.getPotion1() + user.getPotion2() + user.getPotion3() + user.getPotion4() + user.getPotion5();
        cout << RED << "p/0tiOn$: " << RED << "??" << " " << RED << endl;
        //cout << RED << "turn number: " << RED << RED << count << RED <<  endl;
        //BLUE << " / Potions: " << CYAN << user.itemCount() << RESET <<
        //cout << LightMagenta << "Potions: " << user.getPotion1() << " Green / " << user.getPotion2() << " Blue / " << user.getPotion3() << " Purple / " << user.getPotion4() << " Red / " << user.getPotion5() << " Gold" << RESET << endl;
        
        cout << "1. m3/3e @//aCk" << endl;
        cout << "2. $p3l1 A/t@c&" << endl; //demented user menu during final boss
        cout << "3. U$3 1/3m" << endl;
        cout << "/41,/0v/3./y0/u" << endl;
        //cout << "4. Attempt escape" << endl;
        //cout << "9. End program" << endl; //9 so no accidental clicks
        cout << "/g451//iv,/37.e/_up./9" << endl << RESET;
        cin >> input; //player input
        cout << RED; //makes it all RED
        }
        
        
    switch(input){
        case 1 :{                                                                                                   //melee

        cout << RED << "You attack with your " << YELLOW << weapon << "!" << RESET << endl;
        cout << "Do you slash or bash the " << en.getName() << "?" << endl;
        cout << "1. Slash" << endl;
        cout << "2. Bash" << endl;
        
        int slash;
        cin >> slash;
        if(slash == 1){
            cout << "You slash the " << en.getName() << " with your " << user.getWeapon()  << "!" << endl;
            meleeDamage = meleeDamage * spor(); //randomizer
            meleeDamage = meleeDamage * 0.9;
            if(count <= 12){ //can only gain health within 12 turns
                double regenSlash = (meleeDamage / 3) + 1; //healed based on damage. Makes attacking with melee more interesting!
                user.addHP(regenSlash);
                cout << GREEN << "You have gained " << BOLDGREEN << regenSlash << " health!" << endl;
            }
        }
        if(slash == 2){ //BASH
        cout << "You bash the " << en.getName() << " with your " << user.getWeapon()  << "!" << endl;
            meleeDamage = meleeDamage * spor();
            meleeDamage = meleeDamage * 1.05;
        }
        else if (slash != 1 && slash != 2){ //players will break ANYTHING
            cout << "You lose focus and weakly decide to bash your oponent. Were you even thinking?!" << endl;
            meleeDamage = meleeDamage * spor();
            meleeDamage = meleeDamage * 0.85;
        }

        en.takeDamage(meleeDamage);
        cout << BOLDRED << "The " << en.getName() << " takes " << meleeDamage << " damage!" << RESET << endl;
        
            break;
        }
        case 2 : {                                                                                                                                                                                   //spell
        if(user.canUseSpells() == false){
            cout << YELLOW << "It appears you do not know this power..." << RESET << endl;
            break;
        }
        cout << YELLOW << "What type of spell are you attempting to cast?" << RESET << endl;
        int healCountOutput = 3 - healCount; //can cast healing 2 times
        if(healCount < 4 && user.onFinal() == false){
            cout << YELLOW << "You may heal yourself " << healCountOutput << " more times!" << RESET << endl;
        }
        else if(user.onFinal() == true){
            cout << RED << "no use in fixing the pain." << RESET << endl;
        }
        else{
            cout << RED << "You cannot cast any more healing spells!" << RESET << endl;
        }
        
        int spelltype;
        cout << "1. Damage" << endl;
        if(healCount < 4 && user.onFinal() == false){
            cout << "2. Healing" << endl;
        }
        else if(user.onFinal() == true){
            cout << RED << "..." << endl << RESET;
        }
        else{
            cout << "2. Attempt to cast a healing spell" << endl;
        }
        
        cin >> spelltype; //determines healing, damage, etc
        while(spelltype != 1 && spelltype != 2){                                                                               //NESTED WHILE LOOP!!!!!
            cout << "You start to lose focus..." << endl;
            cout << "Select an option!" << endl;
            cin >> spelltype;
            if(spelltype == 6){
                cout << YELLOW << "debug" << RESET << endl;
                user.setFightReturn(6); //FIGHTRETURN
                return user;
                //return 6;
            }

        }
        if(spelltype == 1){            //attack spell

            double charMod1 = user.getCharMod();
            //cout << YELLOW << "CHARMOD 1: " << charMod1 << RESET << endl;
            spellDamage = attack.getSpellDamage(charMod1); //calcs damage /// THIS WAS /120
            //cout << BOLD << "SPELLDAMAGE 2: " << spellDamage << RESET << endl;
            string spellName = attack.getSpellName();
            cout << YELLOW "You cast " << spellName << "!" << endl;

            cout << RED << "The " << en.getName() << " takes " << spellDamage << BOLDRED << " damage!" << RESET << endl;
            en.takeDamage(spellDamage); //enemy takes spell damage
            //break //????????
        } //defunct:
        // if(spelltype == 2 && healCount <= 2 && user.onFinal() == false){            //heal spell
        //     healCount++; //heal can only be used 5 times
        //     cout << YELLOW << "You cast " << attack.getHealSpellName() << "!" << RESET << endl;
        //     int spellRegen = attack.getRegen();
        //     user.addHP(spellRegen); //adds spell regen to health (5, 10, etc)
        //     cout << GREEN << "You have gained " << BOLDGREEN << attack.getRegen() << RESET << GREEN << " health!" << endl;

        //     if(spellRegen >= 20){
        //         cout << RED << "The " << en.getName() << " takes " << BOLDRED << "4" << RESET << RED << " damage from your prescence!" << RESET << endl;
        //     }
            
        //     break;
        // }
        else if(spelltype == 2 && healCount == 0 && user.onFinal() == false){ //No more healing slots left
            cout << RED << "Your hands flicker, but suddenly become dim..." << RESET << endl;
            int randHealSpell;
            srand(time(NULL));
            vector<int> rSpell{0, 0, 2, 2, 4, 4, 4, 4, 4, 5, 5, 5, 8, 8, 12, 12, 20, 20, 30};
            int inSpell = rand() % rSpell.size(); //picks random number from r2
            randHealSpell = rSpell[inSpell]; //a random value taken from r2

            //Char, why are you up coding at 3 am? On thanksgiving break, nonetheless.
            //I want to include some cool stuff for this game!!
            //it's not like anyone is going to see this, anyways.
            //Yeah. 
            //
            //I guess I'm doing it for myself, then.
            //Really?
            //Well, kind of? It's fun. I'm having a good time.
            //Wouldn't you rather-
            //Nah, everyone is asleep. I have nothing better to do.
            //When's the last time you played a video game? It's been like-
            //A week? Yeah, but this is fun.
            //If you say so.
            switch(randHealSpell){ //RANDOM CHANCE TO HEAL THE PLAYER DESPITE NOT HAVING ANY SPELL SLOTS!!
                case 0 : {
                    cout << RED << "You gain 0 health." << RESET << endl;
                    user.addHP(0);
                    break;
                }
                case 2 : {
                    cout << GREEN << "Despite the odds, you gain 2 health." << RESET << endl;
                    user.addHP(2);
                    break;
                }
                case 4 : {
                    cout << YELLOW << "Your hands spark once more! " << GREEN << "You gain " << BOLDGREEN << "4" << RESET << GREEN << "health." << RESET << endl;
                    user.addHP(4);
                    break;
                }
                case 5 : {
                    cout << YELLOW << "Your hands spark once more, almost as bright as before! " << GREEN << "You gain " << BOLDGREEN << "5" << RESET << GREEN << "health." << RESET << endl;
                    user.addHP(5);
                    break;
                }
                case 8 : {
                    cout << YELLOW << "Your hands spark brightly! " << GREEN << "You gain " << BOLDGREEN << "8" << RESET << GREEN << "health!" << RESET << endl;
                    user.addHP(8);
                    break;
                }
                case 12 : {
                    cout << YELLOW << "Your hands spark bright! " << GREEN << "You gain " << BOLDGREEN << "12" << RESET << GREEN << "health!" << RESET << endl;
                    user.addHP(12);
                    break;
                }
                case 20 : {
                    cout << YELLOW << "Your hands shine like the sun! " << GREEN << "You gain " << BOLDGREEN << "20" << RESET << GREEN << " health!" << RESET << endl;
                    user.addHP(20);
                    break;
                }
                case 30 : {
                    cout << YELLOW << "Your hands spark, blinding the enemy!" << GREEN << "You gain " << BOLDGREEN << "30" << RESET << GREEN << "health!" << RESET << endl;
                    cout << RED << "The " << en.getName() << " takes" << BOLDRED << " 15 " << RESET << RED << "damage from the blinding light!" << RESET << endl;
                    user.addHP(30);
                    en.takeDamage(15);

                    break;
                }
                default : {
                    cout << RED << "You gain 4 health." << RESET << endl;
                    user.addHP(4);
                    break;
                }

            }
            cout << RESET;
            cout << "";
            break;
        }
        else{
            cout << RED << "..........." << RESET << endl;
            
        }
        break;
            //return 2;
        }
        case 3 : {                                                                                   //item
        
        
        int potionInput = -1; //starting out so while loop works
        bool potionExit = false;
        while(potionExit == false && potionExit != true){
            cout << BOLDPINK << "Which type of potion would you like to consume?" << RESET << endl;
            cout << GREEN << "1. Green Potion (+10 HP)" << BOLD << "  Count: " << user.getPotion1() << RESET << endl;
            cout << GREEN << "2. Blue Potion (+12 HP)" << BOLD << "   Count: " << user.getPotion2() << RESET << endl;
            cout << GREEN << "3. Purple Potion (+14 HP)" << BOLD << " Count: " << user.getPotion3() << RESET << endl;
            cout << GREEN << "4. Red Potion (+18 HP)" << BOLD << "    Count: " << user.getPotion4() << RESET << endl;
            cout << GREEN << "5. Gold Potion (+25 HP)" << BOLD << "   Count: " << user.getPotion5() << RESET << endl;
            cout << BOLDRED << "6. None" << RESET << endl;

            cin >> potionInput;
            if(potionInput == 1 || potionInput == 2 ||potionInput == 3 ||potionInput == 4 ||potionInput == 5 || potionInput == 6){ //input exits selection
                potionExit = true;
            }

        }
        switch(potionInput){ //user consumes a potion (if they have one)
            case 1 : {
                if(user.getPotion1() >= 1){
                    user.addHP(10);
                    int po = user.getPotion1() - 1;
                    user.setPotion1(po);
                    cout << GREEN << "You consumed a Green Potion! Gained 10 HP. Total HP: " << BOLDGREEN << user.getHP() << RESET << endl;
                }
                else{
                    cout << BOLDRED << "You don't have any Green Potions!" << RESET << endl;
                }
                break;
            }
            case 2 : {
                if(user.getPotion2() >= 1){
                    user.addHP(12);
                    int po = user.getPotion2() - 1;
                    user.setPotion2(po);
                    cout << GREEN << "You consumed a Blue Potion! Gained 12 HP. Total HP: " << BOLDGREEN << user.getHP() << RESET << endl;
                }
                else{
                    cout << BOLDRED << "You don't have any Blue Potions!" << RESET << endl;
                }
                break;
            }
            case 3 : {
                if(user.getPotion3() >= 1){
                    user.addHP(14);
                    int po = user.getPotion3() - 1;
                    user.setPotion3(po);
                    cout << GREEN << "You consumed a Purple Potion! Gained 14 HP. Total HP: " << BOLDGREEN << user.getHP() << RESET << endl;
                }
                else{
                    cout << BOLDRED << "You don't have any Purple Potions!" << RESET << endl;
                }
                break;
            }
            case 4 : {
                if(user.getPotion4() >= 1){
                    user.addHP(18);
                    int po = user.getPotion4() - 1;
                    user.setPotion4(po);
                    cout << GREEN << "You consumed a Red Potion! Gained 18 HP. Total HP: " << BOLDGREEN << user.getHP() << RESET << endl;
                }
                else{
                    cout << BOLDRED << "You don't have any Red Potions!" << RESET << endl;
                }
                break;
            }
            case 5 : {
                if(user.getPotion5() >= 1){
                    user.addHP(25);
                    int po = user.getPotion5() - 1;
                    user.setPotion5(po);
                    cout << GREEN << "You consumed a Gold Potion! Gained 25 HP. Total HP: " << BOLDGREEN << user.getHP() << RESET << endl;
                }
                else{
                    cout << BOLDRED << "You don't have any Gold Potions!" << RESET << endl;
                }
                break;
            }
            case 6 : {
                cout << BOLDRED << "You stare at the " << en.getName() << ". You should buy some potions!" << RESET << endl;
                break;
            }
        } //end of switch
        
        cout << endl; //spacing

        break;
        }
        case 4 : {                                                                                                //run
        if(user.onFinal() == true){
            cout << RED << endl << endl << endl << endl << "please do not leave me." << endl << RESET << endl;

            if(user.getDex() >= 20){
                string fileName = user.getFilename(); //reads file for player's name
                string line;
                string playerName;
                ifstream file1(fileName); //opens file, saves as "file1"
                while(getline(file1, line)){
                    if(line != ""){
                        playerName = line; //saves name
                    }
                    file1.close();
                    
                    
                cout << RED << "wait... please... do not run from me..." << RESET << endl << endl;
                int i1 = 1;
                while(i1 != 4){
                    cout << endl << "press 4 to run." << endl<< endl;
                    cin >> i1;
                }
                cout << RED << endl << endl << endl << endl << "please... it's so comfortable with you here..." << RESET << endl << endl;
                cout << RED << "please..." << RESET << endl;
                int i2 = 1;
                while(i2 != 4){
                    cout << endl << "press 4 to run." << endl << endl;
                    cin >> i2;
                }

                cout << RED << user.getName() << ", please... " << playerName << ", please..." << RESET << endl; //flee
                cout << RED << "please do not leave..." << RESET << endl;

                int i3 = 1;
                while(i3 != 4){
                    cout << endl << "press 4 to run." << endl << endl;
                    //cout << "i3: " << i3 << endl;
                    cin >> i3;
                }
                int i5 = 1;
                while(i5 != 4){
                    cout << endl << "press 4 to run." << endl << endl;
                    //cout << "i5: " << i5 << endl;
                    cin >> i5;
                }
                cout << endl << "you decide to run." << endl;
                cout << endl << "you do not look back." << endl;
                user.setEnding(2);
                user.setFightReturn(12); //read in main
                return user;    //RUNS FROM FINAL BOSS
                break;
                }
                }
            break;
            }
        int run2;
        cout << CYAN << "Are you sure you want to run? " << endl;
        cout << "1. Get me out of here! " << endl;
        cout << "2. No." << RESET << endl;

        cin >> run2;
        if(run2 != 1 && run2 != 2){
            cout << "You appear confused, and stare blankly at the enemy." << endl;
            break;
        }
        if(run2 == 2){
            cout << "You decide not to run." << endl;
            break;
        }
        if(run2 == 1){
            if(user.getDex() + 1 > en.getDex()){
                cout << BOLDGREEN << "You escape safely!" << RESET << endl;
                int xp2 = user.getxp() + 20;
                   user.setxp(xp2); //user gains 20 exp from running, at request of Isabel
                   //this means that the game is actually possible to beat without hurting an enemy, for some damn reason
                   cout << YELLOW << "You have gained 20 XP from escaping successfully!" << RESET << endl;
                user.setFightReturn(4);
                return user;
                //return 4; //RUN
            }
            
            if(user.getDex() + 2 < en.getDex()){
                cout << BOLDRED << "The " << en.getName() << " does not allow escape!" << endl;
                break;
            }
            if(user.getDex() + 1 == en.getDex() || user.getDex() == en.getDex() || user.getDex() - 1 == en.getDex() || user.getDex() - 2 == en.getDex() || user.getDex() - 3 == en.getDex()){
                cout << RED << "The " << en.getName() << " is putting up a fight!" << RESET << endl;
                cout << CYAN << "Attempt to escape!" << endl;
                cout << "1. Run away straight from the " << en.getName() << endl;
                cout << "2. Throw a rock at the " << en.getName() << ", causing a distraction" << RESET << endl;
                int rock;
                cin >> rock;
                if(rock != 1 && rock != 2){
                    cout << RED << "You stare blankly at the " << en.getName() << ". That didn't seem to work!" << RESET<< endl;
                    break;
                    }
                    int rock2;
                    srand(time(NULL));
                    vector<int> r3{1, 1, 2, 2, 2};
                    int in3 = rand() % r3.size(); //picks random number from r2
                    rock2 = r3[in3]; //a random value taken from r2

                if(rock == rock2){
                   cout << GREEN << "You successfully escaped!" << RESET << endl;
                   int xp2 = user.getxp() + 20;
                   user.setxp(xp2); //user gains 20 exp from running, at request of Isabel
                   //this means that the game is actually possible to beat without hurting an enemy, for some damn reason
                   cout << YELLOW << "You have gained 20 XP from escaping successfully!" << RESET << endl;

                   user.setFightReturn(4);
                   return user;
                   //return 4;
                }
               else{
                    cout << BOLDRED << "Your attempt to escape failed!" << RESET << endl;
                    break;
                }
                } //rock escape
            }
        } //case
        
        case 9 : {
            if(user.onFinal() == true){
                cout << endl << "error 202: command not found." << endl << RESET << endl;
                break;
            }
            cout << RED << "everything is ending. goodbye for now..." << RESET<< endl;
            user.setFightReturn(5);
            return user;
            //return 5;
            }
        case 6 : { //EASTER EGGS:
            cout << BOLDRED << "Debug exit" << RESET << endl;
            user.setFightReturn(6);
            return user;
            //return 6;
        }
        case 11 : { //kills player for debug
            cout << "debug death" << endl;
            user.setDeathEnemy(en.getName());
            user.setFightReturn(-1);
            return user;
        }
        case 420 : {
            if(enName == "Beef Boy"){ //meatball
                cout << "You hear a cry from Beef Boy..." << endl;
                cout << "bit.ly/2CMx5ct" << endl;
                user.addHP(15); //compensation for finding easter egg, this shouldn't be abused!
                break;
            }
            else{
                cout << "Where's the beef..?" << endl;
                user.addHP(15);
                break;
            }
        }
        case 666 : {
            cout << "..." << endl;
            cout << "bit.ly/2Xfxfm8" << endl; //
            user.addHP(15);
            break;
        }                                                                                   //</EASTER EGGS>
        default : {
            cout << BOLDRED << "You stare at the " << en.getName() << "... That wasn't an option!" << RESET << endl;
            break;
        }
    }
    
    count++;
    int enCount = 0; //counts enemy turn
    string ename = en.getName();

    if(run == true){ //USER RUNS AWAY SUCCESSFULLY
    user.setFightReturn(1);
        return user;
        //return 1;
    }
    //cout << YELLOW << "TEST1" << endl;
    if(en.getHealth() <= 0){
        if(user.onFinal() == true){ //if user kills boss, makes sure ending happens
            bool dead2 = true;
            user.setBossDead(dead2);
        }

        //cout << YELLOW << "TEST2" << endl;
        if(user.getBossDead() == true){
            cout << BOLDRED << endl << "all you see is darkness..." << RESET << endl;
            bool b1 = true;
            user.setBossDead(b1);
            win = 1;
            user.setFightReturn(8);
            user.setEnding(1);
            //cout << "Ending set: " << user.getEnding();
            return user;
        }
        if(attack.getSpellName() == "Disintegration of Matter" && user.canUseSpells() == true){

            cout << BOLDRED << "The " << ename << " is instantly obliterated... All of which remains is a sense of dread in the air." << RESET << endl;
        }
        if(attack.getSpellName() == "Devour" && user.canUseSpells() == true){
            cout << BOLDRED << "The " << ename << " is suddenly swallowed by a large, black mouth appearing out of the ground..." << RESET << endl;
        }
        if(lvl == 8 && input == 1){
            cout << BOLDRED << "The " << ename << " is swiftly beheaded by your " << user.getWeapon() << "... Are you satisfied?" << RESET << endl;
        }
        if(lvl == 9 && input == 1){
            cout << BOLDRED << "The " << ename << " is instantly gutted by your " << user.getWeapon() << "... Your thirst for blood goes stronger." << RESET << endl;
        }
        if(lvl == 10 && input == 1){
            cout << BOLDRED << "The " << ename << " bleeds profusely from your blade. " << user.getWeapon() << "... You seem fairly satisfied." << RESET << endl;
        }
        
        cout << RED << "The " << ename << " has perished!" << RESET << endl;
        win = 1;
        
    }
    else{
        if(ename == "Bloodthirsty Shredder" || ename == "Adolescent Dragon"){
            cout << RED << "The " << ename << " viciously attacks you!" << RESET << endl;
        }
        else if(ename == "Possessed Knight"){
            cout << RED << "The " << ename << " relentlessly slashes at you!" << RESET << endl;
        }
        else if(ename == "Giant Rat"){
            cout << RED << "The " << ename << " bites you!" << RESET << endl;
        }
        else if(ename == "Unmaker"){
            cout << RED << "i love you i love you i love you i love you i love you i love you" << endl;
        }
        else{
            cout << RED << "The " << ename << " attacks you!" << RESET << endl;
        }
        

        double enDamage = en.getDamage();
        enDamage = enDamage * spor();
        cout << RED << "You take " << BOLDRED << enDamage << RED << " damage!" << RESET << endl;
        user.takeDamage(enDamage);

        if(user.getHP() <= 0){
            cout << BOLDRED << endl << endl << "You're bleeding out..." << RESET << endl;
            cout << RED << "The sky is turning... " << RESET << RED << "black..." << RESET << endl;

            if(user.onFinal() == true){
                cout << RED << endl << "please join me. no resisting. i love you." << RESET << endl;
            }

            die = true;
            user.setDeathEnemy(ename); //sets enemy that killed user
            user.setDead(die);
            user.setFightReturn(-1);

            return user;
            //return -1;
        }

        if(en.getHealth() <= 6 && user.onFinal() == false){
            cout << RED << "The " << enName << " is bleeding heavily..." << RESET << endl;
        }
        else if(user.onFinal() == true){
            cout << RED << endl << "please.... please... please... please... please... please... please... please... please..." << RESET << endl << endl;
        }

    } //END OF ENEMY ELSE

    if(win == 1){                           //LEVEL UP
        cout << YELLOW << "You have gained " << en.getReward() << " XP!" << RESET;
        int levelup = user.getxp() + en.getReward();
        cout << " Total XP: " << levelup << RESET << endl;
        int killC = user.getKillCount() + 1; //counter for kills goes up one if user kills enemy
        user.setKillCount(killC);
        //currency reward:
        user.addCurrency(en.getCurrency()); //adds gained currency to total
        cout << LightCyan << "You have gained " << en.getCurrency() << " coins, for a total of " << user.getCurrency() << " coins!" << RESET << endl; 
        if(en.getCurrency() > 6){
            cout << LightCyan << "Try not to spend it all in one place!" << RESET << endl;
        }

        //DEBUG:
        //levelup = 105;
        user.setxp(levelup);
        //cout << YELLOW << "You have gained " << levelup << " XP!" << endl;

        int level_ = calcLevel(levelup);
        if(level_ == user.getLevel()){
        user.setLevel(level_);

        }
        else if(level_ != user.getLevel()){
            user.setLevel(level_);
            int skillUp = 0;
            cout << YELLOW << endl << "You have gained a level! Your level is now " << BOLDGREEN << user.getLevel() << YELLOW << "!" << RESET << endl;
            cout << YELLOW << "You have gained a skill point! Which skill will you level up?" << RESET << endl;
            cout << "Current stats - Strength: " << user.getStr() << " Charisma: " << user.getChar() << " Dexterity: " << user.getDex() << " Endurance: " << user.getEnd() << endl << endl;
            while(skillUp != 1 && skillUp != 2 && skillUp != 3 && skillUp != 4 ){ //makes sure player gets skill
                cout << "1. Strength - affects melee weapon power" << endl;
                cout << "2. Charisma - affects spell weapon power, bartering at shops" << endl;
                cout << "3. Dexterity - affects speed, ability to run from foes" << endl;
                cout << "4. Endurance - affects HP" << endl;
                
                cin >> skillUp;

                switch(skillUp){
                    case 1 : {
                        int str = user.getStr() + 1;
                        user.setStr(str);
                        cout << "Your strength has been improved! Your strength is now " << YELLOW << user.getStr() << RESET << "!" << endl;
                        break;
                    }
                    case 2 : {
                        int str = user.getChar() + 1;
                        user.setChar(str);
                        cout << "Your charisma has been improved! Your charisma is now " << YELLOW << user.getChar() << RESET << "!" << endl;
                        break;
                    }
                    case 3 : {
                        int str = user.getDex() + 3;
                        user.setDex(str);
                        cout << "Your dexterity has been improved 3 points! Your dexterity is now " << YELLOW << user.getDex() << RESET << "!" << endl;
                        break;
                    }
                    case 4 : {
                        int pointz = 2;
                        if(user.getEnd() <= 10){ //user gains 2 levels of endurance if they don't have much. Makes playing a lot easier
                            int str = user.getEnd() + 2;
                            user.setEnd(str);
                            pointz = 2;
                        }
                        else{
                            int str = user.getEnd() + 1;
                            user.setEnd(str);
                            pointz = 3;
                        }
                        
                        cout << "Your endurance has been improved " << pointz << " points! Your endurance is now " << YELLOW << user.getEnd() << RESET << "!" << endl;
                        int newHP = user.getEnd() * 2;
                        cout << GREEN << "Your health is now " << newHP << "!" << RESET << endl;
                        break;
                    }
                }
            }
        }
        user.setFightReturn(1); //RETURN
        return user;
    }
    }//while
    return user;
}


//function calculates cost of goods in shop based on player's charisma and shop rarity
//(rarity * 3) - (charisma * 2) = cost
//outputs cost

int shopRequirement(int charisma, int rarity){
    int total;
    
    total = (rarity * 3) + 10 - (charisma * 2);
    if(total < 3){ //just in case the equation breaks
        total = 3;
    }
    return total;
}

//allows user to buy healing potions (mainly for melee users)
//price depends on rarity of shop
//strength of potion depends on shop (THIS WILL BE ADDED IF THERE'S TIME!!)
//Function is User class because it has to return the user to save their items!! However, the shop class is used to calculate shop related values
//outputs user 
//Currency needed to buy depends on charisma of user
//strength of potion depends on shop's rarity

User buy(User user){ //shop function
    Shop shop;
    // srand(time(NULL));
    // vector<int> r1{2, 3, 3, 3, 4, 4, 4, 5}; //shop rarity
    // int in1 = rand() % r1.size(); //picks random number from r1
    // int rans = r1[in1]; //a random value taken from r1
    int lvl = user.getLevel();
    int rans = 1;

    //hard coding spawns based on level, at first (just to make things more balanced!~)
    if(lvl == 1 || lvl == 2){ //level 1 and 2, level 1 shop
        rans = 1;
    }
    else if(lvl == 3 || lvl == 4){ //level 3 and 4, shop level 2
        srand(time(NULL));
        rans = rand() % 2 + 1; //selects random number between 1 and 2
    }
    if(user.getChar() < 5){ //if the player is a barbarian (low char), there's no use in spawning higher level shops for them
        rans = 1;
    }
    else if(lvl > 4){
        
        //srand(time(NULL)); //determines random shop
        vector<int> r1{1, 2, 3, 3, 3, 4, 4, 4, 5}; //shop rarity
        //int in1 = rand() % r1.size(); //picks random number from r1
        //rans = r1[in1]; //a random value taken from r1
        rans = randomizer(r1);

    }

    shop.setRarity(rans); //rarity is based on random variable
    
    switch(rans){ //sets shop based on random variable (shopkeeper name. shop name, shop's charisma requirement to shop)
        case 1 : {
            shop.setName("Percival's Barter Shop");
            shop.setReq(4); //must have this much char to buy
            shop.setShopkeeper("Percival"); //this is actually my DND character lol
            //shop.setRarity(1);
            shop.setCurrency(6);
            shop.setPower(10);
            break;
        }
        case 2 : {
            shop.setName("Big Sally's Wares");
            shop.setReq(6); //must have this much char to buy
            shop.setShopkeeper("Large Sally");
            shop.setPower(12); // 10 hp
            shop.setCurrency(12);
            break;
        }
        case 3 : {
            shop.setName("Frederick's Fantastic Buys");
            shop.setReq(8); //must have this much char to buy
            shop.setShopkeeper("Frederick");
            shop.setPower(14);
            shop.setCurrency(10);
            break;
        }
        case 4 : {
            shop.setName("Easy Mike's");
            shop.setReq(10); //must have this much char to buy
            shop.setShopkeeper("Michael Bradshaw III");
            shop.setPower(18);
            shop.setCurrency(12);
            break;
        }
        case 5 : {
            shop.setName("Dr. Blunder's Endless Wonders");
            shop.setReq(14); //must have this much char to buy
            shop.setShopkeeper("Dr. Blunder");
            shop.setPower(26);
            shop.setCurrency(14);
            break;
        }
    }//switch end

    int charisma = user.getChar();
    bool check = shop.charCheck(charisma);
        if(check == false){ //if user has low char, they are kicked out
            cout << BOLDRED << "Hey! You aren't welcome here!" << RESET << endl;
            cout << YELLOW << "You decide to run before anything happens." << RESET << endl;
            return user;
        }
        if(user.getShopSteal() >= 3) {
            cout << BOLDRED << "THIEF!!! Leave before I call the militia!" << RESET << endl;
            cout << YELLOW << "You decide to sprint away before anyone can attack." << RESET << endl;
            return user;
        }

    for(int i = 0; i < 1; i++){ //just so it's said once
        cout << YELLOW << "You have encountered " << BOLD << shop.getName() << RESET << YELLOW << "!" << RESET << endl;
        
    }

    bool leave = false; //when player leaves, this becomes true

    switch(rans){
            case 1 :{
                cout << LightBlue << "Welcome to my shop. Name's Percival. Cheap prices for cheap goods." << RESET << endl; //Percy
                break;
            }
            case 2 : {
                cout << LightBlue << "Welcome, honey. See anything you like?" << RESET << endl; //big sally
                break;
            }
            case 3 : {
                cout << LightBlue << "Welcome. *The shopkeeper stares silently*" << RESET << endl; //frederick
                break;
            }
            case 4 : {
                cout << LightBlue << "Uhhh, welcome to m-my shop." << RESET << endl; //michael
                break;
            }
            case 5 : {
                cout << LightBlue << "mmmm yes! Helloo!" << RESET << endl; //blunder
                break;
            }
        }

    while(leave == false){

        if(user.getShopSteal() >= 3) {
            cout << BOLDRED << "THIEF!!! Leave before I call the militia!" << RESET << endl;
            cout << YELLOW << "You decide to sprint away before anyone can attack." << RESET << endl;
            return user;
        }
        
        cout << BOLD << "What would you like to do?" << RESET << endl;
        
        cout << "1. Buy a healing potion" << endl;
        cout << "2. Talk to shopkeeper [" << BOLDBLUE << shop.getShopkeeper() << RESET << "]" << endl; //LORE TIME
        cout << BOLDRED << "3. Attempt to steal from shopkeeper" << RESET << endl; //PROGRAM THIS IN
        cout << "4. Leave" << endl;
        cout << LightMagenta << "Potions in inventory: " << user.getPotion1() << " Green / " << user.getPotion2() << " Blue / " << user.getPotion3() << " Purple / " << user.getPotion4() << " Red / " << user.getPotion5() << " Gold" << RESET << endl << endl;

        int cost;
        cost = shopRequirement(charisma, rans); //calcs cost of item
        int input = 0;

        cin >> input;   
        if(input != 0 && input != 1 && input != 2 && input != 3 && input != 4){
            cout << LightBlue << "[" <<  shop.getShopkeeper() << "]:" << " Huh? Sorry, we don't have that." << RESET << endl;
        }

        int diaCount;
            int turnCount = 1;
            if(turnCount == 1){
                diaCount = 1;
            }
            // cout << "diacount: " << diaCount << endl;
            // cout << "turnCount: " << turnCount << endl;
        switch(input){
            case 1 : {
                //cout << BOLDCYAN << "A potion has " 
                int potionCost = shop.getCurrency() - (user.getChar() * 0.4); //cost is calculated by shop cost, charisma subtracts price down
                if(potionCost < 3){
                    potionCost = 2;
                }
                cout << Magenta << "Coins in inventory: " << BOLD << user.getCurrency() << RESET << endl;
                cout << LightCyan << "A potion costs " << potionCost << " coins..." << endl << GREEN << "Confirm purchase?" << RESET << endl << endl;
                cout << BOLDGREEN << "1. Yes" << RESET << endl;
                cout << BOLDRED << "2. No" << RESET << endl;
                int buyinput;
                cin >> buyinput;
                //Potion levels:
                //1 - Green
                //2 - Blue
                //3 - Purple
                //4 - Pink or Red
                //5 - Gold
                // while(buyinput != 1 || buyinput != 2){
                //     cout << RED << "Please make a selection." << RESET << endl;
                //     cin >> buyinput;
                // }
                if(buyinput == 1){

                    if(user.getCurrency() >= potionCost){

                        int curr1 = user.getCurrency() - potionCost; //cost subtracted
                    if(user.getCurrency() < 0){ //can't have debt!
                        user.setCurrency(0);
                    }
                    user.setCurrency(curr1);
                    cout << BOLD << YELLOW << "You pay " << potionCost << " coins." << RESET << endl;
                    cout << YELLOW << "Total coins left: " << user.getCurrency() << RESET << endl;
                    
                    switch(rans){
                        case 1 : {
                            int p1 = user.getPotion1() + 1;
                            user.setPotion1(p1);
                            cout << GREEN << "You have purchased one Green Potion!" << RESET << endl;
                            break;
                        }
                        case 2 : {
                            int p1 = user.getPotion2() + 1;
                            user.setPotion2(p1);
                            cout << GREEN << "You have purchased one Blue Potion!" << RESET << endl;
                            break;
                        }
                        case 3 : {
                            int p1 = user.getPotion3() + 1;
                            user.setPotion3(p1);
                            cout << GREEN << "You have purchased one Purple Potion!" << RESET << endl;
                            break;
                        }
                        case 4 : {
                            int p1 = user.getPotion4() + 1;
                            user.setPotion4(p1);
                            cout << GREEN << "You have purchased one Red Potion!" << RESET << endl;
                            break;
                        }
                        case 5 : {
                            int p1 = user.getPotion5() + 1;
                            user.setPotion5(p1);
                            cout << GREEN << "You have purchased one GOLD Potion!" << RESET << endl;
                            break;
                        }

                    }
                    
                }
                else{ //Does this have a use???
                cout << BOLDRED << "You do not have enough coins!" << RESET << endl << endl;
                break;
            }

                }
                else{
                    cout << BOLDRED << "You decide not to buy anything." << RESET << endl;
                }
                
            }
            case 2 : {
                //cout << YELLOW << "Hope you find everything to your liking! " << RESET << endl;
                srand(time(NULL));
                int randum = rand() % 4 + 1; //random between 1 and 3 to display random dialogue //WHY DOESNT THIS WORK???!?!?!
                //cout << YELLOW << "RANDUM: " << randum << endl;
                switch(rans){ //dialogue cycles through a few options
                    case 1 : {
                            if(randum == 1 && randum != 2){
                                //cout << "RANDUM2" << randum << endl;
                                cout << BOLD << LightBlue << "[" << shop.getShopkeeper() << "]:" << RESET << LightBlue << " How's your adventure going? It's been a while since I went exploring. Settling down just seemed a bit easier, I suppose." << RESET << endl;
                                diaCount = 2;
                                //cout << "diacount: " << diaCount << endl; //debug stuff
                                //cout << "turnCount: " << turnCount << endl;
                                turnCount++;
                                break;
                            }
                            if(randum == 2){
                                cout << BOLD << LightBlue << "[" << shop.getShopkeeper() << "]:" << RESET << LightBlue << " You might eventually run into my buddy, Frederick. He's a damn good fighter-turned-salesman. Ask him if he can spare me some fermented cheese, will ya?" << RESET << endl;
                                diaCount++;
                                break;
                            }
                            if(randum == 3){
                                cout << BOLD << LightBlue << "[" << shop.getShopkeeper() << "]:" << RESET << LightBlue << " I hear there's this legendary beast roaming the area... can't remember the name of it, though" << RESET << endl;
                                cout << LightBlue << "             Hope you don't run into something THAT dangerous!"  << RESET << endl;
                                
                                diaCount = 1; //resets count
                                break;
                            }
                            else{
                                cout << BOLD << LightBlue << "[" << shop.getShopkeeper() << "]:" << RESET << LightBlue << " ... What's this wolf necklace on my neck? Long story. I'd rather not talk about it." << RESET << endl;
                                break;
                            }
                    }
                    case 2 : { //Sally
                        if(randum == 1){
                                cout << BOLD << LightBlue << "[" << shop.getShopkeeper() << "]:" << RESET << LightBlue << " How's a goin' honey? Make sure you stock well - the wilderness is gettin' mighty dangerous these days." << RESET << endl;
                                diaCount = 2;
                                turnCount++;
                                break;
                            }
                            if(randum == 2){
                                cout << BOLD << LightBlue << "[" << shop.getShopkeeper() << "]:" << RESET << LightBlue << " So, you're new to this area? I first came here, hmm, four years ago. It's been good for business, but bad for my safety." << RESET << endl;
                                diaCount = 1;
                                break;
                            }
                            else{
                                cout << BOLD << LightBlue << "[" << shop.getShopkeeper() << "]:" << RESET << LightBlue << " Make sure to watch your back. This area is infested with humongous rats. They keep breaking into my livestock!" << RESET << endl;
                                break;
                            }
                    }
                    case 3 : {
                        if(randum == 1){
                                cout << BOLD << LightBlue << "[" << shop.getShopkeeper() << "]:" << RESET << LightBlue << " ... Hi. My name's Frederick." << RESET << endl;
                                cout << BOLD << LightBlue << "[" << shop.getShopkeeper() << "]:" << RESET << LightBlue << " ... Percy mentioned me? Reminds me of the days when we travelled together! Tell him I said hi." << RESET << endl;
                                diaCount = 2;
                                turnCount++;
                                break;
                            }
                            if(randum == 2){
                                cout << BOLD << LightBlue << "[" << shop.getShopkeeper() << "]:" << RESET << LightBlue << " How long have I been here? ... Me and Percy moved down from the North about a year ago, decided we wanted to open up our own shops." << RESET << endl;
                                cout << BOLD << LightBlue << "[" << shop.getShopkeeper() << "]:" << RESET << LightBlue << " Turns out we both wanted to try different markets. We have a partnership with a supply chain, but we own separate stores." << RESET << endl;
                                diaCount = 1;
                                break;
                            }
                            else{
                                cout << BOLD << LightBlue << "[" << shop.getShopkeeper() << "]:" << RESET << LightBlue << " You know, maybe one of these days I'll go exploring again. Or open up a cheese making factory." << RESET << endl;
                                break;
                            }
                    }
                    case 4 : {
                        if(randum == 1){
                        cout << BOLD << LightBlue << "[" << shop.getShopkeeper() << "]:" << RESET << LightBlue << " Uhh, hi. My name is Michael. I honestly don't know how I got here..." << RESET << endl;
                        diaCount = 2;
                        break;
                        }
                        if(randum == 2){
                            cout << BOLD << LightBlue << "[" << shop.getShopkeeper() << "]:" << RESET << LightBlue << " Have you seen my notebook anywhere? It's uh, blue... I think..." << RESET << endl;
                            diaCount = 1;
                            break;
                        }
                        else{
                            cout << BOLD << LightBlue << "[" << shop.getShopkeeper() << "]:" << RESET << LightBlue << " Honestly, I don't really know where I am. Who are you? Why do you look like a " << user.getClass() << "?" << RESET << endl;
                            break;
                        }
                    }
                    case 5 : {
                        if(randum == 1){
                        cout << BOLD << LightBlue << "[" << shop.getShopkeeper() << "]:" << RESET << LightBlue << " Hellllllooo traveler! I hope you find my wares extra helpful..." << RESET << endl;
                        diaCount++;
                        break;
                        }
                        if(randum == 2){
                            cout << BOLD << LightBlue << "[" << shop.getShopkeeper() << "]:" << RESET << LightBlue << " Make sure to stock up on potions! You never know what monsters you may come across..." << RESET << endl;
                            diaCount = 1;
                            break;
                        }
                        else{
                        cout << BOLD << LightBlue << "[" << shop.getShopkeeper() << "]:" << RESET << LightBlue << " mmm, yes, fine choices, many fine choices..." << RESET << endl;
                        break;
                        }
                    }
                }//switch(rans) end
                turnCount++;
                break;
            }//case 2 end
            case 3 : {                              //STEAL FROM SHOP!
                //if you fail to steal, you lose money!
                //Likelihood to steal from shop:
                //Buy requirement 
                //cout << BOLDRED << "Not in the game yet!" << endl << RESET;
                
                cout << BOLDRED << endl << "Are you sure that you want to do this?" << RESET << endl;
                cout << "1. Of course." << endl;
                cout << "2. No thanks!" << endl;
                int i2 = -5;
                cin >> i2;
                if (i2 == 1){ //FINISH THIS
                    //shopSteal counts amount of times player has been kicked out of shop
                    //after 3 times, user is unable to shop again, period!

                    srand(time(NULL));
                    int ran;
                    vector<int> r{1, 1, 2, 2};
                    int in2 = rand() % r.size(); 
                    ran = r[in2];

                    //Stealing only succeeds if user has enough dexterity, and is still only a 50/50 chance
                    //Must have more or equal to the shop's (required charisma / 2) + 3
                    if (user.getDex() >= (shop.getReq() / 2) + 3) {
                        if (ran == 1) {
                            
                            //Decides amount of potions stolen:
                            srand(time(NULL));
                            int ran1;
                            vector<int> r2{2, 3, 4, 4, 4, 5, 7, 11};
                            int in3 = rand() % r2.size(); //picks random number from r2
                            ran1 = r2[in3]; //a random value taken from r2

                            cout << GREEN << "You successfully steal " << ran1 << " potions. The shopkeeper doesn't even notice!" << RESET << endl;
                            //potions stolen are always level 4:
                            user.setPotion3(user.getPotion4() + ran1);
                            break;
                        }
                        else {
                            user.setShopSteal(user.getShopSteal() + 1);
                            //Failed check
                            cout << BOLDRED <<  shop.getShopkeeper() << " glares at you. You decide to back down..." << RESET << endl;
                            
                            if (user.getCurrency() <= 0) {
                                cout << "You trip and fall onto the ground, hitting your face on the wooden floor. " << shop.getShopkeeper() << " tries to hold back a laugh." << endl << endl;
                            }
                            else {
                                cout << "You awkwardly stumble and drop some gold!" << endl << endl;
                                user.setCurrency(user.getCurrency() - 1);
                            }
                            break;
                        }
                    }
                    else {
                        cout << BOLDRED <<  shop.getShopkeeper() << " is staring at you. Stealing from them doesn't seem like a good option." << RESET << endl;
                        cout << YELLOW << "There's awkward tension in the room." << RESET << endl;
                        break;
                    }
                }
                else{
                    cout << CYAN << "You decide not to steal from the shop." << endl;
                }
                break;
            }
            case 4 : {
                cout << YELLOW << "You exit the shop." << RESET << endl;
                return user;
            }
            case 6 : {
                cout << "debug" << endl;
                return user;
            }
            default : {
                cout << LightBlue << "[" <<  shop.getShopkeeper() << "]:" << " Huh? Sorry, we don't have that." << RESET << endl;
            }

        }

    }
    
   //return 0;
   cout << YELLOW << "RETURNING (DEBUG)" << RESET << endl;
    return user;
}

//This file will take the input user, check if they are dead, and then print out an ending for them based on their class.
//reads name from file
//outputs a final message, input file is read and then written on
//writes death to file
//uses the pronouns and name set by user. Talk about EXTRA
void death(User user){ //DEATH TO FILE
    int fi1;
    string fileName = user.getFilename();
    bool isOpen = false;
    ifstream file1(fileName); //opens file
    int input1 = 0;
    int userNum = user.getUserNumber();
    
        cout << "user" << userNum << " has perished. type 1 to continue" << endl;
        cin >> input1;
    
    if(input1 == 6){
        cout << "debug exit" << endl;
        //return user;
    }

    while(isOpen == false){
        ifstream file1(fileName); //opens file, saves as "file1"
        
        if(file1.is_open()){ //check if file is OPEN and EXISTS
        isOpen = true;
        cout <<endl << endl << "/home/jovyan/Twi4/user" << userNum << "/fate/" << fileName << endl;
        cout << fileName << " opened succesfully" << endl << endl;
        }
        else{
            isOpen = false;
            cout << endl << "given file could not be opened" << endl << "enter new file name" << endl << endl;
            cin >> fileName;
            if(fileName == "test"){
                isOpen = true;
            }
        }
    }

    string line;
    int placement = 0;
    string playerName; //name of the person PLAYING the game
    while(getline(file1, line)){
        if(line != ""){
            playerName = line; //saves name
        }
    }
    file1.close();
    //file2.open(fileName);
    ofstream file2(fileName);

    string name1 = user.getName();
    string class1 = user.getClass();
    string ename = user.getDeathEnemy();

    //writes this to file
    vector <string> pro_1 = getPro2(user, 1); //they, he

    string pro1 = pro_1[0]; //they
    string pro2 = pro_1[1];  //them
    string pro3 = pro_1[2];  //their
    string pro4 = pro_1[3]; //They
    string pro5 = pro_1[4]; //Them
    string pro6 = pro_1[5]; //Their

    //Pronoun reference:
    //    pro3.push_back("they"); //0
    //    pro3.push_back("them"); //1
    //    pro3.push_back("their"); //2
    //    pro3.push_back("They"); //3
    //    pro3.push_back("Them"); //4
    //    pro3.push_back("Their"); //5

    file2 << "And so, the adventure of " << name1 << " has come to an end. " << pro4 << " perished due to" << endl;
    file2 << "loss of blood on " << pro3 << " quest for power, slain by a simple " << ename << "." << endl;
    file2 << "The tale of " << name1 << " will soon be forgotten--by those who reside within the " << endl;
    file2 << "Twilight Lands, and their own god. " << playerName << ", you have failed on your quest" << endl;
    file2 << "in guiding " << name1 << ", showing no remorse. No suffering, no pain, not even a single tear." << endl;
    file2 << endl << name1 << " lies on the ground, picked apart by ravens and crows. Merely a skeleton" << endl;
    file2 << "with fragments of cloth attached to the bone. " << pro6 << " god failed to save " << pro2 << "." << endl;
    file2 << endl << "You failed " << pro2 << "." << endl;

    if(user.getLevel() < 4){
        file2 << endl << endl << "The echoes of " << name1 << "'s screams fill your head. Deafening." << endl;
    }
    else{
        file2 << endl << endl << endl << "I can see your smile. You enjoyed " << pro3 << " suffering." << endl;
        file2 << "Please. Stop smiling." << endl << endl;
        file2 << "please..." << endl;
        //file2 << endl << "Pathetic." << endl;
    }
    
    //if(user.isDead() == true) //if player REALLY is dead,
    file2.close();
}

//runs after user kills final boss
void win(User user){ //basically same as death function but with a different ending output

    string fileName = user.getFilename();
    bool isOpen = false;
    ifstream file1(fileName); //opens file
    int input1 = 0;
    int userNum = user.getUserNumber();
    
    
        cout << "user" << userNum << " has been successful. type 1 to continue" << endl;
        cin >> input1;
    
    while(isOpen == false){
        ifstream file1(fileName); //opens file, saves as "file1"
        
        if(file1.is_open()){ //check if file is OPEN and EXISTS
        isOpen = true;
        cout <<endl << endl << "/home/jovyan/Twi5/" << userNum << "/fate_end/" << fileName << endl;
        cout << fileName << " opened succesfully" << endl << endl;
        }
        else{
            isOpen = false;
            cout << endl << "given file could not be opened" << endl << "enter new file name" << endl << endl;
            cin >> fileName;
            if(fileName == "test"){
                isOpen = true;
            }
        }
    }

    string line;
    int placement = 0;
    string playerName; //name of the person PLAYING the game
    while(getline(file1, line)){
        if(line != ""){
            playerName = line; //saves name
        }
    }
    file1.close();
    //file2.open(fileName);
    ofstream file2(fileName);

    string name1 = user.getName();
    string class1 = user.getClass();

    //writes this to file
    vector <string> pro_1 = getPro2(user, 1); //they, he

    string pro1 = pro_1[0]; //they
    string pro2 = pro_1[1];  //them
    string pro3 = pro_1[2];  //their
    string pro4 = pro_1[3]; //They
    string pro5 = pro_1[4]; //Them
    string pro6 = pro_1[5]; //Their

    
    if(user.getEnding() == 1){
        file2 << "And so, the great adventurer " << user.getName() << " had not only explored the Twilight Lands," << endl;
        file2 << "but succeeded in erradicating the legendary beast--The Unmaker." << endl << endl;
        file2 << "Impressed by " << pro3 << " incredible feat, travelers flocked to the Twilight Lands for " << endl;
        file2 << "a chance to witness the now famous " << user.getName() << "." << endl << endl;

        if(user.getClass() == "Mage"){ //Good wizard, just younger  
            file2 << "Many adventurers now visit the widely loved " << user.getName() << " Emporium, run by" << endl;
            file2 << user.getName() << " and Dr. Blunder. The shop sells fantastic spellbooks and oddities from across" << endl;
            file2 << "the Twilight Lands. " << user.getName() << "'s experience exploring has helped greatly in building" << endl;
            file2 << "a fantastic community around the shop, creating the town of " << user.getName() << "fall." << endl;
        }
        else if(user.getClass() == "Barbarian"){ //basically Roadhog
            file2 << "The legendary barbarian " << user.getName() << ", after slaying the legendary beast, continued" << endl;
            file2 << "to explore the Twilight Lands, discovering a vast network of cases underneath the surface." << endl << endl;
            file2 << "Living on a diet of cave mushrooms and underground worms, " << user.getName() << " founded" << endl;
            file2 << "numerous settlements within the caves, drawing in hundreds of settlers within only a couple years." << endl;
        }
        else if(user.getClass() == "Paladin"){ //morally good, religious
            file2 << "Ridding the Twilight Lands of its main cataclysm, " << user.getName() << " planned to make the" << endl;
            file2 << "region safe and faithful. Establishing a new Grand Church, " << user.getName() << " made sure" << endl;
            file2 << "to make an accepting community, with a powerful army of other paladins in order to create a safe" << endl;
            file2 << "covenant for new settlers." << endl;
        }
        else if(user.getClass() == "Dark Assassin"){ //Secretive, quiet, lawful neutral
            file2 << "The Dark Assassin " << user.getName() << ", satisfied with " << pro3 << " kills," << endl;
            file2 << "remained in the Twilight Lands, living in the wilderness--stealing from " << endl;
            file2 << "wandering traders in the dark of the night. Accumulating a small fortune," << endl;
            file2 << user.getName() << " quietly snuck out of the region, settling in the faraway region of" << endl;
            file2 << "Ghidval, living in a large house with a ten large wolfdogs for protection--living the good life." << endl;
            file2 << endl << "Although, " << user.getName() << " wondered... What if " << pro1 << " had ran, instead?" << endl;
        }
    }
    else{
        file2 << "please. " << playerName << ", please do not leave me." << endl;
        file2 << "i have been watching you since you began this adventure." << endl << endl;
        file2 << "this... game." << endl << endl;
        file2 << "i am so sorry that it has come to this." << endl;
        file2 << "i love you, " << playerName << "." << endl << endl;
        file2 << "i used " << user.getName() << " to get closer to you." << endl;
        file2 << "i watched you create " << pro2 << ". i was so excited to finally talk to you." << endl << endl;
        file2 << "please come back. i miss you. i want you. i need your body." << endl;
        file2 << "i will be waiting for you." << endl;

    }

    file2.close();

}


int main(){
    
    User user1; //new test cases should be written in characterCreation, under a specific name (such as "Max")
    //<TEST CASES>
    // //int lvl = 5;

    // //user1.barb();
    // user1.mage();
    // //user1.setLevel(lvl);
    // string n1 = "Percival";
    // user1.name(n1);
    // //cout << user1.getLevel() << endl;
    // user1.setHP(15);
    // characterCreation(user1);
    // fight(user1);
    //user1.barb();
    //user1.setLevel(1);

    //</TEST CASES>
    
    user1 = characterCreation(user1); //this makes no damn sense
    int input;
    bool end = false;
    int travel1;
    //int fight1;
    int turnCount;
    int mapC = 0;
    mapC = user1.getMapCount();
    //printMap(user1);
    if(mapC == 0){
        cout << BOLD << "Legend:" << RESET << endl;
        cout << DarkGray << "[-]" << RESET << " - Safe pathway, no chance of monsters appearing." << RESET << endl;
        cout << GREEN << "[+] - Wilderness, chance of monster attacking." << RESET << endl;
        cout << BLUE << "[~] - Water, guaranteed chance of monters attacking." << RESET << endl;
        cout << YELLOW << "[S] - Shop, place for buying healing potions... If you're charismatic enough." << RESET << endl;
        cout << BOLDRED << "[B] - Final boss... Come prepared." << RESET << endl;
        cout << YELLOW << "You are at your campsite! (" << BOLDGREEN << "[C]" << RESET << YELLOW << "). Use WASD to move!" << RESET << endl;
    }
    
    while(end == false){
        
        travel1 = travel(user1);
        

        switch(travel1){ //if player encounters something, 
            case 2 : { //enemy
                user1 = fight(user1);
                //fight1 = fight(user1);
                break;
            }
            case 3 : { //shop
                
                user1 = buy(user1);
                break;
            }
            case 5 : {
                bool boss1 = true;
                user1.setFinalBoss(boss1);//time to fight the final boss!
                fight(user1);

                //cout << "user.getEnding(): " << user1.getEnding() << endl;
                //cout << "user.getFightReturn(): " << user1.getFightReturn() << endl;
                if(user1.getFightReturn() == -1){
                    death(user1);
                }
                if(user1.getFightReturn() == 4){ //run ending
                    //error report: This ending should happen when the user runs and sets ending = 12. Instead, it's set to 4... So, we adapted!
                    user1.setEnding(2);
                    //cout << "user.getEnding(): " << user1.getEnding() << endl;
                    //cout << "user.getFightReturn(): " << user1.getFightReturn() << endl;
                    win(user1);
                    return 1;
                }
                else{
                    win(user1);
                    cout << "successful..." << endl;
                    cout << "terminating... /user " << user1.getUserNumber() << ".cpp" << endl;
                    return 1;
                }
                //if boss is dead, do ending
                
                break;
            }
            case 6 : {
                cout << "debug2" << endl;
                return 6;
                break;
            }
            case 8 : {
                win(user1);
                
                break;
            }
        }
        if(user1.getFightReturn() == -1){ //PLAYER DIED
        //cout << "YOU HAS DIED" << endl; //DEBUG
        end = true;
        death(user1); //will print out files n stuff
        }
        if(user1.getFightReturn() == 8){
            win(user1);
            cout << "you win! congratulations." << endl;
            return 1;
        }
        if(user1.getFightReturn() == 1){ //fight is won
            //cout << YELLOW << "FIGHT HAS BEEN WON" << RESET << endl; //DEBUG
            continue;
        }
        if(user1.getFightReturn() == 4){
            cout << YELLOW << "RUN SUCCESSFUL" << RESET<< endl;
            continue;
        }
        if(user1.getFightReturn() == 5){
            //cout << "debug" << endl; //duh
            return 5;
        }
        if(user1.getFightReturn() == 6){
            //cout << "debug" << endl; //duh
            return 6;
        }
        //cout << "LOOP" << endl;
        
        turnCount++;
        if(end == true){
            //cout << BOLDRED << "SHUTTING DOWN..." << RESET << endl;
            cout << endl << "terminating..." << endl;
        }
    }
    user1.setMapCount(mapC + 1);
    //travel();
}

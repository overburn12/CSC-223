#include <string>
#include <cstdlib>
#include <time.h>
#include <iostream>

#ifndef CREATURE_H
#define CREATURE_H

class Creature{
    int strength; //How much damage we can inflict
    int hitpoints; //How much damage we can sustain

    //returns type of species
    std::string getSpecies() const;
public:

    //initialize strength to newStrength, hitpoints to newHit
    Creature(int newStrength, int newHit);

    //return the strength of the creature
    int getStrength() const;

    //return the current hitpoints of the creature
    int getHitpoints() const;

    //return damage amount from an attack
    //All creatures inflict damage, which is a random number up to their strength
    int getDamage() const;

    //sets the strength of the creature
    void setStrength(int newStrength);

    //sets the hitpoints of the creature
    void setHitpoints(int newHit);

    //returns true if the creature has any Hitpoints, returns false if hitpoints are 0
    bool isAlive();

    //adjust hitpoints from damage recieved
    void takeDamage(int damage);

    //print to the screen a message showing the hitpoints of the creature
    void printHitpoints();
};

#endif
#include "Creature.h"

#ifndef DEMON_H
#define DEMON_H

class Demon : public Creature{
public:
    //initialize creature
    Demon(int newStrength, int newHit);

    //Demon Creatures have a 5% chance of dealing 50 more damage
    int getDamage() const;
};

#endif
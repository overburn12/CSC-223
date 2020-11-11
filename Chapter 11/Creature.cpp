#include "Creature.h"

Creature::Creature (int newStrength, int newHit) : strength(newStrength), hitpoints(newHit) {}

int Creature::getDamage() const { return ((rand() % strength) + 1); }

int Creature::getStrength() const { return strength; }

int Creature::getHitpoints() const { return hitpoints; }

bool Creature::isAlive() { return (hitpoints != 0); }

void Creature::setStrength(int newStrength){ 
    if(newStrength < 0){
        strength = 0;
    }else{    
        strength = newStrength; 
    }
}

void Creature::setHitpoints(int newHit){
    if(newHit < 0){
        hitpoints = 0;
    }else{
        hitpoints = newHit;
    } 
}

#include "Human.h"

Human::Human() : Creature(10, 10) {}

Human::Human(int newStrength, int newHit) : Creature(newStrength, newHit) {}

std::string Human::getSpecies() const { return("Human"); }

int Human::getDamage() const {
    int damage;
    damage = Creature::getDamage();
    std::cout << getSpecies() << " attacks for " << damage << " points!" << std::endl;
    return ( damage );
}

void Human::takeDamage(int damage){
    setHitpoints(getHitpoints() - damage);
    printHitpoints();
    if( !isAlive() ){
        std::cout << getSpecies() << " has died!" << std::endl;
    }
}

void Human::printHitpoints(){
    std::cout << getSpecies() << " has " << getHitpoints() << " hitpoints" << std::endl;
}
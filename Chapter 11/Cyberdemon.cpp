#include "Cyberdemon.h"

Cyberdemon::Cyberdemon() : Demon(10, 10) {}

Cyberdemon::Cyberdemon(int newStrength, int newHit) : Demon(newStrength, newHit) {}

std::string Cyberdemon::getSpecies() const { return ("Cyberdemon"); }

int Cyberdemon::getDamage() const {
    int damage = Demon::getDamage();
    std::cout << getSpecies() << " attacks for " << damage << " points!" << std::endl;
    return ( damage );
}

void Cyberdemon::takeDamage(int damage){
    setHitpoints(getHitpoints() - damage);
    printHitpoints();
    if( !isAlive() ){
        std::cout << getSpecies() << " has died!" << std::endl;
    }
}

void Cyberdemon::printHitpoints(){
    std::cout << getSpecies() << " has " << getHitpoints() << " hitpoints" << std::endl;
}
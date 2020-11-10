#include "Elf.h"
Elf::Elf() : Creature(10, 10) {}

Elf::Elf(int newStrength, int newHit) : Creature(newStrength, newHit) {}

std::string Elf::getSpecies() const{ return("Elf"); }

int Elf::getDamage() const{
    int damage = Creature::getDamage();
    std::cout << getSpecies() << " attacks for " << damage << " points!" << std::endl;

    if( (rand() % 100) < 10 ){
        std::cout << "Magical attack inflicts " << damage;
        std::cout << " additional damage points!" << std::endl;
        damage *= 2;
    }
    return ( damage );
}

void Elf::takeDamage(int damage){
    setHitpoints(getHitpoints() - damage);
    printHitpoints();
    if( !isAlive() ){
        std::cout << getSpecies() << " has died!" << std::endl;
    }
}

void Elf::printHitpoints(){
    std::cout << getSpecies() << " has " << getHitpoints() << " hitpoints" << std::endl;
}
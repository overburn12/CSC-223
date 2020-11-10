#include "Balrog.h"

Balrog::Balrog() : Demon(10, 10) {}

Balrog::Balrog(int newStrength, int newHit) : Demon(newStrength, newHit) {}

std::string Balrog::getSpecies() const{ return ("Balrog"); }

int Balrog::getDamage() const{
    int damage1 = Demon::getDamage();
    std::cout << getSpecies() << " attacks for " << damage1 << " points!" << std::endl;

    int damage2 = Demon::getDamage();
    std::cout << getSpecies() << " speed attack inflicts " << damage2;
    std::cout << " additional points!" << std::endl;
    return ( damage1 + damage2 );
}

void Balrog::takeDamage(int damage){
    setHitpoints(getHitpoints() - damage);
    printHitpoints();
    if( !isAlive() ){
        std::cout << getSpecies() << " has died!" << std::endl;
    }
}

void Balrog::printHitpoints(){
    std::cout << getSpecies() << " has " << getHitpoints() << " hitpoints" << std::endl;
}

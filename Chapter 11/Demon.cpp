#include "Demon.h"

Demon::Demon(int newStrength, int newHit) : Creature(newStrength, newHit) {}

int Demon::getDamage() const {
    int damage = Creature::getDamage();
    if( (rand() % 100) < 5 ){
        std::cout << "Demonic attack inflicts 50 additional damage points!" << std::endl;
        damage += 50;
    }
    return damage;
}

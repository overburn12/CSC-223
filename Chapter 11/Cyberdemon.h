#include "Demon.h"

class Cyberdemon : public Demon {
    //returns the type of the species
    std::string getSpecies() const;
public:
    //initialize to 10 strength, 10 hitpoints
    Cyberdemon();

    //initialize to new strength, and new hitpoints
    Cyberdemon(int newStrength, int newHit);

    //All creatures inflict damage which is a random number up to their strength
    int getDamage() const;

    //adjust the hitpoints from an attack
    void takeDamage(int damage);

    //print to the screen a message showing the hitpoints of the creature
    void printHitpoints();

};
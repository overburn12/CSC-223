#include "Creature.h"

class Elf : public Creature{
    std::string getSpecies() const;
public:
    //initialize to 10 strength, 10 hitpoints
    Elf();

    //initialize to new strength, and new hitpoints
    Elf(int newStrength, int newHit);

    //All creatures inflict damage which is a random number up to their strength
    int getDamage() const;

    //adjust the hitpoints of the creature when taking damage
    void takeDamage(int damage);

    //print a message to the screen showing the hitpoints of the creature
    void printHitpoints();
};

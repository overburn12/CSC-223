#include "Creature.h"

class Human : public Creature{
    //returns the type of creature
    std::string getSpecies() const;
public:
    //initialize 10 to strength, 10 hitpoints
    Human();

    //initialize to new strength, new hitpoints
    Human(int newStrength, int newHit);

    //All creatures inflict damage which is a random number up to their strength
    int getDamage() const;

    //adjust the hitpoints of the creature when taking damage
    void takeDamage(int damage);

    //print a message to the screen showing the hitpoints of the creature
    void printHitpoints();
};
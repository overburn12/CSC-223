#include "Demon.h"

class Balrog : public Demon{

    //returns the type of creature
    std::string getSpecies() const;

public:
    //initialize to 10 strength, 10 hitpoints
    Balrog();

    //initialize to new strength and new hitpoints
    Balrog(int newStrength, int newHit);

    //All creatures inflict damage which is a random number up to their strength
    //balrogs are so fast they attack twice
    int getDamage() const;

    //adjust hitpoints from damage taken
    void takeDamage(int damage);

    //print a message to the screen showing the hitpoints of the creature 
    void printHitpoints();
};
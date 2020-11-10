#include <iostream>
#include <cstdlib>
#include <time.h>

#include "Creature.cpp"
#include "Demon.cpp"
#include "Balrog.cpp"
#include "Cyberdemon.cpp"
#include "Elf.cpp"
#include "Human.cpp"

template<typename X>
void doSelfAttack(X &theCreature){
    if( theCreature.isAlive() ){ 
        theCreature.printHitpoints();
        theCreature.takeDamage( theCreature.getDamage() ); 
        std::cout << '\n';
    }
} 

int main(){
    srand(time(0));
    int min_hitpoints = 250, max_hitpoints = 500;
    int min_strength = 50, max_strength = 100;

    #define __RND_STRENGTH ( rand() % (max_strength - min_strength) ) + min_strength
    #define __RND_HITPOINTS ( rand() % (max_hitpoints - min_hitpoints) ) + min_hitpoints

    Balrog theRog( __RND_STRENGTH, __RND_HITPOINTS );
    Cyberdemon theCyber( __RND_STRENGTH, __RND_HITPOINTS );
    Elf theElf( __RND_STRENGTH, __RND_HITPOINTS );
    Human theHuman( __RND_STRENGTH, __RND_HITPOINTS );

    int round = 1;
    std::cout << "\nWelcome to the Self-inflicted Battle Royale!\n" << std::endl;

    while( theRog.isAlive() || theCyber.isAlive() || theElf.isAlive() || theHuman.isAlive() ){
        std::cout << "----Round " << round << ", Fight!----\n" << std::endl;
        doSelfAttack(theRog);
        doSelfAttack(theCyber);
        doSelfAttack(theElf);
        doSelfAttack(theHuman);
        round++;
    }

    std::cout << "The Battle has ended!" << std::endl;

    return 0;
}

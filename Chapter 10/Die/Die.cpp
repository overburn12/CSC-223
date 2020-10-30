#include <stdlib.h>
#include <time.h>
#include "Die.h"

die::die(){
    Value = 1;
    srand(time(0));
}

int die::Show(){
    return Value;
}

void die::Roll(){
    Value = rand() % 6 + 1;
}
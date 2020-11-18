#include <iostream>
#include <stdlib.h>
#include "ClockType.hpp"

std::string TF(bool condition){
    if(condition)
        return "True";
    return "False";
}

#define log(x) std::cout << x << std::endl;

int main()
{

   ClockType alarm_clock(13,0,0), time_clock(12,0,0);

    std::cout << "Enter the current time: ";
    std::cin >> time_clock;

    std::cout << "Enter an alarm time: ";
    std::cin >> alarm_clock;

    if(time_clock > alarm_clock)
    {
        std::cout << "Current time is greater than alarm clock time";
        return 0;
    }

    while( time_clock < alarm_clock )
    {
        //std::system("cls");
        std::cout << "---------------------------\n";
        std::cout << "Current time: " << time_clock << std::endl;
        std::cout << "Alarm clock:  " << alarm_clock << std::endl;
        time_clock++;
    }

    std::cout << "The alarm has gone off!";


    return 0;
}
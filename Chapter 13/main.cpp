#include <iostream>
#include <stdlib.h>
#include "ClockType.hpp"

int main()
{
    ClockType alarm_clock, time_clock;
    char select_AM_PM;
    bool fast_mode = false, wrap_the_clock = false;

    std::cout << "Enter the following times using the format 00:00:00" << std::endl;

    std::cout << "Enter the current time: ";
    std::cin >> time_clock;

    std::cout << "Enter an alarm time: ";
    std::cin >> alarm_clock;

    std::cout << "Display AM/PM? Y / N > ";
    std::cin >> select_AM_PM;

    if(select_AM_PM == 'y' || select_AM_PM == 'Y')
    {
        time_clock.set_AM_PM_mode(true);
        alarm_clock.set_AM_PM_mode(true);
    }

    if( alarm_clock.get_total_seconds() - time_clock.get_total_seconds() > (45 * 60) )
    {
        fast_mode = true;
    }

    if(time_clock > alarm_clock)
    {
        fast_mode = true;
        wrap_the_clock = true;
    }

    do
    {
        if(fast_mode)
        {
            time_clock.increase_minutes(1);

            if(time_clock.get_total_seconds() < 60)
            {
                wrap_the_clock = false;
            }
        }
        else
        {
            time_clock++;
        }

        std::system("cls");
        std::cout << "Current time: " << time_clock << std::endl;
        std::cout << "Alarm clock:  " << alarm_clock << std::endl;
    }
    while( time_clock < alarm_clock || wrap_the_clock );

    std::cout << "----------------------\n";
    std::cout << "The alarm has gone off!";

    return 0;
}
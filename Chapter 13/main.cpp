#include <iostream>
#include <stdlib.h>
#include "ClockType.hpp"

int main()
{
    ClockType alarm_clock, time_clock;
    char select_AM_PM;
    bool fast_mode = false, wrap_the_clock = false;

    std::cout << "Alarm Clock Program - Chapter 13" << std::endl;
    std::cout << "Enter the following times using the format 00:00:00" << std::endl;

    std::cout << "Enter the current time: ";
    std::cin >> time_clock;

    std::cout << "Enter an alarm time: ";
    std::cin >> alarm_clock;

    std::cout << "Would you like to display AM/PM? Y / N > ";
    std::cin >> select_AM_PM;

    time_clock.set_AM_PM_mode(select_AM_PM == 'y' || select_AM_PM == 'Y');
    alarm_clock.set_AM_PM_mode(select_AM_PM == 'y' || select_AM_PM == 'Y');

    //If the difference in the alarm clock and time clock is greater than 45 minutes then use fast mode
    //or else you are going to be stuck waiting for a very long time
    fast_mode = alarm_clock.get_total_seconds() - time_clock.get_total_seconds() > 45 * 60;

    //if the alarm clock is before the time clock, we need to wait for the clock
    //to roll past midnight before we start comparing, and we also need to use fast mode
    fast_mode = fast_mode || time_clock > alarm_clock;
    wrap_the_clock = time_clock > alarm_clock;

    do
    {
        if(fast_mode)
        {
            //Fast mode we increase the minutes instead of the seconds
            time_clock.increase_minutes(1);

            //look to see if we have rolled over to midnight from the previous day
            if(time_clock.get_total_seconds() < 60)
            {
                wrap_the_clock = false;
            }
        }
        else
        {
            //just increase the clock by 1 seconds
            time_clock++;
        }

        std::system("cls");
        std::cout << "Current time: " << time_clock << std::endl;
        std::cout << "Alarm clock:  " << alarm_clock << std::endl;
    }
    while(time_clock < alarm_clock || wrap_the_clock);

    std::cout << "-----------------------\n";
    std::cout << "The alarm has gone off!";

    return 0;
}
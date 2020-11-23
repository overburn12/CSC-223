#include <string>
#include <iostream>

#ifndef H_CLOCKTYPE
#define H_CLOCKTYPE

class ClockType{
    //the time slots of the clock
    int hours, minutes, seconds;

    //Show AM/PM on output or regular 00:00:00
    bool show_AM_PM;
public:
    //default constructor
    ClockType() : hours(0), minutes(0), seconds(0), show_AM_PM(false) {}

    //sets the hours, minutes, and seconds on a new clock
    ClockType(int hr, int min, int sec);

    //creates a new clock from an existing ClockType object
    ClockType(ClockType& copy_clock);

    //return the hours on the clock
    int get_hours() const { return hours; }

    //return the minutes on the clock
    int get_minutes() const { return minutes; }

    //return the seconds on the clock
    int get_seconds() const { return seconds; }

    //return the total seconds past midnight on the clock
    int get_total_seconds() const;

    //returns True if we are showing AM/PM
    bool get_AM_PM_mode() const { return show_AM_PM; }

    //set the AM/PM mode. True = Show AM/PM
    // True = 12:00:00 AM
    //False = 00:00:00
    void set_AM_PM_mode(bool AM_PM) { show_AM_PM = AM_PM; }

    //returns the time on the clock as a string
    //00:00:00 or 12:00:00 AM
    std::string get_string() const;

    //set the hours on the clock
    void set_hours(int hr);

    //set the minutes on the clock
    void set_minutes(int min);

    //set the seconds on the clock
    void set_seconds(int sec);

    //increase the hours on the clock
    void increase_hours(int hr) { set_hours(hours + hr); }

    //increase the minutes on the clock
    void increase_minutes(int min) { set_minutes(minutes + min); }

    //increase the seconds on the clock
    void increase_seconds(int sec) { set_seconds(seconds + sec); }

    //set the clock to 00:00:00
    //AM/PM mode off
    void reset();
    
    //Copy an instance of a ClockType object
    void copy(ClockType& copy_clock);

    //Output to stream showing the current time on the clock
    friend std::ostream& operator<<(std::ostream &out, const ClockType &clock1); 

    //Read 00:00:00 from input stream into the clock
    friend std::istream& operator>>(std::istream &in,  ClockType &clock1); 
    
    //increase the clock by 1 second
    ClockType& operator ++ (int);

    //Comparison operators on the ClockType
    bool operator<(const ClockType& clock1) const;
    bool operator<=(const ClockType& clock1) const;
    bool operator>(const ClockType& clock1) const;
    bool operator>=(const ClockType& clock1) const;
    bool operator==(const ClockType& clock1) const;
    bool operator!=(const ClockType& clock1) const;
};

#endif
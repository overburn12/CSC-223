#include <string>
#include <iostream>

#ifndef H_CLOCKTYPE
#define H_CLOCKTYPE

class ClockType{
    int hours, minutes, seconds;
public:
    ClockType(): hours(0), minutes(0), seconds(0) {}
    ClockType(int hr, int min, int sec);
    ClockType(ClockType& copy_clock) { copy(copy_clock); }

    int get_hours() const { return hours; }
    int get_minutes() const { return minutes; }
    int get_seconds() const { return seconds; }

    std::string get_string() const;

    void set_hours( int hr ) { hours = hr; }
    void set_minutes( int min );
    void set_seconds( int sec );

    void increase_hours( int hr ){ set_hours( hours + hr ); }
    void increase_minutes( int min ){ set_minutes( minutes + min ); }
    void increase_seconds( int sec ) { set_seconds( seconds + sec ); }

    void reset();
    
    void copy(ClockType& copy_clock);

    friend std::ostream& operator << (std::ostream &out, const ClockType &clock1); 
    friend std::istream& operator >> (std::istream &in,  ClockType &clock1); 
    
    ClockType& operator ++ (int);

    bool operator < (const ClockType& clock1) const;
    bool operator <= (const ClockType& clock1) const;
    bool operator > (const ClockType& clock1) const;
    bool operator >= (const ClockType& clock1) const;
    bool operator == (const ClockType& clock1) const;
    bool operator != (const ClockType& clock1) const;
};

#endif
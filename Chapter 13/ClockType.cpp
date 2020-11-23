#include "ClockType.hpp"

ClockType::ClockType(int hr, int min = 0 , int sec = 0)
{
    set_seconds(sec);
    set_minutes(min);
    set_hours(hr);
    show_AM_PM = false;
}

ClockType::ClockType(ClockType& copy_clock)
{
    hours = copy_clock.get_hours();
    minutes = copy_clock.get_minutes();
    seconds = copy_clock.get_seconds();
    show_AM_PM = copy_clock.get_AM_PM_mode();
}

int ClockType::get_total_seconds() const
{
    return (((hours * 60) + minutes) * 60) + seconds;
}

std::string ClockType::get_string() const 
{
    std::string return_string = "";

    //we use temp_hours so we can show AM/PM properly
    //00 hours on the clock is shown as 12:00:00 AM
    int temp_hours = hours;

    if(show_AM_PM)
    {
        if(temp_hours > 13)
        {
            temp_hours -= 12;
        }

        if(temp_hours == 0)
        {
            temp_hours = 12;
        }
        //reserve space for "12:00:00 AM"
        return_string.reserve(8 + 3);
    }
    else
    {
        //reserve space for "00:00:00"
        return_string.reserve(8);
    }
    
    
    if(temp_hours < 10)
    {
        return_string += "0";
    }

    return_string += std::to_string(temp_hours);
    return_string += ":";

    if(minutes < 10)
    {
        return_string += "0";
    }

    return_string += std::to_string(minutes);
    return_string += ":";

    if(seconds < 10)
    {
        return_string += "0";
    }   

    return_string += std::to_string(seconds);

    if(show_AM_PM)
    {
        if(hours < 12)
        {
            return_string += " AM";
        }
        else
        {
            return_string += " PM";
        }
    }

    return return_string;
}

void ClockType::set_hours(int hr)
// Set the hours to hr
// If the hours goes over 23, then roll the hours over as if it is the next day
{
    if(hr < 0)
    {
        hours = 0;
    }
    else
    {
        if(hr > 23)
        {
            hours = hr % 24;
        }
        else
        {
            hours = hr;    
        }
    }
}

void ClockType::set_minutes(int min)
// Set the minutes to min
// If the minutes goes over 59, then increase the hours
{
    if(min < 0)
    {
        minutes = 0;
    }
    else
    {
        if(60 <= min)
        {
            increase_hours(min / 60);
        }

        minutes = min % 60;
    }
}

void ClockType::set_seconds(int sec) 
// Set the seconds to sec
// If the seconds go over 59, then increase the minutes
{
    if(sec < 0)
    {
        seconds = 0;
    }
    else
    {
        if(60 <= sec)
        {
            increase_minutes(sec / 60);
        }

        seconds = sec % 60;
    }
}

void ClockType::reset()
{
    hours = 0;
    minutes = 0;
    seconds = 0;
}

void ClockType::copy(ClockType& copy_clock) 
{
    hours = copy_clock.get_hours();
    minutes = copy_clock.get_minutes();
    seconds = copy_clock.get_seconds();
    show_AM_PM = copy_clock.get_AM_PM_mode();
}

std::ostream& operator<<(std::ostream &out, const ClockType &clock1)
{
    //we use temp_hours so we can show AM/PM properly
    //00 hours on the clock is shown as 12:00:00 AM
    int temp_hours = clock1.get_hours();

    if (clock1.get_AM_PM_mode())
    {
        if(clock1.get_hours() > 12)
        {
            temp_hours -= 12;
        }

        if(clock1.get_hours() == 0)
        {
            temp_hours = 12;
        }
    }

    if(temp_hours < 10)
    {
        out << "0";
    }

    out << temp_hours << ":";

    if(clock1.get_minutes() < 10)
    {
        out << "0";
    }

    out << clock1.get_minutes() << ":";
    
    if(clock1.get_seconds() < 10)
    {
        out << "0";
    }

    out << clock1.get_seconds();

    if(clock1.get_AM_PM_mode())
    {
        out << " ";
        if(clock1.get_hours() >= 12)
        {
            out << "PM";
        }
        else
        {
            out << "AM";
        }
    }

    return out;
}

std::istream& operator>>(std::istream &in,  ClockType &clock1)
{
    std::string data;
    int current_num = 0, this_data_type = 0;

    in >> data;

    if(data.size() == 0)
        return in;

    //reset the clock so we dont add to any existing time
    clock1.reset();

    //loop through the input string
    for(int i = 0; i < data.size(); i++)
    {
        //if the char we are at is an actual number
        //then add it to current_num
        if('0' <= data[i] && data[i] <= '9')
        {
            current_num *= 10;
            current_num += (data[i] - '0');
        }

        //if we are at a ':' or the last char in the string
        //we need to push current_num to its proper slot in the clock
        if(data[i] == ':' || i + 1 == data.size())
        {
            if(this_data_type == 0)
            {
                clock1.set_hours(current_num);
            }

            if(this_data_type == 1)
            {
                clock1.set_minutes(current_num);
            }

            if(this_data_type == 2)
            {
                clock1.set_seconds(current_num);
            }

            current_num = 0;
            this_data_type++;
        }
    }

    return in;
}

ClockType& ClockType::operator++(int)
{
    increase_seconds(1);
    return *this;
}

bool ClockType::operator<(const ClockType& clock1) const
{
    if(hours < clock1.get_hours())
    {
        return true;
    }
    else
    {
        if(hours == clock1.get_hours())
        {
            if(minutes < clock1.get_minutes())
            {
                return true;
            }
            else
            {
                if(minutes == clock1.get_minutes())
                {
                    return(seconds < clock1.get_seconds());
                }
            }
        }
    }

    return false;
}

bool ClockType::operator<=(const ClockType& clock1) const
{
    if(hours < clock1.get_hours())
    {
        return true;
    }
    else
    {
        if(hours == clock1.get_hours())
        {
            if(minutes < clock1.get_minutes())
            {
                return true;
            }
            else
            {
                if(minutes == clock1.get_minutes())
                {
                    return(seconds <= clock1.get_seconds());
                }
            }
        }
    }

    return false;
}

bool ClockType::operator>(const ClockType& clock1) const
{
    if(hours > clock1.get_hours())
    {
        return true;
    }
    else
    {
        if(hours == clock1.get_hours())
        {
            if(minutes > clock1.get_minutes())
            {
                return true;
            }
            else
            {
                if(minutes == clock1.get_minutes())
                {
                    return(seconds > clock1.get_seconds());
                }
            }
        }
    }

    return false;
}

bool ClockType::operator>=(const ClockType& clock1) const
{
    if(hours > clock1.get_hours())
    {
        return true;
    }
    else
    {
        if(hours == clock1.get_hours())
        {
            if(minutes > clock1.get_minutes())
            {
                return true;
            }
            else
            {
                if(minutes == clock1.get_minutes())
                {
                    return(seconds >= clock1.get_seconds());
                }
            }
        }
    }
    
    return false;
}

bool ClockType::operator==(const ClockType& clock1) const
{
    return(hours == clock1.get_hours() &&
         minutes == clock1.get_minutes() &&
         seconds == clock1.get_seconds());
}

bool ClockType::operator!=(const ClockType& clock1) const
{
    return(hours != clock1.get_hours() ||
         minutes != clock1.get_minutes() ||
         seconds != clock1.get_seconds());
}

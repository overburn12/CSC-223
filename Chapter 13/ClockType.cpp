#include "ClockType.hpp"

ClockType::ClockType(int hr, int min = 0 , int sec = 0)
{
    set_seconds(sec);
    set_minutes(min);
    set_hours(hr);
}

int ClockType::get_total_seconds() const
{
    return ((( get_hours() * 60 ) + get_minutes()) * 60 ) + get_seconds();
}


std::string ClockType::get_string() const 
{
    std::string return_string;
    return_string.reserve( 8 );
    
    if(get_hours() < 10)
    {
        return_string.append("0");
    }

    return_string.append( std::to_string(get_hours()) );
    return_string.append(":");

    if(get_minutes() < 10)
    {
        return_string.append("0");
    }

    return_string.append( std::to_string(get_minutes()) );
    return_string.append(":");

    if(get_seconds() < 10)
    {
        return_string.append("0");
    }   

    return_string.append( std::to_string(get_seconds()) );

    return return_string;
}

void ClockType::set_hours( int hr )
{
    if( hr < 0 )
    {
        hours = 0;
    }
    else
    {
        if( hr > 23 )
        {
            hours = hr % 24;
        }
        else
        {
            hours = hr;    
        }
    }
}

void ClockType::set_minutes( int min )
{
    if( min < 0 )
    {
        minutes = 0;
    }
    else
    {
        if( 60 <= min )
        {
            increase_hours( min / 60 );
        }
        minutes = min % 60;
    }
}

void ClockType::set_seconds( int sec ) 
{
    if( sec < 0 )
    {
        seconds = 0;
    }
    else
    {
        if( 60 <= sec )
        {
            increase_minutes( sec / 60 );
        }
        seconds = sec % 60;
    }
}

void ClockType::reset()
{
    set_hours(0);
    set_minutes(0);
    set_seconds(0);
}

void ClockType::copy(ClockType& copy_clock) 
{
    set_hours(copy_clock.get_hours());
    set_minutes(copy_clock.get_minutes());
    set_seconds(copy_clock.get_seconds());
    set_AM_PM_mode(copy_clock.get_AM_PM_mode());
}

std::ostream& operator << (std::ostream &out, const ClockType &clock1)
{
    int temp_hours = clock1.get_hours();

    if (clock1.get_AM_PM_mode())
    {
        if(clock1.get_hours() > 12 )
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
    
    if( clock1.get_seconds() < 10)
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

std::istream& operator >> (std::istream &in,  ClockType &clock1)
{
    std::string data;
    int current_num = 0, this_data_type = 0;

    in >> data;

    if(data.size() == 0)
        return in;

    clock1.reset();

    for(int i = 0; i < data.size(); i++)
    {
        if( '0' <= data[i] && data[i] <= '9' )
        {
            current_num *= 10;
            current_num += (data[i] - '0');
        }
        if( data[i] == ':' || i+1 == data.size() )
        {
            if( this_data_type == 0 )
            {
                clock1.set_hours(current_num);
            }
            if( this_data_type == 1 )
            {
                clock1.set_minutes(current_num);
            }
            if( this_data_type == 2 )
            {
                clock1.set_seconds(current_num);
            }
            current_num = 0;
            this_data_type++;
        }
    }
    return in;
}

ClockType& ClockType::operator ++ (int)
{
    this->increase_seconds(1);
    return *this;
}

bool ClockType::operator < (const ClockType& clock1) const
{
    if(this->get_hours() < clock1.get_hours())
    {
        return true;
    }
    else
    {
        if(this->get_hours() == clock1.get_hours())
        {
            if(this->get_minutes() < clock1.get_minutes())
            {
                return true;
            }
            else
            {
                if(this->get_minutes() == clock1.get_minutes())
                {
                    return(this->get_seconds() < clock1.get_seconds());
                }
            }
        }
    }
    return false;
}

bool ClockType::operator <= (const ClockType& clock1) const
{
    if(this->get_hours() < clock1.get_hours())
    {
        return true;
    }
    else
    {
        if(this->get_hours() == clock1.get_hours())
        {
            if(this->get_minutes() < clock1.get_minutes())
            {
                return true;
            }
            else
            {
                if(this->get_minutes() == clock1.get_minutes())
                {
                    return(this->get_seconds() <= clock1.get_seconds());
                }
            }
        }
    }
    return false;
}

bool ClockType::operator > (const ClockType& clock1) const
{
    if(this->get_hours() > clock1.get_hours())
    {
        return true;
    }
    else
    {
        if(this->get_hours() == clock1.get_hours())
        {
            if(this->get_minutes() > clock1.get_minutes())
            {
                return true;
            }
            else
            {
                if(this->get_minutes() == clock1.get_minutes())
                {
                    return(this->get_seconds() > clock1.get_seconds());
                }
            }
        }
    }
    return false;
}

bool ClockType::operator >= (const ClockType& clock1) const
{
    if(this->get_hours() > clock1.get_hours())
    {
        return true;
    }
    else
    {
        if(this->get_hours() == clock1.get_hours())
        {
            if(this->get_minutes() > clock1.get_minutes())
            {
                return true;
            }
            else
            {
                if(this->get_minutes() == clock1.get_minutes())
                {
                    return(this->get_seconds() >= clock1.get_seconds());
                }
            }
        }
    }
    return false;
}

bool ClockType::operator == (const ClockType& clock1) const
{
    return( this->get_hours() == clock1.get_hours() &&
        this->get_minutes() == clock1.get_minutes() &&
        this->get_seconds() == clock1.get_seconds() );
}

bool ClockType::operator != (const ClockType& clock1) const
{
    return( this->get_hours() != clock1.get_hours() ||
        this->get_minutes() != clock1.get_minutes() ||
        this->get_seconds() != clock1.get_seconds() );
}

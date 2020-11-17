#include <string>
#include <iostream>
#include <iomanip>
#include "Course.hpp"

Course::Course( std::string courseID, std::string courseTitle, 
                std::string roomNumber, std::string contactHours ) 
        : course_ID( courseID ),  course_title( courseTitle ), 
          room_number( roomNumber ), contact_hours( contactHours ) {}

std::string Course::get_course_ID() const { return course_ID; }

std::string Course::get_course_title() const { return course_title; }

std::string Course::get_room_number() const { return room_number; }

std::string Course::get_contact_hours() const { return contact_hours; }
    


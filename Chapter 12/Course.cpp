#include <string>
#include <iostream>
#include <iomanip>

#include "Course.hpp"


Course::Course( std::string new_courseID, 
                std::string new_courseTitle, 
                std::string new_roomNumber, 
                std::string new_contactHours ) 
        : courseID( new_courseID ), 
          courseTitle( new_courseTitle ), 
          roomNumber( new_roomNumber ), 
          contactHours( new_contactHours ) {}

Course::~Course() {}


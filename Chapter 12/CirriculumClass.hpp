#include <string>
#include "Course.hpp"

#ifndef H_CIRRICULUMCLASS
#define H_CIRRICULUMCLASS

class CirriculumClass : public Course
{
    double creditHours, tuitionRate;
public:
    CirriculumClass( std::string new_courseID, 
                     std::string new_courseTitle, 
                     std::string new_roomNumber, 
                     std::string new_contactHours, 
                     double new_creditHours, 
                     double new_tuitionRate );
    
    ~CirriculumClass();

    void show();
};

#endif
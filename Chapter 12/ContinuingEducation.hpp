#include <string>
#include "Course.hpp"

#ifndef H_CONTINUINGEDUCATION
#define H_CONTINUINGEDUCATION

class ContinuingEducation : public Course
{
    double fee;
public:
    ContinuingEducation( std::string new_courseID, 
                         std::string new_courseTitle, 
                         std::string new_roomNumber, 
                         std::string new_contactHours, 
                         double new_fee );

    ~ContinuingEducation();

    void show();
};

#endif

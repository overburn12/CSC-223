#include <string>

#ifndef H_COURSE
#define H_COURSE

class Course
{
protected:
    std::string courseID, courseTitle, roomNumber, contactHours;
public:
    Course( std::string new_courseID, 
            std::string new_courseTitle, 
            std::string new_roomNumber, 
            std::string new_contactHours );
    
    virtual ~Course();

    virtual void show() = 0;
};

#endif
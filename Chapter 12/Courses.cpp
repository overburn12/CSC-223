#include <string>
#include <iostream>
#include <iomanip>

class Course
{
protected:
    std::string courseID, courseTitle, roomNumber, contactHours;
public:
    Course    ( std::string new_courseID, 
                std::string new_courseTitle, 
                std::string new_roomNumber, 
                std::string new_contactHours ) 
        : courseID( new_courseID ), 
          courseTitle( new_courseTitle ), 
          roomNumber( new_roomNumber ), 
          contactHours( new_contactHours ) {}
    
    virtual ~Course() {};

    virtual void show() = 0 ;
};

class CirriculumClass : public Course
{
    double creditHours, tuitionRate;
public:
    CirriculumClass( std::string new_courseID, 
                     std::string new_courseTitle, 
                     std::string new_roomNumber, 
                     std::string new_contactHours, 
                     double new_creditHours, 
                     double new_tuitionRate ) 
            : Course( new_courseID, new_courseTitle, new_roomNumber, new_contactHours ), 
              creditHours( new_creditHours ), 
              tuitionRate( new_tuitionRate ) {}
    
    ~CirriculumClass() {}

    void show(){
        int sp = 30;
        std::cout << std::fixed << std::setprecision(2) << '\n' <<
        std::setw(34) << "[Cirriculum Class]" << '\n' <<
        std::setw(sp) << "Course title: "     << courseTitle  << '\n' <<
        std::setw(sp) << "Course ID: "        << courseID     << '\n' <<
        std::setw(sp) << "Room number: "      << roomNumber   << '\n' <<
        std::setw(sp) << "Contacts hours: "   << contactHours << '\n' <<
        std::setw(sp) << "Credit hours: "     << creditHours  << '\n' <<
        std::setw(sp) << "Tuition rate: "     << tuitionRate  << '\n' <<
        std::setw(sp) << "Course fee: "       << tuitionRate * creditHours << std::endl;
    }
};

class ContinuingEducation : public Course
{
    double fee;
public:
    ContinuingEducation( std::string new_courseID, 
                         std::string new_courseTitle, 
                         std::string new_roomNumber, 
                         std::string new_contactHours, 
                         double new_fee )
            : Course( new_courseID, new_courseTitle, new_roomNumber, new_contactHours ), 
              fee( new_fee ) {}

    ~ContinuingEducation() {}

    void show()
    {
        int sp = 30;
        std::cout << std::fixed << std::setprecision(2) << '\n' <<
        std::setw(42) << "[Continuing Education Course]" << '\n' <<
        std::setw(sp) << "Course title: "   << courseTitle  << '\n' <<
        std::setw(sp) << "Course ID: "      << courseID     << '\n' <<
        std::setw(sp) << "Contacts Hours: " << contactHours << '\n' <<
        std::setw(sp) << "Room number: "    << roomNumber   << '\n' <<
        std::setw(sp) << "Course fee: "     << fee          << std::endl;
    }
};
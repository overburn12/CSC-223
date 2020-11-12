#include <string>
#include <iostream>
#include <iomanip>

class Course{
protected:
    int courseID;
    std::string courseTitle;
    int roomNumber;
    int contactHours;
public:
    Course( int new_courseID, std::string new_courseTitle, int new_roomNumber, int new_contactHours ) : 
            courseID(new_courseID), courseTitle(new_courseTitle), 
            roomNumber(new_roomNumber), contactHours(new_contactHours) {}

    Course() : courseID(0), courseTitle(""), roomNumber(0), contactHours(0) {}

    virtual void show() = 0 ;
};

class CirriculumClass : public Course{
    double creditHours;
    double tuitionRate;
public:
    CirriculumClass( int new_courseID, std::string new_courseTitle, int new_roomNumber, 
                     int new_contactHours, double new_creditHours, double new_tuitionRate ) : 
                     Course(new_courseID, new_courseTitle, new_roomNumber, new_contactHours) ,
                     creditHours(new_creditHours), 
                     tuitionRate(new_tuitionRate) {}

    CirriculumClass() : Course(), creditHours(0), tuitionRate(0) {}

    void show(){
        int sp = 30;
        std::cout << std::fixed << std::setprecision(2) << std::endl <<
        std::setw(30) << "[Cirriculum Class]" << std::endl <<
        std::setw(sp) << "Course title: " << courseTitle << std::endl <<
        std::setw(sp) << "Course ID: " << courseID << std::endl <<
        std::setw(sp) << "Room number: " << roomNumber << std::endl <<
        std::setw(sp) << "Credit hours: " << creditHours << std::endl <<
        std::setw(sp) << "Tuition per credit hour: " << tuitionRate << std::endl <<
        std::setw(sp) << "Course fee: " << tuitionRate * creditHours << std::endl;
    }
};

class ContinuingEducation : public Course{
    double fee;
public:
    ContinuingEducation( int new_courseID, std::string new_courseTitle, int new_roomNumber, 
                         int new_contactHours, double new_fee) :
                         Course(new_courseID, new_courseTitle, new_roomNumber, new_contactHours), 
                         fee(new_fee) {}

    ContinuingEducation() : Course(), fee(0) {}

    void show(){
        int sp = 30;
        std::cout << std::fixed << std::setprecision(2) << std::endl <<
        std::setw(35) << "[Continuing Education Course]" << std::endl <<
        std::setw(sp) << "Course title: " << courseTitle << std::endl <<
        std::setw(sp) << "Course ID: " << courseID << std::endl <<
        std::setw(sp) << "Room number: " << roomNumber << std::endl <<
        std::setw(sp) << "Course fee: " << fee << std::endl;
    }
};
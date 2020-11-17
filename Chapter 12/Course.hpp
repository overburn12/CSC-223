#include <string>

#ifndef H_COURSE
#define H_COURSE

class Course
{
    std::string course_ID, course_title, room_number, contact_hours;
public:

    /***************************************************************************//****
    * The constructor for the abstract base class, Course.
    *
    * @param courseID       A string representing the Course number. 
    *                           ex: "CSC-223"
    * @param courseTitle    A string representing the Title of the class. 
    *                           ex: "Computer Programming with C++"
    * @param roomNumber     A string representing the room number of the class. 
    *                           ex: "11-305"
    * @param contactHours   A string representing the contact hours of a class. 
    *                           ex: "M-F 10:00 AM to 12:00 PM"
    *********************************************************************************/
    Course( std::string courseID, std::string courseTitle, 
            std::string roomNumber, std::string contactHours );

    //Returns course_ID string representing the Course Number for the class
    std::string get_course_ID() const;

    //Returns course_title string representing the Name of the class
    std::string get_course_title() const;
    
    //Returns room_number string representing the Room number for the class
    std::string get_room_number() const;
    
    //Returns contact_hours string representing the available Contact hours schedule for the clas
    std::string get_contact_hours() const;
    
    //Virtual decontructor. so the derived class desconstructors are called when pointer is base class
    virtual ~Course() {}

    //Prints to std::cout, showing all the class data with proper formatting
    virtual void show() const = 0;
};

#endif
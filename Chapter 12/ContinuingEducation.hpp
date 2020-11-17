#include <string>
#include "Course.hpp"

#ifndef H_CONTINUINGEDUCATION
#define H_CONTINUINGEDUCATION

class ContinuingEducation : public Course
{
    double fee;
public:
    /***************************************************************************//****
    * The constructor for the class CirriculumClass.
    *
    * @param courseID       A string representing the Course number. 
    *                           ex: "CSC-223"
    * @param courseTitle    A string representing the Title of the class. 
    *                           ex: "Computer Programming with C++"
    * @param roomNumber     A string representing the room number of the class. 
    *                           ex: "11-305"
    * @param contactHours   A string representing the contact hours of a class. 
    *                           ex: "M-F 10:00 AM to 12:00 PM"
    * @param course_fee     A double representing how much it costs to take the class.
    *********************************************************************************/
    ContinuingEducation( std::string courseID, 
                         std::string courseTitle, 
                         std::string roomNumber, 
                         std::string contactHours, 
                         double course_fee );

    //The deconstructor
    ~ContinuingEducation() {}

    //Returns a double representing how much it costs to take the class
    double get_fee() const;

    //Prints to std::cout showing the class information with proper formatting
    void show() const;
};

#endif

#include <string>
#include "Course.hpp"

#ifndef H_CIRRICULUMCLASS
#define H_CIRRICULUMCLASS

class CirriculumClass : public Course
{
    double credit_hours, tuition_rate;
public:
    /***************************************************************************//****
    * The constructor for the class, CirriculumClass.
    *
    * @param courseID       A string representing the Course number. 
    *                           ex: "CSC-223"
    * @param courseTitle    A string representing the Title of the class. 
    *                           ex: "Computer Programming with C++"
    * @param roomNumber     A string representing the room number of the class. 
    *                           ex: "11-305"
    * @param contactHours   A string representing the contact hours of a class. 
    *                           ex: "M-F 10:00 AM to 12:00 PM"
    * @param creditHours    A double representing the amount of credit hours for the class
    *                              ex: 4.0 or 3.0
    * @param tuitionRate    A double representing the cost per credit hour for the class
    *********************************************************************************/
    CirriculumClass( std::string courseID, 
                     std::string courseTitle, 
                     std::string roomNumber, 
                     std::string contactHours, 
                     double creditHours, 
                     double tuitionRate );

    //The deconstructor
    ~CirriculumClass() {};

    //Returns a double representing the total credit hours for the class
    double get_credit_hours() const;

    //Returns a double representing the tuition rate per credit hour for the class
    double get_tuition_rate() const;

    //Returns a double representing the total cost for taking the class
    double get_fee() const;

    //Prints to std::cout showing all the data for the class with proper formatting
    void show() const;
};

#endif
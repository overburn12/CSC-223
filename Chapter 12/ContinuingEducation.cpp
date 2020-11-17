#include <iostream>
#include <iomanip>
#include <string>
#include "ContinuingEducation.hpp"

ContinuingEducation::ContinuingEducation( std::string courseID, 
                                          std::string courseTitle, 
                                          std::string roomNumber, 
                                          std::string contactHours, 
                                          double class_fee )
                    : Course( courseID, courseTitle, roomNumber, contactHours ), 
                      fee( class_fee ) {}

double ContinuingEducation::get_fee() const { return fee; }

void ContinuingEducation::show() const
{
    int sp = 30;
    std::cout << std::fixed << std::setprecision(2) << '\n' <<
    std::setw(42) << "[Continuing Education Course]" << '\n' <<
    std::setw(sp) << "Course title: "   << Course::get_course_title()  << '\n' <<
    std::setw(sp) << "Course ID: "      << Course::get_course_ID()     << '\n' <<
    std::setw(sp) << "Contacts Hours: " << Course::get_contact_hours() << '\n' <<
    std::setw(sp) << "Room number: "    << Course::get_room_number()   << '\n' <<
    std::setw(sp) << "Course fee: "     << ContinuingEducation::get_fee() << std::endl;
}
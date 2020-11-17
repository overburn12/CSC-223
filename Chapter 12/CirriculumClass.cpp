#include <iostream>
#include <iomanip>
#include <string>
#include "CirriculumClass.hpp"

CirriculumClass::CirriculumClass( std::string courseID, 
                                  std::string courseTitle, 
                                  std::string roomNumber, 
                                  std::string contactHours, 
                                  double creditHours, 
                                  double tuitionRate ) 
                : Course( courseID, courseTitle, roomNumber, contactHours ), 
                  credit_hours( creditHours ), 
                  tuition_rate( tuitionRate ) {}

double CirriculumClass::get_credit_hours() const { return credit_hours; }

double CirriculumClass::get_tuition_rate() const { return tuition_rate; }

double CirriculumClass::get_fee() const { return credit_hours * tuition_rate; }

void CirriculumClass::show() const
{
    int sp = 30;
    std::cout << std::fixed << std::setprecision(2) << '\n' <<
    std::setw(34) << "[Cirriculum Class]" << '\n' <<
    std::setw(sp) << "Course title: "     << Course::get_course_title()  << '\n' <<
    std::setw(sp) << "Course ID: "        << Course::get_course_ID()     << '\n' <<
    std::setw(sp) << "Room number: "      << Course::get_room_number()   << '\n' <<
    std::setw(sp) << "Contacts hours: "   << Course::get_contact_hours() << '\n' <<
    std::setw(sp) << "Credit hours: "     << CirriculumClass::get_credit_hours()  << '\n' <<
    std::setw(sp) << "Tuition rate: "     << CirriculumClass::get_tuition_rate()  << '\n' <<
    std::setw(sp) << "Course fee: "       << CirriculumClass::get_fee() << std::endl;
}
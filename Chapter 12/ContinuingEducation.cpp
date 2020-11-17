#include <iostream>
#include <iomanip>
#include <string>
#include "ContinuingEducation.hpp"

ContinuingEducation::ContinuingEducation( std::string new_courseID, 
                                          std::string new_courseTitle, 
                                          std::string new_roomNumber, 
                                          std::string new_contactHours, 
                                          double new_fee )
                    : Course( new_courseID, new_courseTitle, new_roomNumber, new_contactHours ), 
                      fee( new_fee ) {}

ContinuingEducation::~ContinuingEducation() {}

void ContinuingEducation::show()
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
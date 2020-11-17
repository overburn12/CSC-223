#include <iostream>
#include <iomanip>
#include <string>
#include "CirriculumClass.hpp"

CirriculumClass::CirriculumClass( std::string new_courseID, 
                                  std::string new_courseTitle, 
                                  std::string new_roomNumber, 
                                  std::string new_contactHours, 
                                  double new_creditHours, 
                                  double new_tuitionRate ) 
                : Course( new_courseID, new_courseTitle, new_roomNumber, new_contactHours ), 
                  creditHours( new_creditHours ), 
                  tuitionRate( new_tuitionRate ) {}

CirriculumClass::~CirriculumClass() {}

void CirriculumClass::show()
{
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
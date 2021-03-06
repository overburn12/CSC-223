/*
Dynamic Programs Hoskins College offers both curriculum and continuing education courses. 
Write a program that dynamically tracks these courses using an array of object pointers. 

Every course (both curriculum and continuing education) has a course id, title, room number, 
and number of contact hours. 

A curriculum course has credit hours and tuition rate. 
Tuition is calculated by multiplying the course's credit hours by tuition rate. 

A continuing education course has a flat fee (cost). 

Implement a show() function in every class that displays the data in the object.

Part A: Create an inheritance-based collection of classes to represent these different courses. 
Include code in main to new_class your work by instantiating objects of the two derived classes.

Part B: Modify your program. Remove the objects you created in main to new_class the classes. Modify 
the base class so that show() becomes a virtual function.

In main, create a single array capable of holding pointers to objects of both curriculum and 
continuing education courses.

Develop a menu-based system that offers the following options:

Main Menu
1. Add a curriculum class to schedule
2. Add a continuing education class to schedule
3. Display all records
4. Exit 

Implement each menu option
*/

#include <iostream>
#include <string>
#include <cmath>
#include "Course.hpp"
#include "CirriculumClass.hpp"
#include "ContinuingEducation.hpp"


void add_course(Course** &classes, int &class_list_size, bool is_cirriculum_class);
/*Precondition: classes exists
 Postcondition: creates either a CirriculumClass or ContinuingEducation with user-entered data.
                increase class_list_size by 1.
                add the derived class to the end of classes. 
*/

void do_menu(int selection, Course** &classes, int &class_list_size);
/*Precondition: The menu has been printed to the screen, 
                user entered a number (selection) corresponding to the menu number
  Postcondtion: The menu selection is executed by calling the appropriate functions
*/

void load_default_list(Course** &classes, int &class_list_size);
/*Precondtion:  classes exists
 Postcondtion:  classes contains 5-6 derieved classes of Course, each filled with seemingly real data.
                class_list_size corresponds to the size of the classes array
*/

double get_double();
/*Precondition: A message has been printed to the screen, prompting the user to enter a number
  Postcondtion: A number is taken from the input stream and returned as a double.
*/

int get_menu();
/*Precondtion: none
 Postcondtion: The menu is printed to the screen.
                returns a number corresponding to the menu selection.
*/

int main()
{
    int selection, class_list_size = 0;
    Course** courses = nullptr;
    
    std::cout << std::endl;

    //The main loop for repeating the menu selection screen
    do
    {
        selection = get_menu();
        do_menu(selection, courses, class_list_size);
    }
    while(selection != 9);

    //delete all the courses we created on the heap
    delete [] courses;
    return 0;
}

void load_default_list(Course** &classes, int &class_list_size)
{
    std::string default_contact = "M-F 10AM to 12PM";
    delete []  classes;
    class_list_size = 5;
    //create a new dynamic array for the classes
    classes = new Course*[class_list_size];

    //classes[] = new CirriculumClass( courseID, courseTitle, roomNumber, contactHours, creditHours, tuitionRate );
    classes[0] = new CirriculumClass( "CSC-223", "Computer Programming C++", "11-306", default_contact, 4, 325.00 );
    classes[1] = new CirriculumClass( "PHL-103", "Introduction to Ethics",  "6-422", default_contact, 3, 325.00 );
    classes[2] = new CirriculumClass( "ENG-251", "Technical Writing", "12-105", default_contact, 3, 240.00 );
    //classes[] = new ContinuingEducation( courseID, courseTitle, roomNumber, contactHours, fee );
    classes[3] = new ContinuingEducation( "PEC-250", "Fitness and Wellness", "5-105", default_contact, 500.00 );
    classes[4] = new ContinuingEducation( "HED-209", "Drugs and Behavior", "5-203", default_contact, 500.00 );
}

double get_double()
/*  gets a string from input stream. 
    builds and returns a double from that string, 
    while skipping over and ignoring non-number characters.  */
{   
    std::string input_line;
    double the_integer_part = 0, the_decimal_part = 0, decimal_position = 1;
    bool before_decimal_point = true, is_negative = false;

    std::getline(std::cin, input_line);

    for(int i = 0; i < input_line.size(); i++)
    {
        //if the current letter is a number, within the range of 0 to 9
        if('0' <= input_line[i] && input_line[i] <= '9')
        {
            //the single-digit number value we are dealing with
            double this_single_digit = (double)(input_line[i] - '0');

            if(before_decimal_point)
            {
                //We are adding the LSB, so multiply by 10 and make room to add the LSB
                the_integer_part *= 10;

                //add the single digit value we are at
                the_integer_part += this_single_digit;
            }
            else
            {
                //The current decimal power factor, tenths, hundreths, thousandths, etc...
                double this_decimal_power = std::pow(10.0, decimal_position);

                //add the digit value devided by the power factor
                the_decimal_part += (this_single_digit / this_decimal_power);

                //increase the decimal power to the next factor
                decimal_position++;
            }
        }
        else
        {
            if(input_line[i] == '-' && the_integer_part == 0)
            {   //if we come across a - sign and we have not hit a number yet
                //then the number will be returned as negative
                is_negative = true;
            }
            if(input_line[i] == '.')
            {   //if we hit a decimal point then switch to adding the decimal portion
                before_decimal_point = false;
            }
        }
    }

    if(is_negative)
    {
        return -1 * (the_integer_part + the_decimal_part);
    }

    return (the_integer_part + the_decimal_part);  
}

void add_course(Course** &classes, int &class_list_size, bool is_cirriculum_class)
{
    std::string courseTitle, courseID, roomNumber, contactHours;
    double creditHours, tuitionRate, fee;
    Course* new_class = nullptr;

    std::cout << "Enter course Title: "; 
    std::getline(std::cin, courseTitle);

    std::cout << "Enter course ID: "; 
    std::getline(std::cin, courseID);

    std::cout << "Enter the room number: "; 
    std::getline(std::cin, roomNumber);

    std::cout << "Enter the # of contact hours: "; 
    std::getline(std::cin, contactHours);

    //Decide which type of class to make
    if(is_cirriculum_class) 
    {
        std::cout << "Enter the credit hours: "; 
        creditHours = get_double();

        std::cout << "Enter the tuition rate: "; 
        tuitionRate = get_double();

        new_class = new CirriculumClass( courseID, courseTitle, roomNumber, contactHours, creditHours, tuitionRate );
    }
    else
    {
        std::cout << "Enter the course fee: "; 
        fee = get_double();

        new_class = new ContinuingEducation( courseID, courseTitle, roomNumber, contactHours, fee );
    }

    //--------------expand the course pointer array 1 more------------------------
    Course** temp = new Course*[class_list_size+1];
    for(int i = 0; i < class_list_size; i++)
    {
        temp[i] = classes[i];
    }
    class_list_size += 1;
    delete [] classes;
    classes = temp;
    //--------------------------------------------------------------------------
    
    classes[class_list_size - 1] = new_class;
}

int get_menu()
{
    std::cout << "   [Class Program Main Menu]" << std::endl
              << "1. Load a default pre-programmed array of courses" << std::endl
              << "2. Add a curriculum class to schedule" << std::endl
              << "3. Add a continuing education class to schedule" << std::endl
              << "4. Display all records" << std::endl
              << "5. Clear the list of classes" << std::endl
              << "9. Exit" << std::endl
              << " > ";
    return (int)get_double();
}

void do_menu(int selection, Course** &classes, int &class_list_size)
{
    std::cout << std::endl;
    switch(selection)
    {
        case 1: // Load a default pre-programmed array of courses
        {
            std::cout << "Loading the default preprogrammed class list" << std::endl;
            load_default_list(classes, class_list_size);
        }
        break;
        case 2: //Add a curriculum class to schedule
        {
            std::cout << "[Adding a new Cirriculum Class]" << std::endl;
            add_course(classes, class_list_size, true);
        } 
        break;
        case 3: //Add a continuing education class to schedule
        {
            std::cout << "[Adding a new Continuing Education Class]" << std::endl;
            add_course(classes, class_list_size, false);
        } 
        break;
        case 4: //Display all records
        {
            std::cout << "Printing a list of all Classes" << std::endl;
            for(int i = 0; i < class_list_size; i++)
            {
                classes[i]->show();
            }
        } 
        break;
        case 5: //Clear the list of classes
        {
            std::cout << "Clearing the list of saved classes" << std::endl;
            delete [] classes;
            class_list_size = 0;
            classes = nullptr;
        }
        break;
        case 9: //Exit the program
        {
            std::cout << "Exiting the program" << std::endl;
        }
        break;
        default: //Invalid
        {
            std::cout << "That is not a valid menu selection" << std::endl;
        }
        break;
    }
    std::cout << std::endl;
}


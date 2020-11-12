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
#include <limits>
#include "Courses.cpp"

void add_course(Course** &classes, int &class_list_size, bool is_cirriculum_class);
void do_menu(int selection, Course** &classes, int &class_list_size);
void load_default_list(Course** &classes, int &class_list_size);
double get_double();
int get_menu();

int main()
{
    int selection, class_list_size = 0;
    Course** courses;
    std::cout << std::endl;
    do
    {
        selection = get_menu();
        do_menu(selection, courses, class_list_size);
    }
    while(selection != 9);
    delete [] courses;
    return 0;
}

void load_default_list(Course** &classes, int &class_list_size)
{
    class_list_size = 6;
    std::string default_contact = "M-F 10AM to 12PM";
    delete [] classes;
    classes = new Course*[class_list_size];
    //classes[] = new CirriculumClass( courseID, courseTitle, roomNumber, contactHours, creditHours, tuitionRate );
    classes[0] = new CirriculumClass( "CSC-223", "Computer Programming C++", "11-306", default_contact, 4, 325.00 );
    classes[1] = new CirriculumClass( "PHL-103", "Introduction to Ethics",  "6-422", default_contact, 3, 325.00 );
    classes[2] = new CirriculumClass( "ENG-251", "Technical Writing", "12-105", default_contact, 3, 240.00 );
    classes[3] = new CirriculumClass( "MTH-160", "Statistics I", "12-210", default_contact, 3, 240.00 );
    //classes[] = new ContinuingEducation( courseID, courseTitle, roomNumber, contactHours, fee );
    classes[4] = new ContinuingEducation( "PEC-250", "Fitness and Wellness", "5-105", default_contact, 500.00 );
    classes[5] = new ContinuingEducation( "HED-209", "Drugs and Behavior", "5-203", default_contact, 500.00 );
}

double get_double()
{   /*
        This function gets a string from std::cin
        it then looks through and builds a decimal number
        while skiping over any non-number charecters
        and returns the number as a double.
        If there is a '-' before any numbers have been computed
        then the number returned will be negative.
        this is to prevent the program from getting suck in an infinite loop
        when someone enters a string for and expression like
        'std::cin >> (double or int);'

        Precondition: (user enters) getwwh-sfh23gds-dfntrw3.r34rfg5
        Postcondition: -233.345
        Precondition: (user enters) vewr8nv we3dfg45svf. fdh234ggs
        Postcondition: 8345.234
        Precondition: (user enters) efnaler jfsnldjrg  nslkjngd sljnfsdlewnfsj
        Postcondition: 0
    */
    std::string input_line;
    double the_int = 0, the_decimal = 0, the_decimal_position = 1;
    bool before_decimal_point = true;
    bool is_negative = false;

    std::getline(std::cin, input_line);

    for(int i = 0; i < input_line.size(); i++)
    {
        if('0' <= input_line[i] && input_line[i] <= '9')
        {
            if(before_decimal_point)
            {
                the_int = (the_int * 10) + (input_line[i] - '0');
            }
            else
            {
                the_decimal += ((double)(input_line[i] - '0') / std::pow(10.0, the_decimal_position++));
            }
        }
        else
        {
            if(input_line[i] == '-' && the_int == 0)
            {
                is_negative = true;
            }
            if(input_line[i] == '.')
            {
                before_decimal_point = false;
            }
        }
    }
    if(is_negative)
    {
        return -1 * (the_int + the_decimal);
    }
    return (the_int + the_decimal);  
}

void add_course(Course** &classes, int &class_list_size, bool is_cirriculum_class)
{
    std::string courseTitle, courseID, roomNumber, contactHours;
    double creditHours, tuitionRate, fee;
    Course* new_class;

    std::cout << "Enter course Title: "; std::getline(std::cin, courseTitle);
    std::cout << "Enter course ID: "; std::getline(std::cin, courseID);
    std::cout << "Enter the room number: "; std::getline(std::cin, roomNumber);
    std::cout << "Enter the # of contact hours: "; std::getline(std::cin, contactHours);

    if(is_cirriculum_class)
    {
        std::cout << "Enter the credit hours: "; creditHours = get_double();
        std::cout << "Enter the tuition rate: "; tuitionRate = get_double();
        new_class = new CirriculumClass( courseID, courseTitle, roomNumber, contactHours, creditHours, tuitionRate );
    }
    else
    {
        std::cout << "Enter the course fee: "; fee = get_double();
        new_class = new ContinuingEducation( courseID, courseTitle, roomNumber, contactHours, fee );
    }

    //--------------expand the course pointer array 1 more------------------------
    {
        Course** temp = new Course*[class_list_size+1];
        for(int i = 0; i < class_list_size; i++)
        {
            temp[i] = classes[i];
        }
        class_list_size += 1;
        delete [] classes;
        classes = temp;
    }
    //--------------------------------------------------------------------------
    
    classes[class_list_size - 1] = new_class;
}

int get_menu()
{
    int selection;
    std::cout << "   [Class Program Main Menu]" << std::endl
              << "1. Load a default pre-programmed array of courses" << std::endl
              << "2. Add a curriculum class to schedule" << std::endl
              << "3. Add a continuing education class to schedule" << std::endl
              << "4. Display all records" << std::endl
              << "5. Clear the list of classes" << std::endl
              << "9. Exit" << std::endl
              << " > ";
    selection = (int)get_double();
    return selection;
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
            classes = new Course*[class_list_size];
        }
        break;
        case 9:
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


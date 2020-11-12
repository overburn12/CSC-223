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
Include code in main to test your work by instantiating objects of the two derived classes.

Part B: Modify your program. Remove the objects you created in main to test the classes. Modify 
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
#include "Courses.cpp"

void expand_list_one_more(Course** &classes, int &class_list_size)
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

void the_default_list(Course** &classes, int &class_list_size)
{
    class_list_size = 6;
    delete [] classes;
    classes = new Course*[class_list_size];
    //classes[] = new CirriculumClass( courseID, courseTitle, roomNumber, contactHours, creditHours, tuitionRate );
    classes[0] = new CirriculumClass( 3012,  "Computers", 1, 10, 4, 325.00 );
    classes[1] = new CirriculumClass( 6233, "Philosophy", 2, 10, 3, 325.00 );
    classes[2] = new CirriculumClass( 2223,    "English", 3, 10, 3, 240.00 );
    classes[3] = new CirriculumClass( 1212,       "Math", 4, 10, 3, 240.00 );
    //classes[] = new ContinuingEducation( courseID, courseTitle, roomNumber, contactHours, fee );
    classes[4] = new ContinuingEducation( 3333, "Paramedic", 5, 10, 500.00 );
    classes[5] = new ContinuingEducation( 9999,   "Welding", 6, 10, 500.00 );
}

void add_curriculum(Course** &classes, int &class_list_size)
{
    int courseID, roomNumber, contactHours;
    double creditHours, tuitionRate;
    std::string courseTitle;

    std::cout << "Enter course ID: "; std::cin >> courseID;
    std::cout << "Enter course Title: "; std::cin >> courseTitle;
    std::cout << "Enter the room number: "; std::cin >> roomNumber;
    std::cout << "Enter the # of contact hours: "; std::cin >> contactHours;
    std::cout << "Enter the credit hours: "; std::cin >> creditHours;
    std::cout << "Enter the tuition rate: "; std::cin >> tuitionRate;

    Course* test = new CirriculumClass( courseID, courseTitle, roomNumber, 
                                        contactHours, creditHours, tuitionRate );

    expand_list_one_more(classes, class_list_size);
    classes[class_list_size - 1] = test;
}

void add_continuing(Course** &classes, int &class_list_size)
{
    int courseID, roomNumber, contactHours;
    double fee;
    std::string courseTitle;

    std::cout << "Enter course ID: "; std::cin >> courseID;
    std::cout << "Enter course Title: "; std::cin >> courseTitle;
    std::cout << "Enter the room number: "; std::cin >> roomNumber;
    std::cout << "Enter the # of contact hours: "; std::cin >> contactHours;
    std::cout << "Enter the course fee: "; std::cin >> fee;

    Course* test = new ContinuingEducation( courseID, courseTitle, roomNumber, contactHours, fee );
    
    expand_list_one_more(classes, class_list_size);
    classes[class_list_size - 1] = test;
}

int get_menu()
{
    int selection;
    std::cout << "   [Class Program Main Menu]" << std::endl
              << "0. Load a default pre-programmed array of courses" << std::endl
              << "1. Add a curriculum class to schedule" << std::endl
              << "2. Add a continuing education class to schedule" << std::endl
              << "3. Display all records" << std::endl
              << "4. Clear the list of classes" << std::endl
              << "9. Exit" << std::endl
              << " > ";
    std::cin >> selection;
    return selection;
}

void do_menu(int selection, Course** &classes, int &class_list_size)
{
    std::cout << std::endl;

    switch(selection)
    {
        case 0: // Load a default pre-programmed array of courses
        {
            std::cout << "Loading the default preprogrammed class list" << std::endl;
            the_default_list(classes, class_list_size);
        }
        break;
        case 1: //Add a curriculum class to schedule
        {
            std::cout << "[Adding a new Cirriculum Class]" << std::endl;
            add_curriculum(classes, class_list_size);
        } 
        break;
        case 2: //Add a continuing education class to schedule
        {
            std::cout << "[Adding a new Continuing Education Class]" << std::endl;
            add_continuing(classes, class_list_size);
        } 
        break;
        case 3: //Display all records
        {
            std::cout << "Printing a list of all Classes" << std::endl;
            for(int i = 0; i < class_list_size; i++)
            {
                classes[i]->show();
            }
        } 
        break;
        case 4: //Clear the list of classes
        {
            std::cout << "Clearing the list of saved classes" << std::endl;
            delete [] classes;
            class_list_size = 0;
            classes = new Course*[0];
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

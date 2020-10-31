/*
Program 2: A Class Called die 
Part A Create a class called die (the singular of dice). The die class should have a single 
data member called value. The die constructor should initialize the die’s value to 1. 
Create a member function called roll() that gives the die a random value between 1 and 6. 
Create a member function called show() that displays value. In main, demonstrate the creation 
of a die object to validate it is working. 

Part B Revise main to count the number of occurrences of each die value. The best result is 
maximum number of any particular value. If you have the same number of two values, the higher 
value determines the best result. Sample Output: Roll: 23541 Best result: You have one 5 Roll: 
12346 Best result: You have one 6 Roll: 41321 Best result: Two of a kind: 1 Roll: 44364 Best 
result: Three of a kind: 4 Roll: 65533 Best result: Two of a kind: 5 (Note: even though there 
are two three's, the two five's make up the better result.)
*/

#include <iostream>
#include <iomanip>
#include "Die.cpp"

int main(){
    die test_die;
    int roll_test_count, highest_index, words_index;
    
    //statistic counting, how many times 2 of a kind, 3 of a kind, 4 of a kind etc.. occurs
    int word_index_count[5] = {0};

    //count for how many times each face value of the die occurs, 0-based index 
    int die_roll_count[6] = {0}; 

    //if the face value of the die occured x amount of times then its called: two of a kind, 3 of a kind, etc..
    std::string words[5] = {"Single roll", "Two of a kind", "Three of a kind", 
                           "Four of a kind", "Perfect roll"};

    std::cout << "How many times would you like to run the roll test? ";
    std::cin >> roll_test_count;

    int x = roll_test_count;

    //while x goes to 0
    while(x --> 0){
        //reset the counts to zero
        for(int i = 0; i < 6; i++)
            die_roll_count[i] = 0;
        highest_index = 0;

        //conduct a single test of 5 rolls
        std::cout << "Roll: ";
        for(int i = 0; i < 5; i++){
            test_die.Roll();
            std::cout << test_die.Show();
            //add the face value of a single roll to the face value count
            die_roll_count[test_die.Show()-1]++;
        }

        //loop through the counts for each face of the die
        for(int i = 0; i < 6; i++)
            /*compare the face value of the side multiped by the occurence of the side
             with the current highest combo*/
            if(die_roll_count[highest_index] * (highest_index + 1) <= die_roll_count[i] * (i + 1) )
                highest_index = i;

        //the index for the wording is zero-based
        //"single roll" = 0, "2 of a kind" = 1, "3 of a kind" = 2 etc..
        words_index = die_roll_count[highest_index] - 1;

        //statistic counting, how many times did 2 of a kind, 3 of a kind etc occur during all the tests
        word_index_count[words_index]++;

        //output the naming of type of occurence for the highest face value combo
        std::cout << " Best result: " << words[words_index] << ": " << highest_index + 1 << std::endl;

        if(words_index == 4) 
            std::cout << "!!!!!!!!!!!!!!!!!!!!!! 5 of  a kind !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"; 
    }

    if(99 < roll_test_count){
        std::cout << "Statistic occurence:\n" << std::fixed << std::setprecision(2);
            for(int i = 0; i < 5; i++){
                std::cout << words[i] << " happend " << word_index_count[i] << " times, or ";
                std::cout << ( (double)word_index_count[i] / (double)roll_test_count) * 100.0 <<"%\n";
            }
    }
    
    return 0;
}

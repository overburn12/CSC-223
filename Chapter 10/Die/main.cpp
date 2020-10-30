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
    int word_index_count[6] = {0};
    int die_roll_count[6] = {0};
    std::string words[6] = {"Single roll", "Two of a kind", "Three of a kind", 
                           "Four of a kind", "Five of a kind", "Perfect roll"};

    std::cout << "How many times would you like to run the roll test? ";
    std::cin >> roll_test_count;

    for(int x = 0; x < roll_test_count; x++){
        for(int i = 0; i < 6; i++)
            die_roll_count[i] = 0;
        highest_index = 0;

        std::cout << "Roll: ";
        for(int i = 0; i < 5; i++){
            test_die.Roll();
            std::cout << test_die.Show();
            die_roll_count[test_die.Show()-1]++;
        }

        for(int i = 5; i >= 0; i--)
            if(die_roll_count[highest_index] * (highest_index + 1) < die_roll_count[i] * (i + 1) )
                highest_index = i;

        words_index = die_roll_count[highest_index] - 1;
        word_index_count[words_index]++;
        std::cout << " Best result: " << words[words_index] << ": " << highest_index + 1 << std::endl;
    }

    if(roll_test_count > 20){
        std::cout << "Statistic occurence:\n" << std::fixed << std::setprecision(2);
            for(int i = 0; i < 6; i++){
                std::cout << words[i] << " happend " << word_index_count[i] << " times, or ";
                std::cout << ( (double)word_index_count[i] / (double)roll_test_count) * 100.0 <<"%\n";
            }
    }
    
    return 0;
}

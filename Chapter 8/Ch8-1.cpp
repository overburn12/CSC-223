/*
(Game: hangman) Write a gangman game that randomly generates a word and prompts the user 
to guess one letter at a time, as showm in the sample run. Each letter in the word is 
displayed as an asterisk. When the user makes a correct guess, the actual letter is then 
displayed. When the user finishes a word, display the number of misses and ask the user 
whether to continue to play with another word. Declare an arroay to store words, 
as follow: Store 20 different words in a text file, read them into an array. Randomly 
pick a number 1..20 and use this word for the current round.
*/

#include <iostream>
//#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

char WordMap[255][255]={0};
bool GuessedLetters[26]={false};
int CurrentWord;
int WordListSize;

void LoadWords(string strFileName){
    ifstream inFile(strFileName.c_str());

    for(WordListSize=0; !inFile.eof(); WordListSize++)
        inFile.get(WordMap[WordListSize],255);

    inFile.close();
}

void StartNewWord(){
    CurrentWord = rand() % WordListSize;
    
    for(int i=0; i<26; i++)
        GuessedLetters[i]=false;
}

int main(){


    return 0;
}

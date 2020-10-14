/*
(Game: hangman) Write a hangman game that randomly generates a word and prompts the user 
to guess one letter at a time, as showm in the sample run. Each letter in the word is 
displayed as an asterisk. When the user makes a correct guess, the actual letter is then 
displayed. When the user finishes a word, display the number of misses and ask the user 
whether to continue to play with another word. Declare an arroay to store words, 
as follow: Store 20 different words in a text file, read them into an array. Randomly 
pick a number 1..20 and use this word for the current round.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

string WordList[255]={""};
int WordListSize;

void LoadWords(string StrFileName){
    ifstream InFile(StrFileName.c_str());

    for(WordListSize=0; !InFile.eof(); ++WordListSize)
        InFile >> WordList[WordListSize];

    InFile.close();
}

char lcase(char letter){
    if('A' <= letter && letter <= 'Z')
        letter=letter-'A'+'a';
    return letter;
}

void PlayRound(){
    srand(time(0));
    int CurrentWord = rand() % WordListSize;

    string HiddenWord = WordList[CurrentWord];
    int WordLen = HiddenWord.length();
    string VisibleWord (WordLen, '*');

    bool FoundTheLetter;
    bool AlreadyGuessed;
    int Missed=0;
    char TheLetter;

    do{
        cout << "(Guess) Enter a letter in word " << VisibleWord << " > ";
        cin >> TheLetter;
        TheLetter=lcase(TheLetter);
        FoundTheLetter=false;
        AlreadyGuessed=false;

        for(int i=0; i<WordLen; i++){
            if(lcase(VisibleWord[i])==TheLetter){
                AlreadyGuessed=true;
                break;
            }

            if(lcase(HiddenWord[i])==TheLetter){
                VisibleWord[i]=HiddenWord[i];
                HiddenWord[i]='*';
                FoundTheLetter=true;
            }
        }

        if(AlreadyGuessed){
            cout << "\t" << TheLetter << " is already in the word" << endl;
        }else if(!FoundTheLetter){
            Missed++;
            cout << "\t" << TheLetter << " is not in the word. You have missed " << Missed << " time";
            if(Missed!=1)
                cout << "s";
            cout << endl;
        }
    }while(VisibleWord.find('*')!=string::npos);

    cout << "The word is " << VisibleWord << ". you missed " << Missed << " time";
    if(Missed!=1) 
        cout << "s";
    cout << endl;
}

int main(){
    LoadWords("wordlist.txt");
    char PlayAgain;

    do{
        PlayRound();

        cout << "Do you want to guess another word? Enter y or n > ";
        cin >> PlayAgain;
    }while(lcase(PlayAgain) == 'y');

    return 0;
}

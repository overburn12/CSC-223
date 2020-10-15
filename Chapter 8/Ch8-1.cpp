/*
(Game: hangman) Write a hangman game that randomly generates a word and prompts the user 
to guess one letter at a time, as shown in the sample run. Each letter in the word is 
displayed as an asterisk. When the user makes a correct guess, the actual letter is then 
displayed. When the user finishes a word, display the number of misses and ask the user 
whether to continue to play with another word. Declare an array to store words, 
as follow: Store 20 different words in a text file, read them into an array. Randomly 
pick a number 1..20 and use this word for the current round.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

string WordList[255] = {""};
int WordListSize;

void LoadWords(string StrFileName){
    ifstream InFile (StrFileName.c_str());
    string TempWord;
    WordListSize = 0;
    while(!InFile.eof() && WordListSize < 255){
        TempWord = "";
        InFile >> TempWord;
        if(TempWord.length() == 0 || TempWord.find('*') != string::npos) 
            continue; //Skip any empty lines at the end of the file, or if the word contains an asterisk
        WordList[WordListSize++] = TempWord;
    }
    InFile.close();
}

size_t FindAnyCase(string StrInput, char TheLetter){
    if(StrInput.find(TheLetter) != string::npos)
        return StrInput.find(TheLetter);
    if('a' <= TheLetter && TheLetter <= 'z') //if were lowercase, convert to upper
        TheLetter = TheLetter - 'a' + 'A';
    else if('A' <= TheLetter && TheLetter <= 'Z') //else if were uppercase, convert to lower
        TheLetter = TheLetter - 'A' + 'a';
    return StrInput.find(TheLetter);
}

string MaskTheWord(string StrInput){
    string ret (StrInput.length(), '*');
    //loop through and check for non-letters in input string
    for(int i = 0; i < StrInput.length(); ++i)
        if( !('a' <= StrInput[i] && StrInput[i] <= 'z') && 
            !('A' <= StrInput[i] && StrInput[i] <= 'Z') )
            ret[i] = StrInput[i]; //copy over the char becasue it's not a letter
    return ret;
}

void PlayRound(){
    /*Method: There are 2 strings for the current word. HiddenWord and VisibleWord.
    VisibleWord is the string printed to the screen, HiddenWord is the unsolved word.
    HiddenWord starts out as the full word to be guessed, VisibleWord starts out as 
    all asterisks. As the user enters letters, a loop looks through the HiddenWord
    and flips any matching letters into the VisibleWord, then replaces the letter
    in the HiddenWord with an asterisk. Therefore, when the word has been solved
    the VisibleWord will display the full word, and the HiddenWord will be replaced 
    with all asterisks.*/
    int CurrentWord = rand() % WordListSize;
    string HiddenWord = WordList[CurrentWord]; 
    string VisibleWord = MaskTheWord(HiddenWord); 
    bool FoundTheLetter;
    int i, Missed = 0;
    char TheLetter;
    do{
        cout << "(Guess) Enter a letter in word " << VisibleWord << " > ";
        cin >> TheLetter;
        if(TheLetter == '*')
            continue; //to avoid an infinite loop
        FoundTheLetter = false;
        if(FindAnyCase(VisibleWord, TheLetter) != string::npos){
            cout << "\t" << TheLetter << " is already in the word" << endl;
        }else{
            while(FindAnyCase(HiddenWord, TheLetter) != string::npos){
                i = FindAnyCase(HiddenWord, TheLetter);
                VisibleWord[i] = HiddenWord[i];
                HiddenWord[i] = '*';
                FoundTheLetter = true;
            }
            if(!FoundTheLetter){
                Missed++;
                cout << "\t" << TheLetter << " is not in the word" << endl;
            }
        }
    }while(VisibleWord.find('*') != string::npos);
    cout << "The word is " << VisibleWord << ". you missed " << Missed << " time";
    if(Missed != 1) 
        cout << "s";
    cout << endl;
}

int main(){
    srand(time(0));
    LoadWords("wordlist.txt");
    char PlayAgain;
    do{
        PlayRound();
        cout << "Do you want to guess another word? Enter y or n > ";
        cin >> PlayAgain;
    }while(PlayAgain == 'Y' || PlayAgain == 'y');
    return 0;
}

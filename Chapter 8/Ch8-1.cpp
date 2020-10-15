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
            continue;
        WordList[WordListSize++] = TempWord;
    }
    InFile.close();
}

size_t FindAnyCase(string StrInput, char InputLetter){
    if(StrInput.find(InputLetter) != string::npos)
        return StrInput.find(InputLetter);
    if('a' <= InputLetter && InputLetter <= 'z')
        InputLetter = InputLetter - 'a' + 'A';
    else if('A' <= InputLetter && InputLetter <= 'Z')
        InputLetter = InputLetter - 'A' + 'a';
    return StrInput.find(InputLetter);
}

string MaskTheWord(string StrInput){
    string ret (StrInput.length(), '*');
    for(int i = 0; i < StrInput.length(); ++i)
        if( !('a' <= StrInput[i] && StrInput[i] <= 'z') && 
            !('A' <= StrInput[i] && StrInput[i] <= 'Z') )
            ret[i] = StrInput[i];
    return ret;
}

void PlayRound(){
    string HiddenWord = WordList[rand() % WordListSize]; 
    string VisibleWord = MaskTheWord(HiddenWord); 
    bool FoundTheLetter;
    int i, Missed = 0;
    char InputLetter;
    do{
        cout << "(Guess) Enter a letter in word " << VisibleWord << " > ";
        cin >> InputLetter;
        if(InputLetter == '*')
            continue;
        FoundTheLetter = false;
        if(FindAnyCase(VisibleWord, InputLetter) != string::npos){
            cout << "\t" << InputLetter << " is already in the word" << endl;
        }else{
            while(FindAnyCase(HiddenWord, InputLetter) != string::npos){
                i = FindAnyCase(HiddenWord, InputLetter);
                VisibleWord[i] = HiddenWord[i];
                HiddenWord[i] = '*';
                FoundTheLetter = true;
            }
            if(!FoundTheLetter){
                Missed++;
                cout << "\t" << InputLetter << " is not in the word" << endl;
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

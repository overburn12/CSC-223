/*
4-4: Voter Tally
 Citizens in a nearby county recently voted whether or not to approve a bond referendum
  to finance the construction of a new school. The first five results of that vote are 
  contained in the file votes.dat. Write a program that reads the file (votes.dat). 
  The program should summarize the voting data to include a total tally of “yes” and “no” 
  votes as well as a break-down of votes based on the voter’s district. 
  For example, a sample votes.dat file might contain the data shown below. 
  The first value within a line is the voter’s district (1-3). 
  The second value within a line indicates whether the voter approved (Y) or disapproved (N)
   of the measure. Remember, you may quickly make a data file using any text editor such as Windows Notepad. 
   1 Y 2 N 3 N 3 Y 1 Y 2 Y
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main(){
    //Arrays or vectors would be best here
    //but this project is to use switch cases
    int Dist1Yes=0, Dist1No=0;
    int Dist2Yes=0, Dist2No=0;
    int Dist3Yes=0, Dist3No=0;

    char cTempVote;
    int TempDistrict;
    bool VotedYes;

    ifstream InFile("votes.dat");

    while(!InFile.eof()){
        InFile >> TempDistrict >> cTempVote;
        
        if(cTempVote == 'Y' || cTempVote=='y')
            VotedYes=true;
        else
            VotedYes=false;
        
        switch(TempDistrict){
            case 1:
                if(VotedYes)
                    Dist1Yes++;
                else
                    Dist1No++;
            break;
            case 2:
                if(VotedYes)
                    Dist2Yes++;
                else
                    Dist2No++;
            break;
            case 3:
                if(VotedYes)
                    Dist3Yes++;
                else
                    Dist3No++;
            break;
            default:
                cout << "Error! incorrect district number: " << TempDistrict << endl;
        }
    }

    int DisplayOffset = 30;
    int TotalVotes = Dist1Yes + Dist1No + 
                     Dist2Yes + Dist2No + 
                     Dist3Yes + Dist3No;

    cout << endl;
    cout << setw(DisplayOffset) << "[VoterTally from votes.dat]" << endl;
    cout << endl;
    cout << setw(DisplayOffset) << "District 1 total votes: " << Dist1Yes + Dist1No << endl;
    cout << setw(DisplayOffset) << "Voted yes: " << Dist1Yes << endl;
    cout << setw(DisplayOffset) << "Voted no: " << Dist1No << endl ;
    cout << endl;
    cout << setw(DisplayOffset) << "District 2 total votes: " << Dist2Yes + Dist2No << endl;
    cout << setw(DisplayOffset) << "Voted yes: " << Dist2Yes << endl;
    cout << setw(DisplayOffset) << "Voted no: " << Dist2No << endl;
    cout << endl;
    cout << setw(DisplayOffset) << "District 3 total votes: " << Dist3Yes + Dist3No << endl;
    cout << setw(DisplayOffset) << "Voted yes: " << Dist3Yes << endl;
    cout << setw(DisplayOffset) << "Voted no: " << Dist3No << endl;
    cout << endl;
    cout << setw(DisplayOffset) << "Grand total votes: " << TotalVotes << endl;
    cout << endl;

    InFile.close();
    return 0;
}
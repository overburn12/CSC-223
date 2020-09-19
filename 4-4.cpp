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
    int Dist1Yes=0, Dist1No=0;
    int Dist2Yes=0, Dist2No=0;
    int Dist3Yes=0, Dist3No=0;
    char cTempVote;
    int TempDistrict;
    bool VotedYes;
    ifstream InFile("votes.dat");

    while(!InFile.eof()){
        InFile >> TempDistrict >> cTempVote;
        if(cTempVote!='Y' && cTempVote!='N') 
            break;
        if(cTempVote == 'Y' || cTempVote=='y'){
            switch(TempDistrict){
            case 1:
                Dist1Yes++;
                break;
            case 2:
                Dist2Yes++;
                break;
            case 3:
                Dist3Yes++;
                break;
            default:
            }
        }else{
            switch(TempDistrict){
            case 1:
                Dist1No++;
                break;
            case 2:
                Dist2No++;
                break;
            case 3:
                Dist3No++;
                break;
            default:
            }
        }
    }

    int RightOffset = 30;
    int TotalVotes = Dist1Yes + Dist1No + Dist2Yes + Dist2No + Dist3Yes + Dist3No;

    cout << endl;
    cout << setw(RightOffset) << "[VoterTally from votes.dat]" << endl << endl;
    cout << setw(RightOffset) << "District 1 total votes: " << Dist1Yes + Dist1No << endl;
    cout << setw(RightOffset) << "Voted yes: " << Dist1Yes << endl;
    cout << setw(RightOffset) << "Voted no: " << Dist1No << endl << endl;
    cout << setw(RightOffset) << "District 2 total votes: " << Dist2Yes + Dist2No << endl;
    cout << setw(RightOffset) << "Voted yes: " << Dist2Yes << endl;
    cout << setw(RightOffset) << "Voted no: " << Dist2No << endl << endl;
    cout << setw(RightOffset) << "District 3 total votes: " << Dist3Yes + Dist3No << endl;
    cout << setw(RightOffset) << "Voted yes: " << Dist3Yes << endl;
    cout << setw(RightOffset) << "Voted no: " << Dist3No << endl << endl;
    cout << setw(RightOffset) << "Grand total votes: " << TotalVotes << endl << endl;
    InFile.close();
    return 0;
}
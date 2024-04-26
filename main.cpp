#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "bug.h"
#include "crawler.h"
#include "hopper.h"
#include "board.h"


using namespace std;

void outputFileStream();
void parseLine(const string& strLine,     vector<bug*> &bugs);
void inputFileStream(vector<bug*> &bugs);


int main() {

    board newBoard;

    newBoard.inputFileStream();


//
//    inputFileStream(bugs);
    cout << "Initialised file! " << endl;


    int choice;
    do
         {

            cout << "Please choose an option: " << endl;
            cout << "1: Display all bugs. " << endl;
            cout << "2: Find a specific bug. " << endl;
            cout << "3: Tap the board. " << endl;
            cout << "4: Display history of all bugs. " << endl;
            cout << "5: Display all cells. " << endl;
            cout << "6: Run Simulation. " << endl;
            cout << "0: Exit. " << endl;

            cin >> choice;

             if(choice == 1){
                 newBoard.displayAll();
             } else if (choice == 0){
                 outputFileStream();
                 break;
             }

        }while (choice != 0);

    return 0;
}

void outputFileStream(){
    ofstream outFileStream("bugs_life_history_date_time.out"); //bug history file

    if (outFileStream.good() )
    {
        outFileStream <<"testWrite?";

        outFileStream.close();
        cout <<"File has been written"<< endl;
    }
    else
        cout <<"unable to open file";


}

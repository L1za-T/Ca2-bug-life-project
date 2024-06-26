#include <iostream>
#include <fstream>
#include "board.h"


using namespace std;

void outputFileStream(board& newboard);


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

             if(choice == 1) {
                 newBoard.displayAll(std::cout);
             } else if (choice == 2){
                 cout << "Please enter the id you wish to find: "<<endl;
                 cin>> choice;
                 newBoard.findABug(choice);

             }else if(choice == 3 ){
                 newBoard.tapBoard();

             }else if(choice == 4 ){
                 newBoard.displayLifeHistory(std::cout);

             }else if (choice == 0){
                 outputFileStream(newBoard);
                 break;
             }

        }while (choice != 0);

    return 0;
}

void outputFileStream(board &b){
    ofstream outFileStream("bugs_life_history_date_time.out"); //bug history file

    if (outFileStream.good() )
    {

        b.displayLifeHistory(outFileStream);

        outFileStream.close();
        cout <<"File has been written"<< endl;
    }
    else
        cout <<"unable to open file";


}

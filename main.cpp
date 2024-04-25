#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void outputFileStream();
void parseLine(const string& strLine);
void inputFileStream();


int main() {
    outputFileStream();
    inputFileStream();
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


void inputFileStream()
{

    ifstream inFileStream("bugs.txt");

    if (inFileStream.good() )
    {
        string line;
        while (getline(inFileStream, line)) {
            parseLine(line);
        }
        inFileStream.close();
    }
    else
        cout <<"Unable to open file, or file is empty.";

}

void parseLine(const string& strLine){

    //turns line into string stream
    stringstream strStream( strLine );


    const char DELIMITER = ';'; //sets delimiter

    //Fields gathered from bugs.txt
    char *type;
    int id = 0;
    int xCoord = 0;
    int yCoord = 0;
    int direction = 0;
    int size = 0;
    int hopLength = 0;

    getline(strStream, type, DELIMITER);

    try {
        string strTemp;
        getline(strStream, strTemp, DELIMITER);
        type = strTemp.data();

        getline(strStream, strTemp, DELIMITER);
        id = stoi(strTemp);

        getline(strStream, strTemp, DELIMITER);
        xCoord = stoi(strTemp);

        getline(strStream, strTemp, DELIMITER);
        yCoord = stoi(strTemp);

        getline(strStream, strTemp, DELIMITER);
        direction = stoi(strTemp);

        getline(strStream, strTemp, DELIMITER);
        size = stoi(strTemp);

        getline(strStream, strTemp, DELIMITER);
        hopLength = stoi(strTemp);
    }
    catch (std::invalid_argument const& e){
        cout <<"bad input: std::invalid_argument thrown"<< '\n';
    }
    catch (std::out_of_range const& e){
        cout <<"Integer overflow: std::out_of_range thrown"<< '\n';
    }
    cout <<"Type:  "<< type << "id " << id <<"xCoord: "<< xCoord <<"yCoord: "<< yCoord <<"direction: " << direction<<"size: "<< size<< "hopLength: "<< hopLength<< endl;

}
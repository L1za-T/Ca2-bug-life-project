//
// Created by L1za on 26/04/2024.
//

#include "board.h"



void board::inputFileStream()
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

void board::parseLine(const string& strLine){

    //turns line into string stream
    stringstream strStream( strLine );


    const char DELIMITER = ';';//sets delimiter

    //Fields gathered from bugs.txt
    string type;
    int id = 0;
    int xCoord = 0;
    int yCoord = 0;
    int direction = 0;
    int size = 0;
    int hopLength = 0;


    try {
        string strTemp;
        getline(strStream, strTemp, DELIMITER);
        type = strTemp;

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



        if (type=="C") {
            auto *crawlerPtr = new crawler(id, xCoord, yCoord, static_cast<directions>(direction-1), size);
            crawlerPtr->positionToPair(xCoord,yCoord);
            bugs.push_back(crawlerPtr);

        }else if (type== "H") {
            getline(strStream, strTemp, DELIMITER);
            hopLength = stoi(strTemp);
            auto *hopperPtr = new hopper( id, xCoord, yCoord, static_cast<directions>(direction-1), size, hopLength);
            hopperPtr->positionToPair(xCoord, yCoord);
            bugs.push_back(hopperPtr);
        }
    }
    catch (std::invalid_argument const& e){
        cout <<"bad input: std::invalid_argument thrown"<< '\n';
    }
    catch (std::out_of_range const& e){
        cout <<"Integer overflow: std::out_of_range thrown"<< '\n';
    }
//    cout <<"Type:  "<< type << " id: " << id <<" xCoord: "<< xCoord <<" yCoord: "<< yCoord <<" direction: " << direction<< " size: "<< size << " hopLength: " << hopLength<< endl;

}

void board::displayAll() {
    for (bug *b: bugs) {
        cout <<"Id: " << b->getId() <<" coordinates: (" << b->getPosition().first <<","<< b->getPosition().second <<")" <<" direction: " << b->getDir() << " size: "<< b->getSize() << " hopLength: :shrug:"<< endl;

//        cout <<"Type:  "<< type << " id: " << id <<" xCoord: "<< xCoord <<" yCoord: "<< yCoord <<" direction: " << direction<< " size: "<< size << " hopLength: " << hopLength<< endl;
    }

}
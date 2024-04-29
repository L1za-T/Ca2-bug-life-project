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

//            cout <<"Crawler: " << crawlerPtr->getType() << " ID: " << crawlerPtr->getId() << " Direction: " << crawlerPtr->getDir() << endl;

        }else if (type== "H") {
            getline(strStream, strTemp, DELIMITER);
            hopLength = stoi(strTemp);
            auto *hopperPtr = new hopper( id, xCoord, yCoord, static_cast<directions>(direction-1), size, hopLength);
            hopperPtr->positionToPair(xCoord, yCoord);
            bugs.push_back(hopperPtr);

//            cout <<"Type: "<< hopperPtr->getType() << " ID: " << hopperPtr->getId() << " Direction: " << hopperPtr->directionToString(hopperPtr->getDir()) << " Hop Length: " << hopperPtr->gethopLength() << endl;

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

void board::displayAll(ostream& out) {
    for (bug *b: bugs) {

        out <<"Id: " << b->getId() <<" Type: " << findType(b) <<" Coordinates: (" << b->getPosition().first <<","<< b->getPosition().second <<") Direction: " << b->directionToString(b->getDir()) << " Size: "<< b->getSize() << " Hop Length: " << findHopLength(b) << " Status: " << status(b) << endl;


    }

}

void board::findABug(int bugId){
    bool foundBug = 0;

    for (bug *b: bugs) {
        if(b->getId() == bugId){
            cout <<"Id: " << b->getId() <<" Type: " << findType(b) <<" Coordinates: (" << b->getPosition().first <<","<< b->getPosition().second <<") Direction: " << b->directionToString(b->getDir()) << " Size: "<< b->getSize() << " Hop Length: " << findHopLength(b) << " Status: " << status(b) << endl;
            foundBug = 1;
        }
    }
    if (foundBug ==0){
        cout <<"Bug: "<< bugId << " not found" << endl;
    }

}

void board::tapBoard(){
    for(bug *b: bugs){
            b->move();
//            cout << "Id: " << b->getId() << "("<< b->getPath().back().first << "," << b->getPath().back().second << ")"<<" Direction: " << b->directionToString(b->getDir()) << endl;
    }
}

string board::findHopLength(bug *b){
    if(const hopper* hopper = dynamic_cast<const class hopper*>(b)){
        return to_string(hopper->gethopLength());
    };
    return "N/A";
}

string board::findType(bug *b){
    if(const hopper* hopper = dynamic_cast<const class hopper*>(b)){
        return "Hopper";
    } else if(const crawler* crawler = dynamic_cast<const class crawler*>(b)){
        return "Crawler";
    }
    return "N/A";
}

string board::status(bug *b){
    if(b->isAlive() == 1){
        return "Alive";
    };
    return "Dead";
}
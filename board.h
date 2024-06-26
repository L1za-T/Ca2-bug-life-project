//
// Created by L1za on 26/04/2024.
//

#ifndef BUG_LIFE_PROJECT_BOARD_H
#define BUG_LIFE_PROJECT_BOARD_H
#include "bug.h"
#include "crawler.h"
#include "hopper.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class board {
    vector<bug*> bugs;
public:

    void parseLine(const string& strLine);
    void inputFileStream();
    void displayAll(ostream& out);

    string findHopLength(bug *b);

    string status(bug *b);

    string findType(bug *b);

    void findABug(int choice);

    void tapBoard();

    void displayLifeHistory(ostream &out);
};


#endif //BUG_LIFE_PROJECT_BOARD_H

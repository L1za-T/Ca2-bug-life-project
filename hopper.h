//
// Created by L1za on 24/04/2024.
//

#ifndef BUG_LIFE_PROJECT_HOPPER_H
#define BUG_LIFE_PROJECT_HOPPER_H
#include "bug.h"

using namespace std;
class hopper: public bug{
public:
    hopper(int id, int xCoord, int yCoord, directions dir, int size, int hopLength);

    int gethopLength() const;
//    hopper(int id, const pair<int, int> &position, int size, bool alive, const list<pair<int, int>> &path,
//           int hopLength);



private:
    virtual void move();

    int hopLength;
};



#endif //BUG_LIFE_PROJECT_HOPPER_H

//
// Created by L1za on 24/04/2024.
//

#ifndef BUG_LIFE_PROJECT_CRAWLER_H
#define BUG_LIFE_PROJECT_CRAWLER_H
#include "bug.h"

using namespace std;
class crawler: public bug{
public:
    crawler(int id, const pair<int, int> &position, int size, bool alive, const list<pair<int, int>> &path);

private:
    virtual void move();
};


#endif //BUG_LIFE_PROJECT_CRAWLER_H

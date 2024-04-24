//
// Created by L1za on 24/04/2024.
//

#include "crawler.h"


void crawler::move()
{

}

crawler::crawler(int id, const pair<int, int> &position, int size, bool alive, const list<pair<int, int>> &path) : bug(
        id, position, size, alive, path) {}

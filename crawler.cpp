//
// Created by L1za on 24/04/2024.
//

#include "crawler.h"


void crawler::move()
{
    if(alive) {
        while (isWayBlocked()) {
            dir = static_cast<directions>((rand() % 4));
        }

        if (dir == 0) {
            position.second = position.second - 1; // South to North
        }
        if (dir == 2) {
            position.second = position.second + 1; // North to South
        }
        if (dir == 1) {
            position.first = position.first + 1; // West to East
        }
        if (dir == 3) {
            position.first = position.first - 1; // East to West
        }
        updatePath();
    }
}

crawler::crawler(int id, int xCoord, int yCoord, directions dir, int size)
: bug(id, xCoord,yCoord,dir, size) {

}


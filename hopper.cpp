//
// Created by L1za on 24/04/2024.
//

#include "hopper.h"




void hopper::move() {
//    if(alive){
//        while (isWayBlocked()) {
//            dir = static_cast<directions>((rand() % 4));
//        }
//        if (dir == 0) {
//            position.second = position.second - hopLength;
//        }
//        if (dir == 2) {
//            position.second = position.second + hopLength;
//        }
//        if (dir == 1) {
//            position.first = position.first - hopLength;
//        }
//        if (dir == 3) {
//            position.first = position.first + hopLength;
//        }
//        updatePath();
//
//    }

    if(alive) {
        while (isWayBlocked()) {
            dir = static_cast<directions>((rand() % 4));
        }

        if (dir == 0) {
            position.second = position.second - hopLength; // South to North
        }
        if (dir == 2) {
            position.second = position.second + hopLength; // North to South
        }
        if (dir == 1) {
            position.first = position.first + hopLength; // West to East
        }
        if (dir == 3) {
            position.first = position.first - hopLength; // East to West
        }
        updatePath();
    }

}

hopper::hopper(int id, int xCoord, int yCoord, directions dir, int size, int hopLength):bug(id, xCoord, yCoord,dir, size)
{
    sethopLength(hopLength);

}

void hopper::sethopLength(int hopLength) {
    hopper::hopLength = hopLength;
}

bool hopper::isWayBlocked() {

    if(position.second - hopLength < 0 && dir == 0){ //  North
        return true;
    }
    if(position.second + hopLength >9 && dir == 2){ //   South
        return true;
    }
    if(position.first + hopLength > 9 && dir == 1){ //  East
        return true;
    }
    if(position.first - hopLength < 0 && dir == 3){ //  West
        return true;
    }
    return false;
}
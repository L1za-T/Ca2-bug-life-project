//
// Created by L1za on 24/04/2024.
//

#include "hopper.h"




void hopper::move() {


}

hopper::hopper(int id, int xCoord, int yCoord, directions dir, int size, int hopLength):bug(id, xCoord, yCoord,dir, size)
{
    sethopLength(hopLength);

}

void hopper::sethopLength(int hopLength) {
    hopper::hopLength = hopLength;
}

bool hopper::isWayBlocked() {
    if(position.second-hopLength >= 0 && dir == 3){
        return true;
    }
    if(position.second+hopLength <= 9 && dir == 1){
        return true;
    }
    if(position.first-hopLength >= 0 && dir == 0){
        return true;
    }
    if(position.first+hopLength <= 9 && dir == 2){
        return true;
    }
    return false;
}

//int hopper::gethopLength() const {
//    return hopLength;
//}



//int hopper::hopLength() const {
//    return 0;
//}

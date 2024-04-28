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

//int hopper::gethopLength() const {
//    return hopLength;
//}



//int hopper::hopLength() const {
//    return 0;
//}

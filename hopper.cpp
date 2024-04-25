//
// Created by L1za on 24/04/2024.
//

#include "hopper.h"

hopper::hopper(int id, const pair<int, int> &position, int size, bool alive, const list<pair<int, int>> &path,
               int hopLength) : bug(id, position, size, alive, path), hopLength(hopLength) {

}


void hopper::move() {

}
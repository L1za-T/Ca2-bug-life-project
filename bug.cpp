//
// Created by L1za on 24/04/2024.
//

#include "bug.h"

bug::bug(int id, int x, int y, directions dir, int size, bool alive)
: id(id),
position(x, y),
size(size),
alive(alive){}

int bug::getId() const {
    return id;
}

directions bug::getDir() const {
    return dir;
}

void bug::setDir(directions dir) {
    bug::dir = dir;
}

void bug::setId(int id) {
    bug::id = id;
}

const pair<int, int> &bug::getPosition() const {
    return position;
}

void bug::setPosition(const pair<int, int> &position) {
    bug::position = position;
}

int bug::getSize() const {
    return size;
}

void bug::setSize(int size) {
    bug::size = size;
}

bool bug::isAlive() const {
    return alive;
}

void bug::setAlive(bool alive) {
    bug::alive = alive;
}

const list<pair<int, int>> &bug::getPath() const {
    return path;
}

void bug::setPath(const list<pair<int, int>> &path) {
    bug::path = path;
}

bool bug::isWayBlocked()
{

}

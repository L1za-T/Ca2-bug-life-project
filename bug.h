//
// Created by L1za on 24/04/2024.
//

#ifndef BUG_LIFE_PROJECT_BUG_H
#define BUG_LIFE_PROJECT_BUG_H
#include <utility>
#include <list>
#include <iostream>

using namespace std;
enum directions {North, East, South, West};

    class bug {
        
    protected:
        string type;
        int id;
        pair<int, int> position;
        int size;
        bool alive;
        list<pair<int,int>> path;
        directions dir;



    public:
//        bug(){};

        bug(int id, int xCoord, int yCoord, directions dir, int size, bool alive=true);

        virtual void move() =0;

        bool isWayBlocked();

        int getId() const;

        void setId(int id);

        const pair<int, int> &getPosition() const;

        void setPosition(const pair<int, int> &position);

        void positionToPair(int xCoord, int yCoord){
            position= make_pair(xCoord, yCoord);
        }

        int getSize() const;

        void setSize(int size);

        bool isAlive() const;

        string getType();

        void setAlive(bool alive);

        const list<pair<int, int>> &getPath() const;

        void setPath(const list<pair<int, int>> &path);

    directions getDir() const;

    void setDir(directions dir);

};

    //auto
 // std

#endif //BUG_LIFE_PROJECT_BUG_H
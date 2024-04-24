//
// Created by L1za on 24/04/2024.
//

#ifndef BUG_LIFE_PROJECT_BUG_H
#define BUG_LIFE_PROJECT_BUG_H
#include <utility>
#include <list>

using namespace std;
enum directions {North, East, South, West};
    class bug {
    protected:
        int id;
        pair<int, int> position;
        int size;
        bool alive;
        list<pair<int,int>> path;

    public:
        bug();

        bug(int id, const pair<int, int> &position, int size, bool alive, const list<pair<int, int>> &path);

        virtual void move() =0;

        bool isWayBlocked();

        int getId() const;

        void setId(int id);

        const pair<int, int> &getPosition() const;

        void setPosition(const pair<int, int> &position);

        int getSize() const;

        void setSize(int size);

        bool isAlive() const;

        void setAlive(bool alive);

        const list<pair<int, int>> &getPath() const;

        void setPath(const list<pair<int, int>> &path);

    };

 // std

#endif //BUG_LIFE_PROJECT_BUG_H
#ifndef ERA_H
#define ERA_H

#include <QString>
#include "lib/sqlite3/sqlite3.h"
#include "headers/world.h"
/*
 * Era class. An Era is a large period of time in the world creation.
 * Each campaign created belongs to an era that is part of our world.
 * This class handles the creation, modification and destruction of these era,


*/

class Era {

public:
   Era(World &w, int id);
   ~Era();
   QString name() const;
private:
    World &world;
    int id;
};

#endif // ERA_H

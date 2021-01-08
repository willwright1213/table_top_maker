#ifndef ERA_H
#define ERA_H

#include <QString>
#include "headers/world.h"

/*
 * Era class. An Era is a large period of time in the world creation.
 * Each campaign created belongs to an era that is part of our world.
 * This class is a model for selected Era from the database.


*/

class Era {

public:
   static int select(World &w, int id);
   static QString& selected_name();
private:
    Era();
    static int id;
    static int select_callback(void *unused, int count, char **data, char **columns);
};

#endif // ERA_H

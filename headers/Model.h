#ifndef MODEL_H
#define MODEL_H

#include "world.h"

class Model {

protected:
    static int select(World &w, int id);
    static void find_id(World &w, std::string table, QString &value, QString column);
    static void create(World &w, std::string table, QHash<QString, QString>);
    static void remove(World &w, std::string table, int id);
};

#endif // MODEL_H


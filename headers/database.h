#ifndef DATABASE_H
#define DATABASE_H

#include "lib/sqlite3/sqlite3.h"
#include "headers/world.h"

namespace database {
    extern sqlite3 *db;
    int openConnection(QDir *path);
    void closeConnection();
}

#endif // DATABASE_H

#include "headers/database.h"

sqlite3* database::db;

int database::openConnection(QDir *path){ return sqlite3_open(path->canonicalPath().toLocal8Bit()+"/world.db", &database::db);}
void database::closeConnection() { sqlite3_close(database::db);}

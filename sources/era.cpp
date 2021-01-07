#include "../headers/era.h"

Era::Era(World& w, int id): world(w), id(id){}

QString Era::name() const {
    sqlite3 *db;
    char *errmsg;

};

#include "../headers/era.h"
#include "headers/world.h"
#include <iostream>


int Era::select(World &w, int id) {
    select::selected_era.clear();
    int execute = 1;
    if(database::openConnection(w.path()) == SQLITE_OK){
        char *errmsg;
        std::string query;
        query = "SELECT name FROM era WHERE id = " + std::to_string(id) + ";";
        sqlite3_exec(database::db, query.c_str(), select_callback, NULL, &errmsg);
    }
    database::closeConnection();
    qDebug() << "closed connection";
    return execute;
};

int Era::select_callback(void *unused, int count, char **data, char **columns){
    int i;
    for(i = 0; i<count;i++)
        select::selected_era.append(data[i]);
    return 0;
}

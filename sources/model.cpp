#include "headers/model.h"
#include <stdexcept>

void Model::create(World &w, std::string table, QHash<QString, QString> input){
    int code = database::insert(w.path(), table, input);
    if(code != SQLITE_OK) throw std::invalid_argument("Could not insert data, error: " + std::to_string(code));
}

void Model::remove(World &w, std::string table, int id){
    database::remove(w.path(), table, id);
}

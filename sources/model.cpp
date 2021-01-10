#include "headers/model.h"
#include <stdexcept>

void Model::create(World &w, std::string table, QHash<QString, QString> input){
    database::insert(w.path(), table, input);
}

void Model::remove(World &w, std::string table, int id){
    database::remove(w.path(), table, id);
};

void Model::find_id(World &w, std::string table, QString &value, QString column){
    database::find_id(w.path(), table, value.toLocal8Bit().constData(), column.toLocal8Bit().constData());
}

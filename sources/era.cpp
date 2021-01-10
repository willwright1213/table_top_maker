#include "../headers/era.h"
#include "headers/world.h"
#include <iostream>

void Era::create(World &w, QString &name, int ordering) {
    QHash<QString, QString> input;
    input.insert("name", name);
    input.insert("ordering", QString::number(ordering));
    Model::create(w, "era", input);
    //xml::generate();

}

void Era::remove(World &w, int id){
    Model::remove(w, "era", id);
}

int Era::find_by_name(World &w, QString &name){
    Model::find_id(w, "era", name, "name");
}

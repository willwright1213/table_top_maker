#include "../headers/era.h"
#include "headers/world.h"
#include <iostream>

void Era::create(World &w, QString &name, int ordering) {

    QHash<QString, QString> input;
    input.insert("name", name);
    input.insert("ordering", QString::number(ordering));
    database::insert(w.path(), "era", input);
    //xml::generate();

}

void Era::remove(World &w, int id){
    database::remove(w.path(), id);
}

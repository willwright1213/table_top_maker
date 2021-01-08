#include "../headers/era.h"
#include "headers/world.h"
#include <iostream>

void Era::create(World &w, QString &name) {

    QHash<QString, QString> input;
    input.insert("name", name);
    database::insert(w.path(), "era", input);
    //xml::generate();

}

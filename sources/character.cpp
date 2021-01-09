#include "headers/character.h"

void Character::create(World &w, QString &name, QString &race, QString &c) {
    QHash<QString, QString> input;
    input.insert("name", name);
    input.insert("ordering", QString::number(ordering));
    Model::create(w, "era", input);
    //xml::generate();

}

void Character::remove(World &w, int id){
    Model::remove(w, "era", id);
}

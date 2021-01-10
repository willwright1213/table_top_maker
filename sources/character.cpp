#include "headers/character.h"

void Character::create(World &w, QString &name, QString &race, QString &c) {
    QHash<QString, QString> input;
    input.insert("name", name);
    input.insert("race", race);
    input.insert("class", c);
    Model::create(w, "characters", input);
    //xml::generate();

}

void Character::remove(World &w, int id){
    Model::remove(w, "era", id);
}

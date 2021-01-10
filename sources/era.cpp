#include "../headers/era.h"
#include "headers/world.h"
#include <iostream>

QHash<QString, QRegExp> Era::validators;

Era::Era(int &id, int &ordering, QString &name)
    :id(id),name(name),ordering(ordering)
{

}


void Era::create(World &w, QString &name, int ordering)
{
    //Generates our Hash
    QHash<QString, QString> input;
    input.reserve(2);
    input.insert("name", name);
    input.insert("ordering", QString::number(ordering));
    if(!Model::validate_all(input, validators)) throw std::invalid_argument("validation error");
    Model::create(w, "era", input);
    //xml::generate();

}

void Era::remove(World &w, int id){
    Model::remove(w, "era", id);
}

int Era::find_by_name(World &w, QString &name)
{
    return Model::find_id(w, "era", name, "name");
}

void Era::initiate_validators()
{
    validators.insert("name", QRegExp("^[a-zA-z'\\-\\s]{2,30}$"));
    validators.insert("ordering", QRegExp("\\d"));
};

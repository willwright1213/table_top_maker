#include "headers/character.h"

QHash<QString, QRegExp> Character::validators;

void Character::create(World &w, const QString &name, const QString &race, const QString &c, const QString &birth_year, const QString &birth_place,
                      const QString &death_year, const QString &death_place,  const QString &bio)
{
    QHash<QString, QString> input;
    input.insert("name", name);
    input.insert("race", race);
    input.insert("class", c);
    input.insert("birth_year", birth_year);
    input.insert("birth_place", birth_place);
    input.insert("bio", bio);
    if(death_year != nullptr) input.insert("death_year", death_year);
    if(death_place != nullptr) input.insert("death_place", death_place);
    if(!Model::validate_all(input, validators)) throw std::invalid_argument("validation error");
    Model::create(w, "characters", input);
    Model::generateHTML(w, "characters", database::selected);
}

void Character::remove(World &w, int id){ Model::remove(w, "characters", id); }

void Character::initiate_validators()
{
    validators.insert("name", QRegExp("^[a-zA-z'\\-\\s]{2,30}$"));
    validators.insert("race", QRegExp("^[a-zA-z'\\-\\s]{2,30}$"));
    validators.insert("class", QRegExp("^[a-zA-z'\\-\\s]{2,30}$"));
    validators.insert("birth_year", QRegExp("^[a-zA-z'\\-\\s\\d]{2,30}$"));
    validators.insert("birth_place", QRegExp("^[a-zA-z'\\-\\s]{2,30}$"));
    validators.insert("death_year", QRegExp("^[a-zA-z'\\-\\s\\d]{0,30}$"));
    validators.insert("death_place", QRegExp("^[a-zA-z'\\-\\s]{0,30}$"));
    validators.insert("bio", QRegExp("."));
};


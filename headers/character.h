#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>
#include "headers/model.h"

#endif // CHARACTER_H

class Character: public Model {
public:
    static void create(World &w, QString &name, QString &race, QString &c, QString &birth_year, QString &birth_place, QString &death_year, QString &death_place);
    static void remove(World &w, int id);
    static void initiate_validators();
protected:
    static QHash<QString, QRegExp> validators;
};

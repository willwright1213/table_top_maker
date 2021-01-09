#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>
#include "headers/model.h"

#endif // CHARACTER_H

class Character: public Model {
    void create(World &w, QString &name, QString &race, QString &c);
    void remove(World &w, int id);
};

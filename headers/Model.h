#ifndef MODEL_H
#define MODEL_H

#include "world.h"

class Model {

protected:
    static int select(World &w, int id);
    static int find_id(World &w, std::string table, QString &value, QString column);
    static void create(World &w, std::string table, QHash<QString, QString>);
    static void remove(World &w, std::string table, int id);
    static bool validate(QString &value, QRegExp validator);
    static bool validate_all(QHash<QString, QString> &values, QHash<QString, QRegExp> validators);
};

#endif // MODEL_H


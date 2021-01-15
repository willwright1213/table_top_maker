#ifndef MODEL_H
#define MODEL_H

#include "world.h"
#include <QRegularExpression>
class Model {

protected:
    static int select(World &w, int id);
    static int find_id(World &w, const QString&table, const QString& value, const QString& column);
    static void create(World &w, const QString& table, QHash<QString, QString>);
    static void remove(World &w, const QString& table, int id);
    static bool validate(QString &value, QRegExp validator);
    static bool validate_all(QHash<QString, QString> &values, QHash<QString, QRegExp> validators);
    static void generateHTML(World &w, QString, QHash<QString, QString>&);
};

#endif // MODEL_H


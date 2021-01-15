#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>
#include "headers/model.h"

class Character: public Model {
public:
    static void create(World &w, const QString &name, const QString &race, const QString &c,  const QString &birth_year,
                       const QString &birth_place, const QString &death_year, const QString &death_place, const QString &bio);
    static void remove(World &w, const QString& id);
    static void initiate_validators();
protected:
    static QHash<QString, QRegExp> validators;
private:
    static void create_html(World &w, QHash<QString, QString> &hash);

};


#endif // CHARACTER_H


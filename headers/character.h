#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>
#include "headers/model.h"

#endif // CHARACTER_H

class Character: public Model {
public:
    static void create(World &w, const QString &name, const QString &race, const QString &c,  const QString &birth_year,
                       const QString &birth_place, const QString &death_year, const QString &death_place, const QString &bio);

    static void create(World &w, QString &name, QString &race, QString &c, QString &birth_year, QString &birth_place);
    static void remove(World &w, int id);
    static void initiate_validators();
    static void generate_template(World &w);
    static void generate_css(World &w);
protected:
    static QHash<QString, QRegExp> validators;
private:
    static void create_html(World &w, QHash<QString, QString> &hash);

};

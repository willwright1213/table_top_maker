#ifndef ERA_H
#define ERA_H

#include <QString>
#include "headers/model.h"

/*
 * Era class. An Era is a large period of time in the world creation.
 * Each campaign created belongs to an era that is part of our world.
 * This class is a model for selected Era from the database.


*/

class Era: public Model {

public:
   Era(int &id, int &ordering, QString &name);
   static int select(World &w, int id);
   static void create(World &w, QString &name, int ordering);
   static void remove(World &w, int id);
   static int find_by_name(World &w, QString &name);
   static QString& selected_name();
   static void initiate_validators();
protected:
   static QHash<QString, QRegExp> validators;
private:
    Era();
    int id;
    QString name;
    int ordering;
    static int select_callback(void *unused, int count, char **data, char **columns);
};

#endif // ERA_H

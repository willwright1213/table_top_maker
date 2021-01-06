#ifndef WORLD_H
#define WORLD_H

#include <QString>
#include <QDebug>
#include <QDir>
#include "lib/sqlite3/sqlite3.h"



class World {

public:
    World(bool load = false, QString n = QString::Null());

private:
    QString name;


};

#endif // WORLD_H


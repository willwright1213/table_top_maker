#ifndef WORLD_H
#define WORLD_H

#include <QString>
#include <QDebug>
#include <QDir>
#include "headers/database.h"

class World {

public:
    World(bool load = false, QString n = QString::Null());
    ~World();
    void destroy();
    QDir *path() const;
private:
    QString n;
    QDir *p;
};


#endif // WORLD_H


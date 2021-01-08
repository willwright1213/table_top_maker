#ifndef WORLD_H
#define WORLD_H

#include <QString>
#include <QDebug>
#include <QDir>
#include "headers/database.h"

class World {

public:
    World(bool load = false, QString n = QString::Null());
    QDir *path() const;
    int insertEra(QString &name, short ordering);
    int insertEvent(QString &name, int era_id);
    int insertCampaign(QString &name, int era_id);
    int insertCharacter(QString &name, QString &race, QString &c);
    int addCharacterToCampaign(int char_id, int camp_id);
    int openConnection();
    void closeConnection();

private:
    QString n;
};


#endif // WORLD_H


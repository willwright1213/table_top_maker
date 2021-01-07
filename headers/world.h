#ifndef WORLD_H
#define WORLD_H
#pragma once

#include <QString>
#include <QDebug>
#include <QDir>
#include "lib/sqlite3/sqlite3.h"

class World {

public:
    World(bool load = false, QString n = QString::Null());
    QDir *path() const;
    QString name() const;
    int insertEra(std::string name, short ordering);
    int insertCampaign(std::string name, int era_id);
    int insertCharacter(std::string name, std::string race, std::string c);
    int addCharacterToCampaign(int char_id, int camp_id);
    int openConnection();
    void closeConnection();

private:
    QString n;
    sqlite3 *db;
};


#endif // WORLD_H


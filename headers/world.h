#ifndef WORLD_H
#define WORLD_H

#include <QString>
#include <QDebug>
#include <QDir>
#include "headers/database.h"


class World {

public:
    World(bool load = false, const QString& n = nullptr);
    ~World();
    void destroy();
    QDir *path() const;
private:
    QString n;
    QDir *p;
    void generateTemplates();
    void generateCharacterTemplate();
    void generateCampaignTemplate();

};


#endif // WORLD_H


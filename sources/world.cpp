#include "headers/world.h"

World::World(bool load, QString name):n(name){
    if(!load){
        QDir().mkpath(QDir::homePath().append("//Documents/My Games/World Builder/").append(n));
        p = new QDir(QDir::homePath().append("//Documents/My Games/World Builder/").append(n));
        QDir().mkpath(p->canonicalPath().append("/Era"));
        QDir().mkpath(p->canonicalPath().append("/Characters"));
        QDir().mkpath(p->canonicalPath().append("/Campaigns"));
        /* initiate database (opening a connection creates the db file if it doesn't exist) */
        database::initiateDB(p);
        qDebug() << path()->canonicalPath();
    }
    else {
        //verify file intergrity
    }
}

QDir* World::path() const{
    return p;
}

void World::destroy() {
    path()->removeRecursively();
}

World::~World(){
    delete(p);
}

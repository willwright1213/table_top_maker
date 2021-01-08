#include "headers/world.h"
#include <string>


World::World(bool load, QString name):n(name){
    if(!load){
        QDir().mkpath(QDir::homePath().append("//Documents/My Games/World Builder/").append(n));
        QDir().mkpath(path()->canonicalPath().append("/Era"));
        QDir().mkpath(path()->canonicalPath().append("/Characters"));
        QDir().mkpath(path()->canonicalPath().append("/Campaigns"));
        /* initiate database (opening a connection creates the db file if it doesn't exist) */
        database::initiateDB(path());
        qDebug() << path()->canonicalPath();
    }
    else {
        //verify file intergrity
    }
}

QDir* World::path() const{
    return new QDir(QDir::homePath().append("//Documents/My Games/World Builder/").append(n));
}

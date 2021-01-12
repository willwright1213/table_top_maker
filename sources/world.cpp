#include "headers/world.h"

World::World(){

}

World::World(bool load, QString name):n(name){
    if(!load){
        QDir().mkpath(QDir::homePath().append("//Documents/My Games/World Builder/").append(n));
        p = new QDir(QDir::homePath().append("//Documents/My Games/World Builder/").append(n));
        QDir().mkpath(p->canonicalPath().append("/era/template"));
        QDir().mkpath(p->canonicalPath().append("/characters/template"));
        QDir().mkdir(p->canonicalPath().append("/characters/css"));
        QDir().mkpath(p->canonicalPath().append("/campaigns/template"));
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

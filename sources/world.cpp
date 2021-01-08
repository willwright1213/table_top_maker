#include "headers/world.h"
#include <string>


World::World(bool load, QString name):n(name){
    if(!load){
        QDir *temp_path = new QDir(QDir::homePath());
        if(!QDir(temp_path->canonicalPath().append("/Documents/My Games/World Builder")).exists())
            QDir().mkdir(temp_path->canonicalPath().append("/Documents/My Games/World Builder"));
        /* Create a folder of the campaign in the My Games folder */
        if(!QDir(temp_path->canonicalPath().append("/Documents/My Games/World Builder/").append(n)).exists())
            QDir().mkdir(temp_path->canonicalPath().append("/Documents/My Games/World Builder/").append(n));
        /* initiate database (opening a connection creates the db file if it doesn't exist) */
        database::initiateDB(path());
    }
    else {
        //verify file intergrity
    }
}

QDir* World::path() const{
    return new QDir(QDir::homePath().append("//Documents/My Games/World Builder/").append(n));
}

int World::openConnection(){ return sqlite3_open(path()->canonicalPath().toLocal8Bit()+"/world.db", &database::db);}
void World::closeConnection() { sqlite3_close(database::db);}

int World::insertEra(QString &name, short ordering) {
    int execute = 1;
    int connection = database::openConnection(path());
    if(connection == SQLITE_OK){
        std::string query;
        query = "INSERT INTO era (name, ordering) VALUES ('" + (std::string)name.toLocal8Bit() + "', " + std::to_string(ordering) + ");";
        char *errmsg;
        execute = sqlite3_exec(database::db, query.c_str(), NULL, 0, &errmsg);
    }
    database::closeConnection();
    return execute;
}

int World::insertEvent(QString &name, int era_id){
    int execute = 1;
    int connection = database::openConnection(path());
    if(connection == SQLITE_OK){
        std::string query;
        query = "INSERT INTO campaigns (name, era_id) VALUES ('" + (std::string)name.toLocal8Bit() + "', " + std::to_string(era_id) + ");";
        char *errmsg;
        execute = sqlite3_exec(database::db, query.c_str(), NULL, 0, &errmsg);
    }
    database::closeConnection();
    return execute;
}


int World::insertCampaign(QString &name, int era_id) {
    int execute = 1;
    int connection = database::openConnection(path());
    if(connection == SQLITE_OK){
        std::string query;
        query = "INSERT INTO campaigns (name, era_id) VALUES ('" + (std::string)name.toLocal8Bit() + "', " + std::to_string(era_id) + ");";
        char *errmsg;
        execute = sqlite3_exec(database::db, query.c_str(), NULL, 0, &errmsg);
    }
    database::closeConnection();
    return execute;

}


int World::insertCharacter(QString &name,  QString &race, QString &c) {
    int execute = 1;
    int connection = database::openConnection(path());
    if(connection == SQLITE_OK){
        std::string query;
        query = "INSERT INTO characters (name, race, class) VALUES ('" + (std::string)name.toLocal8Bit() + "', '" + (std::string)race.toLocal8Bit() +
                "', '" + (std::string)c.toLocal8Bit() + "');";
        char *errmsg;
        execute = sqlite3_exec(database::db, query.c_str(), NULL, 0, &errmsg);
    }
    database::closeConnection();
    return execute;

}

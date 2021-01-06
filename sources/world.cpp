#include "../headers/world.h"


World::World(bool load, QString n):name(n){
    if(!load){
        sqlite3* db;
        QDir *path = new QDir(QDir::homePath());
        if(!QDir(path->canonicalPath().append("/World Builder")).exists())
            QDir().mkdir(path->canonicalPath().append("/Documents/My Games/World Builder"));
        /* Create a folder of the campaign in the My Games folder */
        if(!QDir(path->canonicalPath().append("/Documents/My Games/World Builder/").append(name)).exists())
            QDir().mkdir(path->canonicalPath().append("/Documents/My Games/World Builder/").append(name));
        path = new QDir(path->canonicalPath().append("/Documents/My Games/World Builder/").append(name));
        /* initiate database (opening a connection creates the db file if it doesn't exist) */
        int connection = sqlite3_open(path->canonicalPath().toLocal8Bit()+"/"+"name"+".db", &db);
        if(connection == SQLITE_OK){
            qDebug() << "DB CREATED";
            std::string create_character_table =
                    "CREATE TABLE era ("
                    "era_id INT PRIMARY KEY NOT NULL, "
                    "name TEXT NOT NULL, "
                    "ordering INT UNIQUE); "

                    "CREATE TABLE campaigns ("
                    "campaign_id INT PRIMARY KEY NOT NULL, "
                    "name TEXT NOT NULL, "
                    "era_id INT NOT NULL, "
                    "FOREIGN KEY(era_id) "
                    "   REFERENCES era (era_id) );";



            char *errmsg;
            int execute = sqlite3_exec(db, create_character_table.c_str(), NULL, 0, &errmsg);
            qDebug() << errmsg;
        }
        else {
            qDebug() << "db created succesfully";
        }
        sqlite3_close(db);
    }
    else {
        //verify file intergrity
    }
}

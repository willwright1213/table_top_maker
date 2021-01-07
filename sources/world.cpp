#include "../headers/world.h"
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
        int connection = openConnection();
        if(connection == SQLITE_OK){
            qDebug() << "DB CREATED";
            std::string query =

                    "CREATE TABLE era ("
                    "id INTEGER PRIMARY KEY NOT NULL, "
                    "name TEXT NOT NULL, "
                    "ordering INT UNIQUE); "

                    "CREATE TABLE campaigns ("
                    "id INTEGER PRIMARY KEY, "
                    "name TEXT NOT NULL, "
                    "era_id INT NOT NULL, "
                    "FOREIGN KEY(era_id) "
                    "   REFERENCES era (id) );"

                    "CREATE TABLE characters ("
                    "id INTEGER PRIMARY KEY NOT NULL, "
                    "name TEXT NOT NULL, "
                    "race TEXT NOT NULL, "
                    "class TEXT NOT NULL );"

                    "CREATE TABLE campaign_characters ("
                    "campaign_id INT NOT NULL, "
                    "character_id INT NOT NULL, "
                    "FOREIGN KEY(campaign_id) REFERENCES campaigns(id), "
                    "FOREIGN KEY(character_id) REFERENCES characters(id) );";

            char *errmsg;
            int execute = sqlite3_exec(db, query.c_str(), NULL, 0, &errmsg);
            qDebug() << execute;
        }
        else {
            qDebug() << "db created succesfully";
        }
        closeConnection();
    }
    else {
        //verify file intergrity
    }
}

QDir* World::path() const{
    return new QDir(QDir::homePath().append("//Documents/My Games/World Builder/").append(n));
}

QString World::name() const { return World::n;}

int World::openConnection(){ return sqlite3_open(path()->canonicalPath().toLocal8Bit()+"/world.db", &db);}
void World::closeConnection() { sqlite3_close(db);}

int World::insertEra(std::string name, short ordering) {
    int execute = 1;
    int connection = openConnection();
    if(connection == SQLITE_OK){
        std::string query;
        query = "INSERT INTO era (name, ordering) VALUES ('" + name + "', " + std::to_string(ordering) + ");";
        char *errmsg;
        execute = sqlite3_exec(db, query.c_str(), NULL, 0, &errmsg);
    }
    closeConnection();
    return execute;
}

int World::insertCampaign(std::string name, int era_id) {
    int execute = 1;
    int connection = openConnection();
    if(connection == SQLITE_OK){
        std::string query;
        query = "INSERT INTO campaigns (name, era_id) VALUES ('" + name + "', " + std::to_string(era_id) + ");";
        char *errmsg;
        execute = sqlite3_exec(db, query.c_str(), NULL, 0, &errmsg);
    }
    closeConnection();
    return execute;

}

int World::insertCharacter(std::string name, std::string race, std::string c) {
    int execute = 1;
    int connection = openConnection();
    if(connection == SQLITE_OK){
        std::string query;
        query = "INSERT INTO characters (name, race, class) VALUES ('" + name + "', '" + race + "', '" + c + "');";
        char *errmsg;
        execute = sqlite3_exec(db, query.c_str(), NULL, 0, &errmsg);
    }
    closeConnection();
    return execute;

}

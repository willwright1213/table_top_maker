#include "headers/database.h"

sqlite3* database::db;
QVector<QString> database::selected = QVector<QString>();

int database::openConnection(QDir *path){ return sqlite3_open(path->canonicalPath().toLocal8Bit()+"/world.db", &database::db);}
void database::closeConnection() { sqlite3_close(database::db);}

void database::initiateDB(QDir *path){
    int connection = database::openConnection(path);
    if(connection == SQLITE_OK){
        std::string query =

                "CREATE TABLE era ("
                "id INTEGER PRIMARY KEY NOT NULL, "
                "name TEXT NOT NULL, "
                "ordering INT UNIQUE); "

                "CREATE TABLE events ("
                "id INTEGER PRIMARY KEY, "
                "name TEXT NOT NULL, "
                "era_id INT NOT NULL, "
                "FOREIGN KEY(era_id) "
                "   REFERENCES era (id) );"

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
                "FOREIGN KEY(character_id) REFERENCES characters(id) );"

                "CREATE TABLE event_characters ("
                "event_id INT NOT NULL, "
                "character_id INT NOT NULL, "
                "FOREIGN KEY(event_id) REFERENCES events(id), "
                "FOREIGN KEY(character_id) REFERENCES characters(id) );";

        char *errmsg;
        int execute = sqlite3_exec(database::db, query.c_str(), NULL, 0, &errmsg);
    }
    else {
    }
    closeConnection();
}

int database::select(QDir *path, int id, std::string table) {
    database::selected.clear();
    int execute = 1;
    if(database::openConnection(path) == SQLITE_OK){
        char *errmsg;
        std::string query;
        query = "SELECT * FROM " + table + " WHERE id = " + std::to_string(id) + ";";
        sqlite3_exec(database::db, query.c_str(), select_callback, NULL, &errmsg);
    }
    database::closeConnection();
    return execute;
};

int database::select_callback(void *unused, int count, char **data, char **columns){
    int i;
    for(i = 0; i<count;i++)
        database::selected.append(data[i]);
    return 0;
}

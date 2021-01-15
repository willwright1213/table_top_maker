#include "headers/database.h"

QSqlDatabase database::db;
QHash<QString, QString> database::selected = QHash<QString, QString>();

int database::openConnection(QDir *path){
    if(path->canonicalPath().toLocal8Bit()+"/world.db" != db.databaseName()) return 2;
    return db.open();
}
void database::closeConnection() { db.close();}

int database::initiateDB(QDir *path){
       QSqlQuery query;
       openConnection(path);
       QString createCampaignsTable=
               "CREATE TABLE campaigns ("
               "id INTEGER PRIMARY KEY, "
               "name TEXT NOT NULL, "
               "info TEXT NOT NULL); ";
       QString createGroupsTable =
               "CREATE TABLE groups ("
               "id INTEGER PRIMARY KEY, "
               "campaign_id INTEGER NOT NULL REFERENCES campaigns(id), "
               "name TEXT NOT NULL); ";
       QString createEventsTable =
               "CREATE TABLE events ("
               "id INTEGER PRIMARY KEY, "
               "campaign_id INTEGER NOT NULL REFERENCES campaigns(id), "
               "name TEXT NOT NULL); ";
       QString createCharactersTable =
               "CREATE TABLE characters ("
               "id INTEGER PRIMARY KEY NOT NULL, "
               "name TEXT NOT NULL, "
               "race TEXT NOT NULL, "
               "class TEXT NOT NULL, "
               "birth_year TEXT NOT NULL, "
               "birth_place TEXT NOT NULL, "
               "death_year TEXT, "
               "death_place TEXT, "
               "bio TEXT);";
       QString createCampaignCharactersTable =
               "CREATE TABLE campaign_characters ("
               "campaign_id INTEGER NOT NULL REFERENCES campaigns(id), "
               "character_id INTEGER NOT NULL REFERENCES characters(id), "
               "group_id INTEGER NOT NULL REFERENCES groups(id), "
               "alignment TEXT);";
       QString createEventCharactersTable =
               "CREATE TABLE event_characters ("
               "event_id INT NOT NULL REFERENCES events(id), "
               "character_id INT NOT NULL REFERENCES characters(id) "
               ");";

       if(!query.exec(createCampaignsTable)) {db.close(); qDebug() << "error"; return 1;}
       if(!query.exec(createGroupsTable)) {db.close(); qDebug() << "error"; return 1;}
       if(!query.exec(createEventsTable)) {db.close(); qDebug() << "error"; return 1;}
       if(!query.exec(createCharactersTable)) {db.close(); qDebug() << "error"; return 1;}
       if(!query.exec(createCampaignCharactersTable)) {db.close(); qDebug() << "error"; return 1;}
       if(!query.exec(createEventCharactersTable)) {db.close(); qDebug() << "error"; return 1;}
       db.close();
       return 0;
}

int database::insert(QDir *path, const QString& table, QHash<QString, QString> &data){
    QSqlQuery query;
    int error = 0;
    QString left = "(";
    QString right = "VALUES (";
    QString insert = "INSERT INTO " + table + " ";
    for(auto val = data.begin(); val != data.end(); val++){
        left.append(val.key() + ", ");
        right.append("'" + val.value() + "', ");
    }

    left.remove(left.length() - 2, left.length() - 1);
    right.remove(right.length() - 2, right.length() - 1);
    left.append(") ");
    right.append(");");
    insert.append(left).append(right);
    openConnection(path);
    if(!query.exec(insert)) error = 1;
    db.close();
    return error;
}

QHash<QString, QString> database::select(QDir *path, const QString& table, int id) {
    selected.clear();
    openConnection(path);
    QSqlQuery query("SELECT * FROM " + table + " WHERE id = " + id + ";");
    QMap<QString, QVariant> sqlIterator(query.boundValues());
    for(auto i = sqlIterator.begin(); i != sqlIterator.end(); i++){
        selected.insert(i.key(), i.value().toString());
    }
    db.close();
    return selected;
};

void database::remove(QDir *path, const QString& table, int id){
    QSqlQuery  query;
    openConnection(path);
    query.prepare("DELETE FROM " + table + " WHERE id = " + id + ";");
    db.exec();
    db.close();
}

int database::find_id(QDir *path, const QString& table, const QString& value, const QString& column){
    selected.clear();
    QSqlQuery  query;
    openConnection(path);
    query.prepare("SELECT * FROM " + table + " WHERE " + column + " = " + "'" + value + "';");
    db.exec();
    closeConnection();
    if(selected.isEmpty())  throw std::invalid_argument("No ID found with value: ");
    return selected.value("id").toInt();
}

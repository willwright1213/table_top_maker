#ifndef DATABASE_H
#define DATABASE_H

#include "lib/sqlite3/sqlite3.h"
#include <QString>
#include <QDir>
#include <QDebug>

namespace database {

    extern sqlite3 *db;
    extern QVector<QString> selected;

    int openConnection(QDir *path);
    void closeConnection();
    void initiateDB(QDir *path);

    QVector<QString> insert(QDir *path, std::string table, QHash<QString, QString> &data);
    int remove(QDir *path, int id);

    QVector<QString> select(QDir *path, int id, std::string table);
    int select_all(QDir *path, std::string table);
    int select_callback(void *unused, int count, char **data, char **columns);
    int select_all_callback(void *unused, int count, char **data, char **columns);

}

#endif // DATABASE_H

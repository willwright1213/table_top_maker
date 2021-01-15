#ifndef DATABASE_H
#define DATABASE_H

#include "lib/sqlite3/sqlite3.h"
#include <QString>
#include <QDir>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>

namespace database {

    extern QSqlDatabase db;
    extern QHash<QString, QString> selected;

    int openConnection(QDir *path);
    void closeConnection();
    int initiateDB(QDir *path);

    int find_id(QDir *path, const QString& table, const QString& value, const QString& column);

    int insert(QDir *path, const QString& table, QHash<QString, QString> &data);
    void remove(QDir *path, const QString& table, const QString& id);


    QSqlRecord select(QDir *path, const QString& table, const QString& id);
    int select_all(const QString&table);


}

#endif // DATABASE_H

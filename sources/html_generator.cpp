#include "headers/html_generator.h"


void htmlGenerator::generate(QDir *path, QString table, QHash<QString, QString>& hash)
{
    QFile file(path->canonicalPath().append("/"+table+"/template/template.html"));
    file.open(QIODevice::ReadOnly);
    QString data = file.readAll();
    QRegularExpression column;
    QString replaceString;
    for(auto it = hash.begin(); it != hash.end(); ++it){

        column.setPattern("<%"+it.key()+"%>");
        replaceString = it.value();
        data.replace(column, replaceString);

    }

    QFile newFile(path->canonicalPath().append("/"+table+"/" + database::selected.value("id") + "_" + database::selected.value("name") +".html"));
    newFile.open(QIODevice::WriteOnly);
    QTextStream out(&newFile);
    out << data;
    newFile.close();
}

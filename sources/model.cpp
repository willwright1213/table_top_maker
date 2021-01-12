#include "headers/model.h"

void Model::create(World &w, std::string table, QHash<QString, QString> input){
    database::insert(w.path(), table, input);
}

void Model::remove(World &w, std::string table, int id){
    database::remove(w.path(), table, id);
};

int Model::find_id(World &w, std::string table, QString &value, QString column){
    return database::find_id(w.path(), table, value.toLocal8Bit().constData(), column.toLocal8Bit().constData());
}

bool Model::validate(QString &value, QRegExp validator) {
    return validator.indexIn(value) + 1;
}

bool Model::validate_all(QHash<QString, QString> &values, QHash<QString, QRegExp> validators){
    for(auto val = values.begin(); val != values.end(); ++ val){
        if(!validate(val.value(), validators.value(val.key()))) {
            qDebug() << val.value() << validators.value(val.key());
            return false;
        }
    }
    return true;
}

void Model::generateHTML(World &w, QString table, QHash<QString, QString>& hash)
{
    QFile file(w.path()->canonicalPath().append("/"+table+"/template/template.html"));
    file.open(QIODevice::ReadOnly);
    QString data = file.readAll();
    QRegularExpression column;
    QString replaceString;
    for(auto it = hash.begin(); it != hash.end(); ++it){

        column.setPattern("<%"+it.key()+"%>");
        replaceString = it.value();
        data.replace(column, replaceString);

    }

    QFile newFile(w.path()->canonicalPath().append("/"+table+"/" + database::selected.value("id") + "_" + database::selected.value("name") +".html"));
    newFile.open(QIODevice::WriteOnly);
    QTextStream out(&newFile);
    out << data;
    newFile.close();
}

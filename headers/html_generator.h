#ifndef XML_H
#define XML_H

#include <QtXml>
#include <QDir>
#include "headers/database.h"

namespace htmlGenerator {

void generate(QDir *path, QString, QHash<QString, QString>&);
void characterTemplate(QDir *path, QString new_name);
}

#endif // XML_H

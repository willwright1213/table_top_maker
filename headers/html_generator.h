#ifndef XML_H
#define XML_H

#include <QtXml>
#include <QDir>

namespace htmlGenerator {

void generate(QHash<QString, QHash<QString, QString>>);
void characterTemplate(QDir *path, QString new_name);
}

#endif // XML_H

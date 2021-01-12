#include "headers/html_generator.h"
#include "headers/database.h"

void htmlGenerator::generate(QHash<QString, QHash<QString, QString>>) {

}


void htmlGenerator::characterTemplate(QDir *path, QString new_name){
    QFile file(path->canonicalPath().append("/characters/" + new_name + ".html"));
    file.open(QIODevice::ReadWrite);
    file.write
    (
        "<!DOCTYPE html>\n"
        "<html>\n"
        "<head>\n"
        "</head>\n"
        "<body>\n"
        "<h1 id=\"test\">My First Heading</h1>"
        "<p>My first paragraph.</p>"
        "</body>"
        "</html>"
    );
    file.close();
}


#include "headers/world.h"

World::World(bool load, const QString& name):n(name){
    if(!load){
        QDir().mkpath(QDir::homePath().append("//Documents/My Games/World Builder/").append(n));
        p = new QDir(QDir::homePath().append("//Documents/My Games/World Builder/").append(n));
        QDir().mkpath(p->canonicalPath().append("/characters/template"));
        QDir().mkdir(p->canonicalPath().append("/characters/css"));
        QDir().mkpath(p->canonicalPath().append("/campaigns/template"));
        QDir().mkpath(p->canonicalPath().append("/campaigns/css"));
        QDir().mkpath(p->canonicalPath().append("/campaigns/images"));
        /* initiate database (opening a connection creates the db file if it doesn't exist) */
        database::db = QSqlDatabase::addDatabase("QSQLITE");
        database::db.setDatabaseName(path()->canonicalPath().toLocal8Bit()+"/world.db");
        database::initiateDB(path());
        generateTemplates();
    }
    else {
        //verify file intergrity
    }
}

QDir* World::path() const{
    return p;
}

void World::destroy() {
    path()->removeRecursively();
}

World::~World(){
    delete(p);
}

void World::generateTemplates(){
    generateCharacterTemplate();
    generateCampaignTemplate();
}

void World::generateCharacterTemplate(){
    QFile file(path()->canonicalPath().append("/characters/template/template.html"));
    file.open(QIODevice::WriteOnly);
    //Generate HTML file
    file.write(
        "<!DOCTYPE html>""<head>""<link rel=\"stylesheet\" href=\"css/stylesheet.css\">"
        "<title> Character - <%name%> </title>"
        "</head>"
        "<body>"
        "<div id=\"wrapper\">"
        "<div id=\"profile\">"
        "<div id=\"image-container\">"
        "<img src=\"images/<%id%>_<%name%>.png\" />"
        "</div>"
        "<div id=\"info\">"
        "<p id=\"info\"><b>Name:</b> <span id=\"value\"><%name%></span></p>"
        "<p id=\"info\"><b>Race:</b> <span id=\"value\"><%race%></span></p>"
        "<p id=\"info\"><b>Class:</b> <span id=\"value\"><%class%></span></p>"
        "<p id=\"info\"><b>Birth Year:</b> <span id=\"value\"><%birth_year%></span></p>"
        "<p id=\"info\"><b>Birth Place:</b> <span id=\"value\"><%birth_place%></span></p>"
        "</div>"
        "</div>"
        "<div id=\"bio\">"
        "<%bio%>"
        "</div>"
        "</div>"
        "</body>"
        "</html>");
    file.close();
    //Generate CSS file
    QFile css_file(path()->canonicalPath().append("/characters/css/stylesheet.css"));
    css_file.open(QIODevice::WriteOnly);
    css_file.write("body {} #wrapper {width: 100%;background-color: red;} ");
    css_file.close();
}

void World::generateCampaignTemplate(){
    QFile file(path()->canonicalPath().append("/campaigns/template/template.html"));
    file.open(QIODevice::WriteOnly);
    //Generate HTML file
    file.write(
        "<!DOCTYPE html>""<head>""<link rel=\"stylesheet\" href=\"css/stylesheet.css\">"
        "<title> Character - <%name%> </title>"
        "</head>"
        "<body>"
        "<div id=\"wrapper\">"
        "<div id=\"profile\">"
        "<div id=\"image-container\">"
        "<img src=\"images/<%id%>_<%name%>.png\" />"
        "</div>"
        "<div id=\"info\">"
        "<p id=\"info\"><b>Name:</b> <span id=\"value\"><%name%></span></p>"
        "<p id=\"info\"><b>Race:</b> <span id=\"value\"><%race%></span></p>"
        "<p id=\"info\"><b>Class:</b> <span id=\"value\"><%class%></span></p>"
        "<p id=\"info\"><b>Birth Year:</b> <span id=\"value\"><%birth_year%></span></p>"
        "<p id=\"info\"><b>Birth Place:</b> <span id=\"value\"><%birth_place%></span></p>"
        "</div>"
        "</div>"
        "<div id=\"bio\">"
        "<%bio%>"
        "</div>"
        "</div>"
        "</body>"
        "</html>");
    file.close();
    //Generate CSS file
    QFile css_file(path()->canonicalPath().append("/campaigns/css/stylesheet.css"));
    css_file.open(QIODevice::WriteOnly);
    css_file.write("body {} #wrapper {width: 100%;background-color: red;} ");
    css_file.close();
}

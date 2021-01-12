#include "headers/character.h"

QHash<QString, QRegExp> Character::validators;

void Character::create(World &w, const QString &name, const QString &race, const QString &c, const QString &birth_year, const QString &birth_place,
                      const QString &death_year, const QString &death_place,  const QString &bio)
{
    QHash<QString, QString> input;
    input.insert("name", name);
    input.insert("race", race);
    input.insert("class", c);
    input.insert("birth_year", birth_year);
    input.insert("birth_place", birth_place);
    input.insert("bio", bio);
    if(death_year != nullptr) input.insert("death_year", death_year);
    if(death_place != nullptr) input.insert("death_place", death_year);
    if(!Model::validate_all(input, validators)) throw std::invalid_argument("validation error");
    Model::create(w, "characters", input);
    Model::generateHTML(w, "characters", database::selected);
}

void Character::create(World &w, QString &name, QString &race, QString &c, QString &birth_year, QString &birth_place)
{
    QHash<QString, QString> input;
    input.insert("name", name);
    input.insert("race", race);
    input.insert("class", c);
    input.insert("birth_year", birth_year);
    input.insert("birth_place", birth_place);
    if(!Model::validate_all(input, validators)) throw std::invalid_argument("validation error");
    Model::create(w, "characters", input);
}


void Character::remove(World &w, int id){ Model::remove(w, "characters", id); }

void Character::initiate_validators()
{
    validators.insert("name", QRegExp("^[a-zA-z'\\-\\s]{2,30}$"));
    validators.insert("race", QRegExp("^[a-zA-z'\\-\\s]{2,30}$"));
    validators.insert("class", QRegExp("^[a-zA-z'\\-\\s]{2,30}$"));
    validators.insert("birth_year", QRegExp("^[a-zA-z'\\-\\s\\d]{2,30}$"));
    validators.insert("birth_place", QRegExp("^[a-zA-z'\\-\\s]{2,30}$"));
    validators.insert("death_year", QRegExp("^[a-zA-z'\\-\\s\\d]{0,30}$"));
    validators.insert("death_place", QRegExp("^[a-zA-z'\\-\\s]{0,30}$"));
    validators.insert("bio", QRegExp("."));
};

void Character::generate_template(World &w){
    QFile file(w.path()->canonicalPath().append("/characters/template/template.html"));
    file.open(QIODevice::WriteOnly);
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
}

void Character::generate_css(World &w){
    QFile file(w.path()->canonicalPath().append("/characters/css/stylesheet.css"));
    file.open(QIODevice::WriteOnly);
    file.write("body {} #wrapper {width: 100%;background-color: red;} ");
    file.close();
}

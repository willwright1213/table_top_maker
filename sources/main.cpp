#include "../headers/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    World *test = new World(false, "Test World");
    QString era_one = "Dark Age";
    QString era_two = "Bronze Age";
    try  {
        Era::create(*test, era_one, 0);
        qDebug() << "created sucessfully";
        Era::create(*test, era_two, 1);
        qDebug() << "created sucessfully";
    }
    catch(std::invalid_argument &e) {
        qDebug() << e.what();
    }
    try {
        Era::remove(*test, 1);
        qDebug() << "removed sucessfully";
        Era::remove(*test, 2);
        qDebug() << "removed sucessfully";
    }  catch (std::invalid_argument &e) {

    }
    try {
        Era::create(*test, era_one, 1);
        qDebug() << "created sucessfully";
        Era::create(*test, era_two, 1);
        qDebug() << "<You should not see this message>";
    }  catch (std::invalid_argument &e) {
        qDebug() << "Could not insert data: ordering needs to be unique";
    }
    test->destroy();
    delete(test);
    return 0;
}

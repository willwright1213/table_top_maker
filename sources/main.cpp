#include "../headers/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    World *test = new World(false, "Test World 2");
    QString era_one = "Dark Age";
    QString era_two = "Bronze Age";
    //Creation test
    try  {
        Era::create(*test, era_one, 0);
        qDebug() << "created sucessfully";
        Era::create(*test, era_two, 1);
        qDebug() << "created sucessfully";
    }
    catch(std::invalid_argument &e) {
        qDebug() << e.what();
    }
    //Removal test
    try {
        Era::remove(*test, 1);
        qDebug() << "removed sucessfully";
        Era::remove(*test, 2);
        qDebug() << "removed sucessfully";
    }  catch (std::invalid_argument &e) {
        qDebug() << e.what();
    }
    //Creation test with non unique ordering
    try {
        Era::create(*test, era_one, 1);
        qDebug() << "created sucessfully";
        Era::create(*test, era_two, 1);
        qDebug() << "<You should not see this message>";
    }  catch (std::invalid_argument &e) {
        qDebug() << "Could not insert data: ordering needs to be unique <Intended for the test>";
    }
   //Find Era by name, and delete it
    try {
        int id = Era::find_by_name(*test, era_one);
        qDebug() << "the id is " << id;
        Era::remove(*test, id);
        qDebug() << "Era with the id " << id << " Has been removed";
    }  catch (std::invalid_argument &e) {
        qDebug() << "error" << e.what();
    }
    //Find Era that does not exist
    try {
        Era::find_by_name(*test, era_one);
    }  catch (std::invalid_argument &e) {
        qDebug() << e.what();
    }
    //Find Era that does not exist
    test->destroy();
    delete(test);
    return 0;
}

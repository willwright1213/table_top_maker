#include "../headers/mainwindow.h"
#include "headers/characterviewer.h"

#include <QApplication>
#include <QGuiApplication>
#include "modeltest.cpp"

int main(int argc, char *argv[])
{

    ModelTest test1;
    QTest::qExec(&test1);

    /*
    QApplication a(argc, argv);
    World *world = new World(false, "test");
    CharacterViewer w(nullptr, *world);
    w.show();
    return a.exec();
    */
}

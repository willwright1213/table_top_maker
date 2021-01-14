#include "../headers/mainwindow.h"

#include <QApplication>
#include <QGuiApplication>
#include "testcase.cpp"

int main(int argc, char *argv[])
{

    TestCase test1;
    QTest::qExec(&test1);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

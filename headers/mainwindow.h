#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QInputDialog>
#include <QDir>
#include "lib/sqlite3/sqlite3.h"
#include "headers/world.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void newGame();
    void loadGame();
    void joinGame();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

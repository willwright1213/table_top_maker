#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QInputDialog>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->newCampaign, &QPushButton::clicked, this, &MainWindow::newGame);
    connect(ui->loadCampaign, &QPushButton::clicked, this, &MainWindow::loadGame);
    connect(ui->joinCampaign, &QPushButton::clicked, this, &MainWindow::joinGame);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newGame() {
   /* open the new game window */
   QString name = QInputDialog::getText(this, "New Game", "Campaign name");
   QDir *path = new QDir(QDir::homePath());
   /* Create a folder of the campaign in the My Games folder */
   if(!QDir(path->canonicalPath().append("/Documents/My Games/").append(name)).exists())
       QDir().mkdir(path->canonicalPath().append("/Documents/My Games/").append(name));
   path = new QDir(path->canonicalPath().append("/Documents/My Games/").append(name));
   qDebug() << path->canonicalPath();
}

void MainWindow::loadGame() {

}

void MainWindow::joinGame() {

}

void MainWindow::createDB(const QString &name){


}

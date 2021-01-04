#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QInputDialog>
#include <QDir>
#include "lib/sqlite3/sqlite3.h"

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
   bool ok;
   QString name = QInputDialog::getText(this, "New World", "World Name", QLineEdit::Normal, "Name your world", &ok);
   if(ok && !name.isEmpty()){
       sqlite3* db;
       QDir *path = new QDir(QDir::homePath());
       /* Create a folder of the campaign in the My Games folder */
       if(!QDir(path->canonicalPath().append("/Documents/My Games/").append(name)).exists())
           QDir().mkdir(path->canonicalPath().append("/Documents/My Games/").append(name));
       path = new QDir(path->canonicalPath().append("/Documents/My Games/").append(name));
       int connection = sqlite3_open(path->canonicalPath().toLocal8Bit()+"/"+"name"+".db", &db);
       if(connection){
           qDebug() << "cannot open/create database";
       }
       else {
           qDebug() << "db created succesfully";
       }
       qDebug() << path->canonicalPath();
       QString campaign = QInputDialog::getText(this, "New Campaign", "Campaign Name", QLineEdit::Normal, "Name your campaign", &ok);
       if(ok && !campaign.isEmpty()){

       }
   }
}

void MainWindow::loadGame() {

}

void MainWindow::joinGame() {

}


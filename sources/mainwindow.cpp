#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"



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
       World *w = new World(false, name);
       QString era = "Dark Age";
       Era::create(*w, era, 1);

       //load the world window
   }
}

void MainWindow::loadGame() {

}

void MainWindow::joinGame() {

}


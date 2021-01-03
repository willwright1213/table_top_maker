#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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
}

void MainWindow::loadGame() {
   /* open the load game window */
}

void MainWindow::joinGame() {
   /* open the join game window */
}

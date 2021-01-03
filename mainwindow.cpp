#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->newCampaign, &QPushButton::clicked, this, &MainWindow::newGame);
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

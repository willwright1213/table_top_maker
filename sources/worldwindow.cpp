#include "headers/worldwindow.h"
#include "ui_worldwindow.h"

WorldWindow::WorldWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorldWindow)
{
    ui->setupUi(this);
}

WorldWindow::~WorldWindow()
{
    delete ui;
}

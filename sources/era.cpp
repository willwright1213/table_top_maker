#include "era.h"
#include "ui_era.h"

Era::Era(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Era)
{
    ui->setupUi(this);
}

Era::~Era()
{
    delete ui;
}

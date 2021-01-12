#include "../headers/characterview.h"
#include "ui_characterview.h"

CharacterView::CharacterView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CharacterView)
{
    ui->setupUi(this);
}

CharacterView::~CharacterView()
{
    delete ui;
}

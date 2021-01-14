#include "headers/worldwindow.h"
#include "ui_worldwindow.h"


WorldWindow::WorldWindow(QWidget *parent, World *w) :
    QWidget(parent),
    w(w),
    ui(new Ui::WorldWindow)
{
    model = new QStringListModel();
    ui->setupUi(this);
    this->setVisible(true);
    connect(ui->addButton, &QPushButton::clicked, this, &WorldWindow::addCharacter);
    qDebug() << w->path()->canonicalPath();
}

WorldWindow::~WorldWindow()
{
    delete ui;
}

/* opens the add character view */
void WorldWindow::addCharacter(){

    AddCharacterView *view = new AddCharacterView(nullptr, w);
    view->show();

}


void WorldWindow::populateCharacterList(){/* model << database::selected_all; */ }

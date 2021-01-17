#include "headers/worldwindow.h"
#include "ui_worldwindow.h"


WorldWindow::WorldWindow(QWidget *parent, World *w) :
    QWidget(parent),
    w(w),
    ui(new Ui::WorldWindow)
{
    model = new QSqlQueryModel;
    database::openConnection(w->path());
    model->setQuery("SELECT * FROM characters", database::db);
    database::closeConnection();
    ui->setupUi(this);
    ui->characterTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->characterTableView->setModel(model);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("race"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("class"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Birth Year"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Birth Place"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Death Year"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Death Year"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Bio"));



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

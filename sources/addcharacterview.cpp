#include "headers/addcharacterview.h"
#include "ui_addcharacterview.h"

AddCharacterView::AddCharacterView(QWidget *parent, World *w) :
    QWidget(parent),
    w(w),
    ui(new Ui::AddCharacterView)
{
    ui->setupUi(this);
    ui->biography->setMarkdown("");
    ui->biography->setHtml("<h1>test</h1>");
    connect(ui->addButton, &QPushButton::clicked, this, &AddCharacterView::submit);
    connect(ui->cancelButton, &QPushButton::clicked, this, &AddCharacterView::cancel);
    setAttribute(Qt::WA_DeleteOnClose, true);
}

AddCharacterView::~AddCharacterView()
{
    delete ui;
}

void AddCharacterView::submit(){

    try {

    Character::create(
       *w,
       ui->name->text(),
                ui->race->text(),
                ui->character_class->text(),
                ui->birth_year->text(),
                ui->birth_place->text(),
                ui->death_year->text(),
                ui->death_place->text(),
                ui->biography->toMarkdown()

    );
    }
    catch(std::invalid_argument &e) {
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.exec();
    }

}

void AddCharacterView::cancel(){close();}

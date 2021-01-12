#include "headers/characterviewer.h"
#include "ui_characterviewer.h"

World CharacterViewer::null_world = NULL;

CharacterViewer::CharacterViewer(QWidget *parent, World &w) :
    QWidget(parent),
    ui(new Ui::CharacterViewer)
{
    QFile file(w.path()->canonicalPath().append("/characters/test.html"));
    file.open(QIODevice::ReadOnly);
    QString html = file.readAll();
    file.close();
    ui->setupUi(this);
    ui->textBrowser->insertHtml(html);
}

CharacterViewer::~CharacterViewer()
{
    delete ui;
}

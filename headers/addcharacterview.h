#ifndef ADDCHARACTERVIEW_H
#define ADDCHARACTERVIEW_H

#include <QWidget>
#include "world.h"
#include "character.h"
#include <QMessageBox>

namespace Ui {
class AddCharacterView;
}

class AddCharacterView : public QWidget
{
    Q_OBJECT

public:
    explicit AddCharacterView(QWidget *parent = nullptr, World *w = nullptr);
    ~AddCharacterView();

public slots:
    void submit();
    void cancel();

private:
    Ui::AddCharacterView *ui;
    World *w;
};

#endif // ADDCHARACTERVIEW_H

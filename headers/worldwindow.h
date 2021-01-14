#ifndef WORLDWINDOW_H
#define WORLDWINDOW_H

#include <QWidget>
#include <QStringListModel>
#include "world.h"
#include "addcharacterview.h"

namespace Ui {
class WorldWindow;
}

class WorldWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WorldWindow(QWidget *parent = nullptr, World *w = nullptr);
    ~WorldWindow();

public slots:
    void addCharacter();

private:
    World *w;
    Ui::WorldWindow *ui;
    QStringListModel *model;
    void populateCharacterList();
};

#endif // WORLDWINDOW_H

#ifndef CHARACTERVIEWER_H
#define CHARACTERVIEWER_H

#include <QWidget>
#include <QDir>
#include "headers/world.h"

namespace Ui {

class CharacterViewer;
}

class CharacterViewer : public QWidget
{
    Q_OBJECT

public:
    explicit CharacterViewer(QWidget *parent = nullptr, World &w = null_world);
    ~CharacterViewer();

private:
    static World null_world;
    Ui::CharacterViewer *ui;
};

#endif // CHARACTERVIEWER_H

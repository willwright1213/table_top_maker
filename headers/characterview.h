#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H

#include <QWidget>

namespace Ui {
class CharacterView;
}

class CharacterView : public QWidget
{
    Q_OBJECT

public:
    explicit CharacterView(QWidget *parent = nullptr);
    ~CharacterView();

private:
    Ui::CharacterView *ui;
};

#endif // CHARACTERVIEW_H

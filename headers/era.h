#ifndef ERA_H
#define ERA_H

#include <QWidget>

namespace Ui {
class Era;
}

class Era : public QWidget
{
    Q_OBJECT

public:
    explicit Era(QWidget *parent = nullptr);
    ~Era();

private:
    Ui::Era *ui;
};

#endif // ERA_H

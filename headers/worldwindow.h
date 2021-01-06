#ifndef WORLDWINDOW_H
#define WORLDWINDOW_H

#include <QWidget>

namespace Ui {
class WorldWindow;
}

class WorldWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WorldWindow(QWidget *parent = nullptr);
    ~WorldWindow();

private:
    Ui::WorldWindow *ui;
};

#endif // WORLDWINDOW_H

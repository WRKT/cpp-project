#ifndef MORPIONWIDGET_H
#define MORPIONWIDGET_H

#include "qpushbutton.h"
#include <QWidget>

namespace Ui {
class MorpionWidget;
}

class MorpionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MorpionWidget(QWidget *parent = nullptr);
    ~MorpionWidget();

private:
    Ui::MorpionWidget *ui;
    QPushButton* retourMenu;
};

#endif // MORPIONWIDGET_H

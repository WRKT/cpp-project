#include "morpionwidget.h"
#include "ui_morpionwidget.h"

MorpionWidget::MorpionWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MorpionWidget)
{
    ui->setupUi(this);
}

MorpionWidget::~MorpionWidget()
{
    delete ui;
}

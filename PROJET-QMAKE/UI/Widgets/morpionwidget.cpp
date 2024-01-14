#include "morpionwidget.h"
#include "ui_morpionwidget.h"

MorpionWidget::MorpionWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MorpionWidget)
{
    ui->setupUi(this);
    this->setParent(parent);

    retourMenu = new QPushButton("Retour au Menu", this);

    retourMenu->move(250,80);

    QObject::connect(retourMenu, SIGNAL(clicked()), this->parent(), SLOT(RetourMenu()));
}

MorpionWidget::~MorpionWidget()
{
    delete ui;
}

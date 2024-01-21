#ifndef Accueil_H
#define Accueil_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class Accueil;
}

class Accueil : public QWidget
{
    Q_OBJECT

public:
    explicit Accueil(QWidget *parent = nullptr);
    ~Accueil();

public slots:
    void on_morpionButton_clicked();

private:
    Ui::Accueil *ui;

signals:
    void nouveauJeu();
};

#endif // Accueil_H

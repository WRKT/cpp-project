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
    void on_puissance4Button_clicked();
    void on_othelloButton_clicked();
    void on_damesButton_clicked();

private:
    Ui::Accueil *ui;

signals:
    void showMorpion();
    void showPuissance4();
    void showOthello();
    void showDames();
};

#endif // Accueil_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QCoreApplication>
#include <memory>
#include "accueil.h"
#include "jeugui.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void CreerNouveauJeu(TypesJeu typeDeJeu);
    void QuitterApplication();

private:
    void initWidgets();

    Ui::MainWindow *ui;
    std::unique_ptr<Accueil> accueilWidget;
    std::unique_ptr<JeuGUI> jeuWidget;
    TypesJeu typeJeu;
};

#endif // MAINWINDOW_H

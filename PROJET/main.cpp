#include "mainwindow.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication application(argc, argv);
    MainWindow fenetre;
    fenetre.show();
    return application.exec();

}

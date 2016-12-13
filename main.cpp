#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Database db;
    QApplication application(argc, argv);
    MainWindow window;
    window.show();

    return application.exec();
}

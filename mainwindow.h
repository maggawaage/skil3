#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "personservice.h"
#include "computerservice.h"
#include <QTableWidget>
#include <QMainWindow>
#include <qDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    vector<Person> tableForPersons();
    vector<Computer> tableForComputers();


private slots:
    void on_pushButtonPerson_clicked();

    void on_pushButtonComputer_clicked();


private:
    Ui::MainWindow *ui;
    QTableWidget* m_TableWidget;

    PersonService _service;
    ComputerService _Cservice;
};

#endif // MAINWINDOW_H

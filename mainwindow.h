#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "personservice.h"
#include "computerservice.h"
#include <QMainWindow>
#include <QTableWidget>
//#include <QTableWidgetItem>
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
    void displayVector(vector<Person> printPersons, int x);


private slots:

    void on_pushButtonPerson_clicked();
    //void on_pushButtonComputer_clicked();*/


private:
    Ui::MainWindow *ui;
    //QTableWidget *person_TableWidget;
    vector<Person> currentlyDisplayedPersons;

    PersonService _service;
    ComputerService _Cservice;
};

#endif // MAINWINDOW_H

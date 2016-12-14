#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "personservice.h"
#include "computerservice.h"
#include "addpersonsdialog.h"
#include "addcomputersdialog.h"
#include "editpersonsdialog.h"
#include "editcomputersdialog.h"

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
    vector<Person> displayPersons();
    vector<Computer> displayComputers();
    void displayPersonsVector(vector<Person> printPersons, int x);
    QString showGender(char input);



private slots:

    void on_pushButtonAddPerson_clicked();

    /*void on_pushButtonAddComp_clicked();

    void on_pushButtonEditPerson_clicked();

    void on_pushButtonEditComputer_clicked();

    void on_pushButtonDeletePerson_clicked();

    void on_pushButtonDeleteComputer_clicked();

    void on_pushButtonPersConnection_clicked();

    void on_pushButtonComConnection_clicked();

    void on_searchPersons_textChanged(const QString &arg1);*/

    void on_Tabs_tabBarClicked(int index);

    void on_pushButtonAddComp_clicked();

    void on_pushButtonEditPerson_clicked();

private:
    Ui::MainWindow *ui;
    vector<Person> _currentlyDisplayedPersons;
    vector<Computer> _currentlyDisplayedComputers;
    PersonService _PService;
    ComputerService _CService;
};

#endif // MAINWINDOW_H

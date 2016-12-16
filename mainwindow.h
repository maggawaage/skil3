#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "personservice.h"
#include "computerservice.h"
#include "personsdialog.h"
#include "connectiondialog.h"
#include "computersdialog.h"

#include <QMainWindow>
#include <QTableWidget>
#include <qDebug>
#include <QTableWidgetItem>

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
    vector<Person> displaySearchPersons(string string);
    vector<Computer> displayComputers();
    vector<Computer> displaySearchComputers(string string);
    QString showGender(char input);

private slots:

    void on_personsTable_clicked(const QModelIndex &index);

    void on_computersTable_clicked(const QModelIndex &index);

    void on_Tabs_tabBarClicked(int index);

    void on_pushButtonAddPerson_clicked();

    void on_pushButtonAddComp_clicked();

    void on_personsTable_doubleClicked(const QModelIndex &index);

    void on_computersTable_doubleClicked(const QModelIndex &index);

    void on_inputSearchPersons_textChanged(const QString &arg1);

    void on_inputSearchComp_textChanged(const QString &arg1);

    void on_actionGo_to_link_triggered();

    void on_pushButtonDeletePerson_clicked();

    void on_pushButtonDeleteComputer_clicked();

    void on_pushButtonPersConnection_clicked();

    void on_pushButtonComConnection_clicked();


private:
    Ui::MainWindow *ui;
    vector<Person> _currentlyDisplayedPersons;
    vector<Computer> _currentlyDisplayedComputers;
    PersonService _PService;
    ComputerService _CService;
    ConnectionDialog _Connection;
};

#endif // MAINWINDOW_H

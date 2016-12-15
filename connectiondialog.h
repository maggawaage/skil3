#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QDialog>
#include "personservice.h"
#include "computerservice.h"
#include "person.h"
#include "computer.h"

namespace Ui {
class ConnectionDialog;
}

class ConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionDialog(QWidget *parent = 0);
    ~ConnectionDialog();
    void PersonOrComputer(int type, string name);
    void tableIfShowComputers(string personName);
    void tableIfShowPersons(string computerName);
    void unlinkTableIfShowPersons(string computerName);
    void unlinkTableIfShowComputers(string computerName);
    QString showGender(char input);
     void test(QString name);

private slots:

    void on_linkedTable_clicked(const QModelIndex &index);

    void on_unLinkedTable_clicked(const QModelIndex &index);

    void on_unlinkButton_clicked();

    void on_linkButton_clicked();



private:
    Ui::ConnectionDialog *ui;
    //0 is person and 1 is computer
    int _PersonOrComputer;
    vector<Person> _currentlyLinkedPersons;
    vector<Computer> _currentlyLinkedComputers;
    vector<Person> _currentlyUnLinkedPersons;
    vector<Computer> _currentlyUnLinkedComputers;
    string _currentName;
    PersonService _PService;
    ComputerService _CService;

};

#endif // CONNECTIONDIALOG_H

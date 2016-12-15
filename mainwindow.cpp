#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <iostream>
#include <QDebug>

using namespace std;

//TODO LIST:
//Fá gender til að virka
//Fá edit fall til að uppfærast í gagnagrunni
//Virkja edit takka
//Fá connect föll til að virka


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayPersons();
}

MainWindow::~MainWindow()
{
    delete ui;
}

vector<Person> MainWindow::displayPersons()
{
    vector<Person> Persons;
    Persons = _PService.getVectorFromDataAccess(Persons);
    QString gender;

    ui->personsTable->setRowCount(Persons.size());
    ui->personsTable->clearContents();
    ui->personsTable->setColumnWidth(0, 175);
    for(size_t row = 0; row < Persons.size(); row++)
    {

        Person CurrentPerson = Persons.at(row);
        QString name = QString::fromStdString(CurrentPerson.getName());
        char ge = CurrentPerson.getGender();
        gender = showGender(ge);
        QString birthYear = QString::number(CurrentPerson.getBirthYear());
        QString deathYear = QString::number(CurrentPerson.getDeathYear());

        ui->personsTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->personsTable->setItem(row, 1, new QTableWidgetItem(gender));
        ui->personsTable->setItem(row, 2, new QTableWidgetItem(birthYear));
        ui->personsTable->setItem(row, 3, new QTableWidgetItem(deathYear));
    }

    _currentlyDisplayedPersons = Persons;
    return Persons;

}

//fengum lanað hjá gunnari kennara
QString MainWindow::showGender(char input)
{
    QString gender;
    if(input == 'M' || input == 'm')
    {
        gender = 'M';
    }
    else if(input == 'F' || input == 'f')
    {
        gender = 'F';
    }
    else
    {
        qDebug() << "error";
        qDebug() << input << endl;
        //error
    }
    return gender;
}

vector<Computer> MainWindow::displayComputers()
{
    vector<Computer> Computers;
    Computers = _CService.getVectorFromDataAccess(Computers);

    ui->computersTable->setRowCount(Computers.size());
    ui->computersTable->clearContents();
    ui->computersTable->setColumnWidth(0, 170);
    ui->computersTable->setColumnWidth(1, 210);

    for(size_t row = 0; row < Computers.size(); row++)
    {

        Computer CurrentComputer = Computers.at(row);
        QString name = QString::fromStdString(CurrentComputer.getName());
        QString type = QString::fromStdString(CurrentComputer.getType());
        QString buildYear = QString::number(CurrentComputer.getBuildYear());

        ui->computersTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->computersTable->setItem(row, 1, new QTableWidgetItem(type));
        ui->computersTable->setItem(row, 2, new QTableWidgetItem(buildYear));

    }

    _currentlyDisplayedComputers = Computers;
    return Computers;

}

void MainWindow::displayPersonsVector(vector<Person> printPersons, int x)
{
    cout << "\n";
    //Couts ID if you want
    if (x == 1)
    {
        cout << "ID" << "\t";
    }
    cout << "Name"<< "\t\t\t" << "Gender" << "\t" << "Birth year";
    cout.width(15);
    cout <<"Year of death";
    cout.width(15);
    cout <<"Age when died" << endl;;
    cout <<"========================================================================\n";

    for(size_t i = 0; i < printPersons.size(); i++)
    {
        //Couts ID number if you want
        cout.setf(ios::left);
        if (x == 1)
        {
            cout.width(8);
            cout << i+1;
        }
        cout.width(24);
        cout << printPersons[i].getName();
        if(printPersons[i].getGender()=='m')
        {
            cout.width(8);
            cout << "Male";
        }
        else
        {
            cout.width(8);
            cout << "Female";
        }
        cout.width(12);
        cout << printPersons[i].getBirthYear();
        if (!(printPersons[i].getDeathYear() == 0))
        {
            cout.width(15);
            cout << printPersons[i].getDeathYear()
                 << (printPersons[i].getDeathYear() - printPersons[i].getBirthYear()) << endl;;
        }
        else
        {
            cout.width(15);
            cout << '-'
                 << "-\n";
        }
    }
}

void MainWindow::on_Tabs_tabBarClicked(int index)
{
    if(index == 0)
    {
        displayPersons();
    }
    else if (index == 1)
    {
        displayComputers();
    }
    else if(index == 2)
    {
        //Another tab?
    }
     qDebug() << "on tabs bar was clicked" << index << endl;
}

void MainWindow::on_personsTable_clicked(const QModelIndex &index)
{
    //ui->pushButtonEditPerson->setEnabled(true);
    ui->pushButtonDeletePerson->setEnabled(true);
}

void MainWindow::on_computersTable_clicked(const QModelIndex &index)
{
    //ui->pushButtonEditComputer->setEnabled(true);
    ui->pushButtonDeleteComputer->setEnabled(true);
}

void MainWindow::on_pushButtonAddPerson_clicked()
{
    PersonsDialog AddPersonsDialog;
    int addPersonReturnValue = AddPersonsDialog.exec();

    if(addPersonReturnValue == 0)
    {
        ui->inputSearchPersons->setText("");
        displayPersons();
        ui->statusBar->showMessage("Successfully added a person!", 2000);
    }
    else
    {
        //qDebug() << "error";
    }
}

void MainWindow::on_pushButtonAddComp_clicked()
{
    ComputersDialog AddComputersDialog;
    int addComputerReturnValue = AddComputersDialog.exec();

    if(addComputerReturnValue == 0)
    {
        ui->inputSearchComp->setText("");
        displayComputers();
        ui->statusBar->showMessage("Successfully added a computer!", 2000);
    }
    else
    {
        //errormessage
    }
}

void MainWindow::on_personsTable_doubleClicked(const QModelIndex &index)
{
    PersonsDialog editPersonsDialog;
    vector<Person> Persons;
    Persons = _PService.getVectorFromDataAccess(Persons);
    //ui->personsTable->clearContents();

    //ui->personsTable->selectionModel()->selection().indexes().at(0)
    //QModelIndex index = ui->personsTable->selectionModel()->selection().indexes().at(0);
    Person person;
    string name = ui->personsTable->item(index.row(),0)->text().toStdString();
    char gender = ui->personsTable->item(index.row(),1)->text().toDouble();
    int birthYear = ui->personsTable->item(index.row(),2)->text().toInt();
    int deathYear = ui->personsTable->item(index.row(),3)->text().toInt();

    person.setName(name);
    person.setGender(gender);
    person.setBirthYear(birthYear);
    person.setDeathYear(deathYear);

    editPersonsDialog.setPerson(person);
    editPersonsDialog.exec();

    //displayPersons();
    //gera í personsdialog
    //kalla á takkafallið?

}

void MainWindow::on_computersTable_doubleClicked(const QModelIndex &index)
{
    ComputersDialog editComputersDialog;
    Computer computer;
    string name = ui->computersTable->item(index.row(),0)->text().toStdString();
    string type = ui->computersTable->item(index.row(),1)->text().toStdString();
    int buildYear = ui->computersTable->item(index.row(),2)->text().toInt();

    computer.setName(name);
    computer.setType(type);
    computer.setBuildYear(buildYear);

    editComputersDialog.setComputer(computer);
    editComputersDialog.exec();

    //kalla á takkafallið ?


}

/*
void MainWindow::on_pushButtonDeletePerson_clicked()
{
    //TODO:
}

void MainWindow::on_pushButtonDeleteComputer_clicked()
{
    //TODO:
}

void MainWindow::on_pushButtonPersConnection_clicked()
{
    //TODO:
}

void MainWindow::on_pushButtonComConnection_clicked()
{
    //TODO:
}

void MainWindow::on_inputSearchPersons_textChanged(const QString &arg1)
{
   //TODO:
}

*/

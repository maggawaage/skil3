#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <iostream>

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

vector<Person> MainWindow::tableForPersons()
{
    vector<Person> persons;
    persons = _PService.getVectorFromDataAccess(persons);
    QString gender;

    ui->personsTable->setRowCount(persons.size());
    ui->personsTable->clearContents();
    for(size_t row = 0; row < persons.size(); row++)
    {

        Person currentPerson = persons.at(row);
        QString name = QString::fromStdString(currentPerson.getName());
        char ge = currentPerson.getGender();
        gender = showGender(ge);
        QString birthYear = QString::number(currentPerson.getBirthYear());
        QString deathYear = QString::number(currentPerson.getDeathYear());

        ui->personsTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->personsTable->setItem(row, 1, new QTableWidgetItem(gender));
        ui->personsTable->setItem(row, 2, new QTableWidgetItem(birthYear));
        ui->personsTable->setItem(row, 3, new QTableWidgetItem(deathYear));

    }

    _currentlyDisplayedPersons = persons;
    return persons;

}

QString MainWindow::showGender(char input)
{
    QString gender;
    if(input == 'M' || input == 'm')
    {
        gender = 'M';
    }
    else
    {
        gender = 'F';
    }
    return gender;
}

vector<Computer> MainWindow::tableForComputers()
{
    vector<Computer> computers;
    computers = _CService.getVectorFromDataAccess(computers);
    //TODO: búa til töflu
    //Name, Type, BuildYear
}

void MainWindow::displayVector(vector<Person> printPersons, int x)
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

void MainWindow::on_pushButtonPerson_clicked()
{
    tableForPersons();
}

/*void MainWindow::on_pushButtonComputer_clicked()
{
    tableForComputers();
}

void MainWindow::on_pushButtonAddPerson_clicked()
{
    //Ná í uppl úr addpersonsdialog.ui

}

void MainWindow::on_pushButtonEditPerson_clicked()
{
    //TODO:
}

void MainWindow::on_pushButtonDeletePerson_clicked()
{
    //TODO:
}


void MainWindow::on_pushButtonConnectToComp_clicked()
{
    //TODO:
}


void MainWindow::on_pushButtonShowConnections_clicked()
{

}*/

void MainWindow::on_PersonsTable_tabBarClicked()
{
    tableForPersons();
}

/*
void MainWindow::on_ComputersTable_tabBarClicked(int index)
{

}*/

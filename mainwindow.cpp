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

    ui->personsTable->setRowCount((int)Persons.size());
    ui->personsTable->clearContents();
    ui->personsTable->setColumnWidth(0, 175);
    for(size_t row = 0; row < Persons.size(); row++)
    {

        Person CurrentPerson = Persons.at(row);
        //QString Id = QString::number(CurrentPerson.getId());
        QString name = QString::fromStdString(CurrentPerson.getName());
        char ge = CurrentPerson.getGender();
        gender = showGender(ge);
        QString birthYear = QString::number(CurrentPerson.getBirthYear());
        QString deathYear = QString::number(CurrentPerson.getDeathYear());

        ui->personsTable->setItem((int)row, 0, new QTableWidgetItem(name));
        ui->personsTable->setItem((int)row, 1, new QTableWidgetItem(gender));
        ui->personsTable->setItem((int)row, 2, new QTableWidgetItem(birthYear));
        ui->personsTable->setItem((int)row, 3, new QTableWidgetItem(deathYear));
    }

    _currentlyDisplayedPersons = Persons;
    return Persons;

}

vector<Person> MainWindow::displaySearchPersons(string string)
{
    vector<Person> Persons;
    Persons = _PService.getVectorFromDataAccess(Persons);

    Persons = PersonService::Search(Persons, string);

    QString gender;

    ui->personsTable->setRowCount((int)Persons.size());
    ui->personsTable->clearContents();
    ui->personsTable->setColumnWidth(0, 175);
    for(size_t row = 0; row < Persons.size(); row++)
    {

        Person CurrentPerson = Persons.at(row);
        //QString Id = QString::number(CurrentPerson.getId());
        QString name = QString::fromStdString(CurrentPerson.getName());
        char ge = CurrentPerson.getGender();
        gender = showGender(ge);
        QString birthYear = QString::number(CurrentPerson.getBirthYear());
        QString deathYear = QString::number(CurrentPerson.getDeathYear());

        ui->personsTable->setItem((int)row, 0, new QTableWidgetItem(name));
        ui->personsTable->setItem((int)row, 1, new QTableWidgetItem(gender));
        ui->personsTable->setItem((int)row, 2, new QTableWidgetItem(birthYear));
        ui->personsTable->setItem((int)row, 3, new QTableWidgetItem(deathYear));

    }

    _currentlyDisplayedPersons = Persons;
    return Persons;

}

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
    return gender;
}

vector<Computer> MainWindow::displayComputers()
{
    vector<Computer> Computers;
    Computers = _CService.getVectorFromDataAccess(Computers);

    ui->computersTable->setRowCount((int)Computers.size());
    ui->computersTable->clearContents();
    ui->computersTable->setColumnWidth(0, 170);
    ui->computersTable->setColumnWidth(1, 210);

    for(size_t row = 0; row < Computers.size(); row++)
    {

        Computer CurrentComputer = Computers.at(row);
        //QString Id = QString::number(CurrentComputer.getId());
        QString name = QString::fromStdString(CurrentComputer.getName());
        QString type = QString::fromStdString(CurrentComputer.getType());
        QString buildYear = QString::number(CurrentComputer.getBuildYear());

        ui->computersTable->setItem((int)row, 0, new QTableWidgetItem(name));
        ui->computersTable->setItem((int)row, 1, new QTableWidgetItem(type));
        ui->computersTable->setItem((int)row, 2, new QTableWidgetItem(buildYear));

    }

    _currentlyDisplayedComputers = Computers;
    return Computers;

}

vector<Computer> MainWindow::displaySearchComputers(string string)
{
    vector<Computer> Computers;
    Computers = _CService.getVectorFromDataAccess(Computers);

    Computers = ComputerService::Search(Computers, string);

    ui->computersTable->setRowCount((int)Computers.size());
    ui->computersTable->clearContents();
    ui->computersTable->setColumnWidth(0, 175);
    ui->computersTable->setColumnWidth(1, 220);

    for(size_t row = 0; row < Computers.size(); row++)
    {

        Computer CurrentComputer = Computers.at(row);
        //QString Id = QString::number(CurrentComputer.getId());
        QString name = QString::fromStdString(CurrentComputer.getName());
        QString type = QString::fromStdString(CurrentComputer.getType());
        QString buildYear = QString::number(CurrentComputer.getBuildYear());

        ui->computersTable->setItem((int)row, 0, new QTableWidgetItem(name));
        ui->computersTable->setItem((int)row, 1, new QTableWidgetItem(type));
        ui->computersTable->setItem((int)row, 2, new QTableWidgetItem(buildYear));

    }

    _currentlyDisplayedComputers = Computers;
    return Computers;

}

void MainWindow::on_Tabs_tabBarClicked(int index)
{
    //Person
    if(index == 0)
    {
        displayPersons();
        ui->pushButtonComConnection->setDisabled(true);
        ui->pushButtonDeleteComputer->setDisabled(true);
    }
    //Computer
    else if (index == 1)
    {
        displayComputers();
        ui->pushButtonPersConnection->setDisabled(true);
        ui->pushButtonDeletePerson->setDisabled(true);
    }
}

void MainWindow::on_personsTable_clicked(const QModelIndex &index)
{
    ui->pushButtonDeletePerson->setEnabled(true);
    ui->pushButtonPersConnection->setEnabled(true);
}

void MainWindow::on_computersTable_clicked(const QModelIndex &index)
{
    //ui->pushButtonEditComputer->setEnabled(true);
    ui->pushButtonDeleteComputer->setEnabled(true);
    ui->pushButtonComConnection->setEnabled(true);
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

    //QString newName = ui->inputPName->text();
    //ui->personsTable->setItem(index.row(),0,)->text.toStdString();

    //_editConnection.on_pushButtonEditPerson_clicked();

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

void MainWindow::on_pushButtonPersConnection_clicked()
{
    int currentPersonIndex = ui->personsTable->currentIndex().row();
    int currentPersonIndexId = _currentlyDisplayedPersons.at(currentPersonIndex).getId();

    _Connection.PersonOrComputer(1, currentPersonIndexId);
    _Connection.setModal(true);
    _Connection.exec();
}

void MainWindow::on_pushButtonComConnection_clicked()
{
    int currentComputerIndex = ui->computersTable->currentIndex().row();
    int currentComputerIndexId = _currentlyDisplayedComputers.at(currentComputerIndex).getId();

    _Connection.PersonOrComputer(0, currentComputerIndexId);
    _Connection.setModal(true);
    _Connection.exec();
}

void MainWindow::on_inputSearchComp_textChanged(const QString &arg1)
{
    string search = arg1.toStdString();

    displaySearchComputers(search);
}

void MainWindow::on_inputSearchPersons_textChanged(const QString &arg1)
{
    string search = arg1.toStdString();

    displaySearchPersons(search);
}

void MainWindow::on_actionGo_to_link_triggered()
{
    #ifdef _WIN32
    {
    system ("start https://github.com/maggawaage/skil2");
    }
    #else //In any other OS
    {
        system ("open https://github.com/maggawaage/skil2");
    }
    #endif
}

void MainWindow::on_pushButtonDeletePerson_clicked()
{
    int currentPersonIndex = ui->personsTable->currentIndex().row();
    int currentPeronIndexID = _currentlyDisplayedPersons.at(currentPersonIndex).getId();
    _PService.deletePerson(currentPeronIndexID);
    _PService.deleteConnectionPerson(currentPeronIndexID);

    ui->personsTable->clear();
    displayPersons();
}

void MainWindow::on_pushButtonDeleteComputer_clicked()
{
    int currentComputerIndex = ui->computersTable->currentIndex().row();
    int currentComputerIndexID = _currentlyDisplayedComputers.at(currentComputerIndex).getId();
    _CService.deleteComputer(currentComputerIndexID);
    _CService.deleteConnectionComputer(currentComputerIndexID);

    ui->computersTable->clear();
    displayComputers();
}

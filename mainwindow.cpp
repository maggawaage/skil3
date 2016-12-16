#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <iostream>
#include <QDebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    string userInput = ui->inputSearchPersons->text().toStdString();

    displayPersons(userInput);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//DISPLAY TABLE OF PERSONS FROM DATABASE
vector<Person> MainWindow::displayPersons(string string)
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

//DISPLAY TABLE OF COMPUTERS FROM DATABASE
vector<Computer> MainWindow::displayComputers(string string)
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

//FUNCTION OF TABS, IF TAB 0 IS CHOSEN USER RECEIVES THE PERSON'S TABLE, OTHERWISE HE/SHE RECEIVES THE COMPUTER'S TABLE
void MainWindow::on_Tabs_tabBarClicked(int index)
{
    //Person
    if(index == 0)
    {
        string userInput = ui->inputSearchPersons->text().toStdString();
        displayPersons(userInput);
        ui->pushButtonComConnection->setDisabled(true);
        ui->pushButtonDeleteComputer->setDisabled(true);
    }
    //Computer
    else if (index == 1)
    {
        string userInput = ui->inputSearchComp->text().toStdString();
        displayComputers(userInput);
        ui->pushButtonPersConnection->setDisabled(true);
        ui->pushButtonDeletePerson->setDisabled(true);
    }
}

//ENABLE DELETE AND CONNECTIONS BUTTONS BY SELECTION AN ITEM ON TABLE
void MainWindow::on_personsTable_clicked(const QModelIndex &index)
{
    ui->pushButtonDeletePerson->setEnabled(true);
    ui->pushButtonPersConnection->setEnabled(true);
}

//ENABLE DELETE AND CONNECTIONS BUTTONS BY SELECTION AN ITEM ON TABLE
void MainWindow::on_computersTable_clicked(const QModelIndex &index)
{
    ui->pushButtonDeleteComputer->setEnabled(true);
    ui->pushButtonComConnection->setEnabled(true);
}

//OPENS A NEW AND CLEAN WINDOW SO USER CAN ADD A NEW PERSON INTO DATABASE
void MainWindow::on_pushButtonAddPerson_clicked()
{
    PersonsDialog AddPersonsDialog;
    AddPersonsDialog.setAddPerson(true);
    int addPersonReturnValue = AddPersonsDialog.exec();

    if(addPersonReturnValue == 0)
    {
        string userInput = ui->inputSearchPersons->text().toStdString();
        displayPersons(userInput);
        ui->statusBar->showMessage("Successfully added a person!", 2000);
    }
    else
    {
        ui->statusBar->showMessage("Not successful!", 2000);
    }
}

//OPENS A NEW AND CLEAN WINDOW SO USER CAN ADD A NEW COMPUTER INTO DATABASE
void MainWindow::on_pushButtonAddComp_clicked()
{
    ComputersDialog AddComputersDialog;
    AddComputersDialog.setAddComputer(true);
    int addComputerReturnValue = AddComputersDialog.exec();

    if(addComputerReturnValue == 0)
    {
        string userInput = ui->inputSearchComp->text().toStdString();
        displayComputers(userInput);
        ui->statusBar->showMessage("Successfully added a computer!", 2000);
    }
    else
    {
        ui->statusBar->showMessage("Not successful!", 2000);
    }
}

//OPENS EDIT MODE IN A NEW WINDOW, SO THAT USER CAN EDIT INFORMATION ABOUT THE PERSON THEY CLICKED ON
void MainWindow::on_personsTable_doubleClicked(const QModelIndex &index)
{
    PersonsDialog editPersonsDialog;
    vector<Person> Persons;
    Persons = _PService.getVectorFromDataAccess(Persons);

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
    editPersonsDialog.setEditPerson(true);
    editPersonsDialog.exec();

}

//OPENS EDIT MODE IN A NEW WINDOW, SO THAT USER CAN EDIT INFORMATION ABOUT THE PERSON THEY CLICKED ON
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
    editComputersDialog.setEditComputer(true);
    editComputersDialog.exec();

}

//OPENS CONNECTION MODE IN A NEW WINDOW, SO THAT USER CAN ADD OR DELETE CONNECTIONS
void MainWindow::on_pushButtonPersConnection_clicked()
{
    int currentPersonIndex = ui->personsTable->currentIndex().row();
    int currentPersonIndexId = _currentlyDisplayedPersons.at(currentPersonIndex).getId();

    _Connection.PersonOrComputer(1, currentPersonIndexId);
    _Connection.setModal(true);
    _Connection.exec();
}

//OPENS CONNECTION MODE IN A NEW WINDOW, SO THAT USER CAN ADD OR DELETE CONNECTIONS
void MainWindow::on_pushButtonComConnection_clicked()
{
    int currentComputerIndex = ui->computersTable->currentIndex().row();
    int currentComputerIndexId = _currentlyDisplayedComputers.at(currentComputerIndex).getId();

    _Connection.PersonOrComputer(0, currentComputerIndexId);
    _Connection.setModal(true);
    _Connection.exec();
}

//SEARCH WINDOW FOR COMPUTERS
void MainWindow::on_inputSearchComp_textChanged(const QString &arg1)
{
    ui->pushButtonComConnection->setDisabled(true);
    ui->pushButtonDeleteComputer->setDisabled(true);
    string search = arg1.toStdString();
    displayComputers(search);
}

//SEARCH WINDOW FOR PERSONS
void MainWindow::on_inputSearchPersons_textChanged(const QString &arg1)
{
    ui->pushButtonPersConnection->setDisabled(true);
    ui->pushButtonDeletePerson->setDisabled(true);
    string search = arg1.toStdString();
    displayPersons(search);
}

//LINK TO GITHUB OF PROJECT
void MainWindow::on_actionGo_to_link_triggered()
{
    #ifdef _WIN32
    {
    system ("start https://github.com/maggawaage/skil3");
    }
    #else //In any other OS
    {
        system ("open https://github.com/maggawaage/skil3");
    }
    #endif
}

//DELETE PERSON WHEN BUTTON IS PUSHED
void MainWindow::on_pushButtonDeletePerson_clicked()
{
    int currentPersonIndex = ui->personsTable->currentIndex().row();
    int currentPeronIndexID = _currentlyDisplayedPersons.at(currentPersonIndex).getId();
    _PService.deletePerson(currentPeronIndexID);
    _PService.deleteConnectionPerson(currentPeronIndexID);

    ui->pushButtonPersConnection->setDisabled(true);
    ui->pushButtonDeletePerson->setDisabled(true);

    string userInput = ui->inputSearchPersons->text().toStdString();
    displayPersons(userInput);

}

//DELETE COMPUTER WHEN BUTTON IS PUSHED
void MainWindow::on_pushButtonDeleteComputer_clicked()
{
    int currentComputerIndex = ui->computersTable->currentIndex().row();
    int currentComputerIndexID = _currentlyDisplayedComputers.at(currentComputerIndex).getId();
    _CService.deleteComputer(currentComputerIndexID);
    _CService.deleteConnectionComputer(currentComputerIndexID);

    ui->pushButtonComConnection->setDisabled(true);
    ui->pushButtonDeleteComputer->setDisabled(true);

    string userInput = ui->inputSearchComp->text().toStdString();
    displayComputers(userInput);

}

void MainWindow::on_actionAbout_Program_triggered(bool checked)
{
    _About.setModal(true);
    _About.exec();
}

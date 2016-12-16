#include "connectiondialog.h"
#include "ui_connectiondialog.h"
#include "mainwindow.h"
#include <vector>
#include <iostream>
#include <QDebug>


using namespace std;

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}

void ConnectionDialog::PersonOrComputer(int type, string name)
{
    if(type==0)
    {
        tableIfShowPersons(name);
        unlinkTableIfShowPersons(name);
        _PersonOrComputer=0;
    }
    if (type==1)
    {
        tableIfShowComputers(name);
        unlinkTableIfShowComputers(name);
        _PersonOrComputer=1;
    }
}

void ConnectionDialog::tableIfShowComputers(string personName)
{
    vector<Computer> LinkedComputers;
    //LinkedComputers.clear();
    LinkedComputers = _PService.getComputersConnectedToPerson(personName);

    ui->linkedTable->setRowCount((int)LinkedComputers.size());
    ui->linkedTable->clearContents();
    ui->linkedTable->setColumnCount(3);
    for(int row = 0; row < LinkedComputers.size(); row++)
    {

        Computer CurrentComputer = LinkedComputers.at(row);
        QString name = QString::fromStdString(CurrentComputer.getName());
        QString type = QString::fromStdString(CurrentComputer.getType());
        QString buildYear = QString::number(CurrentComputer.getBuildYear());

        ui->linkedTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->linkedTable->setItem(row, 1, new QTableWidgetItem(type));
        ui->linkedTable->setItem(row, 2, new QTableWidgetItem(buildYear));

    }
     _currentlyLinkedComputers = LinkedComputers;
    _currentName=personName;
}

void ConnectionDialog::tableIfShowPersons(string computerName)
{
    vector<Person> LinkedPersons;
    //LinkedPersons.clear();
    LinkedPersons = _CService.getPersonsConnectedToComputer(computerName);

    ui->linkedTable->setRowCount((int)LinkedPersons.size());
    ui->linkedTable->clearContents();
    for(int row = 0; row < LinkedPersons.size(); row++)
    {
        Person CurrentPerson = LinkedPersons.at(row);
        QString name = QString::fromStdString(CurrentPerson.getName());
        char ge = CurrentPerson.getGender();
        QString gender = showGender(ge);
        QString birthYear = QString::number(CurrentPerson.getBirthYear());
        QString deathYear = QString::number(CurrentPerson.getDeathYear());

        ui->linkedTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->linkedTable->setItem(row, 1, new QTableWidgetItem(gender));
        ui->linkedTable->setItem(row, 2, new QTableWidgetItem(birthYear));
        ui->linkedTable->setItem(row, 3, new QTableWidgetItem(deathYear));
    }
   _currentlyLinkedPersons = LinkedPersons;
   _currentName=computerName;
}

void ConnectionDialog::unlinkTableIfShowComputers(string personName)
{
    vector<Computer> LinkedComputers;
    //LinkedComputers.clear();
    LinkedComputers = _PService.getComputersConnectedToPerson(personName);
    vector<Computer> UnLinkedComputers;
    //UnLinkedComputers.clear();
    UnLinkedComputers =_CService.getVectorFromDataAccess(UnLinkedComputers);

    for (int i = 0; i < LinkedComputers.size() ; i++)
    {
        for(int j = 0; j < UnLinkedComputers.size() ; j++)
        {
            if( ( LinkedComputers.at(i).getName() == UnLinkedComputers.at(j).getName() ) &
                 ( LinkedComputers.at(i).getType() == UnLinkedComputers.at(j).getType() )  &
                 ( LinkedComputers.at(i).getBuildYear() == UnLinkedComputers.at(j).getBuildYear() ) )
            {
                UnLinkedComputers.erase (UnLinkedComputers.begin()+j);
            }
        }
    }

    ui->unLinkedTable->setRowCount((int)UnLinkedComputers.size());
    ui->unLinkedTable->clearContents();
    ui->unLinkedTable->setColumnCount(3);
    for(int row = 0; row < UnLinkedComputers.size(); row++)
    {

        Computer CurrentComputer = UnLinkedComputers.at(row);
        QString name = QString::fromStdString(CurrentComputer.getName());
        QString type = QString::fromStdString(CurrentComputer.getType());
        QString buildYear = QString::number(CurrentComputer.getBuildYear());

        ui->unLinkedTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->unLinkedTable->setItem(row, 1, new QTableWidgetItem(type));
        ui->unLinkedTable->setItem(row, 2, new QTableWidgetItem(buildYear));
    }
    _currentlyUnLinkedComputers = UnLinkedComputers;
}

void ConnectionDialog::unlinkTableIfShowPersons(string  computerName)
{
    vector<Person> LinkedPersons;
    //LinkedPersons.clear();
    LinkedPersons = _CService.getPersonsConnectedToComputer(computerName);
    vector<Person> UnLinkedPersons;
   // UnLinkedPersons.clear();
    UnLinkedPersons=_PService.getVectorFromDataAccess(UnLinkedPersons);

    qDebug() << "e";
    for (int i = 0; i < LinkedPersons.size() ; i++)
    {
        for(int j = 0; j < UnLinkedPersons.size() ; j++)
        {
            if( ( LinkedPersons.at(i).getName() == UnLinkedPersons.at(j).getName() ) &
                ( LinkedPersons.at(i).getGender() == UnLinkedPersons.at(j).getGender() )  &
                ( LinkedPersons.at(i).getBirthYear() == UnLinkedPersons.at(j).getBirthYear() )  &
                ( LinkedPersons.at(i).getDeathYear() == UnLinkedPersons.at(j).getDeathYear() ) )
            {
                UnLinkedPersons.erase (UnLinkedPersons.begin()+j);
            }
        }
    }

    ui->unLinkedTable->setRowCount((int)UnLinkedPersons.size());
    ui->unLinkedTable->clearContents();
    for(int row = 0; row < UnLinkedPersons.size(); row++)
    {
        Person CurrentPerson = UnLinkedPersons.at(row);
        QString name = QString::fromStdString(CurrentPerson.getName());
        char ge = CurrentPerson.getGender();
        QString gender = showGender(ge);
        QString birthYear = QString::number(CurrentPerson.getBirthYear());
        QString deathYear = QString::number(CurrentPerson.getDeathYear());

        ui->unLinkedTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->unLinkedTable->setItem(row, 1, new QTableWidgetItem(gender));
        ui->unLinkedTable->setItem(row, 2, new QTableWidgetItem(birthYear));
        ui->unLinkedTable->setItem(row, 3, new QTableWidgetItem(deathYear));

    }
        _currentlyUnLinkedPersons = UnLinkedPersons;
}



QString ConnectionDialog::showGender(char input)
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


void ConnectionDialog::on_linkedTable_clicked(const QModelIndex &index)
{
    ui->unlinkButton->setEnabled(true);
    ui->linkButton->setDisabled(true);
}

void ConnectionDialog::on_unLinkedTable_clicked(const QModelIndex &index)
{
    ui->linkButton->setEnabled(true);
    ui->unlinkButton->setDisabled(true);
}


void ConnectionDialog::on_linkButton_clicked()
{
    if(_PersonOrComputer == 1)
    {
    int currentUnLinkIndex = ui->unLinkedTable->currentIndex().row();
    string cName = _currentlyUnLinkedComputers.at(currentUnLinkIndex).getName();

    string pName = _currentName;
     _PService.linkPersonToComputer(pName, cName);

     ui->linkedTable->clear();
     tableIfShowComputers(pName);
     ui->unLinkedTable->clear();
     unlinkTableIfShowComputers(pName);
     ui->linkButton->setDisabled(true);
    }

    if(_PersonOrComputer == 0)
    {
    int currentUnLinkIndex = ui->unLinkedTable->currentIndex().row();
    string pName = _currentlyUnLinkedPersons.at(currentUnLinkIndex).getName();

    string cName = _currentName;
     _PService.linkPersonToComputer(pName, cName);

     ui->linkedTable->clear();
     tableIfShowPersons(cName);
     ui->unLinkedTable->clear();
     unlinkTableIfShowPersons(cName);
     ui->linkButton->setDisabled(true);
    }
}

void ConnectionDialog::on_unlinkButton_clicked()
{
    if(_PersonOrComputer == 1)
    {
    int currentLinkIndex = ui->linkedTable->currentIndex().row();
    string cName = _currentlyLinkedComputers.at(currentLinkIndex).getName();

    string pName = _currentName;
     _PService.deleteConnection(pName, cName);

     ui->linkedTable->clear();
     tableIfShowComputers(pName);
     ui->unLinkedTable->clear();
     unlinkTableIfShowComputers(pName);
     ui->unlinkButton->setDisabled(true);
    }

    if(_PersonOrComputer == 0)
    {
    int currentLinkIndex = ui->linkedTable->currentIndex().row();
    string pName = _currentlyLinkedPersons.at(currentLinkIndex).getName();

    string cName = _currentName;
     _PService.deleteConnection(pName, cName);

     ui->linkedTable->clear();
     tableIfShowPersons(cName);
     ui->unLinkedTable->clear();
     unlinkTableIfShowPersons(cName);
     ui->unlinkButton->setDisabled(true);
    }
}


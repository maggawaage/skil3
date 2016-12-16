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

void ConnectionDialog::PersonOrComputer(int type, int id)
{
    if(type==0)
    {
        tableIfShowPersons(id);
        unlinkTableIfShowPersons(id);
        _PersonOrComputer=0;
    }
    if (type==1)
    {
        tableIfShowComputers(id);
        unlinkTableIfShowComputers(id);
        _PersonOrComputer=1;
    }
}

void ConnectionDialog::tableIfShowComputers(int id)
{
    vector<Computer> LinkedComputers;
    //LinkedComputers.clear();
    LinkedComputers = _PService.getComputersConnectedToPerson(id);

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
   _currentId=id;
}

void ConnectionDialog::tableIfShowPersons(int id)
{
    vector<Person> LinkedPersons;
    //LinkedPersons.clear();
    LinkedPersons = _CService.getPersonsConnectedToComputer(id);

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
   _currentId=id;
}

void ConnectionDialog::unlinkTableIfShowComputers(int id)
{
    vector<Computer> LinkedComputers;
    //LinkedComputers.clear();
    LinkedComputers = _PService.getComputersConnectedToPerson(id);
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

void ConnectionDialog::unlinkTableIfShowPersons(int id)
{
    vector<Person> LinkedPersons;
    //LinkedPersons.clear();
    LinkedPersons = _CService.getPersonsConnectedToComputer(id);
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
    int cId = _currentlyUnLinkedComputers.at(currentUnLinkIndex).getId();

    int pId = _currentId;
     _PService.linkPersonToComputer(pId, cId);

     ui->linkedTable->clear();
     tableIfShowComputers(pId);
     ui->unLinkedTable->clear();
     unlinkTableIfShowComputers(pId);
     ui->linkButton->setDisabled(true);
    }

    if(_PersonOrComputer == 0)
    {
    int currentUnLinkIndex = ui->unLinkedTable->currentIndex().row();
    int pId = _currentlyUnLinkedPersons.at(currentUnLinkIndex).getId();

    int cId = _currentId;
     _PService.linkPersonToComputer(pId, cId);

     ui->linkedTable->clear();
     tableIfShowPersons(cId);
     ui->unLinkedTable->clear();
     unlinkTableIfShowPersons(cId);
     ui->linkButton->setDisabled(true);
    }
}

void ConnectionDialog::on_unlinkButton_clicked()
{
    if(_PersonOrComputer == 1)
    {
    int currentLinkIndex = ui->linkedTable->currentIndex().row();
    int cId = _currentlyLinkedComputers.at(currentLinkIndex).getId();

    int pId = _currentId;
     _PService.deleteConnection(pId, cId);

     ui->linkedTable->clear();
     tableIfShowComputers(pId);
     ui->unLinkedTable->clear();
     unlinkTableIfShowComputers(pId);
     ui->unlinkButton->setDisabled(true);
    }

    if(_PersonOrComputer == 0)
    {
    int currentLinkIndex = ui->linkedTable->currentIndex().row();
    int pId = _currentlyLinkedPersons.at(currentLinkIndex).getId();

    int cId = _currentId;
     _PService.deleteConnection(pId, cId);

     ui->linkedTable->clear();
     tableIfShowPersons(cId);
     ui->unLinkedTable->clear();
     unlinkTableIfShowPersons(cId);
     ui->unlinkButton->setDisabled(true);
    }
}


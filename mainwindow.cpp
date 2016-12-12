#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>




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
    persons = _service.getVectorFromDataAccess(persons);
    //TODO: búa til töflu
    //Name, Gender, BirthYear, DeathYear
    for(size_t i = 0; i < persons.size(); i++)
    {
        //TODO: kalla á create table?
    }

}

vector<Computer> MainWindow::tableForComputers()
{
    vector<Computer> computers;
    computers = _Cservice.getVectorFromDataAccess(computers);
    //TODO: búa til töflu
    //Name, Type, BuildYear
}



void MainWindow::on_pushButtonPerson_clicked()
{
    //TODO: If setning til að fá person list
    //Fá fall úr service sem kallar á access
    // Nota vectorinn til að
    //for lykkja til að búa til nýja töflu
    //show table
    tableForPersons();
}

void MainWindow::on_pushButtonComputer_clicked()
{
    //TODO: If setning til að fá computer list
    tableForComputers();
}


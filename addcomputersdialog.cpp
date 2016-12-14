#include "addcomputersdialog.h"
#include "ui_addcomputersdialog.h"

AddComputersDialog::AddComputersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputersDialog)
{
    ui->setupUi(this);
}

AddComputersDialog::~AddComputersDialog()
{
    delete ui;
}

void AddComputersDialog::on_pushButtonAddComputer_clicked()
{
    //TODO:
    vector<Computer> Computers;
    Computers = _CService.getVectorFromDataAccess(Computers);

    QString name = ui->inputCName->text();
    QString type = ui->inputCType->text();
    QString buildYear = ui->inputCBuildYear->text();

    if(name.isEmpty())
    {
        //errormessage
        return;
    }
    if(type.isEmpty())
    {
        //errormessage
        return;
    }
    if(buildYear.isEmpty())
    {
        //errormessage
        return;
    }

    bool success = _CService.addComputer(name.toStdString(), type.toStdString(), buildYear.toInt());

    if(success)
    {
        ui->inputCName->setText("");
        ui->inputCType->setText("");
        ui->inputCBuildYear->setText("");
        //this->done(0);
    }
    else
    {
        //error message
        //this->done(-1);
    }
}


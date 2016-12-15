#include "computersdialog.h"
#include "ui_computersdialog.h"

ComputersDialog::ComputersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputersDialog)
{
    ui->setupUi(this);
}

ComputersDialog::~ComputersDialog()
{
    delete ui;
}

void ComputersDialog::on_pushButtonAddComputer_clicked()
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

void ComputersDialog::setComputer(Computer computer)
{
    QString name = QString::fromStdString(computer.getName());
    QString type = QString::fromStdString(computer.getType());
    QString buildYear = QString::number(computer.getBuildYear());
    //qDebug() << name;
    ui->inputCName->setText(name);
    ui->inputCType->setText(type);
    ui->inputCBuildYear->setText(buildYear);
}



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
        ui->labelErrorComputerName->setText("<span style='color: red'>Name cannot be empty</span>");
        return;
    }
    if(type.isEmpty())
    {
        //errormessage
        ui->labelErrorComputerType->setText("<span style='color: red'>Type cannot be empty</span>");
        return;
    }
    if(buildYear.isEmpty())
    {
        //errormessage
        ui->labelErrorComputerBY->setText("<span style='color: red'>Build year cannot be empty</span>");
        return;
    }
    else if(!onlyNumbers(buildYear))
    {
        //errormessage
        ui->labelErrorComputerBY->setText("<span style='color: red'>You can only enter numbers</span>");
        return;
    }

    bool success = _CService.addComputer(name.toStdString(), type.toStdString(), buildYear.toInt());

    if(success)
    {
        ui->inputCName->setText("");
        ui->inputCType->setText("");
        ui->inputCBuildYear->setText("");
        this->done(0);
    }
    else
    {
        //error message
        //this->done(-1);
    }
}
bool ComputersDialog::onlyNumbers(QString string)
{
    for(int i = 0; i < string.size(); i++)
    {
        if(!(string[i].isDigit()))
            return false;
    }
    return true;
}

void ComputersDialog::setComputer(Computer computer)
{
    QString name = QString::fromStdString(computer.getName());
    QString type = QString::fromStdString(computer.getType());
    QString buildYear = QString::number(computer.getBuildYear());
    ui->inputCName->setText(name);
    ui->inputCType->setText(type);
    ui->inputCBuildYear->setText(buildYear);
}

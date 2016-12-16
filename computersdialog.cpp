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

//OPEN NEW, CLEAN WINDOW IF USER CLICKES ADD BUTTON, ERROR MESSAGES IF USER INPUTS WRONG INFORMATION
void ComputersDialog::on_pushButtonAddComputer_clicked()
{
    vector<Computer> Computers;
    Computers = _CService.getVectorFromDataAccess(Computers);
    QString name = ui->inputCName->text();
    QString type = ui->inputCType->text();
    QString buildYear = ui->inputCBuildYear->text();

    if(checkIfSame(name.toStdString(), type.toStdString(), buildYear.toInt()))
    {
        ui->labelErrorComputerName->setText("<span style='color: red'>This computer already exists</span>");
        return;
    }

    if(name.isEmpty())
    {
        ui->labelErrorComputerName->setText("<span style='color: red'>Name cannot be empty</span>");
        return;
    }

    if(type.isEmpty())
    {
        ui->labelErrorComputerType->setText("<span style='color: red'>Type cannot be empty</span>");
        return;
    }

    if(buildYear.isEmpty())
    {
        ui->labelErrorComputerBY->setText("<span style='color: red'>Build year cannot be empty</span>");
        return;
    }

    else if(!onlyNumbers(buildYear))
    {
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

}

//UPDATES INFORMATION WHEN USER EDITS PARTICULAR COMPUTER
vector<Computer> ComputersDialog::on_pushButtonEditComputer_clicked()
{
    vector<Computer> Computers;
    Computers = _CService.getVectorFromDataAccess(Computers);

    QString newName = ui->inputCName->text();
    QString type = ui->inputCType->text();
    QString buildYear = ui->inputCBuildYear->text();

    string currentName = tempEditName.toStdString();

    bool success =  (_CService.editComputersType(currentName, type.toStdString()),
    _CService.editComputersBuildYear(currentName, buildYear.toInt()),
    _CService.editComputersName(currentName, newName.toStdString()));

    if(success)
    {
        ui->inputCName->setText("");
        ui->inputCType->setText("");
        ui->inputCBuildYear->setText("");
        this->done(0);
    }

    return Computers;
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

//SET INFORMATION FOR EDIT FUNCTION
void ComputersDialog::setComputer(Computer computer)
{
    QString name = QString::fromStdString(computer.getName());
    tempEditName = name;
    QString type = QString::fromStdString(computer.getType());
    QString buildYear = QString::number(computer.getBuildYear());
    ui->inputCName->setText(name);
    ui->inputCType->setText(type);
    ui->inputCBuildYear->setText(buildYear);

}

bool ComputersDialog::checkIfSame(string name, string type, int bY)
{
    vector<Computer> Computers;
    Computers = _CService.getVectorFromDataAccess(Computers);
    for(size_t i = 0; i < Computers.size(); i++)
    {
        if( ( name == Computers.at(i).getName()     ) &
            ( type == Computers.at(i).getType()     ) &
            ( bY == Computers.at(i).getBuildYear()  ))
        {
            return true;
        }
    }
    return false;

}

//ENABLE/DISABLE ADD AND EDIT BUTTONS, DEPENDING ON WHICH FUNCTION IS IN USE AT THE MOMENT
void ComputersDialog::setEditComputer(bool value)
{
    if(value)
    {
        ui->pushButtonEditComputer->setEnabled(true);
        ui->pushButtonAddComputer->setEnabled(false);
    }
    else
    {
        ui->pushButtonEditComputer->setEnabled(false);
        ui->pushButtonAddComputer->setEnabled(true);
    }
}

//ENABLE/DISABLE ADD AND EDIT BUTTONS, DEPENDING ON WHICH FUNCTION IS IN USE AT THE MOMENT
void ComputersDialog::setAddComputer(bool value)
{
    if(value)
    {
        ui->pushButtonAddComputer->setEnabled(true);
        ui->pushButtonEditComputer->setEnabled(false);
    }
    else
    {
        ui->pushButtonAddComputer->setEnabled(false);
        ui->pushButtonEditComputer->setEnabled(true);
    }
}

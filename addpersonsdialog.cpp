#include "addpersonsdialog.h"
#include "ui_addpersonsdialog.h"

AddPersonsDialog::AddPersonsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPersonsDialog)
{
    ui->setupUi(this);

}

AddPersonsDialog::~AddPersonsDialog()
{
    delete ui;
}

void AddPersonsDialog::on_pushButtonAddPerson_clicked()
{
    vector<Person> Persons;
    Persons = _PService.getVectorFromDataAccess(Persons);

    QString name = ui->inputPName->text();
    //QString gender;
    /*
    if(ui->radioButton1->isChecked())
    {
        ui->inputPGender->text() = 'F';
    }
    else
    {
        ui->inputPGender->text() = 'M';
    }*/
    QString gender = ui->inputPGender->text();
    QString birthYear = ui->inputPBirthYear->text();
    QString deathYear = ui->inputPDeathYear->text();

    if(name.isEmpty())
    {
        //errormessage
        ui->labelErrorPersonName->setText("<span style='color: red'>Name cannot be empty</span>");
        return;
    }
    if(birthYear.isEmpty())
    {
        //errormessage
        return;
    }
    if(deathYear.isEmpty())
    {
        //errormessage
        return;
    }

    bool success = _PService.addPerson(name.toStdString(), gender.toDouble(), birthYear.toInt(), deathYear.toInt());

    if(success)
    {
        ui->inputPName->setText("");
        ui->inputPGender->setText("");
        ui->inputPBirthYear->setText("");
        ui->inputPDeathYear->setText("");
        //this->done(0);
    }
    else
    {
        //error message
        //this->done(-1);
    }
}

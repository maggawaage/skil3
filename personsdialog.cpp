#include "personsdialog.h"
#include "ui_personsdialog.h"
#include <iostream>

PersonsDialog::PersonsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonsDialog)
{
    ui->setupUi(this);

}

PersonsDialog::~PersonsDialog()
{
    delete ui;
}

void PersonsDialog::on_pushButtonAddPerson_clicked()
{
    vector<Person> Persons;
    Persons = _PService.getVectorFromDataAccess(Persons);
    QString name = ui->inputPName->text();
    QString gender;
    if(ui->radioButtonFemale->isChecked())
    {
        ui->radioButtonFemale->text() = 'F';
        gender = 'F';
    }
    else
    {
        ui->radioButtonMale->text() = 'M';
        gender = 'M';
    }

    QString birthYear = ui->inputPBirthYear->text();
    QString deathYear = ui->inputPDeathYear->text();
    ui->labelErrorPersonName->setText("");
    ui->labelErrorPersonBY->setText("");
    ui->labelErrorPersonDY->setText("");

    if(deathYear < birthYear)
    {
        //errormessage
        ui->labelErrorPersonDY->setText("<span style='color: red'>You cannot die before you are born</span>");
        return;
    }
    if(checkIfSame(name.toStdString(), convertQstringToChar(gender), birthYear.toInt(), deathYear.toInt()))
    {
        //errormessage
        ui->labelErrorPersonName->setText("<span style='color: red'>This person already exists</span>");
        return;
    }
    if(name.isEmpty())
    {
        //errormessage
        ui->labelErrorPersonName->setText("<span style='color: red'>Name cannot be empty</span>");
        return;
    }
    if(birthYear.isEmpty())
    {
        //errormessage
        ui->labelErrorPersonBY->setText("<span style='color: red'>Birth year cannot be empty</span>");
        return;
    }
    else if(!onlyNumbers(birthYear))
    {
        //errormessage
        ui->labelErrorPersonBY->setText("<span style='color: red'>You can only enter numbers</span>");
        return;
    }
    if(deathYear.isEmpty())
    {
        //errormessage
        ui->labelErrorPersonDY->setText("<span style='color: red'>Death year cannot be empty</span>");
        return;
    }
    else if(!onlyNumbers(deathYear))
    {
        //errormessage
        ui->labelErrorPersonDY->setText("<span style='color: red'>You can only enter numbers</span>");
        return;
    }

    bool success = _PService.addPerson(name.toStdString(), convertQstringToChar(gender), birthYear.toInt(), deathYear.toInt());

    if(success)
    {
        ui->inputPName->setText("");
        ui->inputPBirthYear->setText("");
        ui->inputPDeathYear->setText("");
        this->done(0);
    }
}

QString PersonsDialog::showGender(char input)
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

void PersonsDialog::setPerson(Person person)
{
    QString name = QString::fromStdString(person.getName());
    tempEditName = name;
    char ge = person.getGender();
    QString gender = showGender(ge);
    QString birthYear = QString::number(person.getBirthYear());
    QString deathYear = QString::number(person.getDeathYear());
    ui->inputPName->setText(name);
    ui->inputPBirthYear->setText(birthYear);
    ui->inputPDeathYear->setText(deathYear);
}

bool PersonsDialog::onlyNumbers(QString string)
{
    for(int i = 0; i < string.size(); i++)
    {
        if(!(string[i].isDigit()))
            return false;
    }
    return true;
}

vector<Person> PersonsDialog::on_pushButtonEditPerson_clicked()
{
    //Uppfæra upplýsingar sem notandi breytti
    vector<Person> Persons;
    Persons = _PService.getVectorFromDataAccess(Persons);

    QString newName = ui->inputPName->text();
    QString gender;
    if(ui->radioButtonFemale->isChecked())
    {
        ui->radioButtonFemale->text() = 'F';
        gender = 'F';
    }
    else
    {
        ui->radioButtonMale->text() = 'M';
        gender = 'M';
    }
    QString birthYear = ui->inputPBirthYear->text();
    QString deathYear = ui->inputPDeathYear->text();


    string currentName = tempEditName.toStdString();

    bool success =  (_PService.editPersonsName(currentName, newName.toStdString()),
    _PService.editPersonsGender(currentName, convertQstringToChar(gender)),
    _PService.editPersonsBirthYear(currentName, birthYear.toInt()),
    _PService.editPersonsDeathYear(currentName, deathYear.toInt()));

    if(success)
    {
        ui->inputPName->setText("");
        ui->inputPBirthYear->setText("");
        ui->inputPDeathYear->setText("");
        this->done(0);
    }

    return Persons;
}

char PersonsDialog::convertQstringToChar(QString str)
{
    //We did not find any easy way to convert a Qstring to char,
    //so we convert it first to std string, and then to char.
    string stdString = str.toStdString();
    char charStr = stdString[0];
    return charStr;
}

bool PersonsDialog::checkIfSame(string name, char gender, int bY, int dY)
{
    vector<Person> Persons;
    Persons = _PService.getVectorFromDataAccess(Persons);
    for(size_t i = 0; i < Persons.size(); i++)
    {
        if( ( name == Persons.at(i).getName()     ) &
            ( gender == Persons.at(i).getGender() ) &
            ( bY == Persons.at(i).getBirthYear()  ) &
            ( dY == Persons.at(i).getDeathYear()  )  )
        {
            return true;
        }
    }
    return false;
}

/*void PersonsDialog::on_pushButtonEditPerson_objectNameChanged(const QString &objectName)
{
    ui->pushButtonEditPerson->setEnabled(true);

}*/

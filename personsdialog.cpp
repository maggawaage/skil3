#include "personsdialog.h"
#include "ui_personsdialog.h"

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
        qDebug() << "hello";
    }
    else
    {
        ui->radioButtonMale->text() = 'M';
        gender = 'M';
        qDebug() << "world";
    }
    //QString gender = ui->inputPGender->text();
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
    qDebug() << gender;
    bool success = _PService.addPerson(name.toStdString(), gender.toDouble(), birthYear.toInt(), deathYear.toInt());

    if(success)
    {
        ui->inputPName->setText("");
        ui->inputPGender->setText("");
        ui->inputPBirthYear->setText("");
        ui->inputPDeathYear->setText("");

        this->done(0);
    }
    else
    {
        //error message
        //this->done(-1);
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
    char ge = person.getGender();
    QString gender = showGender(ge);
    QString birthYear = QString::number(person.getBirthYear());
    QString deathYear = QString::number(person.getDeathYear());
    //qDebug() << name;
    ui->inputPName->setText(name);
    ui->inputPGender->setText(gender);
    ui->inputPBirthYear->setText(birthYear);
    ui->inputPDeathYear->setText(deathYear);
    //færa if else hér til að tékka villur

}

bool PersonsDialog::onlyNumbers(QString string)
{
    for(int i = 0; i < string.size(); i++)
    {
        if(string[i].isDigit())
            return false;
    }
    return true;
}

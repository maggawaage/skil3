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
    //TODO:
    /*AddPersonsDialog addperson;
    int returnAddPersonValue = AddPersonsDialog.exec();
    */
}

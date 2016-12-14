#include "editpersonsdialog.h"
#include "ui_editpersonsdialog.h"

EditPersonsDialog::EditPersonsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditPersonsDialog)
{
    ui->setupUi(this);
}

EditPersonsDialog::~EditPersonsDialog()
{
    delete ui;
}

#include "editcomputersdialog.h"
#include "ui_editcomputersdialog.h"

EditComputersDialog::EditComputersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditComputersDialog)
{
    ui->setupUi(this);
}

EditComputersDialog::~EditComputersDialog()
{
    delete ui;
}

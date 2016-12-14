#ifndef ADDPERSONSDIALOG_H
#define ADDPERSONSDIALOG_H
#include "mainwindow.h"
#include "personservice.h"

#include <QDialog>

namespace Ui {
class AddPersonsDialog;
}

class AddPersonsDialog : public QDialog
{
    Q_OBJECT

public:
    QString showGender(char input);
    explicit AddPersonsDialog(QWidget *parent = 0);
    ~AddPersonsDialog();

private slots:
    void on_pushButtonAddPerson_clicked();

private:
    Ui::AddPersonsDialog *ui;
    PersonService _PService;
};

#endif // ADDPERSONSDIALOG_H

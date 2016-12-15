#ifndef PERSONSDIALOG_H
#define PERSONSDIALOG_H
#include "mainwindow.h"
#include "personservice.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <QChar>

#include <QDialog>

namespace Ui {
class PersonsDialog;
}

class PersonsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PersonsDialog(QWidget *parent = 0);
    ~PersonsDialog();
    bool onlyNumbers(QString string);

private slots:
    void on_pushButtonAddPerson_clicked();

    void on_pushButtonEditPerson_clicked();
    
private:
    Ui::PersonsDialog *ui;
    PersonService _PService;
};

#endif // PERSONSDIALOG_H

#ifndef PERSONSDIALOG_H
#define PERSONSDIALOG_H
#include "mainwindow.h"
#include "personservice.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <QChar>

#include <QDialog>
#include <QTableWidget>
#include <QLineEdit>
#include <QAbstractItemView>

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
    QString showGender(char input);
    void setPerson(Person person);
    bool checkIfSame(string name, char gender, int bY, int dY);

private slots:
    void on_pushButtonAddPerson_clicked();

    vector<Person>  on_pushButtonEditPerson_clicked();

    void on_pushButtonEditPerson_objectNameChanged(const QString &objectName);

private:
    Ui::PersonsDialog *ui;
    PersonService _PService;
    char convertQstringToChar(QString str);
};

#endif // PERSONSDIALOG_H

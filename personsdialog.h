#ifndef PERSONSDIALOG_H
#define PERSONSDIALOG_H
#include "mainwindow.h"
#include "personservice.h"

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
    QString showGender(char input);
    void setPerson(Person person);

private slots:
    void on_pushButtonAddPerson_clicked();
    
private:
    Ui::PersonsDialog *ui;
    PersonService _PService;
};

#endif // PERSONSDIALOG_H

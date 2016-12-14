#ifndef PERSONSDIALOG_H
#define PERSONSDIALOG_H
#include "mainwindow.h"
#include "personservice.h"

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

private slots:
    void on_pushButtonAddPerson_clicked();

    void on_pushButtonEditPerson_clicked();
    
private:
    Ui::PersonsDialog *ui;
    PersonService _PService;
};

#endif // PERSONSDIALOG_H

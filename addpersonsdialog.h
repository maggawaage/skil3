#ifndef ADDPERSONSDIALOG_H
#define ADDPERSONSDIALOG_H

#include <QDialog>

namespace Ui {
class AddPersonsDialog;
}

class AddPersonsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddPersonsDialog(QWidget *parent = 0);
    ~AddPersonsDialog();

private slots:
    void on_pushButtonAddPerson_clicked();

private:
    Ui::AddPersonsDialog *ui;
};

#endif // ADDPERSONSDIALOG_H
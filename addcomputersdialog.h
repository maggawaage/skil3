#ifndef ADDCOMPUTERSDIALOG_H
#define ADDCOMPUTERSDIALOG_H
#include "computerservice.h"

#include <QDialog>

namespace Ui {
class AddComputersDialog;
}

class AddComputersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputersDialog(QWidget *parent = 0);
    ~AddComputersDialog();

private slots:
    void on_pushButtonAddComputer_clicked();

private:
    Ui::AddComputersDialog *ui;
    ComputerService _CService;
};

#endif // ADDCOMPUTERSDIALOG_H

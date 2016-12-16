#ifndef COMPUTERSDIALOG_H
#define COMPUTERSDIALOG_H
#include "mainwindow.h"
#include "computerservice.h"

#include <QDialog>

namespace Ui {
class ComputersDialog;
}

class ComputersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ComputersDialog(QWidget *parent = 0);
    ~ComputersDialog();
    bool onlyNumbers(QString string);
    void setComputer(Computer computer);
    bool checkIfSame(string name, string type, int bY);

private slots:
    void on_pushButtonAddComputer_clicked();

    vector<Computer> on_pushButtonEditComputer_clicked();

private:
    Ui::ComputersDialog *ui;
    ComputerService _CService;
    QString tempEditName;
};

#endif // COMPUTERSDIALOG_H

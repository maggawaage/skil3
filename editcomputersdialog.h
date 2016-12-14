#ifndef EDITCOMPUTERSDIALOG_H
#define EDITCOMPUTERSDIALOG_H

#include <QDialog>

namespace Ui {
class EditComputersDialog;
}

class EditComputersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditComputersDialog(QWidget *parent = 0);
    ~EditComputersDialog();

private:
    Ui::EditComputersDialog *ui;
};

#endif // EDITCOMPUTERSDIALOG_H

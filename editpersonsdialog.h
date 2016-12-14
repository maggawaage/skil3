#ifndef EDITPERSONSDIALOG_H
#define EDITPERSONSDIALOG_H

#include <QDialog>

namespace Ui {
class EditPersonsDialog;
}

class EditPersonsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditPersonsDialog(QWidget *parent = 0);
    ~EditPersonsDialog();

private:
    Ui::EditPersonsDialog *ui;
};

#endif // EDITPERSONSDIALOG_H

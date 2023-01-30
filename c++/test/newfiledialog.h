#ifndef NEWFILEDIALOG_H
#define NEWFILEDIALOG_H

#include <QDialog>

namespace Ui {
class NewFileDialog;
}

class NewFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewFileDialog(QWidget *parent = nullptr);
    ~NewFileDialog();
    QString gettext;
    QString sendtext();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewFileDialog *ui;
};

#endif // NEWFILEDIALOG_H

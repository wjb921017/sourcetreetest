#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QDialog>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    QDialog *dialog;
    QPushButton *qpushbutton;
};
#endif // LOGIN_H

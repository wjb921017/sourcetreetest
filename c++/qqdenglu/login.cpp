#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    dialog = new QDialog(this);
    qpushbutton = new QPushButton(this);
    qpushbutton->setGeometry(10,10,10,10);
    qpushbutton->setText("ffff");
    ui->setupUi(this);
    //this->setLayout(ui->verticalLayout_4);
    qpushbutton->setGeometry(0,0,100,10);
    qpushbutton->setText("ffff");
}

Login::~Login()
{
    delete ui,dialog,qpushbutton;
}

void Login::on_pushButton_clicked()
{
    dialog->show();
}



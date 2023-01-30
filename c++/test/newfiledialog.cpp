#include "newfiledialog.h"
#include "ui_newfiledialog.h"

NewFileDialog::NewFileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewFileDialog)
{
    ui->setupUi(this);
}

NewFileDialog::~NewFileDialog()
{
    delete ui;
}

QString NewFileDialog::sendtext()
{
    return ui->textEdit->toPlainText();
}

void NewFileDialog::on_pushButton_clicked()
{

    this->close();
}

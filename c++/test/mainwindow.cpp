#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "student.h"
#include "school.h"
#include <QFileDialog>
#include<newfiledialog.h>
#include<QFile>
#include<QDateTime>
#include <QPainter>
#include <QFontMetrics>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , offset(0)
    ,text("北方的狼生日快乐！！！！")
{
    ui->setupUi(this);

    QFontMetrics fontmetrics(font);
    textwidth = fontmetrics.width(text);
    qDebug()<<textwidth;


    timer = new QTimer(this);
    timer->start(50);
    connect(timer,SIGNAL(timeout()),this,SLOT(on_time()));
    font.setPixelSize(50);
    std::shared_ptr<student> xiaoming;
    std::shared_ptr<school> cumt;
    pushbutton1 = new QPushButton(this);
    pushbutton1->setGeometry(200,200,100,50);
    pushbutton1->setText("ffff");
    dialog = new QDialog(this);
    dialog->setGeometry(500,500,800,600);
    da = new QPushButton(dialog);
    da->setGeometry(0,0,100,100);
    da->setText("ggg");
    student xiaohong;
    school hcg;
    student* xiaowang=new student(this);
    school* gaoji = new school(this);
    pushbutoon1_clicked();

    QObject::connect(pushbutton1,SIGNAL(clicked()),this,SLOT(opendia()));
    //QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(&hcg,SIGNAL(schoolnote()),&xiaohong,SLOT(studentdo()));
    QObject::connect(da,SIGNAL(clicked()),dialog,SLOT(close()));

    emit hcg.schoolnote();
    delete xiaowang;
    delete gaoji;



}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;

}
void MainWindow::opendia()
{
    dialog->show();
}

void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"kuaishiyongshuangjiegung\n";
    //this->close();
    QFile file;
    file.setFileName(QDateTime::currentDateTime().toString("yyyyMMddhhmmssz")+".txt");
    file.open(QIODevice::ReadWrite);


    NewFileDialog *filedialog = new NewFileDialog(this);
    filedialog->resize(400,400);
    filedialog->show();

    filedialog->setModal(true);
    filedialog->exec();
    file.write(filedialog->sendtext().toUtf8());
    file.close();
    delete filedialog;




}

void MainWindow::on_time()
{
    if(offset <this->width()+textwidth)
        offset += 2;
    else
        offset = 0;
    this->update();
    //qDebug()<<"ffff";
    //qDebug()<<offset;


}
void MainWindow::pushbutoon1_clicked()
{


}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    //QRectF rect(0,0,200,100);
    QPen pen;
    pen.setColor(QColor(Qt::red));
    painter.setPen(pen);
    painter.setFont(font);
    QRect rectf = this->rect();

    rectf.setLeft(this->rect().width()-offset);
    painter.drawText(rectf,Qt::AlignVCenter,text);
}



void MainWindow::on_pushButton_2_clicked()
{

}

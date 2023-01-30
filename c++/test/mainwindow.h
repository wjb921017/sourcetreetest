#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma execution_character_set("utf-8")

#include <QMainWindow>
#include <QPushButton>
#include <QDialog>
#include <QFile>
#include <QPainter>
#include <QWidget>
#include<QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
//class student;
//class school;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //构造函数，
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void pushbutoon1_clicked();
    QPushButton *pushbutton1;
    QDialog *dialog;
    QPushButton *da;
    void paintEvent(QPaintEvent *event) override;
    QFont font;
    int offset;
    QTimer *timer;
    QString text;
    int textwidth;
public slots:
    void opendia();
private slots:
    void on_pushButton_clicked();
    void on_time();



    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QFile file;

//    student* xiaowang;
//    school* gaoji;
};
#endif // MAINWINDOW_H

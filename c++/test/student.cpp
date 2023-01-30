#include "student.h"
#include "QDebug"
student::student(QObject *parent) : QObject(parent)
{

}
void student::studentdo()
{
    qDebug()<<"yeshi";
}

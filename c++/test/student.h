#ifndef STUDENT_H
#define STUDENT_H
#include "QObject"


class student : public QObject
{
    Q_OBJECT
public:
    explicit student(QObject *parent = nullptr);
signals:
public slots:
    void studentdo();

};

#endif // STUDENT_H

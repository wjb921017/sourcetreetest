#ifndef SCHOOL_H
#define SCHOOL_H
#include "QObject"

class school : public QObject
{
    Q_OBJECT
public:
    explicit school(QObject *parent = nullptr);

signals:
    void schoolnote();

};

#endif // SCHOOL_H

#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QString>
#include <QMutex>

class MyThread : public QThread
{
public:
    // constructor
    // set name and Stop is set as false by default
    MyThread(QString s, bool b = false);

    // overriding the QThread's run() method
    void run();

    // variable that mutex protects
    bool Stop;
private:
    QString name;
};

#endif // MYTHREAD_H

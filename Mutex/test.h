#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <QThread>
#include <QMutex>

class Thread : public QThread {
  Q_OBJECT

public:
  Thread(const QString &mes);
  void setMessage1(const QString &message);
  void setMessage2(const QString &message);
  void printMessage(const QString &t);
  void stop();

protected:
  void run();

private:
  QString message_str;
  QMutex mutex;
};



class ThreadDialog : public QDialog {
  Q_OBJECT

public:
  ThreadDialog(QWidget *parent = 0);

};

#endif // TEST_H

#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <semaphore.h>
#include <unistd.h>
#include <QFile>
#include <QTextStream>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class Ventana; }
QT_END_NAMESPACE

class Ventana : public QWidget
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ventana *ui;
};
#endif // VENTANA_H

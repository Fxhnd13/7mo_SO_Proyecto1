#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <tallo.h>>
#include <proceso.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_realizarBtn_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    Tallo crearEstructura(int,int);

private:
    Ui::Widget *ui;
    int cantidadTallos;
    QVector <Tallo> tallos;
};
#endif // WIDGET_H

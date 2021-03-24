#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
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

private:
    Ui::Widget *ui;
    int cantidadTallos;
    QVector <Proceso> tallos;
};
#endif // WIDGET_H

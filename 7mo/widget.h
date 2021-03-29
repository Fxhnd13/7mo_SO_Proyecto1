#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <tallo.h>
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
    Tallo crearEstructura(int,int);
    void pintarTallo(Tallo);
    void pintarNegro(QLabel*);
    void pintarCafe(QLabel*);
    void pintarVerde(QLabel*);
    void pintarTrans(QLabel*);
    void cargarLabels();
    void imprimirTallo(Tallo);
    void escribir(QString);
    void limpiarSalida();

private:
    Ui::Widget *ui;
    int cantidadTallos;
    QVector <Tallo> tallos;
    QVector <QLabel*> labelsRama;
    QVector <QLabel*> labelsHoja;
};
#endif // WIDGET_H

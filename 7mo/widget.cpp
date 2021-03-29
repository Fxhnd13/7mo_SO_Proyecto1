#include "widget.h"
#include "ui_widget.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/prctl.h>
#include <QTextStream>
#include <QFile>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->cantidadTallos = 0;
    this->tallos = QVector<Tallo>();
    this->cargarLabels();
    this->limpiarSalida();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_realizarBtn_clicked()
{
    QString texto = ui->inputText->text();
    ui->historial->setText(ui->historial->toPlainText()+"\n"+texto);
    texto.remove('('); texto.remove(')');
    ui->inputText->setText("");
    QStringList parametros = texto.split(",");
    if(parametros.at(0) == "P" || parametros.at(0) == "p"){
        int idTallo = parametros.at(1).toInt();
        int ramas = (parametros.size()>2)? parametros.at(2).toInt() : 0;
        int hojas = (parametros.size()>3)? parametros.at(3).toInt() : 0;
        if(idTallo > this->cantidadTallos){
            //agregamos a las estructuras para pintar
            Tallo tallo(idTallo, ramas, hojas);
            tallos.append(tallo);
            this->cantidadTallos++;

            //creamos los procesos
            Proceso procesoTallo;
            //creamos
            int p = fork();
            if(p < 0 ){
                //error
            }else if(p == 0){
                for(int i = 0; i < ramas; i++){
                    Proceso rama;
                    int p2 = fork();
                    if(p2 < 0 ){
                        //error
                    }else if(p2 == 0){
                        for(int j = 0; j < hojas; j++){
                            Proceso hoja;
                            int p3 = fork();
                            if(p3 < 0){
                                //error
                            }else if(p3 == 0){
                                hoja.iniciarEspera();
                                break;
                            }
                        }
                        rama.iniciarEspera();
                        break;
                    }
                }
                procesoTallo.iniciarEspera();
            }
        }else{
            //¿modificamos?
        }
    }else if(parametros.at(0) == "m" || parametros.at(0) == "M"){
        if(parametros.at(1).toInt() <= cantidadTallos){
            pintarTallo(tallos.at(parametros.at(1).toInt()-1));
        }
    }else if(parametros.at(0) == "I" || parametros.at(0) == "i"){
        imprimirTallo(tallos.at(parametros.at(1).toInt()-1));
    }
}

Tallo Widget::crearEstructura(int ramas, int hojas){
    Tallo tallo = Tallo(ramas, hojas, QVector<Pipe>());
    int tuberiaAlTallo[2];
    pipe(tuberiaAlTallo);
    Pipe comunicacionAlTallo = Pipe(tuberiaAlTallo);
    tallo.getPipes().append(comunicacionAlTallo);
    for(int i = 0; i < 5; i++){
        int tuberia[2];
        pipe(tuberia);
        Pipe comunicacion = Pipe(tuberia);
        tallo.getPipes().append(comunicacion);
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 10; j++){
            int tuberia[2];
            pipe(tuberia);
            Pipe comunicacion = Pipe(tuberia);
            tallo.getPipes().append(comunicacion);
        }
    }
    return tallo;
}

void Widget::pintarTallo(Tallo tallo){
    pintarCafe(ui->lblTallo);
    for(int i = 0; i < 5; i++) pintarTrans(this->labelsRama.at(i));
    for(int i = 0; i < 50; i++) pintarTrans(this->labelsHoja.at(i));
    for(int i = 0; i < tallo.getRamas(); i++) pintarCafe(this->labelsRama.at(i));
    for(int i = 0; i < tallo.getRamas(); i++){
        for(int j = 0; j < tallo.getHojas(); j++) pintarVerde(this->labelsHoja.at((i*10)+j));
    }
}

void Widget::imprimirTallo(Tallo tallo){
    escribir("Un total de "+QString::number(tallo.getRamas()*tallo.getHojas()+tallo.getRamas()+1)+" procesos");
    escribir("Tallo");
    for(int i = 0; i < tallo.getRamas(); i++){
        escribir("  |----Rama");
        for(int j = 0; j < tallo.getHojas(); j++){
            escribir("         |-----Hoja");
        }
    }
    escribir("--------------------------------------");
}

void Widget::escribir(QString text){
    QFile file("out.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text))
        return;

    QTextStream salida(&file);
    salida << text << "\n";
}

void Widget::limpiarSalida(){
    QFile file("out.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream salida(&file);
    salida << "";
}

void Widget::pintarCafe(QLabel * label){
    QString color = "QLabel { background-color : brown; color : brown; }";
    label->setStyleSheet(color);
    label->update();
}

void Widget::pintarNegro(QLabel * label){
    QString color = "QLabel { background-color : black; color : black; }";
    label->setStyleSheet(color);
    label->update();
}

void Widget::pintarVerde(QLabel * label){
    QString color = "QLabel { background-color : green; color : green; }";
    label->setStyleSheet(color);
    label->update();
}

void Widget::pintarTrans(QLabel * label){
    QString color = "QLabel { color : black; }";
    label->setStyleSheet(color);
    label->update();
}

void Widget::cargarLabels(){
    this->labelsRama.append(ui->lblRama1);
    this->labelsRama.append(ui->lblRama2);
    this->labelsRama.append(ui->lblRama3);
    this->labelsRama.append(ui->lblRama4);
    this->labelsRama.append(ui->lblRama5);
    this->labelsHoja.append(ui->lbl1);
    this->labelsHoja.append(ui->lbl2);
    this->labelsHoja.append(ui->lbl3);
    this->labelsHoja.append(ui->lbl4);
    this->labelsHoja.append(ui->lbl5);
    this->labelsHoja.append(ui->lbl6);
    this->labelsHoja.append(ui->lbl7);
    this->labelsHoja.append(ui->lbl8);
    this->labelsHoja.append(ui->lbl9);
    this->labelsHoja.append(ui->lbl10);
    this->labelsHoja.append(ui->lbl11);
    this->labelsHoja.append(ui->lbl12);
    this->labelsHoja.append(ui->lbl13);
    this->labelsHoja.append(ui->lbl14);
    this->labelsHoja.append(ui->lbl15);
    this->labelsHoja.append(ui->lbl16);
    this->labelsHoja.append(ui->lbl17);
    this->labelsHoja.append(ui->lbl18);
    this->labelsHoja.append(ui->lbl19);
    this->labelsHoja.append(ui->lbl20);
    this->labelsHoja.append(ui->lbl21);
    this->labelsHoja.append(ui->lbl22);
    this->labelsHoja.append(ui->lbl23);
    this->labelsHoja.append(ui->lbl24);
    this->labelsHoja.append(ui->lbl25);
    this->labelsHoja.append(ui->lbl26);
    this->labelsHoja.append(ui->lbl27);
    this->labelsHoja.append(ui->lbl28);
    this->labelsHoja.append(ui->lbl29);
    this->labelsHoja.append(ui->lbl30);
    this->labelsHoja.append(ui->lbl31);
    this->labelsHoja.append(ui->lbl32);
    this->labelsHoja.append(ui->lbl33);
    this->labelsHoja.append(ui->lbl34);
    this->labelsHoja.append(ui->lbl35);
    this->labelsHoja.append(ui->lbl36);
    this->labelsHoja.append(ui->lbl37);
    this->labelsHoja.append(ui->lbl38);
    this->labelsHoja.append(ui->lbl39);
    this->labelsHoja.append(ui->lbl40);
    this->labelsHoja.append(ui->lbl41);
    this->labelsHoja.append(ui->lbl42);
    this->labelsHoja.append(ui->lbl43);
    this->labelsHoja.append(ui->lbl44);
    this->labelsHoja.append(ui->lbl45);
    this->labelsHoja.append(ui->lbl46);
    this->labelsHoja.append(ui->lbl47);
    this->labelsHoja.append(ui->lbl48);
    this->labelsHoja.append(ui->lbl49);
    this->labelsHoja.append(ui->lbl50);
}

#include "widget.h"
#include "ui_widget.h"
#include <stdio.h>
#include <unistd.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->cantidadTallos = 0;
    this->tallos = QVector<Proceso>();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_realizarBtn_clicked()
{
    QString texto = ui->inputText->text();
    texto.remove('('); texto.remove(')');
    if(texto.split(',').at(0) == "P" || texto.split(',').at(0) == "p"){
        QString cadenaEnviar;
        Proceso proceso;
        int tallo = texto.split(',').at(1).toInt();
        if(tallo == (this->cantidadTallos+1)){
            //creamos la tuberia de comunicacion entre este proceso y su hijo (el tallo) que acabamos de crear
            int comunicacion[2];
            pipe(comunicacion);
            proceso = Proceso(0,comunicacion,0);
            int pid_p = fork();
            if(pid_p < 0){
                //error
            }else if(pid_p == 0){
                //si es el hijo
                proceso.iniciarEspera();
            }
            //agregamos el tallo a nuestros tallos existentes y aumentamos la cantidad de tallos que tenemos
            this->tallos.append(proceso);
            this->cantidadTallos++;
        } else{
            proceso = this->tallos.at((tallo-1));
        }
        //Si tiene más de dos parametros
        if(texto.split(',').size() > 2){//Significa que hay que modificar las ramas que posee el tallo seleccionado o creado
            cadenaEnviar = texto.split(',').at(2);
            if(texto.split(',').size() > 3){
                cadenaEnviar.append(",");
                cadenaEnviar.append(texto.split(',').at(3));
            }else{
                cadenaEnviar.append(",00");
            }
        }else{
            cadenaEnviar = "00";
        }
        //ya con el proceso creado o bien identificado, vamos a enviar el mensaje a ese proceso
        QByteArray ba = cadenaEnviar.toLocal8Bit();
        const char *cadena = ba.data();
        write(proceso.getComunicacionEnviar(), cadena, 5);
    }else{
        //¿mostrar algo? creo
    }
    /* int p1,p2,p3;
    QStringList parametros = texto.split(',');
    operacion = parametros[0].at(0);
    p1 = parametros[1].toInt();
    if(parametros.size() > 2){
        p2 = parametros[2].toInt();
        if(parametros.size() > 3) p3 = parametros[3].toInt();
    }
    printf("Parametro 1: %c | Parametro 2: %d | Parametro 3: %d, Parametro 4: %d",operacion.toLatin1(),p1,p2,p3);
    */
}

//boton agregar tallo
void Widget::on_pushButton_clicked(){
    int indiceTallo = ui->inputText->text().split(',').at(0).toInt();
    int cantidadRamas = ui->inputText->text().split(',').at(1).toInt();
    int cantidadHojas = ui->inputText->text().split(',').at(2).toInt();
    int comunicacion[2];
    pipe(comunicacion);
    Proceso tallo = Proceso(0,comunicacion,0);
    int p = fork();
    if(p < 0 ){
        //error
    }else if(p == 0){
        for(int i = 0; i < cantidadRamas; i++){
            int comunicacionRama[2];
            pipe(comunicacionRama);
            Proceso rama = Proceso(1,comunicacionRama,0);
            int p2 = fork();
            if(p2 < 0 ){
                //error
            }else if(p2 == 0){
                for(int j = 0; j < cantidadHojas; j++){
                    int comunicacionHoja[2];
                    pipe(comunicacionHoja);
                    Proceso hoja = Proceso(2,comunicacionHoja,0);
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
        tallo.iniciarEspera();
    }
    this->tallos.append(tallo);
    this->cantidadTallos++;
}

//boton agregar rama
void Widget::on_pushButton_3_clicked(){
    int indiceTallo = ui->inputText->text().toInt();

}

//boton agregar hoja
void Widget::on_pushButton_5_clicked(){

}

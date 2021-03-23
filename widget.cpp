#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_realizarBtn_clicked()
{
    QChar operacion;
    QString texto = ui->inputText->text();
    texto.remove('('); texto.remove(')');
    if(operacion == 'P'){
        int tallo = texto.split(',').at(1).toInt();
        if(tallo == (this->cantidadTallos+1)){
            //creamos la tuberia de comunicacion entre este proceso y su hijo (el tallo) que acabamos de crear
            int comunicacion[2];
            pipe(comunicacion);
            Proceso proceso = Proceso(0,comunicacion,0);
            //agregamos el talloa nuestros tallos existentes y aumentamos la cantidad de tallos que tenemos
            this->tallos.append(proceso);
            this->cantidadTallos++;
        }
        int cantidadRamas;
        if((tallo <= this->cantidadTallos) && ((cantidadRamas = texto.split(',').size()) > 2)){
            this->tallos.at((tallo-1));
            for(int i = 0; i < cantidadRamas; i++){
                int pid_p = fork();
                if(pid_p < 0){
                    printf("Error alv");
                }else{
                    //enviamos mediante el pipe correspondiente (del tallo que estamos) nRama,noHojas, ej "04,03"
                }
            }
        }
    }else{
        //¿mostrar algo? creo
    }
    /* QStringList parametros = texto.split(',');
    operacion = parametros[0].at(0);
    p1 = parametros[1].toInt();
    if(parametros.size() > 2){
        p2 = parametros[2].toInt();
        if(parametros.size() > 3) p3 = parametros[3].toInt();
    } */
    //printf("Parametro 1: %c | Parametro 2: %d | Parametro 3: %d, Parametro 4: %d",operacion.toLatin1(),p1,p2,p3);

}

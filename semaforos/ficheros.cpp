using namespace std;
#include <iostream>
#include <fstream> //guardar fichero


int main()
{
    int cedula,opcion,Bcedula,edad,telefono,Ntelefono,Nedad;
    char nombre[10],apellido[10];
    ofstream Guardar;
    ifstream Leer;
    fstream Temp; //referencia aun archivo temporal
    Guardar.open("Fichero.txt",ios::app);
    while(true)
    {
        cout<<"%%%%%%%%%%%%%%%%%"<<endl;
        cout<<"1 GUARDAR"<<endl;
        cout<<"2 LEER"<<endl;
        cout<<"3 BUSCAR"<<endl;
        cout<<"4 MODIFICAR"<<endl;
        cout<<"5 ELIMINAR"<<endl;
        cout<<"6 SALIR"<<endl;
        cout<<"%%%%%%%%%%%%%%%%%"<<endl;
        cout<<endl;
        cout<<"Elija una opcion:"<<endl;
        cin>>opcion;

        switch(opcion)
        {
            case 1:
                {
                    system("cls");
                    cout<<"Ingrese Nombre: ";
                    cin>>nombre;
                    cout<<"Ingrese Apellido: ";
                    cin>>apellido;
                    cout<<"Ingrese la Edad en años: ";
                    cin>>edad;
                    cout<<"Ingrese Numero de Telefono: ";
                    cin>>telefono;
                    cout<<"Ingrese su numero de cedula: ";
                    cin>>cedula;
                    Guardar<<nombre<<" "<<apellido<<" "<<edad<<" "<<telefono<<" "<<cedula<<endl;
                    break;
                }
            case 2:
                {
                    system("cls");  
                    Leer.open("Fichero.txt");
                    Leer>>nombre>>apellido>>edad>>telefono;
                    while(!Leer.eof())
                    {
                        Leer>>cedula;
                        cout<<"----------------------------"<<endl;
                        cout<<"Nombre:    "<<nombre<<endl;
                        cout<<"Apellido:  "<<apellido<<endl;
                        cout<<"Edad:      "<<edad<<" anios"<<endl;
                        cout<<"Telefono:  "<<telefono<<endl;
                        cout<<"Cedula:    "<<cedula<<endl;
                        cout<<"----------------------------"<<endl;
                        cout<<endl;
                        Leer>>nombre>>apellido>>edad>>telefono;
                    }
                    Leer.close();
                    break;
                }
            case 3:
                {
                    system("cls");  
                    Leer.open("Fichero.txt");
                    Leer>>nombre>>apellido>>edad>>telefono;
                    bool encontrado=false;
                    cout<<"Ingrese su numero de cedula para buscar"<<endl;
                    cin>>Bcedula;
                    while(!Leer.eof())
                    {
                        Leer>>cedula;
                        if(cedula==Bcedula)
                        {
                            encontrado=true;
                            cout<<"----------------------------"<<endl;
                            cout<<"Nombre:    "<<nombre<<endl;
                            cout<<"Apellido:  "<<apellido<<endl;
                            cout<<"Edad:      "<<edad<<" anio"<<endl;
                            cout<<"Telefono:  "<<telefono<<endl;
                            cout<<"Cedula:    "<<cedula<<endl;
                            cout<<"----------------------------"<<endl;
                            cout<<endl;
                        }
                        Leer>>nombre>>apellido>>edad>>telefono;
                    }
                    if(encontrado==false)
                    {
                        cout<<"Cedula no encontrada"<<endl;
                    }
                    Leer.close();
                    break;
                }

            case 4:
                {
                    system("cls");  
                    Leer.open("Fichero.txt");//abre fichero original
                    Temp.open("Temp.txt");//abrimos el temporal tambn
                    Leer>>nombre>>apellido>>edad>>telefono;
                    bool encontrado=false;
                    cout<<"Ingrese clave a modificar"<<endl;
                    cin>>Bcedula;
                    while(!Leer.eof())
                    {
                        Leer>>cedula;
                        if(cedula==Bcedula)
                        {
                            encontrado=true;
                            cout<<"Nombre:    "<<nombre<<endl;
                            cout<<"Apellido:  "<<apellido<<endl;
                            cout<<"Edad :     "<<edad<<" anios"<<endl;
                            cout<<"Telefono:  "<<telefono<<endl;
                            cout<<"Cedula:    "<<cedula<<endl;
                            cout<<endl;
                            cout<<"Ingrese su Edad a modificar"<<endl;
                            cin>>Nedad;
                            cout<<"Ingrese nuevo numero de telefono"<<endl;
                            cin>>Ntelefono;
                            Temp<<nombre<<" "<<apellido<<" "<<Nedad<<" "<<Ntelefono<<" "<<cedula<<endl;
                            cout<<endl;
                            cout<<"Modificado"<<endl;
                        }
                        else
                        {
                            Temp<<nombre<<" "<<apellido<<" "<<edad<<" "<<telefono<<" "<<cedula<<endl;
                        }
                        Leer>>nombre>>apellido>>edad>>telefono;
                    }
                    if(encontrado==false)
                    {
                        cout<<"Cedula no encontrada"<<endl;
                    }
                    Leer.close();
                    Temp.close();
                    remove("Fichero.txt");
                    rename("Temp.txt","Fichero.txt");
                    break;
                }

            case 5:
                {
                    system("cls");
                    Leer.open("Fichero.txt");
                    Temp.open("Temp.txt");
                    Leer>>nombre>>apellido>>edad>>telefono;
                    bool encontrado=false;
                    cout<<"Ingrese clave a eliminar"<<endl;
                    cin>>Bcedula;
                    while(!Leer.eof())
                    {
                        Leer>>cedula;
                        if(cedula==Bcedula)
                        {
                            encontrado=true;
                            cout<<"Nombre:    "<<nombre<<endl;
                            cout<<"Apellido:  "<<apellido<<endl;
                            cout<<"Edad:      "<<edad<<endl;
                            cout<<"Telefono:  "<<telefono<<endl;
                            cout<<"Cedula:    "<<cedula<<endl;
                            cout<<endl;
                            cout<<"Eliminado"<<endl;
                        }
                        else
                        {
                            Temp<<nombre<<" "<<apellido<<" "<<edad<<" "<<telefono<<" "<<cedula<<endl;
                        }
                        Leer>>nombre>>apellido>>edad>>telefono;
                    }
                    if(encontrado==false)
                    {
                        cout<<"Clave no encontrada"<<endl;
                    }
                    Leer.close();
                    Temp.close();
                    remove("Fichero.txt");
                    rename("Temp.txt","Fichero.txt");

                    break;
                }

            case 6:
                {
                    system("cls");

                    break;
                }   
        }   
    }
    return 0;
}
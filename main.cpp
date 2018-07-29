/* ***************************************************************
//	Programador: Gabriel Fontanez
//	# Estudiante: 842-15-3288
//  Profesor: Elio Ramos Colon
//  Curso: COMP 4097-001
// ************************************************************** */
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Flower // Esto es una clase para organizar todos los datos de la flor sea escritos por
             // el usuario o pre-programados.
{
    public:  // Los getName,getNumber y getPrice son para poder buscar los valores del string, int y float
             // que se implementan en el programa al igual se utilizan otravez al usuario usar su input al ser indicado
             // Mientras setName, setNumber y setPrice guardan el valor que es pre indicado antes de empesar el programa
             // y cuando el usuario indique su input.
             // El constuctor Flower(); es donde los valores predeterminados estan puestos.
        Flower();
        string getName();
        int getNumber();
        float getPrice();
        void setName(string myName);
        void setNumber(int myNumber);
        void setPrice(float myPrice);

    private: //Aqui estan las variables que se usaran para este programa
             //Un string que aguanta el nombre de la planta, un int para el numero de plantas
             //y un float para el precio de las flores.
        string name;
        int number;
        float price;
};
int main()
{   //---------------//
    //Variables que validan si el usuario desea utilizar el programa otravez.
    bool loop = true;
    char opcion;
    //--------------//
    //Deja que el programa utilize la clase de Flower.
    Flower ct;
    //--------------//
    //Variables que aguantan el nuevo input puesto por el usuario de nombre de la flor
    //numero de flores y el precio.
    string newName;
    int newNumber;
    float newPrice;

    //-------------------------------------------------------------------------------------------------------
    //Mensaje de bienvenida explicando al usuario que hace el programa
    cout << "\t\t\t\t -Bienvenidos-" << endl;
    cout << "Este programa demuestra al usuario una flor la cual tiene su propio precio\ny cantidad de flores." << endl;
    cout << "Luego le preguntara al usuario a poner un nuevo nombre para la flor,\ncantidad de flores y su precio." << endl;
    cout << "\nOprime ENTER para comenzar." << endl;
    cin.get();//Pausa el programa

    while(loop)
    {
        cout << "*---------------------------------------------------------------------------*\n";
        cout << "La flor que se demuestra en este programa es " << ct.getName() << endl;
        cout << "Tenemos " << ct.getNumber() << " y cuestan $" << ct.getPrice() << "." << endl;
        cout << "*---------------------------------------------------------------------------*\n" << endl;
        //------------------------------------------------------------------------------------------------------
        //Input del Usuario
        cout << "Ahora usted puede insertar el nombre de la planta,\nsu cantidad, y el precio de la flor.\n" << endl;
        //While loop valida si el usuario desea intentar de poner los datos otraves desde el principio.
        bool choice = true;
        cout << "Para comenzar entre el nombre de la flor: ";
        getline(cin,newName);
        cout << "Entre el la cantidad de flores que tienes: ";
        //Validacion en caso de que usuario ponga una letra sin querer
        while(!(cin >> newNumber))
        {
            cout << "Tiene que ser un numero intente denuevo\n" << endl;
            cout << "Entre el la cantidad de flores que tienes: ";
            cin.clear();
            cin.ignore(100,'\n');
        }
        cout << "Entre el precio que se ofrece la flor: ";
        //Validacion en caso de que usuario ponga una letra sin querer
        while(!(cin >> newPrice))
        {
            cout << "Tiene que ser un numero intente denuevo\n" << endl;
            cout << "Entre el precio que se ofrece la flor: ";
            cin.clear();
            cin.ignore(100,'\n');
        }
        //------------------------------------------------------------------------------------------------------
        //Llamada de las distintas funciones para guardar los datos puesto por el cliente
        ct.setName(newName);
        ct.setNumber(newNumber);
        ct.setPrice(newPrice);
        //-------------------------------------------------------------------------------------------------------
        //Resultados finales
        cout << "----------------------------------------------" << endl;
        cout << "\nLos datos que usted ingreso son los siguientes..." << endl;
        cout << "\nNombre: " << ct.getName();
        cout << "\nNumero de Flores: " << ct.getNumber();
        cout << "\nPrecio: $" << fixed << setprecision(2) << ct.getPrice();
        //Verificacion si deceas usar el programa otravez
        while(choice)
        {
            cout << "\nDeseas intentar denuevo?([Y]es/[N]o)" << endl;
            cin >> opcion;
            //Programa comiensa empesando desde donde el usuario inicial mente pone su input
                if (opcion == 'y' || opcion == 'Y')
                {
                    loop = true;
                    choice = false;
                }
            //El programa sale de su loop para poder terminar
                else if (opcion == 'n' || opcion == 'N')
                {
                    loop = false;
                    choice = false;
                }
            //Caso de que el usuario entre un Character que es invalido
                else
                {
                    cout << "Por favor entre una opcion valida entre Y para si o N para no." << endl;
                }
            cin.clear();
            cin.ignore(100,'\n');
        }
    }
    return 0;
}

Flower::Flower()  //Constructor que aguanta la informacion pre llenada para la bienvenida
{
    name = "Orquidea";
    number = 5;
    price = 8.99;
}
//setName,setPrice y setNumber ajustan las variables de name number y price cuando el usuario los cambie
void Flower::setName(string ct)
{
    name = ct;
}
void Flower::setNumber(int Num)
{
    number = Num;
}
void Flower::setPrice(float Mon)
{
    price = Mon;
}
//getName ,getNumber y getPrice buscan la informacion dentro de cada variable en la clase en su parte privada.
string Flower::getName()
{
    return name;
}
int Flower::getNumber()
{
    return number;
}
float Flower::getPrice()
{
    return price;
}

#include <iostream>
using namespace std;

class Herramienta 
{
    // ENCAPCULAMIENTO PRIVADO
private:
    // ATRIBUTOS
    string nombre;
    string codigo;
    string marca;
    float precio;

    // ENCAPCULAMIENTO PUBLICO
public:
	// METODOS
    Herramienta(string = "", string = "", string = "", float = 0.0); 
    Herramienta(Herramienta&); 
    ~Herramienta(); 

    void leerDatos();
    void ImprimirDatos();

    void setNombre(string);
    void setCodigo(string);
    void setMarca(string);
    void setPrecio(float);

    float getPrecio();
    string getNombre();
};
//////////////////////////////////////////////// CONSTRUCTORES Y DESTRUCTOR //////////////////////////////////////////////////////////////
// CONSTRUCTOR GENERAL
Herramienta::Herramienta(string N, string C, string M, float P) 
{
    nombre = N;
    codigo = C;
    marca = M;
    precio = P;
}

// CONSTRUCTOR COPIA
Herramienta::Herramienta(Herramienta& h)
 {
    nombre = h.nombre;
    codigo = h.codigo;
    marca = h.marca;
    precio = h.precio;
}

// DESTRUCTOR
Herramienta::~Herramienta() 
{
    cout << "\tSoy El DESTRUCTOR" << endl;
}
////////////////////////////////////////  METODOS DE LECTURA DE DATOS //////////////////////////////////////////////////////////////
// METODO LEER DATOS
void Herramienta::leerDatos() 
{
    cout<<"\tIngrese el nombre de la herramienta: ";
    getline(cin, nombre);

    cout<<"\tIngrese el codigo de la herramienta: ";
    getline(cin, codigo);

    cout<<"\tIngrese la marca de la herramienta: ";
    getline(cin, marca);

    cout<<"\tIngrese el precio de la herramienta: $";
    cin>>precio;
    cin.ignore(); // Limpiador
}

// METODO IMPRIMIR DATOS 
void Herramienta::ImprimirDatos()
 {
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Codigo: "<<codigo<<endl;
    cout<<"Marca: "<<marca <<endl;
    cout<<"Precio: $"<<precio<<endl;
    cout<<"\n";
}

///////////////////////////////////////// METODOS PARA MODIFICAR (SET)  //////////////////////////////////////////////////////////////
void Herramienta::setNombre(string N)
 {
    nombre = N;
}
void Herramienta::setCodigo(string C) 
{
    codigo = C;
}
void Herramienta::setMarca(string M)
 {
    marca = M;
}
void Herramienta::setPrecio(float P)
 {
    precio = P;
}

///////////////////////////////////////// METODOS PARA OBTENER (GET)  //////////////////////////////////////////////////////////////
float Herramienta::getPrecio()
 {
    return precio;
}
string Herramienta::getNombre()
 {
    return nombre;
}

/////////////////////////////////////// FUNCION PRINCIPAL //////////////////////////////////////////////////////////////
int main() 
{
		// DECLARACION DE VARIABLES
    int n;
    
    // LECTURA DE DATOS
    cout<<"Ingrese la cantidad de herramientas: ";
    cin>>n;
    fflush(stdin);

    Herramienta* herramientas = new Herramienta[n];

    // LEER DATOS
    for(int i = 0; i < n; ++i) 
	{
        cout << "\n\t ***********Ingrese los datos de la herramienta "<<i+1<<"*******************\n";
        herramientas[i].leerDatos();
    }

//***************************** MENU DE HERRAMIENTES *******************************
    	// DECLARACION DE VARIABLES
    int opcion;
    // CICLO DO PARA MOSTRAR MENU
    do 
	{
		// IMPRESION DE OPCIONES
        system("cls");
        cout<<"\n****************************************** MENU *************************************************\n";
        cout<<"\t1. Buscar herramienta por nombre\n";
        cout<<"\t2. Cambiar datos de una herramienta\n";
        cout<<"\t3. Calcular precio promedio de las herramientas\n";
        cout<<"\t4. Salir\n";
        
        // LECTURA DE DATOS
        cout<<"\t\tSeleccione una opcion: ";
        cin>>opcion; 
        cin.ignore(); 

        // CONDICION SWITCH
        switch(opcion) 
		{
//****************** CASO 1 PARA BUSCAR ****************************
            case 1:
			 {
			 	// DECLARACION DE VARIABLES
                string Busqueda;
                 int encontrada = 0;
                 
                // LECTURA DE DATOS
                cout<<"\n\tIngrese el nombre de la herramienta a buscar: ";
                getline(cin, Busqueda);
                
                // CICLO FOR 
                for(int i = 0; i < n; ++i) 
				{
					// CONDICION IF PARA ENCONTRA EL NOMBRE Y SUS DATOS
                    if(herramientas[i].getNombre()==Busqueda) 
					{
                        herramientas[i].ImprimirDatos();
                        encontrada = 1;
                        break;
                    }
                }
                // CONDICION IF AL NO ENCUNTRAR 
                if(encontrada == 0) 
				{
                    cout<<"Herramienta no encontrada.\n";
                }
                system("pause"); // Pausar despu�s de la b�squeda
                break;
            }
//****************** CASO 2 PARA CAMBIAR ****************************
            case 2:
			 {
			 	// DECLARACION DE VARIABLES
                int i;
                
                // LECTURA DE DATOS
                cout<<"\n\t Ingrese el numero de la herramienta a modificar : ";
                cin>>i;
                cin.ignore(); 

                // LECTURA DE DATOS
                cout<<"\n\t Ingrese los nuevos datos de la herramienta "<<i<<":\n";
                herramientas[i-1].leerDatos();
                system("pause");
                break;
            }
//****************** CASO 3 PARA PROMEDIAR PRECIOS ****************************
            case 3: 
			{
				// DECLARACION DE VARIABLES
                float sumaPrecios = 0.0;
                float promedio;
                
                // CICLO FOR CON OPERACION MATEMATICA (ALGO=ALGO+S)
                for(int i = 0; i < n; ++i) 
				{
                    sumaPrecios = sumaPrecios + herramientas[i].getPrecio(); // Suma de precios
                }
                
                // OPERACION MATEMATICA PARA PROMEDIO
                promedio = sumaPrecios / n;
                
                // IMPRESION DE RESULTADOS
                cout << "El  promedio de las herramientas es: $"<<promedio<<endl;
                system("pause");
                break;
            }
//****************** CASO 4 PARA SALIR DEL PROGRAMA ****************************
            case 4:
                cout << "Saliendo del programa \n";
                break;
                
//****************** SI NO OCUPA UNA DE LAS ANTERIORES ****************************
            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
              
                break;
        }
    } while(opcion != 4);// TEMINAR CICLO DO

    // DESTRUCTOR
    delete[] herramientas; 
    return 0;
}// FIN DE LA FUNCION PRINCIPAL







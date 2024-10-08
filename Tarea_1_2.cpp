#include <iostream>

using namespace std;
////////////////////////////////////////////////////////////////////
//                               STRUCT(ESTRUCTURA)
struct Herrami 
{
    char nombre[30];       // Nombre del producto
   char Codigo[30];        // Codigo del producto 
    char Marca[30];        // Marca del producto
 double precio;        // Precio del producto

    // Declaraciones de funciones
    void leerDatos();
    void impriDatos();
};


//////////////////////////////////////////////////////////////////
//                            FUNCIONES
// Función leer
void Herrami::leerDatos() 
{
	// Declaracion de Variables
	int i;
	
        cout << " \tIngrese el nombre de la Herramienta " << ": ";
        cin.getline(nombre, 30); // Leer el nombre del producto
        
        cout << " \tIngrese el Codigo de la Herramienta " << " : ";
        cin.getline(Codigo, 30); // Leer la Cantidad del producto
        
        cout << " \tIngrese la Marca de la Herramienta " << " : ";
        cin.getline(Marca, 30); // Leer la fecha de vencimiento
        
        cout << " \tIngrese el precio de la Herramienta "  << ": $";
        cin >> precio; // Leer el precio del producto
        
         cout << "\n" ;
        cin.ignore(); // Limpiar el buffer de entrada después de leer el número
    
}

// Función imprimir 
void Herrami::impriDatos() 
{
	// Declaracion de Variable
 int i;
      
      // Impresion de los datos obtenidos
        cout << "Nombre: " << nombre << "\n";
        cout << "Codigo: " << Codigo << "\n";
        cout << "Marca: " << Marca << "\n";
        cout << "Precio: $" << precio << "\n\n";
}

void busPorNom(Herrami* herramientas, char* nomBus) 
{
    int n;
    int encon = 0;
    cout << "\nResultados de busqueda para el nombre \"" << nomBus << "\":\n";
    for (int i = 0; i < n; ++i)
	 {
        int j = 0;
        while (herramientas[i].nombre[j] != '\0' && nomBus[j] != '\0' && herramientas[i].nombre[j] == nomBus[j])
		{
		j++;
		}
		 
		 
        if (herramientas[i].nombre[j] == '\0' && nomBus[j] == '\0')
		 {
            herramientas[i].impriDatos();
            ++encon;
        }
    }
    if (encon == 0) {
        cout << "No se encontraron Herramientas con el nombre ingresado \"" << nomBus << "\".\n";
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
//                                   Funcion Principal
int main()
 {
    int n;

    cout << "\n            *********** BIENVENIDO AL INVENTARIO DE LA FERRETERIA ***********\n";
    cout << "  Cuantas Herramientas Hay: ";
    cin >> n;
    cin.ignore(); // Limpiar el buffer de entrada

    // Asignación dinámica de memoria 
    Herrami* herramientas = new Herrami[n];

    // Leer los datos de las Herramientas
    for (int i = 0; i < n; ++i)
	 {
        cout << "\nIngrese los datos de la Herramienta " << (i + 1) << ":\n";
        herramientas[i].leerDatos();
    }

    // Imprimir los datos de las Herramientas
    cout << "\n************ Lista de Herramientas ************\n";
    for (int i = 0; i < n; ++i)
	 {
        cout << "Herramienta " << (i + 1) << ":\n";
        herramientas[i].impriDatos();
        cout << endl;
    }

    // Buscar Herramientas por nombre
    char nomBus[30];
    cout << "Ingrese el nombre de la Herramienta a buscar: ";
    cin.getline(nomBus, 30);
    busPorNom(herramientas, nomBus);

    // Liberar la memoria asignada
    delete[] herramientas;

    return 0;
}



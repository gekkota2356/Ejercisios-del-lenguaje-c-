#include <iostream> // Biblioteca de entrada y salidas
using namespace std;
// Definición de la estructura 
struct Herrami
{
    char nombre[30];       // Nombre del producto
   char Codigo[30];        // Codigo del producto 
    char Marca[30];        // Marca del producto
 double precio;        // Precio del producto
};
// Función para comparar dos cadenas
int comparaString(char* cadena1, char* cadena2)
 {
 // Declaracion de variables
    int i = 0;
    // Ciclo While
    while (cadena1[i] != '\0' && cadena2[i] != '\0') 
	{
// Cilco if
        if (cadena1[i] != cadena2[i]) {
            return 1; // Las cadenas son diferentes
        }
        i++;
    }
    return (cadena1[i] == cadena2[i]) ? 0 : 1; // Verifica si ambas cadenas terminan al mismo tiempo
}
// Función para leer los datos de los productos
void leerHerra(Herrami* herramientas, int n)
 {
 	// Ciclo for
    for (int i = 0; i < n; ++i)
	 {
        cout << " \tIngrese el nombre de la Herramienta " << i + 1 << ": ";
    
        cin.getline(herramientas[i].nombre, 30); // Leer el nombre del producto
        
        cout << " \tIngrese el Codigo de la Herramienta " << i + 1 << " : ";
        cin.getline(herramientas[i].Codigo, 30); // Leer la Cantidad del producto
        
        cout << " \tIngrese la Marca de la Herramienta " << i + 1 << " : ";
        cin.getline(herramientas[i].Marca, 30); // Leer la fecha de vencimiento
        
        cout << " \tIngrese el precio de la Herramienta " << i + 1 << ": $";
        cin >> herramientas[i].precio; // Leer el precio del producto
         cout << "\n" ;
        cin.ignore(); // Limpiar el buffer de entrada después de leer el número
    }
}

// Función para imprimir todos los productos
void impHerra(Herrami* herramientas, int n) 
{
    cout << "\n************Lista de Herramientas************ \n";
    // Ciclo for
    for (int i = 0; i < n; ++i) 
	{
        cout << "Herramienta " << i + 1 << ":\n";
        cout << "Nombre: " << herramientas[i].nombre << "\n";
        cout << "Codigo: " << herramientas[i].Codigo << "\n";
        cout << "Marca: " << herramientas[i].Marca << "\n";
        cout << "Precio: $" << herramientas[i].precio << "\n\n";
    }
}
// Función para buscar productos por una característica específica (nombre en este caso)
void busPorNom(Herrami* herramientas, int n, char* nomBuscado)
 {
 	// declaracion de variables
    int encon = 0;
    cout << "\n  Resultados de busqueda para el nombre \"" << nomBuscado << "\":\n";
    // ciclo for
    for (int i = 0; i < n; ++i)
	 {
        if (comparaString(herramientas[i].nombre, nomBuscado) == 0)
		 {
            cout << "Herramienta " << i + 1 << ":\n";
            cout << "Nombre: " << herramientas[i].nombre << "\n";
            cout << "Codigo : " << herramientas[i].Codigo<< "\n";
            cout << "Marca: " << herramientas[i].Marca << "\n";
            cout << "Precio: $" << herramientas[i].precio << "\n\n";
            encon++;
        }
    }
    // condicion if por si acaso no encontro
    if (encon == 0) 
	{
        cout << "No se encontraron Herramientas con el nombre ingresado \"" << nomBuscado << "\".\n";
    }
}
int main() 
{// Declaracion de Datos
    int n;
  cout << " \n ***********BIENVENIDO AL INVENTARIO DE LA FERRETERIA*********** \n ";
    // Leer el número de productos
    cout << "  Cuantas Herramientas Hay: ";
    cin >> n; 
    // Limpiar 
    cin.ignore();

    // Asignación dinámica de memoria para el arreglo de productos
    Herrami* herramientas = new Herrami[n];
    // Leer los datos de las Herramientas
    leerHerra(herramientas, n);
    // Imprimir todos de las Herramientas
    impHerra(herramientas, n);
///////////////////////////////////////////////////////////////////////////////////////////
    // Busca Herramienras por nombre
    char nomBuscado[30];
    cout << "Ingrese el nombre de la Herramienta a buscar: ";
    cin.getline(nomBuscado, 30); // Leer el nombre del producto a buscar
    busPorNom(herramientas, n, nomBuscado);
    // Liberar la memoria asignada
    delete[] herramientas;
    return 0; // Fin del programa
}



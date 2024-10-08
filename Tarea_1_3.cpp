#include <iostream>

using namespace std;

///////////////////////////////CLASE ///////////////////////////////////////////
class Herramienta
 {
// ENCAPSULAMIENTO PRIVADO( NO SE PUEDE MANIPULAR DIRECTAMENTE)	
private:
	////////////// ATRIBUTOS/////////////
    char* nombre;
    char* codigo;
    char* marca;
    double precio;

// ENCAPSULAMIENTO PUBLICO (PUEDE MANIPULARSE)
public:
//////////////////// CONSTRUCTOR GENERAL (CONTIENE PARAMETROS Y SIN PARAMETROS) //////////////////
    Herramienta(char* N = "", char* C = "", char* M = "", double P = 0.0) 
	{
      
            nombre = N;
        


            codigo = C;
        


            marca = M;
      
        precio = P;
    }// FIN DEL CONSTRUCTOR DEL TIPO GENERAL

////////////////////// CONSTRUCTOR DEL TIPO COPIA /////////////////////////
    Herramienta(Herramienta &h)
	 {

      
            nombre = h.nombre;
     

    
            codigo = h.codigo;

            marca= h.marca;
    
        precio = h.precio;
    }// FIN DEL CONSTRUCTOR DEL TIPO COPIA

//////////////////// DESTRUCTOR (ELIMINA LOS OBJETOS QUE FUERON CREADOS) //////////////
    ~Herramienta()
	 {
        delete[] nombre;
        delete[] codigo;
        delete[] marca;
    }// FIN DEL DESTRUCTOR

// SE MANDAN A LLAMAR LOS METODOS
    void leerDatos();
    void imprimirDatos();
    
};// FIN DE LA CLASE 

///////////////////////////////METODO LEER DATOS /////////////////////////////////
void Herramienta::leerDatos()
 {
    cout << "\tIngrese el nombre de la herramienta: ";
    cin.getline(nombre, 30);

    cout << "\tIngrese el codigo de la herramienta: ";
    cin.getline(codigo, 30);

    cout << "\tIngrese la marca de la herramienta: ";
    cin.getline(marca, 30);

    cout << "\tIngrese el precio de la herramienta: $";
    cin >> precio;
    
    cin.ignore();  // Limpiador
}// FIN DEL METODO LEER DATOS 

////////////////////////////// METODO IMPRIMIR /////////////////////////////
void Herramienta::imprimirDatos()
 {
    cout << "Nombre: " << nombre << endl;
    cout << "Codigo: " << codigo << endl;
    cout << "Marca: " << marca << endl;
    cout << "Precio: $" << precio << endl;
    cout << "\n"<<endl;
}// FIN DEL METODO IMPRIMIR

/////////////////////////////FUNCION PRINCIPAL ///////////////////////////
int main() {
    cout << "\n*********** BIENVENIDO AL INVENTARIO DE LA FERRETERIA ***********\n";
    cout << "\n************ Lista de Herramientas ************\n";
 
    Herramienta h1;
    
    // LEE DATOS
    h1.leerDatos();

    cout << "\n";
    // IMPRIME DATOS
    h1.imprimirDatos();

    // CREA OTRO OBJETO
    Herramienta h2;
    h2.leerDatos();
    
    // MUESTRA LO CREADO
    cout << "\nDatos de la herramienta creada:\n";
    h2.imprimirDatos();

    return 0;
}// FIN DE LA FUNCION PRINCIPAL



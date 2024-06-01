#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>
using namespace std;


void cargarArray(char matrizPalabras[4][20]);
void mostrarArray(char matrizPalabras[4][20]);

int main (){

    //desplazamiento en 1
    //vocales invertidas

    int filas = 4;
    int columnas = 20;
    char matrizPalabras[4][20] = {};
    int opcElegida;
    bool palabra = false;
    cout<<"Bienvenido a nuestro sistema de encriptacion"<<endl;
    do
    {
        cout<<"Elija una opcion:"<<endl;
        cout<<"(1). Cargar arrays con palabras"<<endl;
        cout<<"(2). Mostrar el array cargado"<<endl;
        cout<<"(3). Encriptar palabras con desplazamiento 1"<<endl;
        cout<<"(4). Encriptar palabras con vocales invertidas"<<endl;
        cout<<"(0). Salir del sistema"<<endl;
        cin>>opcElegida;
        
        switch (opcElegida)
        {
        case 1:
            cout<<"-------------------------------------------------------------------------------"<<endl;            
            cout<<"***** INDICACIONES *****"<<endl;
            cout<<"Tiene la posibilidad de ingresar hasta 4 palabras de 20 caracteres como maximo."<<endl;
            cout<<"Carge una palabra a la vez."<<endl;
            cout<<"La palabra debe ser ingresada en minusculas."<<endl;
            cout<<"Al terminar la palabra, ingrese un punto (.) para finalizar."<<endl;
            cout<<"-------------------------------------------------------------------------------"<<endl;
            cargarArray(matrizPalabras);
            palabra = true;
            cout<<"El array ha sido cargado exitosamente."<<endl;
            system("pause");
            system("cls");
            break;
        case 2:
            if (palabra) //si palabra es true que pase a mostrar la palabra, sino nunca se cargo el array
            {
                mostrarArray(matrizPalabras);
                cout << "-------------------"<<endl;
                cout << "Proceso finalizado."<<endl;
                system("pause");
                system("cls");
            }
            else
            {
                cout << "No se ha cargado el array de palabras."<<endl;
                system("pause");    //hace una pausa en la ejecución del programa y espera a que el usuario presione cualquier tecla para continuar.
                system("cls");      //Este comando limpia la pantalla de la consola.
            }
            break;
        case 0:
            cout << "Saliendo del programa..."<<endl;
            cout << "Conexion finalizada."<<endl;
            break;
        }
    } while (opcElegida!=0);

    return 0;
}
//#cargamos el array
void cargarArray(char matrizPalabras[4][20])
{
    string palabra;
    for (int filas = 0; filas < 4; filas++)
    {
        bool palabraValida = false;
        while (!palabraValida)
        {
            cout << "Ingrese la palabra " << filas + 1 << ": "<<endl;
            cin >> palabra;
            int longitudPalabra = palabra.length();
            if (longitudPalabra > 20)
            {
                cout << "La palabra ingresada es demasiado larga. Ingrese una palabra de maximo 20 caracteres."<<endl;
            }
            else
            {
                palabraValida = true;
                for (int columnas = 0; columnas < longitudPalabra; columnas++)
                {
                    matrizPalabras[filas][columnas] = palabra[columnas];
                }
            }
            for (int columnas = longitudPalabra; columnas < 20; columnas++)
            {
                matrizPalabras[filas][columnas] = '\0'; //? Asigna el caracter nulo a las posiciones vacias. previene simbolos y datos basuras en el display.
            }
        }
    }
}
//#Mostrar el array
void mostrarArray(char matrizPalabras[4][20])
{
    for (int filas = 0; filas < 4; filas++)
    {
        cout<<"La Palabra "<<filas + 1<<" es: "<<endl;
        for (int columnas = 0; columnas < 20; columnas++)
        {
            cout << matrizPalabras[filas][columnas];
        }
        cout << endl;
    }
}
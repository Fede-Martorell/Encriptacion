#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

void AsignarArray(char ArrayPalabras[4][20], char palabra[25], char ArrayOriginal[4][20]); //Este carga el array con las palabras que ingrese el usuario, no devuelve valor
void Mostrar(char ArrayPalabras[4][20]); //muestra el array
void Paso1(char ArrayPalabras[4][20]); //Hace paso 1 adaptado a masc y minsc
void InvertirVocales(char ArrayPalabras[4][20]); //invertir vocales
void Reset(char ArrayPalabras[4][20], char ArrayOriginal[4][20]);
void Menu();

bool ValidarLetra(char c) {
    return (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z'); //esta funcion es para comprobar si algun dato ingresado es algun caracter raro o numeros
    //lo que hace es que al definirlo como bool si el caracter ingresado esta entre (a-z) y (A-Z) devuelve true, sino devuelve false
}

bool ValidarOpcion(char c) {
    return c >= '1' and c <= '5';
}

int main() {
    char ArrayPalabras[4][20], palabra[25], ArrayOriginal[4][20];
    char opcion;//ponemos a la opcion como char solo para que sea mas simple hacer la validacion
    bool arrayCargado = false;

    do {
        Menu();
        cin >> opcion;

        // Validar que la opción sea un número del 1 al 5
        while (!ValidarOpcion(opcion)) {//le puse este while solo para la funcion de comprobar que se ingresan opciones validas
            cout << "\nLA OPCION ELEGIDA NO ES VALIDA! Intente nuevamente" << endl;
            cin >> opcion;
        }

        switch (opcion) {
            case '1':
                // Ingreso de datos
                AsignarArray(ArrayPalabras, palabra, ArrayOriginal);
                arrayCargado = true;//este arrayCargado true es una flag, es para que cuando se encuentre en V se puedan realizar otras opciones
                break;

            case '2':
                // Verificar si el array ha sido cargado
                if (!arrayCargado) {//Todos los if de los case es por lo de la flag, para saber si se utilizo la primer opcion o no
                    cout << "Error: Primero debe cargar el array (opcion 1)." << endl;
                    break;
                }
                // Paso 1
                cout << "Con Paso 1:" << endl;
                Paso1(ArrayPalabras);
                Mostrar(ArrayPalabras);
                Reset(ArrayPalabras, ArrayOriginal);
                break;

            case '3':
                // Verificar si el array ha sido cargado
                if (!arrayCargado) {
                    cout << "Error: Primero debe cargar el array (opcion 1)." << endl;
                    break;
                }
                // Con vocales invertidas
                cout << "\nCon Vocales Invertidas:" << endl;
                InvertirVocales(ArrayPalabras);
                Mostrar(ArrayPalabras);
                Reset(ArrayPalabras, ArrayOriginal);
                break;

            case '4':
                // Verificar si el array ha sido cargado
                if (!arrayCargado) {
                    cout << "Error: Primero debe cargar el array (opcion 1)." << endl;
                    break;
                }
                // Con ambas opciones
                cout << "\nCon Ambos Metodos:" << endl;
                Paso1(ArrayPalabras);
                InvertirVocales(ArrayPalabras);
                Mostrar(ArrayPalabras);
                Reset(ArrayPalabras, ArrayOriginal);
                break;

            case '5':
                // salir
                cout << "\nTurning the system off.." << endl;
                break;
        }

    } while (opcion != '5');

    return 0;
}

// -----------------------------------------------------------------------
void Menu() {
    cout << " -------------------------------------------- " << endl;
    cout << "|                     MENU                   |" << endl;
    cout << " -------------------------------------------- " << endl;
    cout << "|          Ingrese La opcion deseada:        |" << endl;
    cout << "|                                            |" << endl;
    cout << "|1) Carga de Datos                           |" << endl;
    cout << "|                                            |" << endl;
    cout << "|2) Modificar Array aplicando Paso 1         |" << endl;
    cout << "|                                            |" << endl;
    cout << "|3) Modificar Array con Vocales Invertidas   |" << endl;
    cout << "|                                            |" << endl;
    cout << "|4) Modificar Array con Ambos Metodos        |" << endl;
    cout << "|                                            |" << endl;
    cout << "|5) Salir                                    |" << endl;
    cout << " -------------------------------------------- " << endl;
}

//-------------------------------------------------------------------------

void AsignarArray(char ArrayPalabras[4][20], char palabra[25], char ArrayOriginal[4][20]) {
    int longitud;

    for (int filas = 0; filas < 4; filas++) {
        bool valido = false;//ponemos la flag en false para que se ejecute 1 vez por lo menos

        while (!valido) {//el while solo es para que repita la validacion hasta que ingresen algo correcto
            cout << "\nIngrese la palabra numero " << filas + 1 << ": ";//solicitamos la carga al usuario
            cin >> palabra;
            valido = true;//hacemos q flag sea verdadera, si hay algun caracter no deseado se cambia a false

            // Verificacion de cada caracter, osea si todos los caracteres son letras
            for (int i = 0; i < strlen(palabra); i++) {
                if (!ValidarLetra(palabra[i])) {//si aca devuelve un valor falso, significa que algun caracter no es letra
                    valido = false;
                    cout << "Error: La palabra solo debe contener letras. Intente nuevamente." << endl;
                    break;
                }
            }
        }

        longitud = strlen(palabra);

        for (int columnas = 0; columnas < longitud; columnas++) {
            ArrayPalabras[filas][columnas] = palabra[columnas];
        }

        for (int columnas = longitud; columnas < 20; columnas++) {
            ArrayPalabras[filas][columnas] = ' ';
        }
    }

    // Copiamos el array auxiliar al que ingresa el usuario
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 20; j++) {
            ArrayOriginal[i][j] = ArrayPalabras[i][j];
        }
    }
}

//----------------------------------------------------------------------

void Mostrar(char ArrayPalabras[4][20]) {
    cout << "\nEl Array es:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 20; j++) {
            cout << ArrayPalabras[i][j];
        }
        cout << endl;
    }
}

//-----------------------------------------------------------------------

void Paso1(char ArrayPalabras[4][20]) {
    for (int Filas = 0; Filas < 4; Filas++) {
        for (int Columnas = 0; Columnas < 20; Columnas++) {
            // Preguntamos si es distinto que las vocales ya que no debemos modificarlas
            if ((ArrayPalabras[Filas][Columnas] != 'a') and
                (ArrayPalabras[Filas][Columnas] != 'e') and
                (ArrayPalabras[Filas][Columnas] != 'i') and
                (ArrayPalabras[Filas][Columnas] != 'o') and
                (ArrayPalabras[Filas][Columnas] != 'u') and
                (ArrayPalabras[Filas][Columnas] != 'A') and
                (ArrayPalabras[Filas][Columnas] != 'E') and
                (ArrayPalabras[Filas][Columnas] != 'I') and
                (ArrayPalabras[Filas][Columnas] != 'O') and
                (ArrayPalabras[Filas][Columnas] != 'U')) {

                // Ahora antes de sumarle 1 al array nos fijamos si al hacerlo este resultado da una vocal y la salteamos
                if (ArrayPalabras[Filas][Columnas] + 1 == 'e') {
                    ArrayPalabras[Filas][Columnas] = 'f';
                }
                else if (ArrayPalabras[Filas][Columnas] + 1 == 'i') {
                    ArrayPalabras[Filas][Columnas] = 'j';
                }
                else if (ArrayPalabras[Filas][Columnas] + 1 == 'o') {
                    ArrayPalabras[Filas][Columnas] = 'p';
                }
                else if (ArrayPalabras[Filas][Columnas] + 1 == 'u') {
                    ArrayPalabras[Filas][Columnas] = 'v';
                }
                else if (ArrayPalabras[Filas][Columnas] == 'z') {
                    ArrayPalabras[Filas][Columnas] = 'b';
                }
                else if (ArrayPalabras[Filas][Columnas] + 1 == 'E') {
                    ArrayPalabras[Filas][Columnas] = 'F';
                }
                else if (ArrayPalabras[Filas][Columnas] + 1 == 'I') {
                    ArrayPalabras[Filas][Columnas] = 'J';
                }
                else if (ArrayPalabras[Filas][Columnas] + 1 == 'O') {
                    ArrayPalabras[Filas][Columnas] = 'P';
                }
                else if (ArrayPalabras[Filas][Columnas] + 1 == 'U') {
                    ArrayPalabras[Filas][Columnas] = 'V';
                }
                else if (ArrayPalabras[Filas][Columnas] == 'Z') {
                    ArrayPalabras[Filas][Columnas] = 'B';
                }
                else if (ArrayPalabras[Filas][Columnas] != ' ') {
                    ArrayPalabras[Filas][Columnas] = ArrayPalabras[Filas][Columnas] + 1;
                }
            }
        }
    }
}

//---------------------------------------------------------------------------------

void InvertirVocales(char ArrayPalabras[4][20]) {
    for (int Filas = 0; Filas < 4; Filas++) {
        for (int Columnas = 0; Columnas < 20; Columnas++) {
            // Minusculas
            if (ArrayPalabras[Filas][Columnas] == 'a') {
                ArrayPalabras[Filas][Columnas] = 'u';
            }
            else if (ArrayPalabras[Filas][Columnas] == 'e') {
                ArrayPalabras[Filas][Columnas] = 'o';
            }
            else if (ArrayPalabras[Filas][Columnas] == 'o') {
                ArrayPalabras[Filas][Columnas] = 'e';
            }
            else if (ArrayPalabras[Filas][Columnas] == 'u') {
                ArrayPalabras[Filas][Columnas] = 'a';
            }
            // Mayusculas
            else if (ArrayPalabras[Filas][Columnas] == 'A') {
                ArrayPalabras[Filas][Columnas] = 'U';
            }
            else if (ArrayPalabras[Filas][Columnas] == 'U') {
                ArrayPalabras[Filas][Columnas] = 'A';
            }
            else if (ArrayPalabras[Filas][Columnas] == 'E') {
                ArrayPalabras[Filas][Columnas] = 'O';
            }
            else if (ArrayPalabras[Filas][Columnas] == 'O') {
                ArrayPalabras[Filas][Columnas] = 'E';
            }
        }
    }
}

//--------------------------------------------------

void Reset(char ArrayPalabras[4][20], char ArrayOriginal[4][20]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 20; j++) {
            ArrayPalabras[i][j] = ArrayOriginal[i][j];
        }
    }
}
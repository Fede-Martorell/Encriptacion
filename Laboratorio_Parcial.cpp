#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

void AsignarArray (char ArrayPalabras[4][20], char palabra[25]); //Este carga el array con las palabras que ingrese el usuario, no devuelve valor
void Mostrar (char ArrayPalabras[4][20]); //muestra el array
void Paso1 (char ArrayPalabras[4][20]); //Hace paso 1 adaptado a masc y minsc
void InvertirVocales (char ArrayPalabras[4][20]); //invertir vocales

int main (){
	
	char ArrayPalabras[4][20], palabra[25];
	int longitud;
	
	//Llamamos al subproceso para cargar nuestro Array de palabras
	AsignarArray(ArrayPalabras,palabra);
	
	//Llamamos al subproceso que muestra nuestro Array
	Mostrar(ArrayPalabras);
	
	
	//hacemos paso 1
	Paso1(ArrayPalabras);
	
	
	Mostrar(ArrayPalabras);
	
	//vocales inversas
	InvertirVocales(ArrayPalabras);
	
	//Mostramos con las vocales invertidas
	Mostrar(ArrayPalabras);
	
	//queda: hacer el switch, hacer apb, probar errores.
}


void AsignarArray (char ArrayPalabras[4][20], char palabra[25]){
	
	int longitud;
	for (int filas = 0; filas < 4; filas++){
		cout << "\nIngrese la palabra numero: " << filas+1 << endl;
		cin >> palabra;
		longitud = strlen(palabra);
		
		for (int columnas = 0; columnas < longitud ; columnas++){
			ArrayPalabras[filas][columnas] = palabra[columnas];
		}
	
		for (int columnas = longitud; columnas < 20; columnas++) {
            ArrayPalabras[filas][columnas] = '\0';
        }
	}
}


void Mostrar (char ArrayPalabras[4][20]){
	
	for (int i = 0; i < 4 ; i++){
		for (int j = 0 ; j < 20; j++){
			cout << ArrayPalabras[i][j] ;
		}
		cout << endl;
	}
}	


void Paso1 (char ArrayPalabras[4][20])
{
	cout << "\nCon Paso 1:" << endl;
	for (int Filas = 0 ; Filas < 4 ; Filas++)
	{
		
		for (int Columnas = 0 ; Columnas < 20 ; Columnas++)
		{
			
			//Para minusculas
			if ((ArrayPalabras [Filas][Columnas] >= 'a') && (ArrayPalabras[Filas][Columnas] < 'z')) 
			{
				ArrayPalabras[Filas][Columnas] = ArrayPalabras[Filas][Columnas] + 1;
			} else
			
			if (ArrayPalabras[Filas][Columnas] == 'z')
			{
				ArrayPalabras[Filas][Columnas] = 'a';
			}else 
			
			//Para mayusculas
			if ((ArrayPalabras [Filas][Columnas] >= 'A') && (ArrayPalabras [Filas][Columnas] < 'Z'))
			{
				ArrayPalabras[Filas][Columnas] = ArrayPalabras[Filas][Columnas] + 1;
			} else
			
			if (ArrayPalabras[Filas][Columnas] == 'Z')
			{
				ArrayPalabras[Filas][Columnas] = 'A';
			}
		}
	}
}

void InvertirVocales (char ArrayPalabras[4][20]) {

	cout << "\nCon vocales Inversas y paso 1: " << endl;
	for (int Filas = 0; Filas < 4; Filas++){
		for (int Columnas = 0; Columnas < 20; Columnas++){
			//Minusculas
			if (ArrayPalabras[Filas][Columnas] == 'a' ){
				ArrayPalabras[Filas][Columnas] = 'u';
			} else
			
			if (ArrayPalabras[Filas][Columnas] == 'e' ){
				ArrayPalabras[Filas][Columnas] = 'o';
			} else
			
			if (ArrayPalabras[Filas][Columnas] == 'o' ){
				ArrayPalabras[Filas][Columnas] = 'e';
			} else 
			
			if (ArrayPalabras[Filas][Columnas] == 'u' ){
				ArrayPalabras[Filas][Columnas] = 'a';
			} else
			
			//Para mayusculas
			if (ArrayPalabras[Filas][Columnas] == 'A' ){
				ArrayPalabras[Filas][Columnas] = 'U';
			} else
			
			if (ArrayPalabras[Filas][Columnas] == 'U' ){
				ArrayPalabras[Filas][Columnas] = 'A';
			} else
			
			if (ArrayPalabras[Filas][Columnas] == 'E' ){
				ArrayPalabras[Filas][Columnas] = 'O';
			} else
			
			if (ArrayPalabras[Filas][Columnas] == 'O' ){
				ArrayPalabras[Filas][Columnas] = 'E';
			}
		}
	}
}
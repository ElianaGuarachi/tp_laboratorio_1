/*
 * utn.h
 *
 *  Created on: 23 sep. 2021
 *      Author: Eliana
 */

#ifndef UTN_H_
#define UTN_H_
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @fn int utn_getNumero(int*, char*, char*, int, int, int)
/// @brief Funcion para pedir un numero por consola
/// @param pResultado Puntero a variable donde se escribir� el valor ingresado en el caso de ser correcto.
/// @param mensaje Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola.
/// @param mensajeError Puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea v�lido.
/// @param minimo Valor m�nimo admitido (inclusive)
/// @param maximo Valor m�ximo admitido (inclusive)
/// @param reintentos Cantidad de veces que se le volver� a pedir al usuario que ingrese un dato en caso de error.
/// @return
int ObtenerEntero( int* pResultado,char mensaje[],char mensajeError[],int minimo,int maximo,int reintentos);

int ObtenerDecimal( float* pResultado,char mensaje[], char mensajeError[], float minimo, float maximo,int reintentos);

int ObtenerCaracterDosOpciones( char* pResultado,char mensaje[], char mensajeError[], char minimo, char maximo, int reintentos);

int ObtenerCaracterEntreRango(char* pResultado,char mensaje[], char mensajeError[], char minimo, char maximo, int reintentos);

int ObtenerCadenaDeCaracteres(char texto[], char mensaje[], char mensajeError[], int reintentos);

#endif /* UTN_H_ */

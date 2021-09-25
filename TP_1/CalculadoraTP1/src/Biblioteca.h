/*
 * Biblioteca.h
 *
 *  Created on: 23 sep. 2021
 *      Author: Eliana
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#include <stdio.h>
#include <ctype.h>

/// @fn int MenuPrincipal(float, float)
/// @brief Funcion que muestra el menu principal con las opciones a elegir para el usuario
/// @param numero1 Copia del numero que recibe por parametro
/// @param numero2 Copia del segundo numero que recibe por parametro
/// @return devuelve la opcion elegida por el usuario
int MenuPrincipal(float numero1, float numero2);

/// @fn int PedirEntero(int*, char[], char[], int, int, int)
/// @brief Funcion que pide un numero entero, lo valida y lo devuelve por parametro
/// @param pResultado direccion de memoria donde se guardara el numero elegido
/// @param mensaje Mensaje que recibe por valor que pide elegir un numero
/// @param mensajeError Mensaje que recibe por valor que se mostrara en el caso de elegir un numero fuera del rango
/// @param minimo Rango minimo para elegir el numero
/// @param maximo Rango maximo para elegir el numero
/// @param reintentos Cantidad de veces que puede intentar ingresar un numero dentro del rango
/// @return Devuelve 0 si eligio un numero valida, devuelve -1 si no fue asi
int PedirEntero(int* pResultado, char mensaje[], char mensajeError[],int minimo,int maximo,int reintentos);

/// @fn float PedirDecimal(char[])
/// @brief Funcion que pide el ingreso de un numero flotante/ decimal
/// @param mensaje Cadena de caracteres recibido por valor que pedira el numero decimal
/// @return Devuelve el numero decimal ingresado por el usuario
float PedirDecimal(char mensaje[]);

#endif /* BIBLIOTECA_H_ */

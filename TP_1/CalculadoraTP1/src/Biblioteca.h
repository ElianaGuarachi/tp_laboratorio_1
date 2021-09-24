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

/// @fn int PedirEntero(char[])
/// @brief Funcion que pide un numero al usuario
/// @param mensaje Mensaje que se paso por parametro para mostrarle al usuario
/// @return Devuelve el numero entero que eligio el usuario
int PedirEntero(char mensaje[]);

/// @fn float PedirDecimal(char[])
/// @brief Funcion que pide un numero decimal al usuario
/// @param mensaje Mensaje que se paso por parametro para mostrarle al usuario
/// @return Devuelve el numero decimal que eligio el usuario
float PedirDecimal(char mensaje[]);

#endif /* BIBLIOTECA_H_ */

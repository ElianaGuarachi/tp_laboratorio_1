/*
 * Biblioteca.h
 *
 *  Created on: 23 sep. 2021
 *      Author: Eliana
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#include <stdio.h>

/// @fn int PedirEntero(char[])
/// @brief Funcion que solicita numeros enteros
/// @param mensaje Cadena de caracteres que se recibe por parametro y que se mostrara para solicitar un numero
/// @return devuelve el numero que ingresa el usuario
int PedirEntero(char mensaje[]);

/// @fn int MenuPrincipal(int, int)
/// @brief Funcion que muestra todas las opciones del menu
/// @param numero1 Numero que recibe por parametro para mostrar en una de la opciones
/// @param numero2 Numero que recibe por parametro para mostrar en una de la opciones
/// @return Devuelve la opcion de menu que selecciono el usuario
int MenuPrincipal(int numero1, int numero2);

#endif /* BIBLIOTECA_H_ */

/*
 * Operaciones.h
 *
 *  Created on: 23 sep. 2021
 *      Author: Eliana
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_
#include <stdio.h>

/// @fn int Suma(int, int)
/// @brief Funcion que realiza la suma entre dos sumandos
/// @param numero1 Numero que recibe por parametro para ser el primer sumando
/// @param numero2 Numero que recibe por parametro para ser el segundo sumando
/// @return Devuelve el resultado de la suma
int Suma(int numero1, int numero2);

/// @fn int Resta(int, int)
/// @brief  Funcion que realiza la resta entre dos numeros
/// @param numero1 Numero que recibe por parametro para ser el primer operador de la resta
/// @param numero2 Numero que recibe por parametro para ser el segundo operador de la rest
/// @return Devuelve el resultado de la resta
int Resta(int numero1, int numero2);

/// @fn long long int Multiplicacion(int, int)
/// @brief Funcion que realiza la multiplicacion entre dos factores
/// @param numero1 Copia del primer factor pasado por parametro
/// @param numero2 Copia del segundo factor pasado por parametro
/// @return
long long int Multiplicacion(int numero1, int numero2);

/// @fn int Division(float*, int, int)
/// @brief Funcion que realiza la division entre dos numeros
/// @param division direccion de memoria en donde se guardara el resultado de la division
/// @param numero1 Copia del valor del numero que sera el dividendo
/// @param numero2 Copia del valor del numero que sera el divisor
/// @return devuelve como resultado un 1 o 0. Si es 1 la division no se realizo, si es 0 se pudo hacer
int Division(float* division, int numero1, int numero2);

/// @fn double CalcularFactorial(int)
/// @brief Funcion que calcula el factorial de un numero
/// @param numero copia del numero al que se le realizara el factorial
/// @return devuelve el resultado del calculo de factorial
double CalcularFactorial( int numero);

#endif /* OPERACIONES_H_ */

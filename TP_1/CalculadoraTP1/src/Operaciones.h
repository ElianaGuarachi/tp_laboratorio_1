/*
 * Operaciones.h
 *
 *  Created on: 23 sep. 2021
 *      Author: Eliana
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_
#include <stdio.h>

/// @fn float Suma(float, float)
/// @brief Funcion que resuelve la suma entre dos operandos
/// @param numero1 Copia del primer operando
/// @param numero2 Copia del segundo operando
/// @return Devuelve el resultado de la suma
float Suma(float numero1, float numero2);

/// @fn float Resta(float, float)
/// @brief Funcion que resuelve la resta entre dos operandos
/// @param numero1 Copia del primer operando
/// @param numero2 Copia del segundo operando
/// @return Devuelve el resultado de la resta
float Resta(float numero1, float numero2);

/// @fn double Multiplicacion(float, float)
/// @brief funcion que se encarga de multiplicar dos numeros
/// @param numero1 Copia del primero operando
/// @param numero2 Copia del segundo operando
/// @return Devuelve el resultado de la operacion
double Multiplicacion(float numero1, float numero2);

/// @fn int Division(float*, float, float)
/// @brief Funcion que realiza una division entre dos operandos
/// @param division Direccion de memoria donde se guardara el resultado de la division si se pudo hacer
/// @param numero1 Copia del primer operando
/// @param numero2 Cppia del segundo operando
/// @return Devuelve dos resultado: 1 si no se pudo hacer la division, y 0 si se puedo
int Division(float* division, float numero1, float numero2);

/// @fn double CalcularFactorial(int)
/// @brief Calcula el factorial de un numero entero positivo
/// @param numero Copia del numero entero que recibe
/// @return Devuelve el resultaod del calculo del factorial
double CalcularFactorial(int numero);


#endif /* OPERACIONES_H_ */

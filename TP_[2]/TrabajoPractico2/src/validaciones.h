/*
 * validaciones.h
 *
 *  Created on: 9 oct. 2021
 *      Author: Eliana
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#include "ArrayEmployees.h"

/// @fn int MenuPrincipal()
/// @brief Funcion que muestra las opciones del menu para elegir una
/// @return Retorna la opcion que se elegio
int MenuPrincipal ();

/// @fn int ValidarRespuestaDelMenu(int*, Employee[], int)
/// @brief Funcion que en el caso de no estar de alta ningun empleado no permite las opciones del menu mas que el alta
/// @param respuesta puntero al espacio en memoria donde esta la opcion elegida del menu
/// @param lista puntero a la estructura array de empleados
/// @param tam tamanio del array
/// @return (-1) si hay error, (0) si se valido
int ValidarRespuestaDelMenu(int* respuesta, Employee lista[], int tam);


#endif /* VALIDACIONES_H_ */


#ifndef PARSER_H_
#define PARSER_H_

#include "LinkedList.h"
#include "Employee.h"

/// @fn int parser_EmployeeFromText(FILE*, LinkedList*)
/// @brief Funcion que parsea los datos de los empleados de un archivo texto
/// @param pFile Puntero a FILE
/// @param pArrayListEmployee Puntero a la lista de la estructura linkedlist
/// @return Devuelve -1 si es NULL o 0 si no pudo parsear
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/// @fn int parser_EmployeeFromBinary(FILE*, LinkedList*)
/// @brief Funcion que parsea los datos de los empleado de un archivo binario
/// @param pFile Puntero a FILE
/// @param  pArrayListEmployee Puntero a la lista de la estructura linkedlist
/// @return Devuelve -1 si es NULL o 0 si no pudo parsear
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

/// @fn int parser_EmployeeGetLastId(int*)
/// @brief funcion que parsea la lectura del ultimo id guardado en un archivo de texto
/// @param newId Parametro por referencia  de un entero
/// @return Devuelve -1 si el puntero es NULL o 0 si no pudo parsear
int parser_EmployeeGetLastId(int* newId);

/// @fn int parser_EmployeeSaveLastId(char*)
/// @brief Funcion que parsea la escritura del ultimo id que guardara en el archivo de texto
/// @param id Puntero a char
/// @return Devuelve -1 si el puntero es NULL o 0 si no pudo parsear
int parser_EmployeeSaveLastId(char* id);

#endif /* PARSER_H_ */

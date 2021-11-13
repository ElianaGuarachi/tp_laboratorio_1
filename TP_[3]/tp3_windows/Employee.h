#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/// @fn Employee employee_new*()
/// @brief Funcion que reserva espacio en memoria dinamica para una estructura empleado e iniciliza las variables
/// @return Devuelve una estructura de empleado inicializada o NULL si no encontro espacio en memoria
Employee* employee_new();

/// @fn Employee employee_newParametros*(char*, char*, char*, char*)
/// @brief Funcion que asigna valores a la estructura de empleado
/// @param idStr Puntero a char del id
/// @param nombreStr Puntero a char del nombre
/// @param horasTrabajadasStr Puntero a char de las horas
/// @param sueldoStr Puntero a char del sueldo
/// @return Devuelve una estructura de empleado cargado o NULL si no se pudo realizar
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/// @fn int employee_delete(Employee*)
/// @brief Funcion que libera el espacio en memoria del puntero a la estructura empleado
/// @param this Puntero a estructura empleado
/// @return Devuelve -1 si es NULL o 0 si se libero es espacio
int employee_delete(Employee* this);

/// @fn int employee_setId(Employee*, int)
/// @brief Funcion que guarda el valor del id a la variable id de la estructura empleado
/// @param this Puntero a estructura empleado
/// @param id Parametro por valor de un entero
/// @return Devuelve -1 si es puntero es NULL o 0 si la funcion es ok
int employee_setId(Employee* this,int id);

/// @fn int employee_getId(Employee*, int*)
/// @brief Funcion que obtiene el valor de id de una estructura de empleados
/// @param this Puntero a estructura empleado
/// @param id Puntero a entero
/// @return Devuelve -1 si es puntero es NULL o 0 si la funcion es ok
int employee_getId(Employee* this,int* id);

/// @fn int employee_setNombre(Employee*, char*)
/// @brief Funcion que guarda el nombre en la variable nombre de la estructura
/// @param this Puntero a estructura empleado
/// @param nombre puntero a char
/// @return Devuelve -1 si los punteros son NULL o 0 si la funcion es ok
int employee_setNombre(Employee* this,char* nombre);

/// @fn int employee_getNombre(Employee*, char*)
/// @brief Funcion que obtiene el nombre de la variable nombre de la estructura de empleado
/// @param this Puntero a estructura empleado
/// @param nombre Puntero a char de nombre
/// @return Devuelve -1 si es puntero es NULL o 0 si la funcion es ok
int employee_getNombre(Employee* this,char* nombre);

/// @fn int employee_setHorasTrabajadas(Employee*, int)
/// @brief Funcion que guarda un entero a una variable de la estructura empleado
/// @param this Puntero a estructura empleado
/// @param horasTrabajadas Parametro de valor de un entero
/// @return Devuelve -1 si es puntero es NULL o 0 si la funcion es ok
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/// @fn int employee_getHorasTrabajadas(Employee*, int*)
/// @brief Funcion que obtiene la direccion de memoria de una variable entero del puntero a empleado
/// @param this Puntero a estructura empleado
/// @param horasTrabajadas Puntero a entero
/// @return Devuelve -1 si los punteros son NULL o 0 si la funcion es ok
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/// @fn int employee_setSueldo(Employee*, int)
/// @brief Funcion que guarda el valor de un entero al puntero de estructura empleado
/// @param this Puntero a estructura empleado
/// @param sueldo Parametro por valor de un entero
/// @return Devuelve -1 si es puntero es NULL o 0 si la funcion es ok
int employee_setSueldo(Employee* this,int sueldo);

/// @fn int employee_getSueldo(Employee*, int*)
/// @brief Funcion que obtiene el valor de un entero a traves de puntero
/// @param this Puntero a estructura empleado
/// @param sueldo Puntero a entero
/// @return Devuelve -1 si los punteros son NULL o 0 si la funcion es ok
int employee_getSueldo(Employee* this,int* sueldo);

/// @fn void employee_showEmployee(Employee*)
/// @brief Funcion que muestra la informacion de una estructura empleado
/// @param this Puntero a estructura empleado
void employee_showEmployee(Employee* this);

/// @fn int employee_modificationOptions(Employee*, int)
/// @brief Funcion que elige modificar algo a traves de una opcion por switch
/// @param this Puntero a estructura empleado
/// @param option Parametro por valor de un entero que sera la opcion
/// @return Devuelve -1 si es puntero es NULL o 0 si la funcion es ok
int employee_modificationOptions(Employee* this, int option);

/// @fn int employee_searchEmployeeById(Employee*, int)
/// @brief Funcion que busca la estructura de un empleado a traves del id
/// @param this Puntero a estructura empleado
/// @param idBuscado Parametro por valor de un entero
/// @return Devuelve -1 si es NULL, 0 si no encontro al empleado, o 1 si encontro el id
int employee_searchEmployeeById(Employee* this, int idBuscado);

/// @fn int employee_compareByName(void*, void*)
/// @brief Funcion criterio que recibe dos punteros a void para compararlos
/// @param opcionA Puntero a void
/// @param opcionB Puntero a void
/// @return Devuelve -1 si los punteros son NULL o 0 si la funcion es ok
int employee_compareByName(void* opcionA, void* opcionB);

/// @fn int employee_ValidadCadena(char[], int)
/// @brief Funcion que valida si la cadena de caracteres es de solo letras
/// @param cadena puntero a char
/// @param limite pasaje por valor del tamanio de la cadena
/// @return Devuelve 1 si no valida o 0 si pudo validar
int employee_ValidadCadena(char cadena[], int limite);

#endif // employee_H_INCLUDED



#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "utn.h"
#define LIBRE 1
#define OCUPADO 0

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}Employee;

/// @fn int initEmployees(Employee*, int)
/// @brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
/// @param list Employee* Pointer to array of employees
/// @param len Array length
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int initEmployees(Employee* list, int len);

/// @fn int addEmployee(Employee*, int, int, char[], char[], float, int)
/// @brief add in a existing list of employees the values received as parameters in the first empty position
/// @param list Employee* Pointer to array of employees
/// @param len Array length
/// @param id copy of employee's id number
/// @param name Pointer to name of employee
/// @param lastName Pointer to lastName of employee
/// @param salary copy of employee's salary
/// @param sector copy of employee's sector
/// @return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/// @fn int findEmployeeById(Employee*, int, int)
/// @brief \brief find an Employee by Id en returns the index position in array.
/// @param list Employee* Pointer to array of employees
/// @param len Array length
/// @param id copy of employee's id
/// @return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
int findEmployeeById(Employee* list, int len,int id);

/// @fn int removeEmployee(Employee*, int, int)
/// @brief Remove a Employee by Id (put isEmpty Flag in 1)
/// @param list Employee* Pointer to array of employees
/// @param len Array length
/// @param id copy of employee's id number
/// @return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
int removeEmployee(Employee* list, int len, int id);

/// @fn int sortEmployees(Employee*, int, int)
/// @brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
/// @param list Employee* Pointer to array of employees
/// @param len Array length
/// @param order [1] indicate UP - [0] indicate DOWN
/// @return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int sortEmployees(Employee* list, int len, int order);

/// @fn int printEmployees(Employee[], int)
/// @brief print the content of employees array
/// @param list Employee* Pointer to array of employees
/// @param length Array length
/// @return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int printEmployees(Employee list[], int length);

/// @fn int BurcarLugarLibre(Employee[], int)
/// @brief Funcion que busca si hay un lugar libre para poder dar inicio al alta
/// @param list Puntero al array de empleados
/// @param length tamanio del array
/// @return (-1) si es error [puntero NULL o no hay lugar disponible] - (1) si encontro lugar disponible
int BurcarLugarLibre(Employee list[], int length);

/// @fn int AltaDeUnEmpleado(Employee*, int, int*)
/// @brief Funcion que se encarga de pedir los datos luego de verificar espacio disponible
/// @param list list Puntero al array de empleados
/// @param len tamanio del array
/// @param id Puntero del id que se incrementa cada vez que se da un alta
/// @return (-1) si es error [puntero NULL o no hay lugar disponible] - (0) El empleado ha sido dado de alta
int AltaDeUnEmpleado(Employee* list, int len, int* id);

/// @fn void MostrarUnSoloEmpleado(Employee)
/// @brief funcion que muestra los datos de un empleado
/// @param unEmpleado estructura de un empleado solo
void MostrarUnSoloEmpleado(Employee unEmpleado);

/// @fn int ModificacionesSobreUnEmpleado(Employee[], int)
/// @brief Funcion que se encarga de ofrecer la posibilidad de modificar los datos de un empleado
/// @param list list Puntero al array de empleados
/// @param len tamanio del array
/// @return (-1) si es error [puntero NULL] - (0) Se realizaron cambios
int ModificacionesSobreUnEmpleado(Employee list[], int len);

/// @fn int OpcionesDeModificacion(Employee[], int, int)
/// @brief funcion que se encarga de mostrar las opciones de cambio para efectuar la que se elija
/// @param list list Puntero al array de empleados
/// @param opcion Copia del valor eligido para modificar informacion
/// @param index Posicion en el array de un empleado
/// @return (-1) si es error [puntero NULL] - (1) Se realizaron cambios sobre la opcion elegida
int OpcionesDeModificacion(Employee list[], int opcion, int index);

/// @fn int BuscarEmpleadoParaRemoverlo(Employee[], int)
/// @brief Funcion que llama a otra para buscar la posicion del empleado en el array que se desea remover
/// @param list list Puntero al array de empleados
/// @param len tamanio del array
/// @return (-1) si es error [puntero NULL] - (0) se removio al empleado
int BuscarEmpleadoParaRemoverlo(Employee list[], int len);

/// @fn int InformarListadosDeEmpleados(Employee*, int)
/// @brief Funcion que a partir de opciones mostrara diferentes listados de los empleado o conteos
/// @param list list Puntero al array de empleados
/// @param len tamanio del array
/// @return (-1) si es error [puntero NULL] - (0) muestra alguna opcion
int InformarListadosDeEmpleadosSegunEleccion(Employee* list, int len);

/// @fn int EmpleadosConSueldosMayorAlPromedio(Employee[], int, float, int*)
/// @brief Funcion que cuenta la cantidad de empleados/as que cobran mas del promedio de los sueldos entre empleados dados de alta
/// @param list list Puntero al array de empleados
/// @param len tamanio del array
/// @param promedio Copia del valor del promedio de sueldos
/// @param contador puntero de la cantidad de empleados
/// @return (-1) si es error [puntero NULL] - (0) se hizo el conteo
int EmpleadosConSueldosMayorAlPromedio(Employee list[], int len, float promedio, int* contador);

/// @fn int InformesDeSalarios(Employee[], int)
/// @brief Funcion que informa total de sueldos, promedio de sueldos y quienes cobran mas del promedio
/// @param list list Puntero al array de empleados
/// @param len tamanio del array
/// @return (-1) si es error [puntero NULL] - (0) se muestran los informes
int InformesSobreSalarios(Employee list[], int len);

/// @fn int PromedioDeSueldos(Employee[], int, float*, float*, int*)
/// @brief Funcion que va a calcular el promedio de sueldos de la nomina de empleados
/// @param list list Puntero al array de empleados
/// @param len tamanio del array
/// @param promedio Puntero al espacio en memoria donde se guarda el promedio
/// @param total Puntero al espacio en memoria donde se guardara la totalidad de sueldos
/// @param contador Puntero al espacio en meoria donde se guardara el valor de contador
/// @return
int PromedioDeSueldos(Employee list[], int len, float* promedio, float* total, int* contador);

#endif /* ARRAYEMPLOYEES_H_ */

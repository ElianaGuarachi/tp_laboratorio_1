
//#include "LinkedList.h"
//#include "Employee.h"
#include "parser.h"
//#include "utn.h"

/// @fn int controller_loadFromText(char*, LinkedList*)
/// @brief Funcion que abre y cierra el archivo de texto de los empleados
/// @param path Puntero a char donde se encuentra en nombre del archivo
/// @param pArrayListEmployee Puntero a estructura Linkedlist
/// @return Devuelve -1 si los punteros o el archivo es NULL, o 0 si es todo ok
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/// @fn int controller_loadFromBinary(char*, LinkedList*)
/// @brief Funcion que abre y cierra el archivo binario de los empleados
/// @param path Puntero a char donde se encuentra en nombre del archivo
/// @param pArrayListEmployee Puntero a estructura Linkedlist
/// @return Devuelve -1 si los punteros o el archivo es NULL, o 0 si es todo ok
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/// @fn int controller_addEmployee(LinkedList*)
/// @brief funcion que se encarga de dar el alta de un empleado
/// @param pArrayListEmployee Puntero a estructura Linkedlist
/// @return Devuelve -1 si los punteros son NULL o no pudo realiza la carga, o 0 si es todo ok
int controller_addEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_editEmployee(LinkedList*)
/// @brief Funcion que permite modificar la informacion de algun empleado/a
/// @param pArrayListEmployee Puntero a estructura Linkedlist
/// @return Devuelve -1 si los punteros son NULL o no pudo realizar la modificacion, o 0 si es todo ok
int controller_editEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_removeEmployee(LinkedList*)
/// @brief Funcion que liberara la memoria dinamica al eliminar al empleado
/// @param pArrayListEmployee Puntero a estructura Linkedlist
/// @return Devuelve -1 si los punteros son NULL o no pudo remover un empleado, o 0 si es todo ok
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_ListEmployee(LinkedList*)
/// @brief funcion que mostrara toda la lista de empleados
/// @param pArrayListEmployee Puntero a estructura Linkedlist
/// @return Devuelve -1 si los punteros son NULL o la lista esta vacia, o 0 si es todo ok
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_sortEmployee(LinkedList*)
/// @brief funcion que realizara un ordenamiento de la lista de empleados
/// @param pArrayListEmployee Puntero a estructura Linkedlist
/// @return Devuelve -1 si los punteros son NULL o no pudo realizar el ordenamiento, o 0 si es todo ok
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_saveAsText(char*, LinkedList*)
/// @brief Funcion que guarda la informacion de la lista al archivo de texto
/// @param path Puntero a char donde se encuentra en nombre del archivo
/// @param pArrayListEmployee Puntero a estructura Linkedlist
/// @return Devuelve -1 si los punteros son NULL o no pudo guardar la informacion al archivo, o 0 si es todo ok
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/// @fn int controller_saveAsBinary(char*, LinkedList*)
/// @brief Funcion que guarda la informacion de la lista al archivo binario
/// @param path Puntero a char donde se encuentra en nombre del archivo
/// @param pArrayListEmployee Puntero a estructura Linkedlist
/// @return Devuelve -1 si los punteros son NULL o no pudo guardar la informacion al archivo, o 0 si es todo ok
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);



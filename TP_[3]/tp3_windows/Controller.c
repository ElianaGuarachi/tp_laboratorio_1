
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
   int retorno=-1;
   if(path != NULL && pArrayListEmployee != NULL)
   {
	   FILE* pFile;
	   pFile = fopen(path, "r");

	   if(pFile != NULL && parser_EmployeeFromText(pFile, pArrayListEmployee)==0)
	   {
		   retorno=0;
		   fclose(pFile);
	   }
   }
   return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		FILE* pFile;
		pFile = fopen(path, "rb");

		if(pFile != NULL && parser_EmployeeFromBinary(pFile, pArrayListEmployee)==0)
		{
			retorno=0;
			fclose(pFile);
		}
	}
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int newId;
	char auxId[10];
	char auxNombre[128];
	char auxHoras[10];
	char auxSueldo[10];
	Employee* newEmployee;

	if(pArrayListEmployee != NULL)
	{
		if(ObtenerPalabras(auxNombre, "\nIngrese el nombre del empleado/a: ", "\nError. Ingrese el nombre del empleado\a: ", 1) &&
		ObtenerCadenaDeNumeros(auxHoras, "\nIngrese la cantidad de horas trabajadas: ", "\nError. Ingrese una cantidad valida: ", 1) &&
		ObtenerCadenaDeNumeros(auxSueldo, "\nIngrese el sueldo del empleado/a: ", "Error. Ingrese un valor valido: ",1) &&
		parser_EmployeeGetLastId(&newId)==0)
		{
			newId = newId+1;
			itoa(newId,auxId,10);
			FormatearCadena(auxNombre);
			newEmployee = employee_newParametros(auxId,auxNombre,auxHoras, auxSueldo);
			if(ll_add(pArrayListEmployee, newEmployee) == 0)
			{
				retorno = 0;
				parser_EmployeeSaveLastId(auxId);
				employee_showEmployee(newEmployee);
				printf("\nEl empleado/a ha sido dado de alta\n");
			}
		}
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int auxId;
    char respuesta;
    int opcion;
    int len;
    int index;
    Employee* employee;

    if(pArrayListEmployee != NULL && (len = ll_len(pArrayListEmployee)) > 0 &&
    	ObtenerCaracterDosOpciones(&respuesta, "\nQuiere modificar los datos de un empleado/a (s-n): ", "Error. Ingrese s - n para responder: ", 's','n', 1)==0 &&
		respuesta == 's' && ObtenerEntero(&auxId, "\nIngrese el id del empleado/a que desea modificar: ", "\nError. Ingrese un numero valido: ", 1, 1500, 1)==0)
    {
    	for(int i=0; i<len; i++)
    	{
    		employee = (Employee*)ll_get(pArrayListEmployee, i);
    		if(employee != NULL && employee_searchEmployeeById(employee, auxId))
    		{
    			index = ll_indexOf(pArrayListEmployee, (Employee*)employee);
    			if(index != -1)
    			{
    				printf("\nEl empleado/a con el id %d es: \n", auxId);
    				employee_showEmployee(employee);
    				retorno=0;
    				break;
    			}
    		}
    	}

		if(retorno == 0 && ObtenerCaracterDosOpciones(&respuesta, "\nEsta seguro que quiere modificar la informacion del empleado/a (s-n): ",
							"Error. Ingrese s - n para responder: ", 's','n', 1)==0 && respuesta == 's' &&
		   ObtenerEntero(&opcion, "\nIngrese: \n1- Cambiar nombre \n2- Cambiar las horas trabajadas \n3- Cambiar el sueldo\n Opcion: ",
				   "\nError. Ingrese una opcion correcta ", 1, 3, 1)==0 && employee_modificationOptions(employee, opcion)==0)
		{
			printf("\nLa nueva informacion  del empleado ha sido modificada: \n");
			employee_showEmployee(employee);
			retorno=1;
		}
    }
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
    int auxId;
    int len;
    int index;
    char respuesta;
    Employee* employee;

    if(pArrayListEmployee != NULL && (len = ll_len(pArrayListEmployee)) > 0 &&
       ObtenerCaracterDosOpciones(&respuesta, "\nQuiere dar de baja a un empleado/a (s-n): ", "Error. Ingrese s - n para responder: ", 's','n', 1)==0 &&
      respuesta == 's' && ObtenerEntero(&auxId, "\nIngrese el id del empleado/a que desea modificar: ", "\nError. Ingrese un numero valido: ", 1, 1500, 1)==0)
    {
    	for(int i=0; i<len; i++)
       	{
       		employee = (Employee*)ll_get(pArrayListEmployee, i);

       		if(employee != NULL && employee_searchEmployeeById(employee, auxId))
       		{
       			employee_showEmployee(employee);
       			index = ll_indexOf(pArrayListEmployee, (Employee*)employee);
       			if(index != -1 && ObtenerCaracterDosOpciones(&respuesta, "\nEsta seguro que quiere eliminar al empleado/a (s-n): ",
	   	   	   	"Error. Ingrese s - n para responder: ", 's','n', 1)==0 && respuesta == 's' && ll_remove(pArrayListEmployee,index)==0)
       			{
					printf("\nEl empleado/a con el id %d fue dado de baja: \n", auxId);
					employee_delete(employee);
					retorno=0;
					break;
       			}
       		}
       	}
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int len;
	int i;
	Employee* employee;
	if(pArrayListEmployee != NULL && (len = ll_len(pArrayListEmployee)) > 0)
	{
		for(i=0; i<len; i++)
		{
			employee = (Employee*) ll_get(pArrayListEmployee, i);
			if(employee != NULL)
			{
				employee_showEmployee(employee);
			}
		}
	}
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int opcion;
	int len;
	if(pArrayListEmployee != NULL && (len = ll_len(pArrayListEmployee)) >= 2 &&
			ObtenerEntero(&opcion, "\nIngrese la opcion de como quiere ordenar el listado: \n 0- Descendente (Z-A) \n 1- Ascendente (A-Z)\n Opcion: ",
								"\nError. Ingrese una opcion valida: ", 0,1,1) ==0)
	{
		if(ll_sort(pArrayListEmployee,employee_compareByName, opcion)==0)
		{
			printf("\nLa lista ha sido ordenada\n");
			retorno=0;

		}
	}
	else
	{
		if(len < 2)
		{
			printf("\nDebe haber al menos dos empleados en la lista para ordenarla\n");
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int len;
	Employee* employee;
	int auxId;
	char auxNombre[50];
	int auxHoras;
	int auxSueldo;
	if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0)
	{
		FILE* pFile;

		pFile = fopen(path, "w");

		if(pFile != NULL && (len = ll_len(pArrayListEmployee))>0)
		{
			fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
			for(int i=0; i<len;i++)
			{
				employee = (Employee*) ll_get(pArrayListEmployee, i);
				if(employee != NULL && employee_getId(employee, &auxId)==0 &&
						   employee_getNombre(employee, auxNombre)==0 &&
						   employee_getHorasTrabajadas(employee, &auxHoras) ==0 &&
						   employee_getSueldo(employee,&auxSueldo)==0)
				{
					fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxNombre,auxHoras,auxSueldo);
					retorno=0;
				}
			}
			fclose(pFile);
		}
	}
	else
	{
		if(ll_isEmpty(pArrayListEmployee))
		{
				printf("\nAsegurese que debe cargar la lista de empleados\n");
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int len;
	Employee* employee;

	if(path != NULL && pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0)
	{
		FILE* pFile;

		pFile = fopen(path, "wb");

		if(pFile != NULL && (len = ll_len(pArrayListEmployee))>0)
		{
			for(int i=0; i<len; i++)
			{
				employee = (Employee*) ll_get(pArrayListEmployee, i);
				if(employee != NULL)
				{
					fwrite(employee, sizeof(Employee), 1, pFile);
					retorno=0;
				}
			}
			fclose(pFile);
		}
	}
	else
	{
		if(ll_isEmpty(pArrayListEmployee))
		{
			printf("\nAsegurese que debe cargar la lista de empleados\n");
		}
	}
    return retorno;
}


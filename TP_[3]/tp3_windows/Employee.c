#include "Employee.h"

Employee* employee_new()
{
	Employee* newEmployee;

	newEmployee = (Employee*) malloc (sizeof(Employee));

	if(newEmployee != NULL)
	{
		employee_setId(newEmployee, 0);
		employee_setNombre(newEmployee, " ");
		employee_setHorasTrabajadas(newEmployee, 0);
		employee_setSueldo(newEmployee, 0);
	}

	return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* newEmployee;
	int id;
	int horas;
	int sueldo;
	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		newEmployee = employee_new();

		if(newEmployee != NULL)
		{
			id = atoi(idStr);
			horas = atoi(horasTrabajadasStr);
			sueldo = atoi(sueldoStr);

			if(!(employee_setId(newEmployee, id) == 0 &&
			employee_setNombre(newEmployee, nombreStr) == 0 &&
			employee_setHorasTrabajadas(newEmployee, horas) == 0 &&
			employee_setSueldo(newEmployee, sueldo) == 0))
			{
				free(newEmployee);
				newEmployee=NULL;
			}
		}
	}
	return newEmployee;
}

//Setters
int employee_setId(Employee* this,int id)
{
	int retorno=-1;
	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno=0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this != NULL && nombre != NULL && employee_ValidadCadena(nombre, sizeof(nombre)))
	{
		strcpy(this->nombre, nombre);
		retorno=0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno;
	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno=0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno=-1;
	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		retorno=0;
	}
	return retorno;
}

//Getters
int employee_getId(Employee* this,int* id)
{
	int retorno=-1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno=0;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno=0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int retorno=-1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno=0;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno=-1;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno=0;
	}
	return retorno;
}

int employee_delete(Employee* this)
{
	int retorno=-1;
	if(this != NULL)
	{
		free(this);
		retorno=0;
	}
	return retorno;
}


void employee_showEmployee(Employee* this)
{
	int id;
	char nombre[50];
	int horas;
	int sueldo;
	if(employee_getId(this, &id)==0 &&
	   employee_getNombre(this, nombre)==0 &&
	   employee_getHorasTrabajadas(this, &horas) ==0 &&
	   employee_getSueldo(this,&sueldo)==0)
	{
		printf("\n%5d\t %15s \t %5d \t %10d \n", id, nombre, horas, sueldo);
	}
}

int employee_searchEmployeeById(Employee* this, int idBuscado)
{
	int retorno=-1;
	int auxId;
	if(this != NULL)
	{
		retorno=0;
		employee_getId(this,&auxId);
		if(auxId == idBuscado)
		{
			retorno=1;
		}
	}
	return retorno;
}

int employee_modificationOptions(Employee* this, int option)
{
	int retorno = -1;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;
	if(this != NULL)
	{
		switch(option)
		{
		case 1:
			if(ObtenerPalabras(auxNombre, "\nIngrese el nuevo nombre: ", "Error. Ingrese un nombre valido: ", 1) &&
					FormatearCadena(auxNombre) && employee_setNombre(this, auxNombre)==0)
			{
				retorno=0;
			}
			break;

		case 2:
			if(ObtenerEntero(&auxHoras, "\nIngrese la nueva cantidad de horas trabajadas: ",
					"\nError. Ingrese una cantidad validad: ", 1, 400, 1)==0 &&
					employee_setHorasTrabajadas(this, auxHoras) == 0)
			{
				retorno=0;
			}
			break;

		case 3:
			if(ObtenerEntero(&auxSueldo, "\nIngrese el nuevo sueldo: ",
				"\nError. Ingrese una cantidad validad: ", 1, 999999, 1)==0 &&
					employee_setSueldo(this, auxSueldo)==0)
			{
				retorno=0;
			}
			break;
		}
	}
	return retorno;
}

int employee_compareByName(void* opcionA, void* opcionB)
{
	Employee* empleadoUno;
	Employee* empleadoDos;
	char nombreA[50];
	char nombreB[50];
	int compara;

	if(opcionA != NULL && opcionB != NULL)
	{
		empleadoUno = (Employee*) opcionA;
		empleadoDos = (Employee*) opcionB;

		if(employee_getNombre(empleadoUno, nombreA)==0 &&
		   employee_getNombre(empleadoDos, nombreB)==0)
		{
			compara = strcmp(nombreA,nombreB);
		}
	}
	return compara;
}

//=====================================================================================================================
int employee_ValidadCadena(char cadena[], int limite)
{
	int retorno=1;
	int i;
	for(i=0; i< limite && cadena[i] != '\0'; i++)
		{
			if((cadena[i] > 64 && cadena [i] < 91) || (cadena[i] > 159 && cadena[i] < 166) || (i!=0 && cadena[i] == 32))
			{
				continue;
			}

			if(cadena[i] < 97 || cadena[i] > 122)
			{
				retorno= 0;
				break;
			}
		}

	return retorno;
}



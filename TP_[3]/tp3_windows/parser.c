
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		int cantidad;
		char auxId[50];
		char auxNombre[150];
		char auxHoras[50];
		char auxSueldo[50];

		Employee* employee;

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo);// CABECERA
		do
		{
			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo);
			if(cantidad==4)
			{
				retorno=0;
				employee = employee_newParametros(auxId,auxNombre,auxHoras,auxSueldo);
				ll_add(pArrayListEmployee, employee);
			}
			else
			{
				break;
			}

		}while(!feof(pFile));
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int final=0;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		Employee* employee;
		do
		{
			employee = employee_new();
			final = fread(employee, sizeof(Employee), 1, pFile);
			if(final == 1)
			{
				ll_add(pArrayListEmployee, employee);
				retorno=0;
			}
		}while(final != 0);
	}
    return retorno;
}


int parser_EmployeeGetLastId(int* newId)
{
	int retorno=-1;
	char auxId[10];
	FILE* pFile;
	int cantidad;
	if(newId != NULL)
	{
		pFile = fopen("ultimoId.csv", "r");
		if(pFile != NULL)
		{
			cantidad = fscanf(pFile, "%[^\n]", auxId);
			if(cantidad == 1)
			{
				retorno = 0;
				*newId = atoi(auxId);
			}
			fclose(pFile);
		}
	}
	return retorno;
}

int parser_EmployeeSaveLastId(char* id)
{
	int retorno=-1;
	FILE* pFile;

	if(id != NULL)
	{
		pFile = fopen("ultimoId.csv", "w");

		if(pFile != NULL)
		{
			fprintf(pFile, "%s", id);
			retorno=0;
		}

		fclose(pFile);
	}
	return retorno;
}


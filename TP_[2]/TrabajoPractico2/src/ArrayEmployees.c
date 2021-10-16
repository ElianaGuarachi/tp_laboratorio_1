
#include "ArrayEmployees.h"

int initEmployees(Employee* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			list[i].isEmpty = LIBRE;
			retorno=0;
		}
	}
	return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno = -1;
	for(int i=0; i<len; i++)
	{
		if(list != NULL && name != NULL && lastName != NULL && len > 0)
		{
			if(list[i].isEmpty == LIBRE)
			{
				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].salary = salary;
				list[i].sector = sector;
				list[i].isEmpty = OCUPADO;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int findEmployeeById(Employee* list, int len,int id)
{
	int index = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == OCUPADO && list[i].id == id)
			{
				index=i;
				break;
			}
		}
	}
	return index;
}

int removeEmployee(Employee* list, int len, int id)
{
	int retorno=-1;
	if(list != NULL && len > 0)
	{
		for(int i=0; i< len; i++)
		{
			if(list[i].isEmpty==OCUPADO && list[i].id == id)
			{
				list[i].isEmpty = LIBRE; //LIBRE = 1
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;
	int i, j;
	Employee auxiliar;
	if(list != NULL && len > 0)
	{
		for(i=0; i< len-1; i++)
		{
			for(j=i+1;j<len; j++)
			{
				if(list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
				{
				switch(order)
				{
					case 0:
						if(strcmp(list[i].lastName, list[j].lastName)<0 ||
						(strcmp(list[i].lastName, list[j].lastName)== 0 &&
								list[i].sector < list[j].sector))
						{
							auxiliar = list[i];
							list[i] = list[j];
							list[j] = auxiliar;
							retorno=0;
						}
					break;

					case 1:
					if(strcmp(list[i].lastName, list[j].lastName)>0 ||
					(strcmp(list[i].lastName, list[j].lastName)== 0 &&
							list[i].sector > list[j].sector))
					{
						auxiliar = list[i];
						list[i] = list[j];
						list[j] = auxiliar;
						retorno=0;
					}
					break;
					}
				}
			}
		}
	}
	return retorno;
}

int printEmployees(Employee list[], int length)
{
	int retorno = -1;

	if(list != NULL && length > 0)
	{
		for(int i=0; i<length; i++)
		{
			if(list[i].isEmpty == OCUPADO)
			{
				MostrarUnSoloEmpleado(list[i]);
				retorno=0;
			}
		}
	}

	return retorno;
}

void MostrarUnSoloEmpleado(Employee unEmpleado)
{
	printf("\n%5d %25s %25s %15.2f %10d", unEmpleado.id, unEmpleado.lastName, unEmpleado.name,
			unEmpleado.salary, unEmpleado.sector);
}

int BurcarLugarLibre(Employee list[], int length)
{
	int retorno=-1;
	if(list != NULL && length > 0)
	{
		for(int i=0; i< length; i++)
		{
			if(list[i].isEmpty == LIBRE)
			{
				retorno=1;
			}
		}
	}
	return retorno;
}

int AltaDeUnEmpleado(Employee* list, int len, int* id)
{
	int retorno = -1;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int auxId;
	if(id != NULL)
	{
		if(BurcarLugarLibre(list, len)==1)
		{
			if(ObtenerPalabras(name, "\nIngrese nombre/s del empleado/a: ", "Error. Debe ingresar nombres validos", 1) &&
			ObtenerPalabras(lastName, "\nIngrese apellido/s del empleado/a:", "Error. Debe ingresar apellidos validos",1) &&
			ObtenerDecimal(&salary,"\nIngrese el salario del empleado/a: ", "Error. Debe ingresar un numero valido", 1, INT_MAX,2) == 0 &&
			ObtenerEntero(&sector,"\nIngrese el numero de sector del empleado/a: ","Error. Debe ingresar un numero valido",1,SHRT_MAX,2) == 0)
			{
				FormatearCadena(name);
				FormatearCadena(lastName);
				*id+=1;
				auxId=*id;
				addEmployee(list, len, auxId, name,lastName,salary,sector);
				printf("\nEl empleado/a %s %s ha sido dado de alta\n", name, lastName);
				retorno=0;
			}
			else
			{
				printf("\nDebe ingresar todo los datos correctamente para dar de alta a un empleado");
			}
		}
		else
		{
			printf("\nNo hay lugar disponible\n");
		}
	}
	return retorno;
}

int ModificacionesSobreUnEmpleado(Employee list[], int len)
{
	int retorno = -1;
	char respuesta;
	int auxId;
	int opcion;
	int index;
	if(list != NULL && len > 0)
	{
		ObtenerCaracterDosOpciones(&respuesta,"\nEsta seguro/a que desea modificar los datos de un empleado/a? s/n: ",
						"\nError. Seleccione s (si) - n (no)", 's', 'n', 1);
		if(respuesta=='s')
		{
			printEmployees(list, len);
			printf("\n");
			if(ObtenerEntero(&auxId, "\nIngrese el ID del empleado/a al que desea modificar su informacion: ","Error.",1,len,1)==0)
			{
				index = findEmployeeById(list, len, auxId);
				if(index != -1)
				{
					MostrarUnSoloEmpleado(list[index]);
					ObtenerCaracterDosOpciones(&respuesta,"\nEsta seguro que quiere modificar la informaicon del empleado/a? s/n: ",
										"\nError. Seleccione s/n", 's', 'n', 1);
					if(respuesta == 's' &&
						ObtenerEntero(&opcion, "\nElija una opcion que desee modificar 1-Nombre 2-Apellido 3-Salario 4-Sector: ",
															"Error. La opcion no es valida",1,4,1)==0 &&
						OpcionesDeModificacion(list, opcion, index))
					{
						retorno=0;
					}
				}
				else
				{
					printf("\nNo hay un empleado con el ID que busca\n");
				}
			}
		}
	}

	return retorno;
}

int OpcionesDeModificacion(Employee list[], int opcion, int index)
{
	int retorno=-1;
	char auxNombre[51];
	char auxApellido[51];
	float auxSalario;
	int auxSector;
	if(list != NULL)
	{
		switch(opcion)
		{
		case 1:
			if(ObtenerPalabras(auxNombre, "\nIngrese nuevo nombre/s del empleado/a: ",
					"Error. Debe ingresar nombres validos", 1))
			{
				FormatearCadena(auxNombre);
				strcpy(list[index].name, auxNombre);
				printf("\nEl nombre del empleado/a ha sido modificado\n");
				retorno = 1;
			}
		break;

		case 2:
			if(ObtenerPalabras(auxApellido, "\nIngrese nuevo apellido/s del empleado/a: ",
					"Error. Ingrese nuevamente", 1))
			{
				FormatearCadena(auxApellido);
				strcpy(list[index].lastName, auxApellido);
				printf("\nEl apellido del empleado/a ha sido modificado\n");
				retorno=1;
			}
		break;

		case 3:
			if(ObtenerDecimal(&auxSalario,"\nIngrese nuevo salario del empleado/a: ",
					"Error. Debe ingresar un numero valido", 1, INT_MAX,2)==0)

			{
				list[index].salary=auxSalario;
				printf("\nEl salario del empleado/a ha sido modificado\n");
				retorno=1;
			}
		break;

		case 4:
			if(ObtenerEntero(&auxSector,"\nIngrese el numero de sector del empleado/a: ",
					"Error. Debe ingresar un numero valido",1,SHRT_MAX,2)==0)
			{
				list[index].sector = auxSector;
				printf("\nEl sector del empleado/a ha sido modificado\n");
				retorno=1;
			}
		break;
		}
	}

	return retorno;
}

int BuscarEmpleadoParaRemoverlo(Employee list[], int len)
{
	int retorno = -1;
	char respuesta;
	int auxId;
	int index;
	if(list != NULL && len > 0)
	{
		ObtenerCaracterDosOpciones(&respuesta,"\nEsta seguro/a que desea dar de baja un empleado/a? s/n: ",
				"\nError. Seleccione s/n", 's', 'n', 1);
		if(respuesta == 's')
		{
			printEmployees(list, len);
			printf("\n");
			if(ObtenerEntero(&auxId, "\nIngrese el id del empleado/a que desea dar de baja: ",
					"Error. Ingrese un numero valido.",1,len,1)==0)
			{
				index = findEmployeeById(list, len, auxId);
				if(index != -1)
				{
					MostrarUnSoloEmpleado(list[index]);
					ObtenerCaracterDosOpciones(&respuesta,"\nQuiere confirmar la baja del empleado/a? s/n: ",
							"\nError. Seleccione s/n", 's', 'n', 1);
					if(respuesta == 's' && removeEmployee(list, len, auxId)==0)
					{
						printf("\nEl empleado/a ha sido dado de baja.\n");
						retorno=0;
					}
				}
			}
			else
			{
				printf("\nNo hay un empleado/a con el Id ingresado\n");
			}
		}
	}
	return retorno;
}

int InformarListadosDeEmpleadosSegunEleccion(Employee* list, int len)
{
	int retorno=-1;
	int opcion;
	if(list != NULL && len > 0)
	{
		if(ObtenerEntero(&opcion, "\n\t1- Listado de empleados/as \n\t2- Total, promedio de salarios y quienes cobran mas del promedio\n"
				"\nIngrese el listado que desee ver: ", "\nError. No es una opcion correcta\n", 1, 2, 1 )==0)
		{
			switch(opcion)
			{
			case 1:
				if(ObtenerEntero(&opcion, "\n\t\t0- Ordenar Z a A \n\t\t1- Ordenar A a Z\n"
						"\nIngrese por que orden quiere la lista: ", "\nError. No es una opcion correcta\n", 0, 1, 1 )==0)
				{
					if(sortEmployees(list, len, opcion)==0)
					{
						printEmployees(list, len);
						retorno=0;
					}
				}
				break;

			case 2:
				if(InformesSobreSalarios(list, len)==0)
				{
					retorno=0;
				}
				break;
			}
		}
	}
	return retorno;
}

int InformesSobreSalarios(Employee list[], int len)
{
	int retorno=-1;
	float promedio;
	int contador;
	float totalSalarios;
	int cobranMasDelPromedio;
	if(list != NULL && len > 0)
	{
		if(PromedioDeSueldos(list, len, &promedio, &totalSalarios, &contador)==0)
		{
			printf("\n\tEl total entre los %d salarios es: %.2f\n", contador, totalSalarios);
			printf("\n\tEl salario promedio es %.2f\n", promedio);

			if(EmpleadosConSueldosMayorAlPromedio(list,len, promedio, &cobranMasDelPromedio)==0)
			{
				printf("\n\tLos/las empleados/as que cobrar mas del promedio son %d\n", cobranMasDelPromedio);
				retorno=0;
			}
		}
	}

	return retorno;
}

int EmpleadosConSueldosMayorAlPromedio(Employee list[], int len, float promedio, int* contador)
{
	int retorno=-1;
	int i;
	int auxContador;
	auxContador=0;
	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == OCUPADO && list[i].salary > promedio)
			{
				auxContador++;
				retorno=0;
			}
		}
		*contador = auxContador;
	}
	return retorno;
}

int PromedioDeSueldos(Employee list[], int len, float* promedio, float* total, int* contador)
{
	int i;
	int retorno=-1;
	int auxContador;
	float auxTotal;
	float auxPromedio;
	auxContador=0;
	auxTotal=0;
	if(list != NULL && len > 0 && promedio != NULL && total != NULL && contador != NULL)
	{
		for(i=0; i < len; i++)
		{
			if(list[i].isEmpty == OCUPADO)
			{
				auxTotal+= list[i].salary;
				auxContador++;
				retorno=0;
			}
		}
		auxPromedio = auxTotal / auxContador;
		*promedio= auxPromedio;
		*contador= auxContador;
		*total = auxTotal;
	}
	return retorno;
}






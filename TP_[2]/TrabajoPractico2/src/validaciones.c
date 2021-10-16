#include "validaciones.h"

int MenuPrincipal ()
{
	int respuesta;

	printf("\nMENU PRINCIPAL\n"
		   "\n1. ALTAS de empleados"
		   "\n2. MODIFICAR datos de un empleado"
		   "\n3. BAJA de empleado"
		   "\n4. INFORMAR"
		   "\n5. SALIR\n");

	ObtenerEntero(&respuesta, "\nIngrese una opcion del menu: ",
			"Error. El numero ingresado no esta en el menu", 1,5,2);

	return respuesta;
}


int ValidarRespuestaDelMenu(int* respuesta, Employee lista[], int tam)
{
	int retorno = -1;
	if(lista != NULL && respuesta != NULL && tam> 0)
	{
		for(int i=0; i<tam ; i++)
		{
			if(lista[i].isEmpty == OCUPADO)
			{
				break;
			}
			if(lista[i].isEmpty == LIBRE && *respuesta > 1 && *respuesta < 5)
			{
				retorno=0;
			}

		}
	}

	return retorno;
}





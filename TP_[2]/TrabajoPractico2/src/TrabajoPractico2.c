/*
 ============================================================================
 Name        : TrabajoPractico2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 ============================================================================
 */

#include "ArrayEmployees.h"
#include "validaciones.h"

#define NOMINA 1000

int main(void){

	setbuf(stdout, NULL);

	Employee empleados[NOMINA]; /*= {{1, "Eliana Mercedes", "Guarachi", 123456, 123, OCUPADO},
									{2, "Soledad", "Pastoruti", 123478, 456, OCUPADO},
									{3, "Gabriel", "Alvarez", 789456, 456, OCUPADO},
									{4, "Marina", "Zarate", 456123, 963, OCUPADO},
									{5, "Elias", "Guarachi", 123487, 369, OCUPADO},
									{6, "Ariel", "Guarachi", 963258, 258, OCUPADO}};*/
	int respuesta;
	int id;
	id=0;

	if(initEmployees(empleados, NOMINA) == -1)
	{
		printf("\nHubo un error");
	}

	do{
		respuesta = MenuPrincipal();

		if(ValidarRespuestaDelMenu(&respuesta, empleados, NOMINA)==0)
		{
			respuesta = 6;
		}

		switch(respuesta)
			{
				case 1:
				if(AltaDeUnEmpleado(empleados, NOMINA, &id) == -1)
				{
					printf("\nNo se dio de alta a ningun empleado\n");
				}
				break;

				case 2:
					if(ModificacionesSobreUnEmpleado(empleados, NOMINA)==-1)
					{
						printf("\nNo se realizo ninguna modificacion a ningun empleado\n");
					}

				break;

				case 3:
					if(BuscarEmpleadoParaRemoverlo(empleados, NOMINA) == -1)
					{
						printf("\nNingun empleado ha sido dado de baja\n");
					}
				break;

				case 4:
					if(InformarListadosDeEmpleadosSegunEleccion(empleados, NOMINA) == -1)
					{
						printf("\nNo se pudo ordenar la lista");
					}
				break;

				case 5:
				printf("\nUsted salio del programa");
				break;

				case 6:
					printf("\nDebe dar de alta por lo menos a un empleado\n");
			}

	}while(respuesta != 5);

	return EXIT_SUCCESS;
}

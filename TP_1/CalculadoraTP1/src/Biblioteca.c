/*
 * Biblioteca.c
 *
 *  Created on: 23 sep. 2021
 *      Author: Eliana
 */
#include "Biblioteca.h"

int MenuPrincipal(float numero1, float numero2)
{
	int opcion;
	int respuesta;
	printf("\n1. Ingresar 1er operando (A= %.2f)\n", numero1);
	printf("2. Ingresar 2do operando (B= %.2f)\n", numero2);
	printf("3. Calcular todas las operaciones\n"
			"\t a) Calcular la suma (A+B)\n"
			"\t b) Calcular la resta (A-B)\n"
			"\t c) Calcular la division (A/B)\n"
			"\t d) Calcular la multiplicacion (A*B)\n"
			"\t e) Calcular los factoriales (A! y B!)\n");
	printf("4. Informar resultados\n");
	printf("5. Salir\n");

	respuesta=PedirEntero(&opcion, "\nIngrese la opcion del menu: ", "\nLa opcion no esta dentro del menu.", 1, 5, 2);

	if(respuesta!=0)
	{
		printf("\nError");
	}

	return opcion;
}

int PedirEntero(int* pResultado, char mensaje[], char mensajeError[],int minimo,int maximo,int reintentos)
{

	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%d", &bufferInt);
			if(bufferInt>=minimo && bufferInt<=maximo)
			{
				*pResultado=bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}

		}while(reintentos >= 0);

	}

	return retorno;
}

float PedirDecimal(char mensaje[])
{
	float numero;
	if(mensaje!=NULL)
	{

		printf("%s", mensaje);
		scanf("%f",&numero);
	}

	return numero;
}

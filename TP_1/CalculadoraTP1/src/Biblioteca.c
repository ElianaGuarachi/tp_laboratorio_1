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
	printf("\n1. Ingresar 1er operando (A= %.2f)\n", numero1);
	printf("2. Ingresar 2do operando (B= %.2f)\n", numero2);
	printf("3. Calcular todas las operaciones\n");
	printf("4. Informar resultados\n");
	printf("5. Salir\n");

	opcion=PedirEntero("\nIngrese una opcion del menú: ");

	return opcion;
}

int PedirEntero(char mensaje[])
{

	int numero;
	printf("%s", mensaje);
	scanf("%d", &numero);
	return numero;
}

float PedirDecimal(char mensaje[])
{

	float numero;
	printf("%s", mensaje);
	scanf("%f",&numero);

	return numero;
}

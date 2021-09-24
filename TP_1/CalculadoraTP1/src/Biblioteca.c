/*
 * Biblioteca.c
 *
 *  Created on: 23 sep. 2021
 *      Author: Eliana
 */
#include "Biblioteca.h"

int MenuPrincipal(int numero1, int numero2)
{
	int opcion;
	printf("\n1. Ingresar 1er operando (A= %d)\n", numero1);
	printf("2. Ingresar 2do operando (B= %d)\n", numero2);
	printf("3. Calcular todas las operaciones\n");
	/*printf("   a) Calcular la suma (A+B)\n");
	printf("   b) Calcular la resta (A-B)\n");
	printf("   c) Calcular la division (A/B)\n");
	printf("   d) Calcular la multiplicacion (A*B)\n");
	printf("   e) Calcular el factorial (A! y B!)\n");*/
	printf("4. Informar resultados\n");
	printf("5. Salir\n");

	printf("\nIngrese una opcion del menú: ");
	scanf("%d", &opcion);

	return opcion;
}

int PedirEntero(char mensaje[])
{

	int numero;
	printf("%s", mensaje);
	scanf("%d",&numero);

	//validar?

	return numero;
}

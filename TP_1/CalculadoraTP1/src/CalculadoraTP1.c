/*
 ============================================================================
 Name        : CalculadoraTP1.c
 Author      : Eliana Guarachi Sarzuri
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include "Biblioteca.h"
#include "Operaciones.h"


int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int num1;
	int num2;
	int resta;
	int suma;
	long long int multiplicacion;
	float division;
	int respuestaDivision;
	double factorialA;
	double factorialB;
	num1=0;
	num2=0;

	do
	{

		opcion=MenuPrincipal(num1, num2);
		switch(opcion)
		{
			case 1:
				num1=PedirEntero("\nIngrese operando A: ");
				break;

			case 2:
				num2=PedirEntero("\nIngrese operando B: ");
				break;

			case 3:
				suma=Suma(num1, num2);
				resta=Resta(num1, num2);
				respuestaDivision=Division(&division, num1, num2);
				multiplicacion=Multiplicacion(num1, num2);
				factorialA=CalcularFactorial(num1);
				factorialB=CalcularFactorial(num2);
				printf("\nLas operaciones se realizaron con exito.\n");
				break;

			case 4:
				printf("\na) El resultado de A+B es: %d\n", suma);
				printf("b) El resultado de A-B es: %d\n", resta);
				if(respuestaDivision==0)
				{
					printf("c) El resultado de A/B es: %.2f\n", division);
				}
				else
				{
					printf("c)No es posible dividir por cero\n");
				}
				printf("d) El resultado de A*B es: %I64d\n", multiplicacion);
				if(num1>-1)
				{
					printf("e) El factorial de A es: %.0f", factorialA);
				}
				else
				{
					printf("e) El factorial de A es: - %.0f", factorialA);
				}
				if(num2>-1)
				{
					printf(" y el factorial de B es: %.0f\n", factorialB);
				}
				else
				{
					printf(" y el factorial de B es: - %.0f\n", factorialB);
				}

				break;

			case 5:
				printf("\nUsted salio del programa");
				break;

			default:
				printf("\nSeleccione una opcion del menu");
		}
	}while(opcion!=5);


	return EXIT_SUCCESS;
}

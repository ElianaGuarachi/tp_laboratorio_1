/*
 ============================================================================
 Name        : CalculadoraTP1.c
 Author      : Eliana Guarachi Sarzuri
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Biblioteca.h"
#include "Operaciones.h"
#define TAM 30

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int respuesta;
	float num1;
	float num2;
	float resta;
	float suma;
	double multiplicacion;
	float division;
	int respuestaDivision;
	double factorialA;
	double factorialB;
	int x;
	int y;
	num1=0;
	num2=0;

	do
	{
		opcion=MenuPrincipal(num1, num2);
		switch(opcion)
		{
			case 1:
				respuesta = VerificarNumero(&num1, 2);
				if(respuesta)
				{
					printf("\nDevuelta al menu principal");
				}
				break;

			case 2:
				respuesta = VerificarNumero(&num2, 2);
				if(respuesta)
				{
					printf("\nDevuelta al menu principal");
				}
				break;

			case 3:
				suma=Suma(num1, num2);
				resta=Resta(num1, num2);
				respuestaDivision=Division(&division, num1, num2);
				multiplicacion=Multiplicacion(num1, num2);
				x = num1;
				y = num2;
				if(x>-1)
				{
					factorialA=CalcularFactorial(x);
				}
				else
				{
					x=x*(-1);
					factorialA=CalcularFactorial(x);
				}
				if(y>0)
				{
					factorialB=CalcularFactorial(y);
				}
				else
				{
					y=y*(-1);
					factorialB=CalcularFactorial(y);
				}

				printf("\nLas operaciones se realizaron con exito.\n");
				break;

			case 4:
				printf("\na) El resultado de A+B es: %.2f", suma);
				printf("\nb) El resultado de A-B es: %.2f", resta);
				if(respuestaDivision == 0)
				{
					printf("\nc) El resultado de A/B es: %.2f", division);
				}
				else
				{
					printf("\nc) No se puede dividir por cero");
				}
				printf("\nd) El resultado de A*B es: %.2f", multiplicacion);

				//Factorial (la calcula cientifica resuelve en numeros enteros negativo o positivos)
				if((x==num1 && y==num2) || (x*-1==num1 && y==num2) || (x==num1 && y*-1==num2) || (x*-1==num1 && y*-1==num2))
				{
					printf("\ne) El factorial de A es: (+/-)%.0f y El factorial de B es: (+/-)%.0f\n", factorialA, factorialB);
				}
				else
				{
					if((x==num1 && y*-1>num2) || (x*-1==num1 && y<num2) || (x*-1==num1 && y*-1>num2) || (x==num1 && y<num2))
					{
						printf("\ne) El factorial de A es: (+/-)%.0f y El factorial de B no se puede realizar porque es decimal\n", factorialA);
					}
					else
					{
						if((y==num2 && x<num1) || (y*-1==num2 && x*-1>num1) || (y==num2 && x*-1>num1) || (y*-1==num2 && x<num1))
						{
							printf("\ne) El factorial de A no se puede realizar porque es decimal y El factorial de B es:  (+/-)%.0f\n", factorialB);
						}
						else
						{
							printf("\ne) No se puede realizar el factorial en numeros decimales\n");
						}
					}

				}
				break;

			case 5:
				printf("\nUsted salio del programa");
				break;

		}
	}while(opcion!=5);


	return EXIT_SUCCESS;
}

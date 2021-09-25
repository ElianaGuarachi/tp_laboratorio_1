
#include "Operaciones.h"

float Suma(float numero1, float numero2)
{
	float resultado;

	resultado= numero1 + numero2;

	return resultado;
}

float Resta(float numero1, float numero2)
{
	float resultado;

	resultado = numero1 - numero2;

	return resultado;
}

double Multiplicacion(float numero1, float numero2)
{
	double resultado;

	resultado= (double)numero1 * numero2;

	return resultado;
}

int Division(float* division, float numero1, float numero2)
{
	int respuesta;
	if(numero2 != 0)
	{
		*division= numero1/numero2;
		respuesta=0;
	}
	else
	{
		respuesta=1;
	}

	return respuesta;
}

double CalcularFactorial(int numero)
{

	double resultado;

	if(numero==0)
	{
		resultado = 1;
	}
	else
	{

		resultado = numero * CalcularFactorial(numero - 1);

	}


	return resultado;
}



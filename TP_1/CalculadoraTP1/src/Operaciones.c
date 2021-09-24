
#include "Operaciones.h"

int Suma(int numero1, int numero2)
{
	int resultado;

	resultado= numero1 + numero2;

	return resultado;
}

int Resta(int numero1, int numero2)
{
	int resultado;

	resultado = numero1 - numero2;

	return resultado;
}

long long int Multiplicacion(int numero1, int numero2)
{
	long long int resultado;

	resultado= (long long)numero1 * numero2;

	return resultado;
}

int Division(float* division, int numero1, int numero2)
{
	int respuesta;
	if(numero2 != 0)
	{
		*division= (float)numero1/numero2;
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
		if(numero<0)
		{
			numero=numero*(-1);
			resultado = numero * CalcularFactorial(numero - 1);
		}
		else
		{
			resultado = numero * CalcularFactorial(numero - 1);
		}
	}


	return resultado;
}

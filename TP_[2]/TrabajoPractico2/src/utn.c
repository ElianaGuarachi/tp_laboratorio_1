/*
 * utn.c
 *
 *  Created on: 23 sep. 2021
 *      Author: Eliana
 */
#include "utn.h"

static int getString(char* cadena, int longitud);

static int getInt(int* pResultado);
static int esNumerica(char* cadena, int limite);

static int getFloat(float* pResultado);
static int esFlotante(char* cadena, int limite);

//-------------------------------------------------------------------------------------------------

static int getString(char* cadena, int longitud)
{
	int retorno;
	retorno=-1;
	char bufferString[4096]; //se va a modificar

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		//no crashea - no lee mas de 4096 -- lee casi todo incluso \n, menos el \0
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
			}

			if(strnlen(bufferString, sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena, bufferString, longitud);
				retorno=0;
			}
		}
	}

	return retorno;
}

//==============================================================================================================================

int ObtenerEntero( int* pResultado, char mensaje[], char mensajeError[],int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInt; //areas de intercambio

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			if(getInt(&bufferInt) == 0 && bufferInt>=minimo && bufferInt<=maximo)
			{
				*pResultado=bufferInt;
				retorno = 0; //salio ok
				break;//rompe los reintentos con el do while
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;//para que no sea eterno
			}

		}while(reintentos >= 0);//la que me pasan por parametro

	}

	return retorno;
}

static int getInt(int* pResultado)
{
	int retorno;
	char bufferString[50];
	retorno=-1;

	if(pResultado != NULL)
	{
		if(getString(bufferString,sizeof(bufferString)) == 0)
		{
			if(esNumerica(bufferString,sizeof(bufferString)))
			{
				*pResultado = atoi(bufferString);
				retorno=0;
			}
		}
	}

	return retorno;
}

static int esNumerica(char* cadena, int limite)
{

	int retorno;
	int i;
	retorno = 1;
	for(i=0; i< limite && cadena[i] != '\0'; i++)
	{
		if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}

		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno= 0;
			break;
		}
		//Continue
	}
	//break
	return retorno;
}
//=====================================================================================================================

int ObtenerDecimal( float* pResultado,char mensaje[], char mensajeError[], float minimo, float maximo,int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			if(getFloat(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado=bufferFloat;
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

static int getFloat(float* pResultado)
{
	int retorno;
	char buffer[64];
	retorno=-1;

	if(pResultado != NULL)
	{
		if(getString(buffer,sizeof(buffer)) == 0 && esFlotante(buffer,sizeof(buffer)))
		{
				*pResultado = atof(buffer);
				retorno=0;
		}
	}

	return retorno;
}

static int esFlotante(char* cadena, int limite) //modificar
{
	int retorno;
	int contadorPunto;
	int i;
	contadorPunto=0;
	retorno = 1;

	for(i=0; i< limite && cadena[i] != '\0'; i++)
	{
		if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}
		if(cadena[i] == '.')
		{
			contadorPunto++;
			continue;
		}

		if(cadena[i] > '9' || cadena[i] < '0' || contadorPunto > 1)
		{
			retorno= 0;
			break;
		}
		//Continue
	}
	//break
	return retorno;
}
//=========================================================================================================================
int ObtenerCaracterDosOpciones(char* pResultado,char mensaje[], char mensajeError[], char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if(bufferChar == minimo || bufferChar == maximo)
			{
				*pResultado=bufferChar;
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
//====================================================================================================================================

int ObtenerCaracterEntreRango(char* pResultado,char mensaje[], char mensajeError[], char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if(bufferChar >= minimo || bufferChar <= maximo)
			{
				*pResultado=bufferChar;
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

//======================================================================================================================================

int ObtenerCadenaDeCaracteres(char texto[], char mensaje[], char mensajeError[], int tam)
{
	int retorno = 0;

	char bufferString[tam];

	if(texto != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s", mensaje);
			fflush(stdin);
			scanf("%[^\n]", bufferString);
			strcpy(texto, bufferString);

	}
	return retorno;
}





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

static int esPalabra(char cadena[], int limite);

static int esCuitCuil(char cadena[], int limite);

static int esNumerosLetras(char cadena[], int limite);
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

static int esFlotante(char* cadena, int limite)
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
int ObtenerCaracterDosOpciones(char* pResultado,char mensaje[], char mensajeError[], char opcion1, char opcion2, int reintentos)
{
	int retorno = -1;
	char bufferChar;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if(bufferChar == opcion1 || bufferChar == opcion2)
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

int ObtenerPalabras(char texto[], char mensaje[], char mensajeError[], int reintentos)
{
	int retorno = 0;

	char bufferString[51];

	if(texto != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do{
			printf("%s", mensaje);
			fflush(stdin);
			if(getString(bufferString,sizeof(bufferString))==0 && esPalabra(bufferString,sizeof(bufferString)))
			{
				strcpy(texto, bufferString);
				retorno=1;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);


	}
	return retorno;
}

static int esPalabra(char cadena[], int limite)
{
	int retorno=1;
	int i;
	for(i=0; i< limite && cadena[i] != '\0'; i++)
		{
			if((cadena[i] > 64 && cadena [i] < 91) || (cadena[i] > 159 && cadena[i] < 166) || (i!=0 && cadena[i] == 32))
			{
				continue;
			}

			if(cadena[i] < 97 || cadena[i] > 122)
			{
				retorno= 0;
				break;
			}
		}

	return retorno;
}

//==============================================================================================
int FormatearCadena(char cadena[])
{
	int retorno;
	int i;
	int tam;

	retorno = 0;
	strlwr(cadena);
	tam = strlen(cadena);

	if(cadena!=NULL)
	{
		for(i=0;i<tam; i++)
		{
			if(i==0 || cadena[i-1] == 32) //32 = espacio
			{
				cadena[i]=toupper(cadena[i]);
			}
		}

		retorno=1;
	}
	return retorno;
}

//==============================================================================================

int ObtenerCuitCuil(char texto[], char mensaje[], char mensajeError[], int reintentos)
{
	int retorno = 0;

	char bufferString[14];

	if(texto != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do{
			printf("%s", mensaje);
			fflush(stdin);
			if(getString(bufferString,sizeof(bufferString))==0 && esCuitCuil(bufferString,sizeof(bufferString)))
			{
				strcpy(texto, bufferString);
				retorno=1;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);


	}
	return retorno;
}

static int esCuitCuil(char cadena[], int limite)
{
	int retorno=1;
	int i;
	for(i=0; i< limite && cadena[i] != '\0'; i++)
		{
			if((i == 2 || i== 11) && cadena[i] == '-')
			{
				continue;
			}

			if((cadena[i] > '9' || cadena[i] < '0') || ((i==2 || i==11) && cadena[i] != '-') || strlen(cadena) > 13)
			{
				retorno= 0;
				break;
			}
		}

	return retorno;
}

//===============================================================================================
int ObtenerNumerosLetras(char texto[], char mensaje[], char mensajeError[], int reintentos)
{
	int retorno = 0;

	char bufferString[100];

	if(texto != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%[^\n]", bufferString);
			if(esNumerosLetras(bufferString,sizeof(bufferString)))
			{
				strcpy(texto, bufferString);
				retorno=1;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);


	}
	return retorno;
}

static int esNumerosLetras(char cadena[], int limite)
{
	int retorno=1;
	int i;
	for(i=0; i< limite && cadena[i] != '\0'; i++)
		{
			if((cadena[i] > 64 && cadena [i] < 91) ||
				(cadena[i] > 159 && cadena[i] < 166) ||
				(i!=0 && cadena[i] == 32) ||
				(cadena[i]> 47 && cadena[i]<58))
			{
				continue;
			}

			if(cadena[i] < 97 || cadena[i] > 122)
			{
				retorno= 0;
				break;
			}
		}

	return retorno;
}

//============================================================================================

int FormatearCadenaConNumeros(char cadena[])
{
	int retorno;
	int i;
	int tam;

	retorno = 0;

	if(cadena!=NULL)
	{
		strlwr(cadena);
		tam = strlen(cadena);

		for(i=0;i<tam; i++)
		{
			if(i==0 || cadena[i-1] == 32) //32 = espacio
			{
				cadena[i]=toupper(cadena[i]);
			}
			if(cadena[i] > '0' && cadena[i]< '9')
			{
				continue;
			}
		}

		retorno=1;
	}
	return retorno;
}




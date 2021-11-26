#include "Input.h"

int Menu(char opciones[])
{
	int opcion;

	printf("%s", opciones);
	IngresarEntero("\nIngrese una opcion: ", "Ingreso invalido", &opcion, 2);

	return opcion;
}

int IngresarCadena(char cadena[], char mensaje[], char mensajeError[], int tamanio, int reintentos)
{
	int retorno;

	retorno = 1;

	if(cadena!=NULL && mensaje != NULL)
	{
		while(reintentos > 0)
		{
			printf("%s", mensaje);

			if(GetString(cadena, tamanio) == 0)
			{
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}

	}

	return retorno;
}

int GetString(char cadena[], int tamanio)
{
	int retorno;
	char auxiliar[tamanio];

	retorno = 1;

	fflush(stdin);
	fgets(auxiliar, tamanio, stdin);

	if(sonSoloLetras(auxiliar) == 0)
	{
		strtok(auxiliar, "\n");
		strncpy(cadena, auxiliar, tamanio);
		retorno = 0;
	}

	return retorno;
}

//**************************************************************************************************

int IngresarEntero(char mensaje[], char mensajeError[], int*resultado, int reintentos/*, int minimo, int maximo*/)
{
	int retorno;
	int auxiliar;


	retorno = 1;

	if(resultado != NULL && mensaje != NULL && mensajeError != NULL/* && minimo <= maximo*/)
	{
		while(reintentos > 0)
		{
			printf("%s", mensaje);

			if(GetInt(&auxiliar) == 0/* && auxiliar >= minimo && auxiliar <= maximo*/)
			{
				*resultado = auxiliar;
				retorno = 0; //VERDADERO
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}
	}

	return retorno;
}

int GetInt(int* resultado)
{
	int retorno;
	char auxiliar[100];

	retorno = 1; //FALSO

	fflush(stdin);
	fgets(auxiliar, 100, stdin);

	if(EsNumerico(auxiliar) == 0)
	{
		*resultado = atoi(auxiliar);
		retorno = 0; //VERDADERO
	}

	return retorno;
}

//**************************************************************************************************

int IngresarFlotante(char mensaje[], char mensajeError[], float*resultado, int reintentos/*, int minimo, int maximo*/)
{
	int retorno;
	float auxiliar;

	retorno = 1; //FALSO

	if(resultado != NULL && mensaje != NULL && mensajeError != NULL/* && minimo <= maximo*/)
	{
		while(reintentos > 0)
		{
			printf("%s", mensaje);

			if(GetFloat(&auxiliar) == 0/* && auxiliar >= minimo && auxiliar <= maximo*/)
			{
				*resultado = auxiliar;
				retorno = 0; //VERDADERO
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}

	}

	return retorno;
}

int GetFloat(float* resultado)
{
	int retorno;
	char auxiliar[100];

	retorno = -1; //FALSO

	fflush(stdin);
	fgets(auxiliar, 100, stdin);

	if(EsNumerico(auxiliar) == 0)
	{
		*resultado = atof(auxiliar);
		retorno = 0; //VERDADERO
	}

	return retorno;
}

//**********************************************************************************************

int IngresarCadenaNumerica(char cadena[], char mensaje[], char mensajeError[], int tamanio, int reintentos)
{
	int retorno;

	retorno = 1;

	if(cadena!=NULL && mensaje != NULL)
	{
		while(reintentos > 0)
		{
			printf("%s", mensaje);

			if(GetStringNumbers(cadena, tamanio) == 0)
			{
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}

	}

	return retorno;
}

int GetStringNumbers(char cadena[], int tamanio)
{
	int retorno;
	char auxiliar[tamanio];

	retorno = 1;

	fflush(stdin);
	fgets(auxiliar, tamanio, stdin);

	if(EsNumerico(auxiliar) == 0)
	{
		strtok(auxiliar, "\n");
		strncpy(cadena, auxiliar, tamanio);
		retorno = 0;
	}

	return retorno;
}

int EsNumerico(char cadena[])
{
	int i;
	int retorno;

	i = 0;
	retorno = 1;

	while(cadena[i] != '\0')
	{
		if(isdigit(cadena[i]) != 0 || '$' || '.')
		{
			retorno = 0;
		}
		else
	    {
			if(cadena[i] != '\0' && cadena[i] != '\n')
			{
				retorno = 1;
				break;
			}
		}

		i++;
	}

	return retorno;
}

int sonSoloLetras(char cadena[])
{
	int retorno;
	int i;

	retorno = 1;
	i = 0;

	while(cadena[i] != '\0')
	{
		if(isalpha(cadena[i]) != 0 || isspace(cadena[i]) != 0 || '-')
		{
			retorno = 0;
		}
		else
		{
			if(cadena[i] != '\0' && cadena[i] != '\n')
			{
				retorno = 1;
				break;
			}
		}
		i++;
	}

	return retorno;
}

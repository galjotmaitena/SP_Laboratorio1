#include "Editorial.h"
#include "Input.h"


eEditorial* Publisher_New()
{
	eEditorial* pEditorial;

	pEditorial = (eEditorial*)malloc(sizeof(eEditorial));

	if(pEditorial == NULL)
	{
		exit(EXIT_FAILURE) ;
	}

	return pEditorial;
}

eEditorial* Publisher_NewParametros(char* idStr,char* nombreStr)
{
	eEditorial *pEditorial;

	pEditorial = Publisher_New();

	if (pEditorial != NULL && idStr != NULL && nombreStr != NULL)
	{
		if(EsNumerico(idStr) == 0)
		{
			Publisher_SetId(pEditorial, atoi(idStr));
		}
		else
		{
			printf("\nERROR id.");
		}

		if(sonSoloLetras(nombreStr) == 0)
		{
			Publisher_SetNombre(pEditorial, nombreStr);
		}
		else
		{
			printf("\nERROR.");
		}
	}

	return pEditorial;
}

void Publisher_Delete(eEditorial* this)
{
	if(this != NULL)
	{
	    free(this);
	}
}

//************************************************************************

int Publisher_SetId(eEditorial* this,int id)
{
	int retorno;

	retorno = -1;

	if(this != NULL && id > 0)
	{
		this->idEditorial = id;
		retorno = 0;
	}

	return retorno;
}
int Publisher_GetId(eEditorial* this,int* id)
{
	int retorno;

	retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->idEditorial;
		retorno = 0;
	}

	return retorno;
}

//************************************************************************

int Publisher_SetNombre(eEditorial* this,char* nombre)
{
	int retorno;

	retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strncpy(this->nombre, nombre, 128);
		retorno = 0;
	}

	return retorno;
}
int Publisher_GetNombre(eEditorial* this,char* nombre)
{
	int retorno;

	retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre, 128);
		retorno = 0;
	}

	return retorno;
}

//************************************************************************

void Publisher_ValidarArchivo(char* mensaje, char* path)
{
	if(mensaje != NULL && path != NULL)
	{
		do
		{
			IngresarCadena(path, mensaje, "\nIngreso invalido", 128, 2);
		}while(strcmp(path, "editoriales.csv") > 0 || strcmp(path, "editoriales.csv") < 0);
	}
}

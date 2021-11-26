#include "Libros.h"
#include "Input.h"
#include "Editorial.h"

eLibro* Books_New()
{
	eLibro* pLibro;

	pLibro = (eLibro*)malloc(sizeof(eLibro));

	if(pLibro == NULL)
	{
		exit(EXIT_FAILURE);
	}

	return pLibro;
}

eLibro* Books_NewParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr)
{
	eLibro *pLibro;

	pLibro = Books_New();

	if (pLibro != NULL && idStr != NULL && tituloStr != NULL && autorStr != NULL && precioStr != NULL && idEditorialStr != NULL)
	{
		if(EsNumerico(idStr) == 0)
		{
			Books_SetId(pLibro, atoi(idStr));
		}
		else
		{
			printf("\nERROR id.");
		}

		if(sonSoloLetras(tituloStr) == 0)
		{
			Books_SetTitulo(pLibro, tituloStr);
		}
		else
		{
			printf("\nERROR.");
		}

		if(sonSoloLetras(autorStr) == 0)
		{
			Books_SetAutor(pLibro, autorStr);
		}
		else
		{
			printf("\nERROR.");
		}

		if(EsNumerico(precioStr) == 0)
		{
			Books_SetPrecio(pLibro, atof(precioStr));
		}
		else
		{
			printf("\nERROR id.");
		}
			Books_SetIdEditorial(pLibro, atoi(idEditorialStr));
	}

	return pLibro;
}

void Books_Delete(eLibro* this)
{
	if(this != NULL)
	{
	    free(this);
	}
}

//************************************************************************

int Books_SetId(eLibro* this,int id)
{
	int retorno;

	retorno = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
int Books_GetId(eLibro* this,int* id)
{
	int retorno;

	retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

//************************************************************************

int Books_SetTitulo(eLibro* this,char* titulo)
{
	int retorno;

	retorno = -1;

	if(this != NULL && titulo != NULL)
	{
		strncpy(this->titulo, titulo, 128);
		retorno = 0;
	}

	return retorno;
}
int Books_GetTitulo(eLibro* this,char* titulo)
{
	int retorno;

	retorno = -1;

	if(this != NULL && titulo != NULL)
	{
		strncpy(titulo, this->titulo, 128);
		retorno = 0;
	}

	return retorno;
}

//************************************************************************

int Books_SetAutor(eLibro* this,char* autor)
{
	int retorno;

	retorno = -1;

	if(this != NULL && autor != NULL)
	{
		strncpy(this->autor, autor, 128);
		retorno = 0;
	}

	return retorno;
}
int Books_GetAutor(eLibro* this,char* autor)
{
	int retorno;

	retorno = -1;

	if(this != NULL && autor != NULL)
	{
		strncpy(autor, this->autor, 128);
		retorno = 0;
	}

	return retorno;
}

//************************************************************************

int Books_SetPrecio(eLibro* this,float precio)
{
	int retorno;

	retorno = -1;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}
int Books_GetPrecio(eLibro* this,float* precio)
{
	int retorno;

	retorno = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}

//************************************************************************

int Books_SetIdEditorial(eLibro* this,int idEditorial)
{
	int retorno;

	retorno = -1;

	if(this != NULL && idEditorial > 0)
	{
		this->idEditorial = idEditorial;
		retorno = 0;
	}

	return retorno;
}
int Books_GetIdEditorial(eLibro* this,int* idEditorial)
{
	int retorno;

	retorno = -1;

	if(this != NULL && idEditorial != NULL)
	{
		*idEditorial = this->idEditorial;
		retorno = 0;
	}

	return retorno;
}

//************************************************************************

int Books_ImprimirUnLibro(eLibro* unLibro, eEditorial* unaEditorial)
{
	int retorno;
	int id;
	char titulo[128];
	char autor[128];
	float precio;
	char editorial[128];

	retorno = -1;

	if(unLibro != NULL)
	{
		if(Books_GetId(unLibro, &id) == 0 && Books_GetTitulo(unLibro, titulo) == 0 &&
		Books_GetAutor(unLibro, autor) == 0 && Books_GetPrecio(unLibro, &precio) == 0 &&
		Publisher_GetNombre(unaEditorial, editorial) == 0)
		{
			printf("\n%-4d %-45s %-25s %-10.2f %s", id, titulo, autor, precio, editorial);
		}
		else
		{
			printf("\nError");
		}


		retorno = 0;
	}

	return retorno;
}

int Books_CompareByAutor(void* x, void* y)
{
	int compara;
	eLibro* unLibro;
	eLibro* otroLibro;
	char unAutor[128];
	char otroAutor[128];

	if(x != NULL && y != NULL)
	{
		unLibro = (eLibro*)x;
		otroLibro = (eLibro*)y;

		if(Books_GetAutor(unLibro, unAutor) == 0 && Books_GetAutor(otroLibro, otroAutor) == 0)
		{
			compara = strcmp(unAutor, otroAutor);
		}
		else
		{
			printf("\nERROR en la comparacion");
		}

	}

	return compara;
}

int Books_FilterMinotauro(void* unLibro)
{
	int retorno;
	eLibro* auxiliarLibro;
	int idEditorial;

	retorno = 0;

	if(unLibro != NULL)
	{
		auxiliarLibro = (eLibro*)unLibro;

		if(Books_GetIdEditorial(auxiliarLibro, &idEditorial) == 0)
		{
			if(idEditorial == 4)
			{
				retorno = 1;
			}
		}
	}

	return retorno;
}

/** PLANETA: 20% (si el monto es mayor o igual a $300)
  * SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200)*/

void* Books_Map(void* unLibro)
{
	eLibro* auxiliarLibro;
	eLibro* retorno;
	int idEditorial;
	float precioLibro;
	float precioConDescuento;
	float descuento;

	retorno = NULL;

	if(unLibro != NULL)
	{
		auxiliarLibro = (eLibro*)unLibro;

		if(Books_GetIdEditorial(auxiliarLibro, &idEditorial) == 0)
		{
			if(idEditorial == 1 && Books_GetPrecio(auxiliarLibro, &precioLibro) == 0)
			{
				if(precioLibro >= 300)
				{
					descuento = (precioLibro * 20) / 100;
					precioConDescuento = precioLibro - descuento;

					if(Books_SetPrecio(auxiliarLibro, precioConDescuento) == 0)
					{
						retorno = auxiliarLibro;
					}
				}
			}
			else
			{
				if(idEditorial == 2 && Books_GetPrecio(auxiliarLibro, &precioLibro) == 0)
				{
					if(precioLibro <= 200)
					{
						descuento = (precioLibro * 10) / 100;
						precioConDescuento = precioLibro - descuento;

						if(Books_SetPrecio(auxiliarLibro, precioConDescuento) == 0)
						{
							retorno = auxiliarLibro;
						}
					}
				}
			}
		}
	}

	return retorno;
}

//************************************************************************

void Books_ValidarArchivo(char* mensaje, char* path)
{
	if(mensaje != NULL && path != NULL)
	{
		do
		{
			IngresarCadena(path, mensaje, "\nIngreso invalido", 128, 2);
		}while(strcmp(path, "libros.csv") > 0 || strcmp(path, "libros.csv") < 0);
	}
}

#include "Controller.h"
#include "Parser.h"
#include "Libros.h"
#include "Editorial.h"

int Controller_LoadFromText(char* mensaje , LinkedList* pArrayList, int opcion)
{
	FILE* miArchivo;
	int retorno;
	char path[128];

	retorno = 1;

	if(pArrayList != NULL && path != NULL)
	{
		if(opcion == 0)
		{
			Publisher_ValidarArchivo(mensaje, path);
		}
		else
		{
			if(opcion == 1)
			{
				Books_ValidarArchivo(mensaje, path);
			}
		}

		miArchivo = fopen(path, "r");

		if(miArchivo != NULL)
		{
			switch(opcion)
			{
			case 0:
				if(Parser_PublisherFromText(miArchivo, pArrayList) == 0)
				{
					retorno = 0;
				}
				else
				{
					printf("\nNo se pudo parsear correctamente.");
				}
				break;
			case 1:
				if(Parser_BooksFromText(miArchivo, pArrayList) == 0)
				{
					retorno = 0;
				}
				else
				{
					printf("\nNo se pudo parsear correctamente.");
				}
				break;
			}
			fclose(miArchivo);
		}

	}
    return retorno;
}

int Controller_ListBooks(LinkedList* pArrayListBooks, LinkedList* pArrayListEditorial)
{
	int i;
	int len;
	eLibro* auxiliar;
	eEditorial* auxiliarEditorial;
	int retorno;

	retorno = 1;
	auxiliar = NULL;

	if(pArrayListBooks != NULL)
	{
		len = ll_len(pArrayListBooks);

		for(i = 0; i < len; i++)
		{
			auxiliar = (eLibro*)ll_get(pArrayListBooks, i);

			if(auxiliar != NULL)
			{
				auxiliarEditorial = Controller_GetEditorial(auxiliar, pArrayListEditorial);

				if(auxiliarEditorial != NULL)
				{
					Books_ImprimirUnLibro(auxiliar, auxiliarEditorial);
					retorno = 0;
				}
			}
		}
	}
    return retorno;
}

eEditorial* Controller_GetEditorial(eLibro* unLibro, LinkedList* pArrayListEditorial)
{
	eEditorial* retorno;
	eEditorial* unaEditorial;
	int i;
	int len;
	int idEditorial;
	int idEditorialLibro;

	retorno = NULL;

	if(pArrayListEditorial != NULL && unLibro != NULL)
	{
		len = ll_len(pArrayListEditorial);

		for(i = 0; i < len; i++)
		{
			unaEditorial = (eEditorial*)ll_get(pArrayListEditorial, i);

			if(unaEditorial != NULL)
			{
				if(Books_GetIdEditorial(unLibro, &idEditorialLibro) == 0 && Publisher_GetId(unaEditorial, &idEditorial) == 0)
				{
					if(idEditorialLibro == idEditorial)
					{
						retorno = unaEditorial;
					}
				}
			}
		}
	}

	return retorno;
}


int Controller_SortBooks(LinkedList* pArrayListBooks, LinkedList* pArrayListEditorial)
{
	int retorno;
	LinkedList* pListaOrdenada;

	retorno = 1;

	if(pArrayListBooks != NULL)
	{
		pListaOrdenada = ll_clone(pArrayListBooks);

		if(pListaOrdenada != NULL)
		{
			if(ll_sort(pListaOrdenada, Books_CompareByAutor, 1) == 0)
			{
				Controller_ListBooks(pListaOrdenada, pArrayListEditorial);
				retorno = 0;
			}
			else
			{
				printf("\nNo se pudo ordenar");
			}
		}
		else
		{
			printf("\nLista nula.");
		}
	}

	return retorno;
}

int Controller_FilterEditorial(char* path , LinkedList* pArrayList, LinkedList* pArrayListEditorial)
{
	int retorno;
	FILE* miArchivo;
	LinkedList* nuevaLista;

	retorno = 1;

	if(path != NULL && pArrayList != NULL)
	{
		miArchivo = fopen(path, "w");
		nuevaLista = ll_filter(pArrayList, Books_FilterMinotauro);
		if(miArchivo != NULL && nuevaLista != NULL)
		{
			if(Parser_SaveAsText(miArchivo, nuevaLista) == 0)
			{
				Controller_ListBooks(nuevaLista, pArrayListEditorial);
				retorno = 0;
			}
			else
			{
				printf("\nError parser");
			}
			fclose(miArchivo);
		}
	}

	return retorno;
}

int Controller_MapLibros(char* path , LinkedList* pArrayList, LinkedList* pArrayListEditorial)
{
	int retorno;
	FILE* miArchivo;
	LinkedList* nuevaLista;

	retorno = 1;

	if(path != NULL && pArrayList != NULL)
	{
		miArchivo = fopen(path, "w");
		nuevaLista = ll_map(pArrayList, Books_Map);

		if(miArchivo != NULL && nuevaLista != NULL)
		{
			if(Parser_SaveAsText(miArchivo, nuevaLista) == 0)
			{
				Controller_ListBooks(nuevaLista, pArrayListEditorial);
				retorno = 0;
			}
			else
			{
				printf("\nError parser");
			}
			fclose(miArchivo);
		}
	}

	return retorno;
}

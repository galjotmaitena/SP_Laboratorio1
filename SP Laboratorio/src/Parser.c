#include "Parser.h"
#include "Editorial.h"
#include "Libros.h"

int Parser_PublisherFromText(FILE* pFile , LinkedList* pArrayListPublisher)
{
	eEditorial* unaEditorial;
	char id[50];
	char nombre[128];
	int r;
	int retorno;

	retorno = 1;

	if(pArrayListPublisher != NULL)
	{
		if(pFile == NULL)
		{
			printf("El archivo no existe");
			exit(EXIT_FAILURE);
		}

		do
		{
			r = fscanf(pFile, "%[^,], %[^\n]\n", id, nombre);

			if(r == 2)
			{
				unaEditorial = Publisher_NewParametros(id, nombre);

				if(unaEditorial != NULL)
				{
					retorno = ll_add(pArrayListPublisher, unaEditorial);
				}
			}
			else
			{
				printf("ERROR");
				exit(EXIT_FAILURE);
			}
		}while(!feof(pFile));

		retorno = 0;
	}
    return retorno;
}

int Parser_BooksFromText(FILE* pFile , LinkedList* pArrayListBooks)
{
	eLibro* unLibro;
	char id[50];
	char titulo[128];
	char autor[128];
	char precio[50];
	char idEditorial[50];
	int r;
	int retorno;

	retorno = 1;

	if(pArrayListBooks != NULL)
	{
		if(pFile == NULL)
		{
			printf("El archivo no existe");
			exit(EXIT_FAILURE);
		}

		do
		{
			r = fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n", id, titulo, autor, precio, idEditorial);

			if(r == 5)
			{
				unLibro = Books_NewParametros(id, titulo, autor, precio, idEditorial);

				if(unLibro != NULL)
				{
					retorno = ll_add(pArrayListBooks, unLibro);
				}
			}
			else
			{
				printf("ERROR");
				exit(EXIT_FAILURE);
			}
		}while(!feof(pFile));

		retorno = 0;
	}
    return retorno;
}

int Parser_SaveAsText(FILE* pFile , LinkedList* pArrayList)
{
	eLibro* unLibro;
	int auxiliarId;
	char auxiliarTitulo[128];
	char auxiliarAutor[128];
	float auxiliarPrecio;
	int auxiliarIdEditorial;
	int retorno;
	int len;
	int i;

	retorno = 1;

	if(pFile != NULL && pArrayList != NULL)
	{
		len = ll_len(pArrayList);

		for(i = 0; i < len; i++)
		{
			unLibro = (eLibro*)ll_get(pArrayList, i);

			if(Books_GetId(unLibro, &auxiliarId) == 0 && Books_GetTitulo(unLibro, auxiliarTitulo) == 0 &&
			Books_GetAutor(unLibro, auxiliarAutor) == 0 && Books_GetPrecio(unLibro, &auxiliarPrecio)  == 0 &&
			Books_GetIdEditorial(unLibro, &auxiliarIdEditorial) == 0)
			{
				fprintf(pFile, "\n%d, %s, %s, %.2f, %d", auxiliarId, auxiliarTitulo, auxiliarAutor, auxiliarPrecio, auxiliarIdEditorial);

				retorno = 0;
			}
		}
	}
	return retorno;
}

/*
 ============================================================================
Galjot Maitena divB
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Input.h"

int main(void) {
	setbuf(stdout, NULL);

	LinkedList* listaEditoiales;
	LinkedList* listaLibros;
	int opcion;
	int flagLibros;
	int flagEditoriales;

	listaEditoiales = ll_newLinkedList();
	listaLibros = ll_newLinkedList();

	flagLibros = 0;
	flagEditoriales = 0;

	do
	{
		opcion = Menu("\n\n1. Cargar libros."
						"\n2. Cargar Editoriales."
						"\n3. Ordenar de manera ascendente por autor."
						"\n4. Mostrar libros."
						"\n5. Filtrar por editorial Minotauro."
						"\n6. Mapear"
						"\n7. SALIR");
		switch(opcion)
		{
		case 1:
			if(flagLibros == 0)
			{
				if(Controller_LoadFromText("\nIngrese el nombre del archivo libros.csv: ", listaLibros, 1) == 1)
				{
					printf("ERROR");
				}
				else
				{
					printf("\nFunciono libros");
					flagLibros = 1;
				}
			}
			break;
		case 2:
			if(flagEditoriales == 0)
			{
				if(Controller_LoadFromText("\nIngrese el nombre del archivo editoriales.csv: ", listaEditoiales, 0) == 1)
				{
					printf("ERROR");
				}
				else
				{
					printf("\nFunciono editoriales");
					flagEditoriales = 1;
				}
			}
			break;
		case 3:
			if(flagLibros == 1 && flagEditoriales == 1)
			{
				if(Controller_SortBooks(listaLibros, listaEditoiales) == 1)
				{
					printf("ERROR");
				}
			}
			else
			{
				printf("\nPrimero debe seleccionar la opcion 1 y 2 del menu.");
			}
			break;
		case 4:
			if(flagLibros == 1 && flagEditoriales == 1)
			{
				if(Controller_ListBooks(listaLibros, listaEditoiales) == 1)
				{
					printf("ERROR");
				}
			}
			else
			{
				printf("\nPrimero debe seleccionar la opcion 1 y 2 del menu.");
			}
			break;
		case 5:
			if(flagLibros == 1 && flagEditoriales == 1)
			{
				if(Controller_FilterEditorial("listaFiltrada.csv", listaLibros, listaEditoiales) == 1)
				{
					printf("ERROR");
				}
			}
			else
			{
				printf("\nPrimero debe seleccionar la opcion 1 y 2 del menu.");
			}
			break;
		case 6:
			if(flagLibros == 1 && flagEditoriales == 1)
			{
				if(Controller_MapLibros("mapeado.csv", listaLibros, listaLibros) == 1)
				{
					printf("ERROR");
				}
				else
				{
					printf("FUNCIONO");
				}
			}
			else
			{
				printf("\nPrimero debe seleccionar la opcion 1 y 2 del menu.");
			}

			break;
		case 7:
			printf("\nSALIR");

			if(ll_deleteLinkedList(listaEditoiales) == 0 && ll_deleteLinkedList(listaLibros) == 0)
			{
				printf("\nMemoria liberada");
			}

			break;
		default:
			printf("\nOpcion invalida");
			break;
		}
	}while(opcion != 7);

	return EXIT_SUCCESS;
}

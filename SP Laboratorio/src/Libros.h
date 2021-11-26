/*
 * Libros.h
 *
 *  Created on: 22 nov 2021
 *      Author: EXOSMART
 */

#ifndef LIBROS_H_
#define LIBROS_H_
#include "Editorial.h"

typedef struct
{
	int id;
	char titulo[128];
	char autor[128];
	float precio;
	int idEditorial;
}eLibro;

/// \fn eLibro Books_New*()
/// \brief reserva un espacion en memoria dinamica
/// \return retorna un puntero a eLibro, si no funciono este puntero sera NULL
eLibro* Books_New();
/// \fn eLibro Books_NewParametros*(char*, char*, char*, char*, char*)
/// \brief crea un puntero eLibro y le carga cada uno de los datos
/// \param idStr id del libro
/// \param tituloStr titulo del libro
/// \param autorStr autor del libro
/// \param precioStr precio del libro
/// \param idEditorialStr id de la editorial del libro
/// \return retorna un puntero a eLibro, si no funciono este puntero sera NULL
eLibro* Books_NewParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr);
/// \fn void Books_Delete(eLibro*)
/// \brief libera el espacio de memoria
/// \param this espacio a memoria a ser liberado
void Books_Delete(eLibro* this);

/// \fn int Books_SetId(eLibro*, int)
/// \brief asigna un id a al puntero recivido por parametro
/// \param this puntero eLibro
/// \param id id a asignar
/// \return retorna 0 si salio todo bien o 1 si el puntero es nulo
int Books_SetId(eLibro* this,int id);
/// \fn int Books_GetId(eLibro*, int*)
/// \brief recive un puntero en el cual escribira el valor del id
/// \param this puntero a eLibro, del cual se obtendra el id
/// \param id puntero en el que se escribira el valor del id
/// \return retorna 0 si salio todo bien o 1 si los punteros son nulos
int Books_GetId(eLibro* this,int* id);

/// \fn int Books_SetTitulo(eLibro*, char*)
/// \brief asigna un titulo a al puntero recivido por parametro
/// \param this puntero eLibro
/// \param nombre noombre a asignar
/// \return retorna 0 si salio todo bien o 1 si el puntero es nulo
int Books_SetTitulo(eLibro* this,char* nombre);
/// \fn int Books_GetTitulo(eLibro*, char*)
/// \brief recive un puntero en el cual escribira el titulo del libro
/// \param this puntero a eLibro, del cual se obtendra el titulo
/// \param nombre puntero en el que se escribira el  nombre
/// \return retorna 0 si salio todo bien o 1 si los punteros son nulos
int Books_GetTitulo(eLibro* this,char* nombre);

/// \fn int Books_SetAutor(eLibro*, char*)
/// \brief asigna un autor al puntero recivido por parametro
/// \param this puntero eLibro
/// \param autor autor a asignar
/// \return retorna 0 si salio todo bien o 1 si el puntero es nulo
int Books_SetAutor(eLibro* this,char* autor);
/// \fn int Books_GetAutor(eLibro*, char*)
/// \brief recive un puntero en el cual escribira el autor del libro
/// \param this puntero a eLibro, del cual se obtendra el autor
/// \param autor puntero en el que se escribira el  autor
/// \return retorna 0 si salio todo bien o 1 si los punteros son nulos
int Books_GetAutor(eLibro* this,char* autor);

/// \fn int Books_SetPrecio(eLibro*, float)
/// \brief asigna un precio al puntero recivido por parametro
/// \param this puntero eLibro
/// \param precio precio a asignar
/// \return retorna 0 si salio todo bien o 1 si el puntero es nulo
int Books_SetPrecio(eLibro* this,float precio);
/// \fn int Books_GetPrecio(eLibro*, float*)
/// \brief recive un puntero en el cual escribira el precio del libro
/// \param this puntero a eLibro, del cual se obtendra el precio
/// \param precio puntero en el que se escribira el  precio
/// \return retorna 0 si salio todo bien o 1 si los punteros son nulos
int Books_GetPrecio(eLibro* this,float* precio);

/// \fn int Books_SetIdEditorial(eLibro*, int)
/// \brief asigna un id de la editorial al puntero recivido por parametro
/// \param this puntero eLibro
/// \param idEditorial  id de editorial a asignar
/// \return retorna 0 si salio todo bien o 1 si el puntero es nulo
int Books_SetIdEditorial(eLibro* this,int idEditorial);
/// \fn int Books_GetIdEditorial(eLibro*, int*)
/// \brief recive un puntero en el cual escribira el id de la editorial del libro
/// \param this puntero a eLibro, del cual se obtendra el id de la editorial
/// \param idEditorial puntero en el que se escribira el  id de la editorial
/// \return retorna 0 si salio todo bien o 1 si los punteros son nulos
int Books_GetIdEditorial(eLibro* this,int* idEditorial);

/// \fn int Books_ImprimirUnLibro(eLibro*, eEditorial*)
/// \brief Muestra un solo libro
/// \param unLibro Libro a mostrar
/// \param unaEditorial Editorial de la que se mostrara solo su descripcion
/// \return retorna 0 si se pudo mostrar o -1 si los punterosson nulos y fallaronlos getters
int Books_ImprimirUnLibro(eLibro* unLibro, eEditorial* unaEditorial);

/// \fn int Books_CompareByAutor(void*, void*)
/// \brief compara los libros por autores
/// \param x uno de los puntros a void de los cuales de hara un unboxing de un libro
/// \param y otro de los puntros a void de los cuales de hara un unboxing de otro libro
/// \return 0 si son iguales, -1 si el primero es menor que el segundo alfabeticamente,1 si el primero es mayor
int Books_CompareByAutor(void* x, void* y);

/// \fn int Books_FilterMinotauro(void*)
/// \brief filtra los libros con la condicion de que la editorial sea minotauro (4)
/// \param unLibro libro del que se evaluara la editorial
/// \return retorna 1 si cumple la condicion o 0 si el puntero es nulo o no cumple la condicion
int Books_FilterMinotauro(void* unLibro);

/// \fn void Books_ValidarArchivo(char*, char*)
/// \brief Valida el nombre del archivo que escribira el usuario
/// \param mensaje Mensaje que le indica al usuario que nombre de archivo ingresar
/// \param path cadena donde se guardara el nombre del archivo
void Books_ValidarArchivo(char* mensaje, char* path);

/// \fn void Books_Map*(void*)
/// \brief Busca los libros que sean de una editorial en particular, y dependiendo de esta se le realiza un descuento en el precio
/// \param unLibro libro del que verificara la editorial, para ver si aplica al descuento
void* Books_Map(void* unLibro);

#endif /* LIBROS_H_ */

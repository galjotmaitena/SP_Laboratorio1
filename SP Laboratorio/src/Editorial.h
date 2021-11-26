#include <stdio.h>
#include <stdlib.h>
#ifndef EDITORIAL_H_
#define EDITORIAL_H_


typedef struct
{
	int idEditorial;
	char nombre[128];
}eEditorial;

/// \fn eEditorial Publisher_New*()
/// \brief reserva un espacion en memoria dinamica
/// \return retorna un puntero a eLibro, si no funciono este puntero sera NULL
eEditorial* Publisher_New();
/// \fn eEditorial Publisher_NewParametros*(char*, char*)
/// \brief crea un puntero eEditorial y le carga cada uno de los datos
/// \param idStr id de la editorial
/// \param nombreStr nombre de la editorial
/// \return retorna un puntero a eEditorial, si no funciono este puntero sera NULL
eEditorial* Publisher_NewParametros(char* idStr,char* nombreStr);
/// \fn void Publisher_Delete(eEditorial*)
/// \brief libera el espacio de memoria
/// \param this espacio a memoria a ser liberado
void Publisher_Delete(eEditorial* this);

/// \fn int Publisher_SetId(eEditorial*, int)
/// \brief asigna un id a al puntero recivido por parametro
/// \param this puntero eEditorial
/// \param id id a asignar
/// \return retorna 0 si salio todo bien o 1 si el puntero es nulo
int Publisher_SetId(eEditorial* this,int id);
/// \fn int Publisher_GetId(eEditorial*, int*)
/// \brief recive un puntero en el cual escribira el valor del id
/// \param this puntero a eEditorial, del cual se obtendra el id
/// \param id puntero en el que se escribira el valor del id
/// \return retorna 0 si salio todo bien o 1 si los punteros son nulos
int Publisher_GetId(eEditorial* this,int* id);

/// \fn int Publisher_SetNombre(eEditorial*, char*)
/// \brief asigna un nombre a al puntero recivido por parametro
/// \param this puntero eEditorial
/// \param nombre nombre a asignar
/// \return retorna 0 si salio todo bien o 1 si el puntero es nulo
int Publisher_SetNombre(eEditorial* this,char* nombre);
/// \fn int Publisher_GetNombre(eEditorial*, char*)
/// \brief recive un puntero en el cual escribira el valor del nombre
/// \param this puntero a eEditorial, del cual se obtendra el nombre
/// \param nombre puntero en el que se escribira el valor del nombre
/// \return retorna 0 si salio todo bien o 1 si los punteros son nulos
int Publisher_GetNombre(eEditorial* this,char* nombre);

/// \fn void Publisher_ValidarArchivo(char*, char*)
/// \brief Valida el nombre del archivo que escribira el usuario
/// \param mensaje Mensaje que le indica al usuario que nombre de archivo ingresar
/// \param path cadena donde se guardara el nombre del archivo
void Publisher_ValidarArchivo(char* mensaje, char* path);
#endif /* EDITORIAL_H_ */

/*
 * Controller.h
 *
 *  Created on: 22 nov 2021
 *      Author: EXOSMART
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"
#include "Libros.h"
#include "Input.h"

/// \fn int controller_LoadFromText(char*, LinkedList*, int)
/// \brief Carga los datos de las listas desde los archivos libros.csv y editoriales.csv (modo texto).
/// \param mensaje mensaje que indica el nombre del archivo a leer
/// \param pArrayListPublisher  lista que luego se enviara al parser
/// \param opcion 0 si es el archivo de editoriales o 1 si es el de libros
/// \return retorna 0 si esta todo ok o 1 si la lista o el parser son nulos o si no se pudo parsear
int Controller_LoadFromText(char* mensaje , LinkedList* pArrayList, int opcion);

/// \fn int controller_ListBooks(LinkedList*, LinkedList*)
/// \brief Enlista los libros
/// \param pArrayListBooks lista de libros
/// \param pArrayListEditorial lista de editoriales
/// \return retorna 0 si salio todo ok o 1 si las listas son nulas o no se pudo mostrar
int Controller_ListBooks(LinkedList* pArrayListBooks, LinkedList* pArrayListEditorial);

/// \fn eEditorial controller_GetEditorial*(eLibro*, LinkedList*)
/// \brief busca la editorial del libro enviado por parametro
/// \param unLibro  libro del que se buscara la editorial
/// \param pArrayListEditorial lista de editoriales a recorrer
/// \return retorna una editorial o NULL
eEditorial* Controller_GetEditorial(eLibro* unLibro, LinkedList* pArrayListEditorial);

/// \fn int controller_SortBooks(LinkedList*, LinkedList*)
/// \brief Ordena la lista
/// \param pArrayListBooks lista de libros
/// \param pArrayListEditorial lista de editoriales
/// \return retorna 0 si se pudo ordenar y 1 si las listas son nulas o fallo el ordenamiento
int Controller_SortBooks(LinkedList* pArrayListBooks, LinkedList* pArrayListEditorial);

/// \fn int controller_FilterEditorial(char*, LinkedList*, LinkedList*)
/// \brief filtra la lista y luego crea un nuevo .csv con la lista ya filtrada
/// \param path direccion donde se encontrara el nuevo archivo
/// \param pArrayList lista de libros
/// \param pArrayListEditorial lista de editoriales
/// \return retorna 0 si se pudo crear el nuevo archivo y 1 si las listas o el path fueron nulos
int Controller_FilterEditorial(char* path , LinkedList* pArrayList, LinkedList* pArrayListEditorial);

int Controller_MapLibros(char* path , LinkedList* pArrayList, LinkedList* pArrayListEditorial);

#endif /* CONTROLLER_H_ */

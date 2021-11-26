#include <stdio.h>
#include <stdlib.h>
#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"

/// \fn int Parser_PublisherFromText(FILE*, LinkedList*)
/// \brief Parsea los datos los datos de editoriales desde el archivo editoriaes.csv (modo texto).
/// \param pFile archivo a parsear
/// \param pArrayListPublisher lista de editoriales
/// \return retorna 0 si se pudo parsear o 1 si la lista es nula o fallo el parseado
int Parser_PublisherFromText(FILE* pFile , LinkedList* pArrayListPublisher);

/// \fn int Parser_BooksFromText(FILE*, LinkedList*)
/// \brief Parsea los datos los datos de libros desde el archivo libros.csv (modo texto).
/// \param pFile archivo a parsear
/// \param pArrayListBooks lista de libros
/// \return retorna 0 si se pudo parsear o 1 si la lista es nula o fallo el parseado
int Parser_BooksFromText(FILE* pFile , LinkedList* pArrayListBooks);

/// \fn int Parser_SaveAsText(FILE*, LinkedList*)
/// \brief
/// \param pFile
/// \param pArrayList
/// \return
int Parser_SaveAsText(FILE* pFile , LinkedList* pArrayList);

#endif /* PARSER_H_ */

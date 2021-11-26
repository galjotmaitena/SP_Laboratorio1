#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#ifndef INPUT_H_
#define INPUT_H_

/// \fn int Menu(char[])
/// \brief Muestra un menu de opciones, del cual debemos seleccionar una y la retorna
/// \param opciones Las opciones que se mostraran
/// \return Retorna la opcion elegida
int Menu(char opciones[]);

/// \fn int IngresarCadena(char[], char[], char[], int, int)
/// \brief Pide el ingreso de una cadena de caracteres, y la valida antes de guardarla
/// \param cadena array donde se guardara el string ingresado
/// \param mensaje mensaje que sera mostrado para pedir el dato solicitado
/// \param mensajeError mensaje que sera mostrado en caso de que haya un error en el ingreso
/// \param tamanio tamanio del array de caracteres
/// \param reintentos la cantidad de veces que el usuario podra reintentarlo
/// \return retorna (1) si el ingreso fue invalido o (0) si fue exitoso
int IngresarCadena(char cadena[], char mensaje[], char mensajeError[], int tamanio, int reintentos);
/// \fn int GetString(char[], int)
/// \brief guarda la cadena y valida que se hayan ingresado solo letras
/// \param cadena cadena que se validara
/// \param tamanio el tamanio de dicha cadena
/// \return retorna (1) si hubo un error o (0) si la validacion fue exitosa
int GetString(char cadena[], int tamanio);

/// \fn int IngresarEntero(char[], char[], int*, int)
/// \brief pide el ingreso de un entero, lo valida y lo devuelve por parametro
/// \param mensaje mensaje que sera mostrado para pedir el dato solicitado
/// \param mensajeError mensaje que sera mostrado en caso de que haya un error en el ingreso
/// \param resultado direccion de memoria en la que se guardara el dato ingresado
/// \param reintentos la cantidad de veces que el usuario podra reintentarlo
/// \return retorna (1) si el ingreso fue invalido o (0) si fue exitoso
int IngresarEntero(char mensaje[], char mensajeError[], int*resultado, int reintentos);
/// \fn int GetInt(int*)
/// \brief guarda el string ingresado, lo valida y si la validacion es exitosa lo transforma a un dato de tipo int
/// \param resultado direccion de memoria donde se guardara el dato de tipo int
/// \return retorna (1) si hubo un error o (0) si la validacion fue exitosa
int GetInt(int* resultado);

/// \fn int IngresarFlotante(char[], char[], float*, int)
/// \brief pide el ingreso de un flotante, lo valida y lo devuelve por parametro
/// \param mensaje mensaje que sera mostrado para pedir el dato solicitado
/// \param mensajeError mensaje que sera mostrado en caso de que haya un error en el ingreso
/// \param resultado direccion de memoria en la que se guardara el dato ingresado
/// \param reintentos la cantidad de veces que el usuario podra reintentarlo
/// \return retorna (1) si el ingreso fue invalido o (0) si fue exitoso
int IngresarFlotante(char mensaje[], char mensajeError[], float*resultado, int reintentos);
/// \fn int GetFloat(float*)
/// \brief guarda el string ingresado, lo valida y si la validacion es exitosa lo transforma a un dato de tipo float
/// \param resultado direccion de memoria donde se guardara el dato de tipo int
/// \return retorna (1) si hubo un error o (0) si la validacion fue exitosa
int GetFloat(float* resultado);

/// \fn int EsNumerico(char[])
/// \brief valida que la cadena solo tenga caracteres numericos
/// \param cadena cadena que se recorrera y validara
/// \return retorna (1) si encontro caracteres no numericos o (0) si solo encontro numeros, es decir si fue exitosa
int EsNumerico(char cadena[]);
/// \fn int sonSoloLetras(char[])
/// \brief valida que la cadena solo tenga letras
/// \param cadena cadena que se recorrera y validara
/// \return retorna (1) si encontro caracteres numericos o (0) si solo encontro solo letras, es decir si fue exitosa
int sonSoloLetras(char cadena[]);

int IngresarCadenaNumerica(char cadena[], char mensaje[], char mensajeError[], int tamanio, int reintentos);
int GetStringNumbers(char cadena[], int tamanio);

#endif /* INPUT_H_ */

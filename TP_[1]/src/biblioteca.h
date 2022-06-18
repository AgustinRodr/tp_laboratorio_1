/*
 * biblioteca.h
 *
 *  Created on: 16 abr. 2022
 *      Author: invitadopc
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

/// @brief solicita un numero al usuario y lo valida;
///
/// @param pNumeroIngresado Puntero(direccion de memoria) donde se carga el numero;
/// @param mensaje Es el mensaje a ser mostrado;
/// @param mensajeError Es el mensaje de error a ser mostrado;
/// @param maximo	Limite mayor a validar;
/// @param minimo	limite menor a validar;
/// @param maximoDeReintentos maximo de reintentos que le doy al usuario;
/// @return si obtuvo el numero [0] si no [-1];
///
void mostrar();

int tomarUnEntero(int *punteroNumeroIngresado,int maximo,int minimo,char * mensajeLimites,char * mensajeError ,int contadorDeIntentos);

int tomarUnFlotante(float *punteroNumeroIngresado, float maximo,float minimo,char * mensajeLimites,char * mensajeError ,int contadorDeIntentos);

int tomarUnEnteroSinMaximo(int *punteroNumeroIngresado,int minimo,char * mensajeLimites,char * mensajeError ,int contadorDeIntentos);

int tomarUnFlotanteSinMaximo(float *punteroNumeroIngresado,float minimo,char * mensajeLimites,char * mensajeError ,int contadorDeIntentos);
#endif /* BIBLIOTECA_H_ */

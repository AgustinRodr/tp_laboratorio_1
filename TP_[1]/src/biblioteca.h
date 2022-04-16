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

int getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,
		int maximo, int minimo, int maximoDeReintentos);

float precioxUnidad(int numero1, int numero2);

float diferencia(int numero1, int numero2);

float descuento(int numero1, int numero2);

float interes(int numero1, int numero2);

float enBitcoin(int numero1, int numero2);

#endif /* BIBLIOTECA_H_ */


#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,
		int maximo, int minimo, int maximoDeReintentos);

int validarLetrasFinal(char cadena[]);

int getString(char* cadena, int longitud);

int getEsString(char cadena[],char mensaje[], char mensajeError[], int reintentos);

int myGets(char* cadena, int len);

int mensaje(char * mensaje);





#endif /* UTN_H_ */

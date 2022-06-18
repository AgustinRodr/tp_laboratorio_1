#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,
		int maximo, int minimo, int maximoDeReintentos){

	int auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%d", &auxNumeroIngresado);
			maximoDeReintentos--;

			if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo){
						*pNumeroIngresado = auxNumeroIngresado;
						retorno = 0;
						break;
			}else{
				printf("%s", mensajeError);
			}

		}while(maximoDeReintentos > 0);
	}

	return retorno;
}

int validarLetrasFinal(char cadena[])
{
    int validacionRetorno = 1;
    int i = 0;
    if(cadena != NULL)
    {
        while(cadena[i] != '\0')
        {
            if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z'))
            {
                validacionRetorno = 0;
                break;
            }
            i++;
        }
    }
    return validacionRetorno;
}

int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

int myGets(char* cadena, int len){
	int retorno;
	retorno =-1;
	if(cadena != NULL && len >0 && fgets(cadena,len,stdin)==cadena){
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n'){
			cadena[strlen(cadena)-1] = '\0';
		}
	retorno=0;
	}

return retorno;
}

int getEsString(char cadena[],char mensaje[], char mensajeError[], int reintentos){
	int retorno = -1;
	char cadenaAux[51];
	if(mensaje != NULL && cadena != NULL && mensajeError != 0 && reintentos > 0){
		do{
		printf("%s", mensaje);
		if (myGets(cadenaAux,sizeof(cadenaAux)) ==0 && esNombre(cadenaAux) == 1){
			strcpy(cadena, cadenaAux);
			retorno = 0;
			break;
		}
		else{
			printf("%s",mensajeError);
			reintentos--;
			retorno = 1;
		}
		}while(reintentos >=0);

	}

	return retorno;
}

int mensaje(char * mensaje){

	printf("%s",mensaje);
	return 0;
}

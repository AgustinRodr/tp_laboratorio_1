
#include <stdio.h>
#include <stdlib.h>

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

void mostrar(){

	printf("1)Ingresar kilometros:\n");
	printf("2)Ingresar precio de vuelo Aerolineas:\n");
	printf("3)Ingresar precio de vuelo Latam\n");
	printf("4)Calcular todos los costos:\n");
	printf("5)Informar resultados\n");
	printf("6)Carga forzada de datos\n");
	printf("7)Salir\n");
}

float precioxUnidad(int numero1, int numero2)
{
    return numero1*numero2;
}

float diferencia(int numero1, int numero2)
{
    return numero1-numero2;
}

float descuento(int numero1, int numero2)
{
    return numero1*numero2;
}

float interes(int numero1, int numero2)
{
    return numero1*numero2;
}

float enBitcoin(int numero1, int numero2)
{
    return numero1/numero2;
}



#include <stdio.h>
#include <stdlib.h>

/// @brief
///
/// @param puntero_del_numero_que_obtendremos
/// @param maximo_numero_que_obtendremos
/// @param minimo_numero_que_obtendremos
/// @param mensaje_informando_los_limites
/// @param mensaje_de_Error
/// @param contadorDeIntentos
/// @return
 int tomarUnEntero(int *punteroNumeroIngresado,int maximo,int minimo,char * mensajeLimites,char * mensajeError ,int contadorDeIntentos){

		int numeroDeSeguridad;
		int retorno;
		retorno= -1;
		if(punteroNumeroIngresado != NULL && maximo >= minimo && minimo <= maximo){
			do{
				printf("%s",mensajeLimites);
				scanf("%d",&numeroDeSeguridad);
			if(numeroDeSeguridad <= maximo && numeroDeSeguridad >= minimo){
				retorno = 0;
				*punteroNumeroIngresado = numeroDeSeguridad;
				break;
			}else{
				contadorDeIntentos = contadorDeIntentos - 1 ;
				printf("%s",mensajeError);
			}

		}while(contadorDeIntentos > 0);

	}
	return retorno;
}

 /// @brief
 ///
 /// @param puntero_del_numero_que_obtendremos
 /// @param maximo_numero_que_obtendremos
 /// @param minimo_numero_que_obtendremos
 /// @param mensajeLimites
 /// @param mensaje_de_Error
 /// @param contadorDeIntentos
 /// @return
int tomarUnFlotante(float *punteroNumeroIngresado, float maximo,float minimo,char * mensajeLimites,char * mensajeError ,int contadorDeIntentos){

		float numeroDeSeguridad;
		int retorno;
		retorno=1;
		if(punteroNumeroIngresado != NULL && maximo >= minimo && minimo <= maximo){
			do{
				printf("%s",mensajeLimites);
				scanf("%f",&numeroDeSeguridad);
			if(numeroDeSeguridad <= maximo && numeroDeSeguridad >= minimo){
				retorno = 0;
				*punteroNumeroIngresado = numeroDeSeguridad;
				break;
			}else{
				contadorDeIntentos = contadorDeIntentos - 1 ;
				printf("%s",mensajeError);
			}

		}while(contadorDeIntentos > 0);

	}
	return retorno;
}

/// @brief
///
/// @param puntero_del_numero_que_obtendremos
/// @param minimo_numero_que_obtendremos
/// @param mensaje_informando_los_limites
/// @param mensaje_de_Error
/// @param contadorDeIntentos
/// @return
int tomarUnEnteroSinMaximo(int *punteroNumeroIngresado,int minimo,char * mensajeLimites,char * mensajeError ,int contadorDeIntentos){

		int numeroDeSeguridad;
		int retorno;
		retorno=1;
		if(punteroNumeroIngresado != NULL){
			do{
				printf("%s",mensajeLimites);
				scanf("%d",&numeroDeSeguridad);
			if(numeroDeSeguridad >= minimo){
				retorno = 0;
				*punteroNumeroIngresado = numeroDeSeguridad;
				break;
			}else{
				contadorDeIntentos = contadorDeIntentos - 1;
				printf("%s",mensajeError);
			}

			}while(contadorDeIntentos > 0);
		}
	return retorno;
}
/// @brief
///
/// @param puntero_del_numero_que_obtendremos
/// @param minimo_numero_que_obtendremos
/// @param mensaje_informando_los_limites
/// @param mensajeError
/// @param contadorDeIntentos
/// @return
int tomarUnFlotanteSinMaximo(float *punteroNumeroIngresado,float minimo,char * mensajeLimites,char * mensajeError ,int contadorDeIntentos){

		float numeroDeSeguridad;
		int retorno;
		retorno= -1;
		if(punteroNumeroIngresado != NULL){
			do{
				printf("%s",mensajeLimites);
				scanf("%f",&numeroDeSeguridad);
			if(numeroDeSeguridad >= minimo){
				retorno = 0;
				*punteroNumeroIngresado = numeroDeSeguridad;
				break;
			}else{
				contadorDeIntentos = contadorDeIntentos - 1;
				printf("%s",mensajeError);
			}
		}while(contadorDeIntentos > 0);
	}
	return retorno;
}

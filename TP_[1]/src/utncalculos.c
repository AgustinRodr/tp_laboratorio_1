#include <stdio.h>
#include <stdlib.h>

/// @brief
///
/// @param puntero_al_resultado
/// @param numero_el_cual_sera_aumentado_o_disminuido
/// @param porsentaje_expresado_en_decimales_de_aumento
/// @return
int calcularAumentoDescuento(float * punteroResultado,float numeroParaAumentar,float porsentajeDeAumentoDescuento){
	int retorno;
	retorno =-1;
	if(punteroResultado != NULL && numeroParaAumentar != 0){
	float numeroDeControl;

	numeroDeControl = numeroParaAumentar + numeroParaAumentar * porsentajeDeAumentoDescuento;

	* punteroResultado = numeroDeControl;

	retorno =0;
	}
	return retorno;
}

/// @brief
///
/// @param puntero_al_resultado
/// @param nuemro_a_dividir
/// @param numero_por_el_cual_se_dividira
/// @return
int convertirDeMonedas(float * punteroResultado,float dividendo,float divisor ){
	int retorno;
	float resultadoAuxiliar;
	retorno =-1;

	if(punteroResultado != NULL && divisor > 0 && dividendo > 0){
		retorno = 0;
		resultadoAuxiliar = dividendo / divisor;
		* punteroResultado = resultadoAuxiliar;

	}
	return  retorno;
}


/// @brief
///
/// @param puntero_al_resultado
/// @param numeroUno
/// @param numeroDos
/// @return
int diferenciador(float * punteroDeResultado,float numeroUno,float numeroDos){
	int retorno;
	retorno = -1;
	float resultadoAuxiliar;
	if(punteroDeResultado != NULL && numeroUno >= 0  && numeroDos >= 0){

		if(numeroUno > numeroDos){

			resultadoAuxiliar = numeroUno - numeroDos;
			* punteroDeResultado = resultadoAuxiliar;
			retorno = 0;

		}
		if(numeroDos > numeroUno){

			resultadoAuxiliar = numeroDos - numeroUno;
			* punteroDeResultado = resultadoAuxiliar;
			retorno = 0;
		}


	}
	return retorno;
}

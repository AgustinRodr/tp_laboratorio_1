/*
 ============================================================================
 Name        : TP_[1].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"


int main(void) {
	setbuf(stdout,NULL);
   int flagCuentas;
   int errores;
   int opcionDelMenu;
   float kilomtrosTotales;
   float precioAerolineas;
   float precioLatam;
   float aerolineasDebito;
   float latamDebito;
   float aerolineasCredito;
   float latamCredito;
   float precioEnBitcoinAerolineas;
   float precioEnBitcoinLatam;
   float precioUnitarioAerolineas;
   float precioUnitarioLatam;
   float diferenciaDePrecio;
   flagCuentas=0;
   errores = 0;
   kilomtrosTotales =0;
   precioAerolineas=0;
   precioLatam=0;


do{
   printf("1. Ingresar Kilometros: (km=%.2f)\n\n",kilomtrosTotales);

   printf("2. ingresar Precio de Vuelos: (Aerolineas=$%.2f, Latam=$%.2f\n)",precioAerolineas,precioLatam);
   printf("-precio vuelo Aerolineas:\n");
   printf("-precio vuelo Latam:\n\n");

   printf("3. Calcular todos los costos : \n");
   printf("a)Tarjeta de debito (descuento 10%) \n");
   printf("b)Tarjeta de credito (interes 25%) \n");
   printf("c)Bitcoin (1BTC->4606954,55 Pesos Argentinos) \n");
   printf("d)mostrar precio por km (precio unitario)  \n");
   printf("e)Mostrar diferencia de precio ingresada (Latam-Aerolineas) \n\n");

   printf("4. Informar resultados  \n");
   if((opcionDelMenu ==4 || opcionDelMenu ==5 ) && flagCuentas == 1){
   printf("KMs Ingresados: %.2fkm  \n",kilomtrosTotales);
   printf("Latam:\n");
   printf("Precio  Latam: $%.2f \n",precioLatam);
   printf("a)Precio  con tarjeta de debito: $%.2f \n",latamDebito);
   printf("b)Precio con tarjeta  de credito: $%.2f \n",latamCredito);
   printf("c)Precio pagando con  bitcoins: %.2f BTC \n",precioEnBitcoinLatam);
   printf("d)Precio unitario: $%.2f \n",precioUnitarioLatam);
   printf("Aerolineas:\n");
   printf("Precio Aerolineas: $%.2f  \n",precioAerolineas);
   printf("a)Precio  con tarjeta de debito: $%.2f \n",aerolineasDebito);
   printf("b)Precio con tarjeta  de credito: $%.2f \n",aerolineasCredito);
   printf("c)Precio pagando con  bitcoins: %.2f BTC \n",precioEnBitcoinAerolineas);
   printf("d)Precio unitario: $%.2f \n",precioUnitarioAerolineas);
   printf("La diferencio de precio es: $%.2f \n\n",diferenciaDePrecio);
  }else{ printf("Latam:\n");
  printf("a)Precio  con tarjeta de debito: \n");
  printf("b)Precio con tarjeta  de credito: \n");
  printf("c)Precio pagando con  bitcoins: \n");
  printf("d)Precio unitario: \n");
  printf("Aerolineas:");
  printf("a)Precio  con tarjeta de debito: \n");
  printf("b)Precio con tarjeta  de credito: \n");
  printf("c)Precio pagando con  bitcoins: \n");
  printf("d)Precio unitario: \n");
  printf("La diferencio de precio es: \n\n");

  }


   printf("5. Carga forzada de datos  \n");
   printf("6. Salir \n");

   errores = tomarUnEntero(&opcionDelMenu,6,1,"ingrese un numero entre 1 y 6, por la opcion del menu a la cual quiera ingresar ","numero ingresado no es valido",3);

   switch(opcionDelMenu){
   case 1 :
	  do{
		  printf("1. Ingresar Kilometros : \n");
		  printf("2 salir : \n");
		  errores = tomarUnEntero(&opcionDelMenu,2,1,"ingrese un numero entre 1 y 2, por la opcion del menu a la cual quiera ingresar ","numero ingresado no es valido",3);
           if(opcionDelMenu == 1){
        	   //toma de kilometros
        	   errores = tomarUnFlotante(&kilomtrosTotales,384400.0,1.0,"ingrese la cantidad de kilometros que quiere recorrer  mayor a 1klm","numero ingresado no es valido",3);
        	   printf("gracias por ingresar los klm a recorer, lo enviaremos nuevamente al menu de inicio  \n");
        	   break;
           }
	   }while(opcionDelMenu != 2);
   break;
   case 2 :

	   do{
	 		//toma de precio
		   printf("1. ingresar Precio de Vuelo por Aerolineas : \n");
	 	   printf("2. ingresar Precio de Vuelo por Latam : \n");
	 	   printf("3 salir : \n");
	 		 errores = tomarUnEntero(&opcionDelMenu,3,1,"ingrese un numero entre 1 y 3, por la opcion del menu a la cual quiera ingresar ","numero ingresado no es valido",3);

	 		 if(opcionDelMenu == 1){

	 			 errores = tomarUnFlotanteSinMaximo(&precioAerolineas,0,"ingresar un precio para Aerolineas superior a 0","precio invalido",3);
                  }
	 		 if(opcionDelMenu == 2){

	 			errores = tomarUnFlotanteSinMaximo(&precioLatam,0,"ingresar un precio para Latam superior a 0","precio invalido",3);
	 		 }
	 	   }while(opcionDelMenu != 3);

      break;
   case 3:
                 //calculo del precio solo si no son 0
	             if(kilomtrosTotales != 0 && precioAerolineas != 0 && precioLatam != 0){
	            	 errores = calcularAumentoDescuento(&aerolineasDebito,precioAerolineas,-0.10);
	            	 errores = calcularAumentoDescuento(&latamDebito,precioLatam,-0.10);
	            	 errores = calcularAumentoDescuento(&aerolineasCredito,precioAerolineas,0.25);
	            	 errores = calcularAumentoDescuento(&latamCredito,precioLatam,0.25);
	            	 errores =  convertirDeMonedas(&precioEnBitcoinAerolineas,precioAerolineas,4606954.55);
	            	 errores =  convertirDeMonedas(&precioEnBitcoinLatam,precioLatam,4606954.55);
	            	 errores =  convertirDeMonedas(&precioUnitarioAerolineas,precioAerolineas,kilomtrosTotales);
	            	 errores =  convertirDeMonedas(&precioUnitarioLatam,precioLatam,kilomtrosTotales);
	            	 errores = diferenciador(&diferenciaDePrecio,precioLatam,precioAerolineas);
	            	 flagCuentas=1;
             }else{
            	 printf("No se ingreso precio a alguno de los vuelos o kilometraje \n");
              }
	 	  break;
   case 4:
                if(kilomtrosTotales == 0 || precioAerolineas == 0 || precioLatam == 0){
	 			printf("No se ingreso precio a alguno de los vuelos o kilometraje se le regresara al menu  \n");
	 			}
      break;
   case 5:
	   kilomtrosTotales = 7090;
	   precioAerolineas = 162965.00;
	   precioLatam =159339;
	   errores = calcularAumentoDescuento(&aerolineasDebito,precioAerolineas,-0.10);
	   errores = calcularAumentoDescuento(&latamDebito,precioLatam,-0.10);
	   errores = calcularAumentoDescuento(&aerolineasCredito,precioAerolineas,0.25);
	   errores = calcularAumentoDescuento(&latamCredito,precioLatam,0.25);
	   errores =  convertirDeMonedas(&precioEnBitcoinAerolineas,precioAerolineas,4606954.55);
	   errores =  convertirDeMonedas(&precioEnBitcoinLatam,precioLatam,4606954.55);
	   errores =  convertirDeMonedas(&precioUnitarioAerolineas,precioAerolineas,kilomtrosTotales);
	   errores =  convertirDeMonedas(&precioUnitarioLatam,precioLatam,kilomtrosTotales);
	   errores = diferenciador(&diferenciaDePrecio,precioLatam,precioAerolineas);
	   flagCuentas=1;
      break;

   	   }

	}while(opcionDelMenu != 6);


	return  0;
}

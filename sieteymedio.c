#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define T  40


int menu();
int main();
void elegirOpcion();


void presentacion(){
printf("**  **   ****   **    **\n");
printf("**  **  **  **  ***  ***\n");
printf("**  **  ******  ** ** **\n");
printf("******  **  **  **    **\n");
printf(" ****   **  **  **    **\n");
printf("SIMULACION DEL JUEGO DEL SIETE Y MEDIO\n");
}


void iniciarbaraja(float N_tarjetas [], char T_tarjetas []){
	//printf("LLenando baraja\n");
	char Figuras[4];
	Figuras[0]='O'; //Oros
	Figuras[1]='C'; //Copas
	Figuras[2]='E'; //Espadas
	Figuras[3]='B'; //Bastos
	int cont=0; // saca los valores del arreglo
	int aux=1; //llena los valores del 1-12

	for(int j=0;j<T;j++){

		if(j%10==0 && j!=0){
			cont++;
		}
		T_tarjetas[j]=Figuras[cont];
	//	printf("%c,%c\n", T_tarjetas[j],Figuras[cont]);
	}

	for(int i=0;i<T;i++){
		
		if(aux>7 && aux<11){
			N_tarjetas[i]=0.5;
		}else{
		N_tarjetas[i]=aux;	
		}
		if(aux==10){
			aux=0;
		}
		aux++;
	}
}

void barajear(float N_tarjetas[], char T_tarjetas[]){
	float aux1;
 	int aux2, aux3;
 	char aux4;
 //	printf("ENtre a barajeam \n");
 	//
 	int bar= 20 + rand() % 1000;
 	for(int i=0; i<bar; i++){  //numero de barajeadas
 		aux2 = rand() % T;
 		//printf("el random 1 es: %d\n", aux2);
 		aux3=rand()%T;
 		//printf("el random 2 es: %d\n", aux3);
 		aux1=N_tarjetas[aux2];
 		aux4=T_tarjetas[aux2];
 		N_tarjetas[aux2]=N_tarjetas[aux3];
 		T_tarjetas[aux2]=T_tarjetas[aux3];
 		N_tarjetas[aux3]=aux1;
 		T_tarjetas[aux3]=aux4;
 		
 		
 	}
 

}
void turno_Jugador(float N_tarjetas[], char T_tarjetas[], float *sumaJ, int *i){
	printf("*******************************TURNO DEL JUGADOR*************************************\n");
	printf("****E:Espadas*****\n" );
	printf("****O:Oros****\n" );
	printf("****B:Bastos****\n" );
	printf("****C:Copas****\n" );

	int opc = -1;
	
	int aux=0;
	
	do{

		aux=*i;

		printf("Tu carta es : %f de  %c \n ",N_tarjetas[aux],T_tarjetas[aux]);
		
		*sumaJ += N_tarjetas[aux];
		printf(" La  Suma  de tus cartas es %f\n",*sumaJ);
		N_tarjetas[aux]=0;
		*i=aux-1;
		if (*sumaJ>7.5)break;
		
		printf("Quieres otras tarjeta? ...........\n");
		printf("Si:[1]         No:[0]\n");
		scanf("%d",&opc);
		printf("%d\n",opc);
	}while(opc != 0);

}


	void turno_Maquina(float N_tarjetas[], char T_tarjetas[], float *sumaM, int *i, int para){
         printf("******************************* TURNO MAUINA*************************** \n");
		int aux=0;
		while(*sumaM<para){
			aux=*i;
			//printf("AuxM %d\n",aux );
			printf("la carta de la maquina es: %f de : %c\n",N_tarjetas[aux],T_tarjetas[aux]);
			*sumaM += N_tarjetas[aux];
			
			N_tarjetas[aux]=0;
			*i=aux-1;
			if(*sumaM>7.5)
				break;
		}
		printf("LA SUMA TOTAL DE LA MAQUINA ES: %f\n",*sumaM);
	}

	void turno_Maquina1(float N_tarjetas[], char T_tarjetas[], float *sumaM1, int *i, int para){

		int aux=0;
		while(*sumaM1<para){
			aux=*i;
			//printf("AuxM %d\n",aux );
			//printf("Dando una carta: %f %c",N_tarjetas[aux],T_tarjetas[aux]);
			*sumaM1 += N_tarjetas[aux];
			//printf("Suma %f\n",*sumaM);
			N_tarjetas[aux]=0;
			*i=aux-1;
			if(*sumaM1>7.5)
				break;
		}
	}	

	void turno_Maquina2(float N_tarjetas[], char T_tarjetas[], float *sumaM2, int *i, int para){

		int aux=0;
		while(*sumaM2<para){
			aux=*i;
			//printf("AuxM %d\n",aux );
			//printf("Dando una carta: %f %c",N_tarjetas[aux],T_tarjetas[aux]);
			*sumaM2 += N_tarjetas[aux];
			//printf("Suma %f\n",*sumaM);
			N_tarjetas[aux]=0;
			*i=aux-1;
			if(*sumaM2>7.5)
				break;
		}
	}


void juego(float N_tarjetas [], char T_tarjetas []){
	printf("Dentro de juego..................\n");
	iniciarbaraja(N_tarjetas, T_tarjetas);
	srand(time(0));

	barajear(N_tarjetas, T_tarjetas);
	float sumaJ=0; //
	float sumaM=0;
	int i=39;
	turno_Jugador(N_tarjetas, T_tarjetas, &sumaJ, &i);
	if (sumaJ>7.5)
	{
		printf("*****PERDISTESSSS POR DEFAULT CARNAL!!!!! \n");
	}else{
		turno_Maquina(N_tarjetas, T_tarjetas, &sumaM, &i, 5);
		  if(sumaM>7.5){
		  	printf("*******************************************************************\n" );
		  	printf(" Felicidades le has ganado a la maquina con un puntaje de : %f \n", sumaJ );
		    printf("*******************************************************************\n" );
		  }else{

		  	if(sumaJ>sumaM){
		  	printf("*******************************************************************\n" );
		  	printf(" Felicidades le has ganado a la maquina con un puntaje de : %f \n", sumaJ );
		    printf("*******************************************************************\n" );

		  	}else {
		  	printf("*******************************************************************\n" );
		  	printf(" PERDISTE ,TE HE GANADO JAJAJAJAJAJAJAJAJAJAJAJAJA  CON UN PUNTAJE DE: %f \n",sumaM );
		    printf("*******************************************************************\n" );

		  	}



		  }

	}

	printf("Quieres Regresar al Menù Principal\n");
	printf("Si:[1]         No:[0] (exit)\n");
	int g;
	scanf("%d",&g);
	if (g == 1){
	system("clear");
	main();
	}else{
		exit(0);
	}

}

void simulacion(float N_tarjetas[],char T_tarjetas[]){
	
	int opc2 = 0;
	
	int contador1=0;
	int contador2=0;
	
	printf("Cuantas simulaciones quieres hacer: ");
	scanf("%d", &opc2);
	while(opc2 > 0){
		float sumaM1 = 0;
	    float sumaM2 = 0;
		int i = 39;
		iniciarbaraja(N_tarjetas, T_tarjetas);
		barajear(N_tarjetas, T_tarjetas);
		turno_Maquina1(N_tarjetas, T_tarjetas, &sumaM1, &i, 5);
			if (sumaM1>7.5)
	{
	           contador2++;	
	}else{
		turno_Maquina2(N_tarjetas, T_tarjetas, &sumaM2, &i, 5);
		  if(sumaM2>7.5){
		  	contador1++;
		  }else{

		  	if(sumaM1>sumaM2){
		  		contador1++;

		  	}else {
		  		contador2++;
		  	}



		  }

	}

		//srand(time(NULL));
		opc2--;

	}
	printf("*******************************************************************\n" );
	printf("Maquina uno gano: %d veces\n", contador1);
	printf("*******************************************************************\n" );
	printf("Maquina dos gano: %d veces\n", contador2);
	printf("*******************************************************************\n" );
	printf("Quieres Regresar al Menù Principal\n");
	printf("Si:[1]         No:[0] (exit)\n");
	int g;
	scanf("%d",&g);
	if (g == 1){
	system("clear");
	main();
	}else{
		exit(0);
	}

}

void elegirOpcion(int o){
	float N_tarjetas [T];
	char T_tarjetas[T];
	if(o == 1){
	juego(N_tarjetas, T_tarjetas);
	
    }
    else if(o == 2){
   
	simulacion(N_tarjetas, T_tarjetas);
    }

}

int menu(){
	int variable=-1;
	printf("*********Bienvenido a la Pràctica 4*********\n");
	printf("Que quieres hacer\n");
  	printf("1.-Jugar contra la máquina (Jugador vs CPU).\n2.-Realizar una simulacion entre CPU vs CPU.\n3.-Salir de la App.\n");
  	scanf("%d",&variable);
  	printf("Usted Eligió: %d\n",variable);
   return variable;
}

int main(){
	int o;
	presentacion();
	o = menu();
	elegirOpcion(o);
}
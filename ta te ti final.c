#include <stdio.h>
#include <time.h>
//Funciones 

void turnos(char mat[3][3]); 
void posiciones(char mat[3][3]);
void tablero(char mat[3][3]);
void introduce_valor(char mat[3][3]);
void intro_IA(char mat[3][3]);
int victoria(char mat[3][3]);
void vuelve_a_elegir(char mat[3][3]);

int main(){
	//un ta te ti es una matriz cuadrada 3x3.
	char mat[3][3];
	char rta = 's';
	do {
		turnos(mat); //llama a todas las funciones y hace un refresco en pantalla.
		printf("\n ¿Queres volver a intentar? (S/N) \n\n");
		do{
			fflush(stdin); 
			scanf("%c", &rta); 
			rta = tolower(rta); //conversión de minúscula a mayúscula o viceversa.
			if(rta != 's' && rta != 'n'){
				printf("Caracter incorrecto. ¿Queres volver a intentar? (S/N) \n");
			}
		} while(rta != 's' && rta != 'n');
    }while (rta == 's');
    system("cls");
    printf("Gracias por participar! \n");
	return 0;	
}

void turnos(char mat [3][3]){
	int i,j;
	i = 0; 		//  ACTUALIZACION: si inicializo i en 1, va a comenzar jugando la pc.

	posiciones(mat);
	
	do{
		tablero (mat);
		if(i % 2 == 0){ //si el resto de i es = 0, juegan los humanos
			introduce_valor (mat);
		}
		else{
			intro_IA(mat);
		}
		j = victoria(mat); 
		i++; //salvamos un bucle infinito cuando i se incrementa. 
		//volvemos  a hacer un clear, ya que si no ponemos no nos muestra la ultima jugada. 
		system("cls");
			
	}while(i < 9 && j == 2); //para hacerlo nueve veces. //ACTUALIZACION 15/10/18: SI i<=9 NUNCA NOS VA A MOSTRAR EMPATE. 
			if(j == 0){
				printf("Felicitaciones, ganaste!  :) \n\n");
			}
			else if(j == 1){
				printf("Los boots gararon :( \n\n");
			}
			else{
				printf("Empate!\n\n");
			}
	
}

void posiciones(char mat [3][3]){ //la idea es que la matriz tenga 1,2,3,4,5,6,7,8,9 posiciones.
	int i, j;
	char aux;
	aux = '1';
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			mat[i][j] = aux++; //para que pueda incrementar numeros en la posicion i y j en la matriz, aux va a ir incrementando dichas posiciones.
		}
	}
}
//la idea es meter valores entre 1 y 9 y tampoco puede ser el mismo valor repetido, es decir, no puede ser pocisión 1 y 1. 
//vamos a hacerlo con un do while
void introduce_valor(char mat[3][3]){
	int i,j,aux;
	char x;
	do{
		do{
			printf("Introduzca un valor entre 1 y 9: ");
			fflush(stdin); //limpiamos el buffer.
			scanf("%c", &x);
		}while(x < '1' || x > '9'); 
		
		aux = 0;
		
		switch (x){
			case '1': { //declaramos el caso para la posición de la matriz. 
				i = 0;
				j = 0;
				if(mat[i][j] == 'X' || mat[i][j] == 'O'){ //si la matriz [i][j] es igual que Cruz o la matriz [i][j] es igual que Círculo, entonces buscamos EVITAR la posición
					aux = 1; 												 //gracias a esto, evitaremos la pocisión. Aux va a valer 1, entonces la casilla va a estar ocupada.
					printf("Espacio ocupado. Intenta con otro numero: \n\n");
				}
			break;		
		}
		case '2': { 
				i = 0; 
				j = 1;
				if(mat[i][j] == 'X' || mat[i][j] == 'O'){ 
					aux = 1;
					printf("Espacio ocupado. Intenta con otro numero: \n\n");
				}
			break;		
		}
		case '3': { 
				i = 0;
				j = 2;
				if(mat[i][j] == 'X' || mat[i][j] == 'O'){ 
					aux = 1; 
					printf("Espacio ocupado. Intenta con otro numero: \n\n");
				}
			break;		
		}
		case '4': { 
				i = 1;
				j = 0;
				if(mat[i][j] == 'X' || mat[i][j] == 'O'){
					aux = 1; 
					printf("Espacio ocupado. Intenta con otro numero: \n\n");
				}
			break;		
		}
		case '5': {
				i = 1;
				j = 1;
				if(mat[i][j] == 'X' || mat[i][j] == 'O'){
					aux = 1; 
					printf("Espacio ocupado. Intenta con otro numero: \n\n");
				}
			break;		
		}
		case '6': { 
				i = 1;
				j = 2;
				if(mat[i][j] == 'X' || mat[i][j] == 'O'){ 
					aux = 1; 
					printf("Espacio ocupado. Intenta con otro numero: \n\n");
				}
			break;		
		}
		case '7': { 
				i = 2;
				j = 0;
				if(mat[i][j] == 'X' || mat[i][j] == 'O'){ 
					aux = 1; 
					printf("Espacio ocupado. Intenta con otro numero: \n\n");
				}
			break;		
		}
		case '8': {
				i = 2;
				j = 1;
				if(mat[i][j] == 'X' || mat[i][j] == 'O'){ 
					aux = 1; 
					printf("Espacio ocupado. Intenta con otro numero: \n\n");
				}
			break;		
		}
		case '9': { 
				i = 2;
				j = 2;
				if(mat[i][j] == 'X' || mat[i][j] == 'O'){ 
					aux = 1; 
					printf("Espacio ocupado. Intenta con otro numero: \n\n");
				}
			break;		
		}
	}	
	
	}while(aux == 1);  //mientras aux == 1, la casilla va a estar ocupada por su respectiva ficha.
	
	mat[i][j] = 'X';	
	
}

void intro_IA(char mat[3][3]){
	int i,j,k;
	char aux;
	srand(time(NULL)); //generamos la semilla y definimos un tiempo nulo. 
	do{
		i = rand() % 3; //nos va a generar un num aleatorio entre 0 y 2 al rededor de toda la matriz. 
		j = rand() % 3;
		k = 0;
		if (mat[i][j] == 'X' || mat[i][j] == 'O'){
			k = 1;
		}
	}while(k == 1);
	mat[i][j] = 'O';
}

void tablero(char mat [3][3]){//para pintar el tablero, necesitamos leer los valores de la matriz.
	int i,j;
	//la idea es que no pueda imprimir ninguna rayita vertical a la derecha del 3, entonces creo dos bucles for y una condición
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(j<2){//si j es menor que dos, entonces va a imprimir la barra | para los valores menores que dos y que la posicion 3.
				printf(" %c| ", mat[i][j]);
			}
			else{
				printf(" %c ", mat[i][j]);
			}
		}
		if(i<2){
			printf("\n-----------\n");
		}		
	}
	printf("\n\n");
}

int victoria(char mat[3][3]){ //la idea es que devuelve 1 si alguien gana y 0 si no gana nadie.
	if(mat[0][0] == 'X' || mat[0][0] == 'O'){
		if(mat[0][0] == mat[0][1] && mat[0][0] == mat[0][2]){ //implementación transistiva, relaciono primera posición con la ultima pos (a-> b -> c) pos a -->  pos c. 
			if(mat[0][0] == 'X'){
				return 0; //devuelve cero si nosotros, los humanos, ganamos. 
			} //CUANDO SE EJECUTA UN RETURN SE SALE DE LA FUNCIÓN
			else{
				return 1; //GANO LA COMPU. 
			}
		}
		//de la 1 a la siete
		if(mat[0][0] == mat[1][0] && mat[0][0] == mat[2][0]){
			if(mat[0][0] == 'X'){
				return 0;  
			} 
			else{
				return 1;
			}
		}
	}
	//caso de la ficha central es decir el cinco
	if(mat[1][1] == 'X' || mat[1][1] == 'O'){
				if(mat[1][1] == mat[0][0] && mat[1][1] == mat[2][2]){
					if(mat[1][1] == 'X'){
					return 0;
				} 
				else{
					return 1; 
				}
			}
			if(mat[1][1] == mat[1][0] && mat[1][1] == mat[1][2]){
					if(mat[1][1] == 'X'){
					return 0;
				} 
				else{
					return 1; 
				}
			}
		if(mat[1][1] == mat[2][0] && mat[1][1] == mat[0][2]){
					if(mat[1][1] == 'X'){
					return 0;  
				} 
					else{
						return 1;  
					}
			}
			if(mat[1][1] == mat[0][1] && mat[1][1] == mat[2][1]){
					if(mat[1][1] == 'X'){
					return 0; 
				} 
				else{
					return 1; 
				}
			}
				
	} //caso del 7 al 9
	if(mat[2][2] == 'X' || mat[2][2] =='O'){
		if(mat[2][2] == mat[2][0] && mat[2][2] == mat[2][1]){
			if(mat[2][2] == 'X'){
					return 0;
				}
				else{
					return 1;
				}
		} //para 3 6 9 
		if(mat[2][2] == mat[0][2] && mat[2][2] == mat[1][2]){
			if(mat[2][2] == 'X'){
					return 0; 
				} 
				else{
					return 1; 
				}
		}
	}
	return 2;
}

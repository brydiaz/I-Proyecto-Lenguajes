#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "4InLine.h"
#define N 7
#define VALOR_VICTORIA 1024
#define FICHA_CPU 'X'
#define FICHA_JUGADOR 'O'

/*
Entradas: el tablero que se desea imprimir
Salidas: el tablero impreso

imprime el tablero
*/
void printTable(char table[7][7]){
    printf(" 0\t 1\t 2\t 3\t 4\t 5\t 6\t\n");
    for(int i = 0; i<7; i++){
        for (int j = 0; j<7; j++){
            printf("|%c| \t", table[i][j]);
        }
        printf("\n");
    }
    return 0;
    
}

/*
Entradas: --
Salidas: --

imprime ascii code

*/

void asciiArt(){

    printf("  _  _                  _  __                 \n");
    printf(" | || |                |  /_/                 \n");
    printf(" | || |_    ___ _ __   | |_ _ __   ___  __ _ \n");
    printf(" |__   _|  / _ %c '_ %c  | | | '_ %c / _ %c%c _` |\n", 92, 92, 92, 92, 47);
    printf("    | |   |  __/ | | | | | | | | |  __/ (_| |\n");
    printf("    |_|    %c___|_| |_| |_|_|_| |_|%c___|%c__,_|\n", 92, 92, 92);

    
}

/*
Entradas: el tablero que se usará como referencia, el movimiento que se jugó
y la ficha que se está jugando

Salidas: --

Pone el movimiento deseado en el tablero

*/

void makeMove(char table[7][7], int move, char token){

    for(int i = 6; i>-1; i--){
        if(table[i][move] == ' '){
            table[i][move] =  token;
            break;
        }
    }

}

/*
Entradas: el tablero que se usa como referencia, el la ficha del jugador
Salidas: 1 si se ganó

Verifica horizontal, vertical, o diagonales si gana

*/
int checkVictory(char table[7][7], char token){
	int i;      //fila
      int j;      //columna




	// Comprobación horizontal

	//va analizando fila por fila
	for(i=0;i<7;i++){

		//Esta analiza la parte horizontal, termina en 7-3 porque 
		//faltando 3 columnas ya no es necesario analizar nada, es imposible que haya 4 en línea en solo 3 espacios
		for(j=0;j<(7-3);j++){

			//Comienza a comprobar si las 4 están en fila horizontal
			if(	(table[i][j] == token) &&
				(table[i][j+1] == token) &&
				(table[i][j+2] == token) &&
				(table[i][j+3] == token)){	
					//retorna 1 en caso de haber ganado
					return 1;
				}
		}

	}
	

	// Comprobación vertical
	for(j=0;j<7;j++){

		//Esta analiza la parte vertical, termina en 7-3 porque
		//faltando 3 filas ya no es necesario analizar nada, es imposible que haya 4 en línea en solo 3 espacios
		for(i=0;i<(7-3);i++){

			//Comienza a comprobar si las 4 están en fila vertical
			if(	(table[i][j] == token) &&
				(table[i+1][j] == token) &&
				(table[i+2][j] == token) &&
				(table[i+3][j] == token)){
					return 1;
				}
		}

	}



	// Comprobación diagonal de izquierda a derecha es decir -> \
	//Es una diagonal, a partir de la fila 7-3 es imposible que hayan 4 en línea
	for(i=0;i<(7-3);i++){

		//es una diagonal, a partir de la columna 7-3 es imposible que hayan 4 en línea
		for(j=0;j<(7-3);j++){


			//comienza a comprobar si las 4 están en fila diagonal
			//La comprobación va sumando en cada if porque es diagonal
			if(	(table[i][j] == token) && 
				(table[i + 1][j + 1] == token) && 
			   	(table[i + 2][j + 2] == token) && 
				(table[i + 3][j + 3] == token)){
				return 1;
			}
		}
	}


	// Comprobación diagonal de derecha a izquierda es decir -> /

	//Comienza en 7-3 porque faltando 3 filas ya no es necesario analizar nada
	//es imposible que haya 4 en línea en solo 3 espacios
	for(i=0;i<(7-3);i++){
	
		//Esta es diferente porque comienza por la columna derecha y va restando,
		//Debe ser mayor a 2, porque las últimas diagonales solo tiene 3, 2 y 1 espacio respectivamente
		for(j=7-1;j>2;j--){

			//Aqui comienza a comprobar si las 4 tokens están en diagonal /
			//Se van sumando las filas (analizando hacia abajo) y restando las columnas (analizando hacia la derecha)
			if(	(table[i][j] == token) &&
				(table[i+1][j-1] == token) &&
				(table[i+2][j-2] == token) &&
				(table[i+3][j-3] == token)){
							return 1;
				}
		}
	}

	return 0;
}

/*
Entradas: --
Salidas: --

Controla el flujo del programa 
cuando juega el jugador y cuando juega el pc
*/

void gameOn(){

    int winner = 0;
    int turn = 0;
    int finalWinner = 0;
    char table[7][7];

    for(int i = 0; i<7; i++){
        for (int j = 0; j<7; j++){
            table[i][j] = ' ';
        }
    }

    while(winner == 0){
        printTable(table);
        if(turn == 0){

            int op;
            printf("\n");
            printf("DIGITA UNA OPCION JUGADOR\n");
            scanf("%d", &op);
            makeMove(table, op, FICHA_JUGADOR);
            winner = checkVictory(table, FICHA_JUGADOR);
            if(winner == 1){
                finalWinner = 1;
            }
            turn = 1;
        }else{

            printf("Ahora iría el IA");
            break;

        }
    }

    if(finalWinner == 1){
        printf("FELICIDADES LE GANASTE AL IA");
    }else{
        printf("QUE MAL, PERDISTE CONTRA EL IA");
    }
}


/*
Entradas: --
Salidas: --

Control del menú en el programa

*/

void mainGame(){
    asciiArt();
    int op; 
    printf("\n");
    printf("1. Iniciar juego\n");
    printf("2. Desarrolladores\n");
    printf("3. Salir\n");
    scanf("%d", &op);

    if(op == 1 ){

        gameOn();

    }else if(op == 2){
        
        printf("Developers");

    }else if(op == 3){
        printf("GRACIAS POR USAR :D");
        exit(-1);

    }else{
        printf("ERROR Opcion invalida\n");
        mainGame();
    }
    
    
}


int main(){
    mainGame();
    return 0;
}

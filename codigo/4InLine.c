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


//Se le pasa el tablero para que le dé la cantidad de cuantos hijos
//puede tener según la cantidad de columnas con la primera fila vacía
int posibilidades(char tablero[N][N])
{
	int j;
	int cont = 0;

	//Verifica si cada columna está vacía en su primera fila superior
	for (j = 0; j < N; j++)
	{
		if (tablero[0][j] == ' ')
		{
			cont += 1;
		}
	}

	//devuelve la cantidad de columnas vacias en su primera fila superior
	return cont;
}



int comprobarVictoriaPC(char tablero[N][N])
{
	int i;
	int j;
	char ficha = FICHA_CPU;
	// Chequeo horizontal

	//va analizando fila por fila
	for (i = 0; i < N; i++)
	{

		//Esta analiza la parte horizontal, termina en N-3 porque
		//faltando 3 columnas ya no es necesario analizar nada, es imposible que haya 4 en línea en solo 3 espacios
		for (j = 0; j < (N - 3); j++)
		{

			//Comienza a comprobar si las 4 están en fila horizontal
			if ((tablero[i][j] == ficha) &&
			    (tablero[i][j + 1] == ficha) &&
			    (tablero[i][j + 2] == ficha) &&
			    (tablero[i][j + 3] == ficha))
			{
				//retorna 1 de ser correcto y haber ganado el CPU
				return 1;
			}
		}
	}

	// Chequeo vertical
	for (j = 0; j < N; j++)
	{

		//Esta analiza la parte vertical, termina en N-3 porque
		//faltando 3 filas ya no es necesario analizar nada, es imposible que haya 4 en línea en solo 3 espacios
		for (i = 0; i < (N - 3); i++)
		{

			//Comienza a comprobar si las 4 están en fila vertical
			if ((tablero[i][j] == ficha) &&
			    (tablero[i + 1][j] == ficha) &&
			    (tablero[i + 2][j] == ficha) &&
			    (tablero[i + 3][j] == ficha))
			{
				return 1;
			}
		}
	}

	// Chequeo diagonal de izquierda a derecha es decir -> \
	//Es una diagonal, a partir de la fila N-3 es imposible que hayan 4 en línea
	for (i = 0; i < (N - 3); i++)
	{

		//es una diagonal, a partir de la columna N-3 es imposible que hayan 4 en línea
		for (j = 0; j < (N - 3); j++)
		{

			//comienza a comprobar si las 4 están en fila diagonal
			//La comprobación va sumando en cada if porque es diagonal
			if ((tablero[i][j] == ficha) &&
			    (tablero[i + 1][j + 1] == ficha) &&
			    (tablero[i + 2][j + 2] == ficha) &&
			    (tablero[i + 3][j + 3] == ficha))
			{
				return 1;
			}
		}
	}

	// Chequeo diagonal de derecha a izquierda es decir -> /

	//Comienza en N-3 porque faltando 3 filas ya no es necesario analizar nada
	//es imposible que haya 4 en línea en solo 3 espacios
	for (i = 0; i < (N - 3); i++)
	{

		//Esta es diferente porque comienza por la columna derecha y va restando,
		//Debe ser mayor a 2, porque las últimas diagonales solo tiene 3, 2 y 1 espacio respectivamente
		for (j = N - 1; j > 2; j--)
		{

			//Aqui comienza a comprobar si las 4 fichas están en diagonal /
			//Se van sumando las filas (analizando hacia abajo) y restando las columnas (analizando hacia la derecha)
			if ((tablero[i][j] == ficha) &&
			    (tablero[i + 1][j - 1] == ficha) &&
			    (tablero[i + 2][j - 2] == ficha) &&
			    (tablero[i + 3][j - 3] == ficha))
			{
				return 1;
			}
		}
	}

	return 0;
}

//Es todo lo mismo que victoria CPU
int comprobarVictoriaJugador(char tablero[N][N])
{
	int i;
	int j;
	char ficha = FICHA_JUGADOR;
	// Chequeo horizontal

	//va analizando fila por fila
	for (i = 0; i < N; i++)
	{

		//Esta analiza la parte horizontal, termina en N-3 porque
		//faltando 3 columnas ya no es necesario analizar nada, es imposible que haya 4 en línea en solo 3 espacios
		for (j = 0; j < (N - 3); j++)
		{

			//Comienza a comprobar si las 4 están en fila horizontal
			if ((tablero[i][j] == ficha) &&
			    (tablero[i][j + 1] == ficha) &&
			    (tablero[i][j + 2] == ficha) &&
			    (tablero[i][j + 3] == ficha))
			{
				//retorna 1 de ser correcto y haber ganado el CPU
				return 1;
			}
		}
	}

	// Chequeo vertical
	for (j = 0; j < N; j++)
	{

		//Esta analiza la parte vertical, termina en N-3 porque
		//faltando 3 filas ya no es necesario analizar nada, es imposible que haya 4 en línea en solo 3 espacios
		for (i = 0; i < (N - 3); i++)
		{

			//Comienza a comprobar si las 4 están en fila vertical
			if ((tablero[i][j] == ficha) &&
			    (tablero[i + 1][j] == ficha) &&
			    (tablero[i + 2][j] == ficha) &&
			    (tablero[i + 3][j] == ficha))
			{
				return 1;
			}
		}
	}

	// Chequeo diagonal de izquierda a derecha es decir -> \
	//Es una diagonal, a partir de la fila N-3 es imposible que hayan 4 en línea
	for (i = 0; i < (N - 3); i++)
	{

		//es una diagonal, a partir de la columna N-3 es imposible que hayan 4 en línea
		for (j = 0; j < (N - 3); j++)
		{

			//comienza a comprobar si las 4 están en fila diagonal
			//La comprobación va sumando en cada if porque es diagonal
			if ((tablero[i][j] == ficha) &&
			    (tablero[i + 1][j + 1] == ficha) &&
			    (tablero[i + 2][j + 2] == ficha) &&
			    (tablero[i + 3][j + 3] == ficha))
			{
				return 1;
			}
		}
	}

	// Chequeo diagonal de derecha a izquierda es decir -> /

	//Comienza en N-3 porque faltando 3 filas ya no es necesario analizar nada
	//es imposible que haya 4 en línea en solo 3 espacios
	for (i = 0; i < (N - 3); i++)
	{

		//Esta es diferente porque comienza por la columna derecha y va restando,
		//Debe ser mayor a 2, porque las últimas diagonales solo tiene 3, 2 y 1 espacio respectivamente
		for (j = N - 1; j > 2; j--)
		{

			//Aqui comienza a comprobar si las 4 fichas están en diagonal /
			//Se van sumando las filas (analizando hacia abajo) y restando las columnas (analizando hacia la derecha)
			if ((tablero[i][j] == ficha) &&
			    (tablero[i + 1][j - 1] == ficha) &&
			    (tablero[i + 2][j - 2] == ficha) &&
			    (tablero[i + 3][j - 3] == ficha))
			{
				return 1;
			}
		}
	}

	return 0;
}
//Cada vez que el
double Heuristica(char tablero[N][N])
{
	if (comprobarVictoriaPC(tablero))
		return VALOR_VICTORIA;
	if (comprobarVictoriaJugador(tablero))
		return -VALOR_VICTORIA;
	else
		return 0;
}

//Hacer una copia del tablero para que así el minimax pueda generar un juego teórico por aparte
//y así elegir lo que crea que es la mejor opción
void tableroTeorico(char tablero1[N][N], char tablero2[N][N]){
	int i; int j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			tablero2[i][j] = tablero1[i][j];
		}
	}
}


//Se encarga de crear un Nodo y cargarlo con nivel, n_hijos, valor, movimientos
Nodo CreaNodo(char tablero[N][N],int nivel,int profundidadArbol){
	int i; int j=0;
	Nodo p;

	//la nodo P le cargamos el nivel que tiene en el árbol que se va creando
	p.nivel = nivel;
	//al nodo P le cargamos un tablero igual
	tableroTeorico(tablero,p.tablero);

	//Va a decir la cantidad de hijos que puede tener dado
	//la cantidad de filas superiores vacías haya
	p.n_hijos = posibilidades(tablero);

	p.valor = 0;

	//Verifica si ya hay una victoria en el juego o sí el __nivel ya alcanzo cierto grado___
	//de ser así, no le da nodos hijos al nodo
	if (comprobarVictoriaPC(p.tablero) || comprobarVictoriaJugador(p.tablero) || p.nivel == 2*profundidadArbol+2){
        p.n_hijos = 0;
	}

	//Si el árbol puede tener hijos entonces ejecuta este if
	if (p.n_hijos != 0){
	  //Reserva memoria para los nodos hijos
        p.hijos = (Nodo **) malloc(p.n_hijos*sizeof(Nodo *));
	  //Reseva memoria para los movimientos
        p.movimientos = (int *) malloc(p.n_hijos*sizeof(int));

	  //Recorre la primera fila de la matriz y se fija cuales están vacias, diciendo así cuales columnas
	  //son opciones de movimiento
        for(i=0;i<N;i++){
            if(tablero[0][i] == ' '){
                p.movimientos[j] = i;
                j += 1;
            }
        }
	}

	//No crea hijos y no tiene movimientos
	else{
        p.hijos = NULL;
        p.movimientos = NULL;
	}

	//Retorna el Nodo P que contiene 
	//	-n_hijos: la cantidad de hijos que puede tener según la cantidad de columnas con primera fila vacía
	//	-movimientos: la cantidad de movimientos que puede hacer según la cantidad de columnas con primera fila vacía
	return p;
}



// Crea nodos hijos y los carga con a info que tiene cada nodo (n_hijos, movimientos, nivel, ...) creando así un nivel más en el árbol
void CreaNivel(Nodo *Padre,char ficha,int profundidadArbol){
	int i;
	Nodo *Hijo;

	for(i=0;  i<Padre->n_hijos  ;i++){
		//Da memoria al nodo
		Hijo = (Nodo *) malloc(sizeof(Nodo));

		//Copia la informacion del tablero
		tableroTeorico(Padre->tablero,Hijo->tablero);

		//Envia la ficha y la mete en el tablero del NODO HIJO según la columna que vaya en el for
		makeMove(Hijo->tablero,Padre->movimientos[i],ficha);

		//Carga el Nodo Hijo
		*Hijo = CreaNodo(Hijo->tablero,Padre->nivel+1,profundidadArbol);

		//Carga al nodo padre con un nodo (hoja) que funciona cómo opcion
		//de lo que puede ser una jugada
		Padre->hijos[i] = Hijo;
	}
}


//raiz: El nodo por el que comienza
//profundidad: Hasta donde llegara el árbol (no puede ser infinito por lo que se le da una un número especifico que se va reduciendo)
void CreaArbol(Nodo *raiz, int profundidad, int profundidadArbol){

	//Se encarga de crear nodos hijos y cargarlos, esto según la cantidad de hijos que tenga la raiz
	CreaNivel(raiz, FICHA_CPU, profundidadArbol);
	for (int i = 0; i < raiz->n_hijos; i++){
		CreaNivel(raiz->hijos[i], FICHA_JUGADOR, profundidadArbol);
	}

	//Marca el fin de la recursividad
	if(profundidad == 0) return;
	else{
		int i; 
		int j;
		
		// Según la cantidad de columnas con primera fila vacia,
		//se va a crear la profundiad del árbol
		for(i=0; i<raiz->n_hijos ;i++){
			
			// En la matriz hijos, se le debe de dar a cada hijo otros
			// hijos para así ir generando el árbol
			for(j=0; j < raiz->hijos[i]->n_hijos  ;j++){
				CreaArbol(raiz->hijos[i]->hijos[j],profundidad-1,profundidadArbol);
			}
		}
	}
	return;
}


//Sirve para liberar memoria o tarde o temporano el programa colapsaría
//va eliminando nodo por nodo con recursividad
void BorraArbol(Nodo *raiz){
	if(raiz->n_hijos == 0){
        free(raiz);
	}
	else{
        int i;
        for (i=0;i<raiz->n_hijos;i++){
            BorraArbol(raiz->hijos[i]);
        }
        free(raiz->hijos);
        free(raiz->movimientos);
	}

	return;
}



//Se le da un valor a cada hoja para así poder
void ValorarHojas(Nodo *raiz){

	//Se encuentra en el nivel donde el nodo analizado ya no tiene más niveles
	if (raiz->n_hijos == 0){

		//Al nodo se le da un valor de gane "teórico"
		
		//recuerde que está usando un tablero "copia" el cual mediante "crearArbol" se le cargaron posibles
		//lugares donde puede dejar caer la ficha, el tablero que pasamos en heuristica lleva esa jugada "teórica"
		//así es cómo puede comprobar si la máquina "ganará" en teoría.
		raiz->valor = Heuristica(raiz->tablero);
	}

	//Continuar bajando hata llegar a la última fila de nodos (último nivel)
	else{
		for (int i=0;i<raiz->n_hijos;i++){
			ValorarHojas(raiz->hijos[i]);
		}
	}
}





//	Función principal de Minimax
/*
	Parte de la teoría de Minimax indica que los niveles van salteados entre máximo y mínimo
	de ahí que se analice "Raiz->nivel % 2  == 0" para los valores máximos 
	y
	"Raíz->nivel %2 == 1" para los valores mínimos

	por esto mismo es que se llama Minimax
*/
void MiniMax(Nodo *Raiz){
	// Esta es una ligera variante del minimax, donde las herencias se dividen entre 2

	// Comprueba si ya se llegó a lo más bajo del arbolito
	if (Raiz->n_hijos != 0){
		
		//Recorre los hijos del nodo en cuestión
        	for (int i=0; i<Raiz->n_hijos ;i++){

			//Si tiene hijos, los recorre con el Minimax bajando al siguiente nivel hasta llegar al último
			// y así cumplir con la recursividad
            	if (Raiz->hijos[i]->n_hijos != 0){
                		MiniMax(Raiz->hijos[i]);
            	}
        	}


		//Analiza los máximos
        	if (Raiz->nivel % 2 == 0){

		  	//Le carga el valor del primer nodo de ese nivel
            	Raiz->valor = Raiz->hijos[0]->valor;
			
			//Se encarga de ir comparando cada nodo de la línea y ver cual es el mejor
            	for (int i=1; i<Raiz->n_hijos ;i++){

				//Busca el nodo de mayor valor (la mejor opción para la compu)
                		if (Raiz->hijos[i]->valor > Raiz->valor){
                  		Raiz->valor = Raiz->hijos[i]->valor;
                		}
            	}
        	}


		//Analiza los mínimos
		if (Raiz->nivel % 2 == 1){ 
			//Le carga el valor del primer nodo de ese nivel
			Raiz->valor = Raiz->hijos[0]->valor;

			//Se encarga de ir comparando cada nodo de la línea y ver cual es el mejor
			for (int i=1;i<Raiz->n_hijos;i++){

				//Busca el nodo de mínimo valor (la peor opción para el contrincante)
                		if (Raiz->hijos[i]->valor < Raiz->valor){
                    		Raiz->valor = Raiz->hijos[i]->valor;
                		}
            	}
        	}
		

		//El valor de la raíz se divide en 2 para caer
		//en la mejor decisión entre mejor y peor
		Raiz->valor = Raiz->valor / 2;
	}
}



//La computadora está jugando
//Se le pasa el tablero y se le pasa la profundidadArbol
//Hay una matriz que lleva las varas lógicas
int juegaPC(char tablero[N][N], int profundidadArbol){

	//Crea un nodo raiz que se encarga de tener hijos, movimientos, nivel?, valor? y copiar la matriz
	Nodo Raiz = CreaNodo(tablero,0,profundidadArbol);


	//Crea el arbol de posibilidades
	CreaArbol(&Raiz,profundidadArbol,profundidadArbol);

	// Sirve para ir dándole valores de "gane teórico" a los hijos de la raíz
	ValorarHojas(&Raiz);


	//Algoritmo principal que se va a encargar de tomar las decisiones
	MiniMax(&Raiz);




	//Se procede a elegir las mejores opciones
	//Se carga en "tiradas_buenas" todas las opciones que son igual de buenas
	int num_tiradas_buenas = 0;
	int tiradas_buenas[8];
	int j=0;
	for (int i=0; i<Raiz.n_hijos; i++){
		if (Raiz.hijos[i]->valor == 2.0*Raiz.valor){
			num_tiradas_buenas++;
			tiradas_buenas[j] = Raiz.movimientos[i];
			j++;
		}
	}




	//Se elige "randommente" de la lista alguna que sea buena
	int tiradaBuenaRandom = rand() % num_tiradas_buenas;
	int movimiento = tiradas_buenas[tiradaBuenaRandom];




	//Se libera la memoria o el programa explota
	BorraArbol(&Raiz);



	//devuelve el movimiento a hacer
	return movimiento;
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

	        int columna = juegaPC(table, 2);
	        makeMove(table,columna,FICHA_CPU);
            winner = checkVictory(table, FICHA_CPU);
            if(winner == 1){
                finalWinner = 0;
            }
            turn = 0;
        

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

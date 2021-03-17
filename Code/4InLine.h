#define N 7
#define VALOR_VICTORIA 1024
#define FICHA_CPU 'X'
#define FICHA_JUGADOR 'O'


//Struct de nodo para poder crear los arboles de minimax
typedef struct nodo{
	struct nodo **hijos;
	int *movimientos;
	int n_hijos;
	char tablero[N][N];
	double valor;
	int nivel;
} Nodo;

//-------------------------------------------------------------------------------

/*
Entradas: el tablero que se usará como referencia

Salidas: --

Se le pasa el tablero para que le dé la cantidad de cuantos hijos
puede tener según la cantidad de columnas con la primera fila vacía

*/
int posibilidades(char[N][N]);
//-------------------------------------------------------------------------------


//-------------------------------------------------------------------------------

/*
Entradas: el tablero que se usa como referencia
Salidas: 1 si se ganó
Verifica horizontal, vertical, o diagonales si gana
*/
int comprobarVictoriaPC(char partida[N][N]);
int comprobarVictoriaJugador(char partida[N][N]);
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------

double heuristica(char[N][N]);
//-------------------------------------------------------------------------------


//-------------------------------------------------------------------------------
/*
Entradas: el tablero que se usa como referencia, el tablero que copia
Salidas: 1--
Hacer una copia del tablero para que así el minimax pueda generar un juego teórico por aparte
/y así elegir lo que crea que es la mejor opción

*/
void tableroTeorico(char [N][N],char [N][N]);
//-------------------------------------------------------------------------------


//-------------------------------------------------------------------------------

/*
Entradas: el tablero que se usa como referencia, el nivel, y su profundidad 
Salidas: --
Se encarga de crear un Nodo y cargarlo con nivel, n_hijos, valor, movimientos
*/

Nodo creaNodo(char [N][N],int ,int );
//-------------------------------------------------------------------------------


//-------------------------------------------------------------------------------
/*

Entradas: puntero a un nodo padre, la ficha del jugador, y la profundidad del arbol
salidas: --
// Crea nodos hijos y los carga con a info que tiene cada nodo (n_hijos, movimientos, nivel, ...) creando así un nivel más en el árbol

*/
void creaNivel(Nodo *,char ,int );
//-------------------------------------------------------------------------------

/*
//-------------------------------------------------------------------------------


/*
---------------------------------------------------------------------------
Entradas:recibe un nodo raiz, la profundidad y la profundidad del arbol
salidas: --

Crea el arbol de llamadas recursivas y sus niveles
*/
void creaArbol(Nodo *,int ,int );
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
/*
Entradas:recibe un nodo raiz
salidas: --

borra el arbol hoja a hoja en llamadas recursivas 
*/
void borrarArbol(Nodo *);
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
/*
Entradas:recibe un nodo raiz
salidas: --

le valor a las hojas para poder trabajarlas
*/
void valorarHojas(Nodo *);
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
/*

Entradas:recibe un nodo raiz
salidas: --

Crea el algoritmo miniMax
Parte de la teoría de minimax indica que los niveles van salteados entre máximo y mínimo
de ahí que se analice "Raiz->nivel % 2  == 0" para los valores máximos 
y
"Raíz->nivel %2 == 1" para los valores mínimos

por esto mismo es que se llama minimax
*/
void miniMax(Nodo *);
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
/*

Entradas:recibe un tablero, y la profundidad del arbol
salidas: Un entero que representa la columna a jugar
se encarga de jugar el turno de la pc, inicar el minimax etc

*/
int juegaPC(char [N][N],int );
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
/*
Entradas: el tablero que se desea imprimir
Salidas: el tablero impreso

imprime el tablero
*/
void imprimitTablero(char tablero[7][7]);
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------

/*
---------------------------------------------------------------------------
Entradas:--
salidas: --

Flujo de juego principal
*/
void juegoPrincipal();
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
/*
Entradas: El ascii que desea implementar
Salidas: --

imprime ascii code

*/
void arteAscii(int op);
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
/*
Entradas: el tablero que se usará como referencia, el movimiento que se jugó
y la ficha que se está jugando

Salidas: --

Pone el movimiento deseado en el tablero

*/
void hacerMovimiento(char tablero[7][7], int movimiento, char ficha);
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
/*
Entradas: --
Salidas: --
Verifica si desea jugar de nuevo
*/
void jugarDeNuevo();
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
/*
---------------------------------------------------------------------------
Entradas:--
salidas: --

Flujo de juego 
*/
void juego();
//-------------------------------------------------------------------------------

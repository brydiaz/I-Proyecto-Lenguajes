#define N 7
#define VALOR_VICTORIA 1024
#define FICHA_CPU 'X'
#define FICHA_JUGADOR 'O'

typedef struct nodo{
	struct nodo **hijos;
	int *movimientos;
	int n_hijos;
	char tablero[N][N];
	double valor;
	int nivel;
} Nodo;

int posibilidades(char[N][N]);
int comprobarVictoriaPC(char partida[N][N]);
int comprobarVictoriaJugador(char partida[N][N]);
void meterEnTablero(char[N][N], int, char);
double Heuristica(char[N][N]);

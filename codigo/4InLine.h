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



double Heuristica(char[N][N]);

void CopiaTablero(char [N][N],char [N][N]);
Nodo CreaNodo(char [N][N],int ,int );
void CreaNivel(Nodo *,char ,int );
void CreaDobleNivel(Nodo *,int );
void CreaArbol(Nodo *,int ,int );
void BorraArbol(Nodo *);
void ValorarHojas(Nodo *);
void MiniMax(Nodo *);
int juegaPC(char [N][N],int );

void printTable(char table[7][7]);
void mainGame();
void asciiArt();
void makeMove(char table[7][7], int move, char token);
int checkVictory(char table[7][7], char token);
void gameOn();

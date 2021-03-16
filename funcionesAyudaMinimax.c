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

//Comprueba la victoria de la máquina
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

//Comprueba la victoria del jugador
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

//Se encarg de meter en el juego la opción que eligió el jugador ya sea el usuario o la maquina
//PD: tablero es la matriz con iconos vacios que se crea apenas empezamos a jugar
void meterEnTablero(char tablero[N][N], int columna, char ficha)
{
	int i;
	for (i = 0; i < N; i++)
	{

		//Verifica de abajo hacía arriba si la posición está vacía, si no lo está sigue hasta estarlo
		//recuerde que antes de llamar a esta función ya fue verificado que la columna no está llena
		if (tablero[N - 1 - i][columna] == ' ')
		{
			tablero[N - 1 - i][columna] = ficha;
			break;
		}
	}
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




//tablero: Se le pasa la matriz del juego
//ficha: La ficha del jugador actual, sea el usuario o el CPU, eso depende de quien se está analizando


//Devuelve 1 en caso de que el jugador actual haya gando
int comprobarVictoria(char tablero[7][7], char ficha){
	int i;      //fila
      int j;      //columna




	// Comprobación horizontal

	//va analizando fila por fila
	for(i=0;i<7;i++){

		//Esta analiza la parte horizontal, termina en 7-3 porque 
		//faltando 3 columnas ya no es necesario analizar nada, es imposible que haya 4 en línea en solo 3 espacios
		for(j=0;j<(7-3);j++){

			//Comienza a comprobar si las 4 están en fila horizontal
			if(	(tablero[i][j] == ficha) &&
				(tablero[i][j+1] == ficha) &&
				(tablero[i][j+2] == ficha) &&
				(tablero[i][j+3] == ficha)){	
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
			if(	(tablero[i][j] == ficha) &&
				(tablero[i+1][j] == ficha) &&
				(tablero[i+2][j] == ficha) &&
				(tablero[i+3][j] == ficha)){
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
			if(	(tablero[i][j] == ficha) && 
				(tablero[i + 1][j + 1] == ficha) && 
			   	(tablero[i + 2][j + 2] == ficha) && 
				(tablero[i + 3][j + 3] == ficha)){
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

			//Aqui comienza a comprobar si las 4 fichas están en diagonal /
			//Se van sumando las filas (analizando hacia abajo) y restando las columnas (analizando hacia la derecha)
			if(	(tablero[i][j] == ficha) &&
				(tablero[i+1][j-1] == ficha) &&
				(tablero[i+2][j-2] == ficha) &&
				(tablero[i+3][j-3] == ficha)){
							return 1;
				}
		}
	}

	return 0;
}


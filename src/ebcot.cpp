#include <iostream>
#include <cmath>
#include "ImagenES.h"
#include "FichBits.h"

#define SIGNO 4


using namespace std;

int matrizContextoLL[3][3][5];

int matrizContextoHL[3][3][5];

int matrizContextoHH[3][3][5];

int matrizContextoSigno[3][3][5];

void inicializaLL(){

	matrizContextoLL[0][0][0] = 0;

	matrizContextoLL[0][0][1] = 1;

	matrizContextoLL[0][0][2] = 2;
	matrizContextoLL[0][0][3] = 2;
	matrizContextoLL[0][0][4] = 2;

	matrizContextoLL[0][1][0] = 3;
	matrizContextoLL[0][1][1] = 3;
	matrizContextoLL[0][1][2] = 3;
	matrizContextoLL[0][1][3] = 3;
	matrizContextoLL[0][1][4] = 3;

	matrizContextoLL[0][2][0] = 4;
	matrizContextoLL[0][2][1] = 4;
	matrizContextoLL[0][2][2] = 4;
	matrizContextoLL[0][2][3] = 4;
	matrizContextoLL[0][2][4] = 4;

	matrizContextoLL[1][0][0] = 5;

	matrizContextoLL[1][0][1] = 6;
	matrizContextoLL[1][0][2] = 6;
	matrizContextoLL[1][0][3] = 6;
	matrizContextoLL[1][0][4] = 6;

	matrizContextoLL[1][1][0] = 7;
	matrizContextoLL[1][1][1] = 7;
	matrizContextoLL[1][1][2] = 7;
	matrizContextoLL[1][1][3] = 7;
	matrizContextoLL[1][1][4] = 7;

	matrizContextoLL[2][0][0] = 8;
	matrizContextoLL[2][0][1] = 8;
	matrizContextoLL[2][0][2] = 8;
	matrizContextoLL[2][0][3] = 8;
	matrizContextoLL[2][0][4] = 8;
	matrizContextoLL[2][1][0] = 8;
	matrizContextoLL[2][1][1] = 8;
	matrizContextoLL[2][1][2] = 8;
	matrizContextoLL[2][1][3] = 8;
	matrizContextoLL[2][1][4] = 8;
	matrizContextoLL[2][2][0] = 8;
	matrizContextoLL[2][2][1] = 8;
	matrizContextoLL[2][2][2] = 8;
	matrizContextoLL[2][2][3] = 8;
	matrizContextoLL[2][2][4] = 8;
}

void inicializaHL(){
	
}

void inicializaHH(){
	
}

int calculaContexto(int h, int v, int d, int subbanda){

	switch(subbanda){
		case LL:
		case LH:
		return matrizContextoLL[h][v][d];
		break;
		case HL:
		return matrizContextHL[h][v][d];
		break;
		case HH:
		return matrizContextoHH[h][v][d];
		break;
		case SIGNO:
		return matrizContextoSigno[h][v][d];
		break;
	}
}

bool obtenerBitsSignificativos(bool **m, int ancho, int alto, int i, int j, int *h, int *v, int *d){

	bool r = false;
	h = v = d = 0;

	// Comprobamos la vertical
	if( i < alto && m[i-1][j]){
		v++;
		r = true;
	}
	if( i >= 0 && m[i+1][j]){
		v++;
		r=true;
	}
	//Comprobamos la horizontal
	if( j >= 0 && m[i][j-1]){
		h++;
		r = true;
	}
	if( j < ancho && m[i][j+1]){
		h++;
		r=true;
	}

	// Comprabamos las diagonales	
	if( i >= 0 && j >= 0 && m[i-1][j-1]){
		d++;
		r = true;
	}
	if( i >= 0 && j < ancho && m[i-1][j+1]){
		d++;
		r = true;
	}
	if( i < alto && j >= 0 && m[i+1][j-1]){
		d++;
		r = true;
	}
	if( i < alto && j < ancho && m[i+1][j+1]){
		d++;
		r = true;
	}

		return r;
}

int main (int argc, char const *argv[])
{
	int anchoB1,altoB1,nivel,subbanda;
	char fichero[20]="test/lena.bl1";
	char ficherosal[20]="test/ej.bi1";
	int **BloqueEj;

	inicializaLL();
	ReservaPlano(64,64,&BloqueEj);

	CargaBloque(fichero, &anchoB1, &altoB1, &nivel, &subbanda,BloqueEj);

	/**
	/*	Plano para guardar el signo de los valores a comprimir
	/*	true es negativo
	/*	false es positivo
	**/
	bool **signo;
	
	/**
	/*	Matriz de significacia
	**/
	bool **significancia;
	
	/**
	/* Matriz de refinamiento
	**/
	bool **refinamiento;
	
	// Saber cuantos planos de bits necesitaremos	
	int max = 0;
	int aux = 0;

	signo = new bool*[altoB1];
	significancia = new bool*[altoB1];
	refinamiento = new bool*[altoB1];
	for(int i = 0; i < altoB1; i++){
		
		signo[i] = new bool[anchoB1];
		significancia[i] = new bool[anchoB1];
		refinamiento[i] = new bool[anchoB1];
		for(int j = 0; j < anchoB1; j++){
			significancia[i][j] = false;
			refinamiento[i][j] = false;
			aux = BloqueEj[i][j];
			// Necesitamos todo en valor absoluto para saber cual es el mas grande
			if(aux < 0){ // Si es negativo
				signo[i][j] = true;		//Marcamos que es negativo
				aux = aux * (-1);	//Lo convertimos a positivo
			} else {	// Si es positivo
				signo[i][j] = false;	// Marcamos que es positivo
			}
			if(max < aux)
			{
				max = aux;
			}
		}
	}


	int numeroDePlanos = 0;
	for(int i = 32; i > 0; i--)
	{
		// El valor maximo ya esta en valor absoluto
		if( (max & (1<<i-1)) > 0 )
		{
			numeroDePlanos = i;
			break;
		}
	}

	cout << "El valor max es = " << max << "\nEl numero de planos a crear es de " << numeroDePlanos << endl;

	// Crear los planos de bits rellenandolos
	char ***PlanoDeBits;
	PlanoDeBits = new char ** [numeroDePlanos];
	for(int n = 0; n < numeroDePlanos; n++)
	{
		PlanoDeBits[n] = new char *[altoB1];
		for(int i=0;i<altoB1;i++){
			PlanoDeBits[n][i] = new char[anchoB1];
			for(int j=0;j<anchoB1;j++){
				if( (aux & (1 << n)) > 0)
					PlanoDeBits[n][i][j]=true;
				else 
					PlanoDeBits[n][i][j]=false;
			}
		}

	}

	InicializaEscritura(ficherosal);
	FILE *FCtxt=fopen("ej.ct1","wb");
	int h,v,d;
	
	for(int n = numeroDePlanos-1; n >= 0; n--){
		
		// Propagacion
		for(int i=0; i<altoB1; i++){
			for(int j=0; j<anchoB1; j++){
				if(significancia[i][j] == false && obtenerBitsSignificativos(significancia, anchoB1, altoB1,i, j, &h, &v, &d))
				{
					if(PlanoDeBits[n][i][j]){
						// Escribimos el bit
						EscribeBit(1);

						// Escribimos contexto
						putc(calculaContexto(h,v,d,subbanda), FCtxt);

						// Escribimos signo
						EscribeBit(signo[i][j]);

						//Escribimos contexto de signo
						putc(calculaContexto(h,v,d,SIGNO), FCtxt);
					}
					else
					{
						// Escribimos el bit
						EscribeBit(0);
						
						// Escribimos contexto
						putc(calculaContexto(h,v,d,subbanda), FCtxt);
					}
				}
			}
		}
		
		// Refinamiento
		for(int i=0; i<altoB1; i++){
			for(int j=0; j<anchoB1; j++){
				int contexto;
				if(significancia[i][j]){
					EscribeBit(PlanoDeBits[n][i][j]);
					if(!refinamiento[i][j]){
						if(obtenerBitsSignificativos(significancia, anchoB1, altoB1,i, j, &h, &v, &d))
							contexto=15;
						else contexto=14;
						refinamiento[i][j]=true;
					}
					else contexto=16;

					putc(contexto,FCtxt);
				}
			}
		}
		
		// Limpieza
		for(int i=0; i<altoB1; i++){
			for(int j=0; j<anchoB1; j++){
				if(!obtenerBitsSignificativos(significancia, anchoB1, altoB1,i, j, &h, &v, &d)){
					EscribeBit(PlanoDeBits[n][i][j]);
					contexto = 9;
					putc(contexto,FCtxt);
				}
				
			}
		}
	}

	FinalizaEscritura();
	fclose(FCtxt);
	GuardaBloque(ficherosal,anchoB1,altoB1,nivel,subbanda,BloqueEj);        

	return 0;
}

#include <iostream>
#include "ImagenES.h"
#include "FichBits.h"

using namespace std;

int matrizContextoLL[3][3][5];

int matrizContextoHL[3][3][5];

int matrizContextoHH[3][3][5];

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

int calculaContexto(int h, int v, int d, int subbanda){

	switch(subbanda){
		case LL:
		case LH:
		return matrizContextoLL[h][v][d];
		break;
		case HL;

		break;

		case HH;



		break;


	}


}

int main (int argc, char const *argv[])
{
	int anchoB1,altoB1,nivel,subbanda;
	char fichero[20]="test/lena.bl1";
	char ficherosal[20]="test/ej.bi1";
	int **BloqueEj;

	inicializaLL();
	ReservaPlano(64,64,&BloqueEj);

	CargaBloque(fichero, &anchoB1,&altoB1, &nivel, &subbanda,BloqueEj);

	// Saber cuantos planos de bits necesitaremos
	int max = 0;
	for(int i = 0; i < anchoB1; i++){
		for(int j = 0; j < altoB1){
			if(max < BloqueEj[i][j])
			{
				max = BloqueEj[i][j];
			}
		}
	}

	
	int numeroDePlanos = 0;
	for(int i = 32; i > 0; i--)
	{
		if(max & (1<<i-1) == 1)
		{
			numeroDePlanos = i;
			break;
		}
	}
	
	cout << "El valor max es = " + max "\nEl numero de planos a crear es de " + numeroDePlanos;
	
	//Crear los planos de bits rellenandolos

	InicializaEscritura(ficherosal);
	FILE *^FCtxt=fopen("ej.ct1","wb");

	for(int i=0;i<anchoB1;i++){
		for(int j=0;j<altoB1;j++){


		// Hacer las tres pasadas




		}
	}

	FinalizaEscritura();
	fclose(FCtxt);
	GuardaBloque(ficherosal,anchoB1,altoB1,nivel,subbanda,BloqueEj);        


	cout<< "Esto algun dia ira";
	return 0;
}

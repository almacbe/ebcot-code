#include <iostream>
#include <cmath>
#include <fstream>
#include "../headers/ImagenES.h"
#include "../headers/FichBits.h"

#define SIGNO 4

using namespace std;

char matrizContextoLL[3][3][5];

char matrizContextoHL[3][3][5];

char matrizContextoHH[3][3][5];

char matrizContextoSigno[3][3][5];

void inicializaLL() {

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

void inicializaHL() {

	matrizContextoHL[0][0][0] = 0;

	matrizContextoHL[0][0][1] = 1;

	matrizContextoHL[0][0][2] = 2;
	matrizContextoHL[0][0][3] = 2;
	matrizContextoHL[0][0][4] = 2;

	matrizContextoHL[0][1][0] = 5;
	matrizContextoHL[0][1][1] = 6;
	matrizContextoHL[0][1][2] = 6;
	matrizContextoHL[0][1][3] = 6;
	matrizContextoHL[0][1][4] = 6;

	matrizContextoHL[0][2][0] = 8;
	matrizContextoHL[0][2][1] = 8;
	matrizContextoHL[0][2][2] = 8;
	matrizContextoHL[0][2][3] = 8;
	matrizContextoHL[0][2][4] = 8;

	matrizContextoHL[1][0][0] = 3;

	matrizContextoHL[1][0][1] = 3;
	matrizContextoHL[1][0][2] = 3;
	matrizContextoHL[1][0][3] = 3;
	matrizContextoHL[1][0][4] = 3;

	matrizContextoHL[1][1][0] = 7;
	matrizContextoHL[1][1][1] = 7;
	matrizContextoHL[1][1][2] = 7;
	matrizContextoHL[1][1][3] = 7;
	matrizContextoHL[1][1][4] = 7;

	matrizContextoHL[2][0][0] = 4;
	matrizContextoHL[2][0][1] = 4;
	matrizContextoHL[2][0][2] = 4;
	matrizContextoHL[2][0][3] = 4;
	matrizContextoHL[2][0][4] = 4;
	matrizContextoHL[2][1][0] = 7;
	matrizContextoHL[2][1][1] = 7;
	matrizContextoHL[2][1][2] = 7;
	matrizContextoHL[2][1][3] = 7;
	matrizContextoHL[2][1][4] = 7;
	matrizContextoHL[2][2][0] = 8;
	matrizContextoHL[2][2][1] = 8;
	matrizContextoHL[2][2][2] = 8;
	matrizContextoHL[2][2][3] = 8;
	matrizContextoHL[2][2][4] = 8;

}

void inicializaHH() {
	matrizContextoHH[0][0][0] = 0;

	matrizContextoHH[0][0][1] = 3;

	matrizContextoHH[0][0][2] = 6;
	matrizContextoHH[0][0][3] = 8;
	matrizContextoHH[0][0][4] = 8;

	matrizContextoHH[0][1][0] = 1;
	matrizContextoHH[0][1][1] = 4;
	matrizContextoHH[0][1][2] = 7;
	matrizContextoHH[0][1][3] = 8;
	matrizContextoHH[0][1][4] = 8;

	matrizContextoHH[0][2][0] = 2;
	matrizContextoHH[0][2][1] = 5;
	matrizContextoHH[0][2][2] = 7;
	matrizContextoHH[0][2][3] = 8;
	matrizContextoHH[0][2][4] = 8;

	matrizContextoHH[1][0][0] = 1;

	matrizContextoHH[1][0][1] = 4;
	matrizContextoHH[1][0][2] = 7;
	matrizContextoHH[1][0][3] = 8;
	matrizContextoHH[1][0][4] = 8;

	matrizContextoHH[1][1][0] = 2;
	matrizContextoHH[1][1][1] = 5;
	matrizContextoHH[1][1][2] = 7;
	matrizContextoHH[1][1][3] = 8;
	matrizContextoHH[1][1][4] = 8;

	matrizContextoHH[2][0][0] = 2;
	matrizContextoHH[2][0][1] = 5;
	matrizContextoHH[2][0][2] = 7;
	matrizContextoHH[2][0][3] = 8;
	matrizContextoHH[2][0][4] = 8;
	matrizContextoHH[2][1][0] = 2;
	matrizContextoHH[2][1][1] = 5;
	matrizContextoHH[2][1][2] = 7;
	matrizContextoHH[2][1][3] = 8;
	matrizContextoHH[2][1][4] = 8;
	matrizContextoHH[2][2][0] = 2;
	matrizContextoHH[2][2][1] = 5;
	matrizContextoHH[2][2][2] = 7;
	matrizContextoHH[2][2][3] = 8;
	matrizContextoHH[2][2][4] = 8;
}

char calculaContexto(int h, int v, int d, int subbanda) {

	switch (subbanda) {
	case LL:
	case LH:
		return matrizContextoLL[h][v][d];
		break;
	case HL:
		return matrizContextoHL[h][v][d];
		break;
	case HH:
		return matrizContextoHH[h][v][d];
		break;
	case SIGNO:
		return matrizContextoSigno[h][v][d];
		break;
	default:
		//ESTO SIGNIFICA ERROR
		return -100;
	}

}

bool obtenerVecinosSignificativos(char **plano, bool **m, int ancho, int alto, int i, int j,
		int *h, int *v, int *d) {

	bool r = false;
	*h = *v = *d = 0;

	// Comprobamos la vertical
	if (i > 0 && (m[i - 1][j] || plano[i - 1][j]) ) {
		(*v)++;
		r = true;
	}

	if (i < alto - 1 && (m[i + 1][j] || plano[i + 1][j]) ) {
		(*v)++;
		r = true;
	}

	//Comprobamos la horizontal
	if (j > 0 && (m[i][j - 1]|| plano[i][j - 1]) ) {
		(*h)++;
		r = true;
	}
	if (j < ancho - 1 && (m[i][j + 1]|| plano[i][j + 1]) ) {
		(*h)++;
		r = true;
	}

	// Comprabamos las diagonales	
	if (i > 0 && j > 0 && (m[i - 1][j - 1] || plano[i-1][j-1]) ) {
		(*d)++;
		r = true;
	}
	if (i > 0 && j < ancho - 1 && (m[i - 1][j + 1] || plano[i-1][j+1]) ) {
		(*d)++;
		r = true;
	}
	if (i < alto - 1 && j > 0 && (m[i + 1][j - 1] || plano[i+1][j-1]) ) {
		(*d)++;
		r = true;
	}
	if (i < alto - 1 && j < ancho - 1 && (m[i + 1][j + 1] || plano[i+1][j+1]) ) {
		(*d)++;
		r = true;
	}

	return r;
}

int main(int argc, char const *argv[]) {
	int anchoB1, altoB1, nivel, subbanda;
	char fichero[20] = "test/lena.bl1";
	char ficherosal[20] = "test/ej.bi1";
	int **BloqueEj;

	// Contadores del numero de bits generados y de numero de bits codificados en cada fase
	int bitsPropagacion, bitsRefinamiento, bitsLimpieza;
	int bitsGenProp, bitsGenRef, bitsGenLimp;

	InicializaEscritura(ficherosal);
	FILE *FCtxt = fopen("test/ej.ct1", "w");

	inicializaLL();
	ReservaPlano(64, 64, &BloqueEj);

	CargaBloque(fichero, &anchoB1, &altoB1, &nivel, &subbanda, BloqueEj);

	// Plano para guardar el signo de los valores a comprimir
	//	true es negativo
	//	false es positivo
	bool **signo;

	// Matriz de significacia
	bool **significativo;

	// Matriz de refinado
	bool **refinado;

	// Matriz para saber que bits no se han codificado
	bool **codificado;

	// Saber cuantos planos de bits necesitaremos	
	int max = 0;
	int aux = 0;

	signo = new bool*[altoB1];
	significativo = new bool*[altoB1];
	refinado = new bool*[altoB1];
	codificado = new bool*[altoB1];

	for (int i = 0; i < altoB1; i++) {

		signo[i] = new bool[anchoB1];
		significativo[i] = new bool[anchoB1];
		refinado[i] = new bool[anchoB1];
		codificado[i] = new bool[anchoB1];
		for (int j = 0; j < anchoB1; j++) {
			significativo[i][j] = refinado[i][j] = codificado[i][j] = false;
			aux = BloqueEj[i][j];
			// Necesitamos todo en valor absoluto para saber cual es el mas grande
			if (aux < 0) { // Si es negativo
				signo[i][j] = true; //Marcamos que es negativo
				aux = aux * (-1); //Lo convertimos a positivo
			} else { // Si es positivo
				signo[i][j] = false; // Marcamos que es positivo
			}
			BloqueEj[i][j] = aux;
			if (max < aux) {
				max = aux;
			}
		}
	}

	int numeroDePlanos = 0;
	for (int i = 32; i > 0; i--) {
		// El valor maximo ya esta en valor absoluto
		if ((max & (1 << i - 1)) > 0) {
			numeroDePlanos = i;
			break;
		}
	}

	cout << "El valor max es = " << max
			<< "\nEl numero de planos a crear es de " << numeroDePlanos << endl;

	// Crear los planos de bits rellenandolos
	char ***PlanoDeBits;
	PlanoDeBits = new char **[numeroDePlanos];
	for (int n = 0; n < numeroDePlanos; n++) {
		PlanoDeBits[n] = new char *[altoB1];
		for (int i = 0; i < altoB1; i++) {
			PlanoDeBits[n][i] = new char[anchoB1];
			for (int j = 0; j < anchoB1; j++) {
				if ((BloqueEj[i][j] & (1 << n)) > 0)
					PlanoDeBits[n][i][j] = 1;
				else
					PlanoDeBits[n][i][j] = 0;
			}
		}

	}

	int h, v, d;
	char contexto;

	for (int n = numeroDePlanos - 1; n >= 0; n--) {
		bitsPropagacion = bitsRefinamiento = bitsLimpieza = bitsGenProp
				= bitsGenRef = bitsGenLimp = 0;

		cout << "Comienza la codificacion del plano " << n << endl;
		// Propagacion
		cout << "Empieza propagacion ... ";
		for (int i = 0; i < altoB1; i++) {
			for (int j = 0; j < anchoB1; j++) {
				if (!significativo[i][j] && obtenerVecinosSignificativos( PlanoDeBits[n],
						significativo, anchoB1, altoB1, i, j, &h, &v, &d)) {
					if (PlanoDeBits[n][i][j]) {
						// Escribimos el bit
						EscribeBit(1);

						// Escribimos contexto
						putc(calculaContexto(h, v, d, subbanda), FCtxt);

						// Escribimos signo
						EscribeBit(signo[i][j]);

						//Escribimos contexto de signo
						putc(calculaContexto(h, v, d, SIGNO), FCtxt);

						bitsGenProp += 4;
					} else {
						// Escribimos el bit
						EscribeBit(0);

						// Escribimos contexto
						putc(calculaContexto(h, v, d, subbanda), FCtxt);

						bitsGenProp += 2;
					}
					// Marcamos el bit como que ya está codificado
					codificado[i][j] = true;

					// Marcamos el bit como significativo
					significativo[i][j] = true;

					// Aumentamos el contador de bit codificados en la fase de propagacion
					bitsPropagacion++;
				}
			}
		}
		cout << "Bits codificados " << bitsPropagacion << endl;

		// Refinamiento

		cout << "Empieza refinado ... ";
		for (int i = 0; i < altoB1; i++) {
			for (int j = 0; j < anchoB1; j++) {
				if (!codificado[i][j] && significativo[i][j]) {
					EscribeBit(PlanoDeBits[n][i][j]);
					if (refinado[i][j]) {
						contexto = 16;
					} else {
						if (obtenerVecinosSignificativos(PlanoDeBits[n], significativo,
								anchoB1, altoB1, i, j, &h, &v, &d))
							contexto = 15;
						else
							contexto = 14;
						
						refinado[i][j] = true;
					}
					
					putc(contexto, FCtxt);

					// Marcamos el bit como que ya esta codificado
					codificado[i][j] = true;

					bitsGenRef += 2;
					bitsRefinamiento++;
				}
			}
		}
		
		cout << "Bits codificados " << bitsRefinamiento << endl;
		
		// Limpieza
		cout << "Empieza limpieza ... ";
		for (int i = 0; i < altoB1; i++) {
			for (int j = 0; j < anchoB1; j++) {
				if (!codificado[i][j]) {
					if (PlanoDeBits[n][i][j]) {
						// Escribimos el bit
						EscribeBit(1);

						// Obtenemos los vecinos significativos
						obtenerVecinosSignificativos( PlanoDeBits[n], significativo, anchoB1,
								altoB1, i, j, &h, &v, &d);

						//Escribimos contexto de signo
						putc(calculaContexto(h, v, d, SIGNO), FCtxt);
						
						// Escribimos el signo
						EscribeBit(signo[i][j]);
						
						bitsGenLimp += 4;
					} else {
						// Escribimos el bit
						EscribeBit(0);

						// Obtenemos los vecinos significativos
						obtenerVecinosSignificativos( PlanoDeBits[n], significativo, anchoB1,
								altoB1, i, j, &h, &v, &d);

						// Escribimos contexto
						putc(calculaContexto(h, v, d, SIGNO), FCtxt);
						
						bitsGenLimp += 2;
					}
					bitsLimpieza++;
				} else {
					// Deshacemos la matriz de codificados porque va a comenzar la codificacíon de un nuevo plano
					codificado[i][j] = false;
				}

			}
		}
		cout << "Bits codificados " << bitsLimpieza << endl;

		cout << "Total de bits codificados " << bitsLimpieza + bitsPropagacion + bitsRefinamiento << endl;

		cout << "Total de bits generados " << bitsGenLimp + bitsGenProp
				+ bitsGenRef << endl << endl;
	}

	GuardaBloque(ficherosal, anchoB1, altoB1, nivel, subbanda, BloqueEj);

	FinalizaEscritura();
	fclose(FCtxt);

	return 0;
}

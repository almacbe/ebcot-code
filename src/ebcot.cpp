#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
#include "../headers/ImagenES.h"
#include "../headers/FichBits.h"

#define SIGNO 4

using namespace std;

char matrizContextoLL[3][3][5];

char matrizContextoHL[3][3][5];

char matrizContextoHH[3][3][5];



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

int calculaContextoSigno(int h, int v,bool ** significativo, bool **signo,int ancho, int alto) {

	int ho,ver;
	if(h==0 || v==0 || v==ancho || h==alto){
		ho=ver=0;
		return 9;
	}

	if(significativo[h-1][v] && significativo[h+1][v] && signo[h-1][v] && signo[h+1][v]){
		ho=1;
	}
	else if(significativo[h-1][v] && significativo[h+1][v] && !signo[h-1][v] && !signo[h+1][v]){
		ho=-1;
	}
	else{
		ho=0;
	}

	if(significativo[h][v-1] && significativo[h][v+1] && signo[h][v-1] && signo[h][v+1]){
		ver=1;
	}
	else if(significativo[h][v-1] && significativo[h][v+1] && !signo[h][v-1] && !signo[h][v+1]){
		ver=-1;
	}
	else{
		ver=0;
	}

	if(ho==0 && ver==0){
		return 9;
	}
	if((ho==0 && ver==1)||(ho==0 && ver==-1)){
		return 10;
	}
	if((ho==1 && ver==1)||(ho==-1 && ver==-1)){
		return 13 ;
	}
	if((ho==1 && ver==0)||(ho==-1 && ver==0)){
		return 12;
	}
	if((ho==1 && ver==-1)||(ho==-1 && ver==1)){
		return 11;
	}
	
	cerr << "Ha fallado al encontrar un contexto de signo\n";
	exit(0);
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
	default:
		//ESTO SIGNIFICA ERROR
		return -100;
	}

}

bool obtenerVecinosSignificativos(bool **m, int ancho, int alto, int i, int j, int *h, int *v, int *d) {

	bool r = false;
	*h = *v = *d = 0;
	
	// Comprobamos la vertical
	if (i > 0 && m[i - 1][j]) {
		(*v)++;
		r = true;
	}

	if (i < alto - 1 && m[i + 1][j]) {
		(*v)++;
		r = true;
	}

	//Comprobamos la horizontal
	if (j > 0 && m[i][j - 1]) {
		(*h)++;
		r = true;
	}
	if (j < ancho - 1 && m[i][j + 1]) {
		(*h)++;
		r = true;
	}

	// Comprabamos las diagonales	
	if (i > 0 && j > 0 && m[i - 1][j - 1]) {
		(*d)++;
		r = true;
	}
	if (i > 0 && j < ancho - 1 && m[i - 1][j + 1]) {
		(*d)++;
		r = true;
	}
	if (i < alto - 1 && j > 0 && m[i + 1][j - 1]) {
		(*d)++;
		r = true;
	}
	if (i < alto - 1 && j < ancho - 1 && m[i + 1][j + 1]) {
		(*d)++;
		r = true;
	}

	return r;
}

int validarArgumentos(int argc, char const **argv){
	if (argc == 3 || argc == 4){	
		return 0;
	}
	
	cout << "Se han pasado " << argc << " argumentos:" << endl;
	cout << "El formato para codificar es: ebcot nombre_de_bloque (sin la extension) numero_de_bloques "<<endl;
	cout << "El formato para decodificar es: ebcot nombre_de_bloque (sin la extension) numero_de_bloques decodificar"<<endl;
	return 1;
}

int main(int argc, char const *argv[]) {
	// Nombre del fichero del bloque
	char fichero[100];

	// Nombre del fichero de codificacion de los bits
	char ficheroBinario[100] = "test/ej.bi1";

	// Fichero de salida para el context
	char ficheroContexto[100] = "test/ej.ct1";
	FILE *FCtxt;

	// Fichero de longitudes
	char ficheroLength[100] = "test/ej.lp1";
	FILE *FLength;

	// Informacion del bloque a cargar
	int anchoBloque, altoBloque, nivel, subbanda;

	// Puntero donde se va a guardar los bloques
	int **Bloque;

	// Numero de planos que tenemos que tratar
	int numeroDePlanos;

	// Matriz tridimensional para guardar los planos de bits
	char ***PlanoDeBits;

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

	// Variables para guardar el numero de bits
	// significatios en la horizontal, vertical
	// y diagonal
	int h, v, d;
	

	// Variable para guardar el contexto que corresponda
	char contexto;

	// Variables para saber cual sera el maximo de planos a crear
	int max = 0;
	int aux = 0;

	// Contadores del numero de bits generados y de numero de bits codificados en cada fase
	int bitsPropagacion, bitsRefinamiento, bitsLimpieza;
	int bitsGenProp, bitsGenRef, bitsGenLimp;

	// Variables para guardar los bits de la parte alta y baja 
	// de los numero guardados en el fichero de tamaños
	unsigned char ParteAlta, ParteBaja;
	
	// Variables para cargar los valores de bits codificados en cada pasada, 
	// son los que se leen del fichero .lbx
	int bitsPropagacionCod, bitsRefinamientoCod, bitsLimpiezaCod;

	// Saber si codificamos o decodificamos
	// 0 -> codificamos
	// 1 -> decodificamos
	int cod_deco;

	// Numero de bloques que tenemos que codificar
	int numeroDeBloques;
	
	if(validarArgumentos(argc,argv)){
		exit(1);
	}
	
	if(argc == 3)cod_deco=0;
	else if ( argc == 4) cod_deco=1;
	else cod_deco = -1;
	
	sprintf(fichero, "%s.bl", argv[1]);
	numeroDeBloques = atoi(argv[2]);
	
	inicializaLL();
	inicializaHL();
	inicializaHH();

	if (cod_deco == 0) {
		for(int nb = 1; nb <= numeroDeBloques; nb++){
			char ficheroAux[100];
			sprintf(ficheroAux, "%s%d", fichero, nb);
			cout << fichero << endl;
			ReservaPlano(64, 64, &Bloque);
			CargaBloque(ficheroAux, &anchoBloque, &altoBloque, &nivel, &subbanda,
					Bloque);
						
			InicializaEscritura(ficheroBinario);
			FCtxt = fopen(ficheroContexto, "wb");
			FLength = fopen(ficheroLength, "wb");
		
			// Acontinuacion reservamos la memoria para todas las matrices auxiliares,
			// convertimos la matriz de bloques a valor absoluto
			// y calculamos el valor maximo del bloque para saber
			// el numero de planos de bits que vamos a necesitar

			signo = new bool*[altoBloque];
			significativo = new bool*[altoBloque];
			refinado = new bool*[altoBloque];
			codificado = new bool*[altoBloque];

			for (int i = 0; i < altoBloque; i++) {
				signo[i] = new bool[anchoBloque];
				significativo[i] = new bool[anchoBloque];
				refinado[i] = new bool[anchoBloque];
				codificado[i] = new bool[anchoBloque];
				for (int j = 0; j < anchoBloque; j++) {
					significativo[i][j] = refinado[i][j] = codificado[i][j] = false;
					aux = Bloque[i][j];
					// Necesitamos todo en valor absoluto para saber cual es el mas grande
					if (aux < 0) { // Si es negativo
						signo[i][j] = true; //Marcamos que es negativo
						aux = aux * (-1); //Lo convertimos a positivo
					} else { // Si es positivo
						signo[i][j] = false; // Marcamos que es positivo
					}
					Bloque[i][j] = aux;
					if (max < aux) {
						max = aux;
					}
				}
			}

			// Averiguamos en que posicion tiene el primer bit igual a 1
			numeroDePlanos = 0;
			for (int i = 32; i > 0; i--) {
				// El valor maximo ya esta en valor absoluto
				if ((max & (1 << i - 1)) > 0) {
					numeroDePlanos = i;
					break;
				}
			}

			cout << "El valor max es = " << max
					<< "\nEl numero de planos a crear es de " << numeroDePlanos
					<< endl;

			// Crear los planos de bits y los rellenamos
			PlanoDeBits = new char **[numeroDePlanos];
			for (int n = 0; n < numeroDePlanos; n++) {
				PlanoDeBits[n] = new char *[altoBloque];
				for (int i = 0; i < altoBloque; i++) {
					PlanoDeBits[n][i] = new char[anchoBloque];
					for (int j = 0; j < anchoBloque; j++) {
						if ((Bloque[i][j] & (1 << n)) > 0)
							PlanoDeBits[n][i][j] = 1;
						else
							PlanoDeBits[n][i][j] = 0;
					}
				}

			}

			// Comienza la codificacon
			putc(anchoBloque, FLength);
			putc(altoBloque, FLength);
			putc(nivel, FLength);
			putc(subbanda, FLength);

			// Escribimos el plano en el que esta el primer bit significativo
			putc(numeroDePlanos, FLength);
		
			for (int n = numeroDePlanos - 1; n >= 0; n--) {
				bitsPropagacion = bitsRefinamiento = bitsLimpieza = bitsGenProp
						= bitsGenRef = bitsGenLimp = 0;
				cout << "Comienza la codificacion del plano " << n << endl;
				// Propagacion
				cout << "Empieza propagacion ... ";
				for (int k = 0; k < altoBloque; k = k + 4) {
					for (int j = 0; j < anchoBloque; j++) {
						for (int i = k; i < k + 4; i++) {
							if (!significativo[i][j]
									&& obtenerVecinosSignificativos(significativo, anchoBloque, altoBloque,
											i, j, &h, &v, &d)) {
								if (PlanoDeBits[n][i][j]) {
									// Escribimos el bit
									EscribeBit(1);

									// Escribimos contexto
									putc(calculaContexto(h, v, d, subbanda), FCtxt);

									// Escribimos signo
									EscribeBit(signo[i][j]);

									//Escribimos contexto de signo
									putc(calculaContextoSigno(h, v, significativo, signo,anchoBloque,  altoBloque), FCtxt);

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

								// Aumentamos el contador de bit codificados en la fase de propagacion
								bitsPropagacion++;
							}
						}
					}
				}
				cout << "Bits codificados " << bitsPropagacion << endl;

				// Refinamiento

				cout << "Empieza refinado ... ";
				for (int k = 0; k < altoBloque; k = k + 4) {
					for (int j = 0; j < anchoBloque; j++) {
						for (int i = k; i < k + 4; i++) {
							if (!codificado[i][j] && significativo[i][j]) {
								EscribeBit(PlanoDeBits[n][i][j]);
								if (refinado[i][j]) {
									contexto = 16;
								} else {
									if (obtenerVecinosSignificativos(significativo,
											anchoBloque, altoBloque, i, j, &h, &v,
											&d))
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
				}
				cout << "Bits codificados " << bitsRefinamiento << endl;

				// Limpieza
				cout << "Empieza limpieza ... ";
				for (int k = 0; k < altoBloque; k = k + 4) {
					for (int j = 0; j < anchoBloque; j++) {
						for (int i = k; i < k + 4; i++) {
							if (!codificado[i][j]) {
								if (PlanoDeBits[n][i][j]) {
									// Escribimos el bit
									EscribeBit(1);

									// Obtenemos los vecinos significativos
									obtenerVecinosSignificativos(significativo, 
											anchoBloque, altoBloque, i, 
											j, &h, &v, &d);

									// Escribimos contexto
									putc(calculaContexto(h, v, d, subbanda), FCtxt);

									// Escribimos el signo
									EscribeBit(signo[i][j]);

									//Escribimos contexto de signo
									putc(calculaContextoSigno(h, v, significativo, signo,anchoBloque,  altoBloque), FCtxt);

									// Marcamos el bit como significativo
									significativo[i][j] = true;
								
									bitsGenLimp += 4;
								} else {
									// Escribimos el bit
									EscribeBit(0);

									// Obtenemos los vecinos significativos
									obtenerVecinosSignificativos(
											significativo, anchoBloque, altoBloque,
											i, j, &h, &v, &d);

									// Escribimos contexto
									putc(calculaContextoSigno(h, v, significativo, signo,anchoBloque,  altoBloque), FCtxt);

									bitsGenLimp += 2;
								}
								bitsLimpieza++;
							} else {
								// Deshacemos la matriz de codificados porque va a comenzar la codificacíon de un nuevo plano
								codificado[i][j] = false;
							}
						}
					}
				}
				cout << "Bits codificados " << bitsLimpieza << endl;

				cout << "Total de bits codificados " << bitsLimpieza
						+ bitsPropagacion + bitsRefinamiento << endl;

				cout << "Total de bits generados " << bitsGenLimp + bitsGenProp
						+ bitsGenRef << endl << endl;

				// Guardamos el numero de bit codificados en propagacion
				putc(bitsPropagacion / 256, FLength);
				putc(bitsPropagacion % 256, FLength);
				// Guardamos el numero de bit codificados en refinamiento
				putc(bitsRefinamiento / 256, FLength);
				putc(bitsRefinamiento % 256, FLength);

				// Guardamos el numero de bit codificados en limpieza
				putc(bitsLimpieza / 256, FLength);
				putc(bitsLimpieza % 256, FLength);
			
			
			}

			FinalizaEscritura();
			fclose(FCtxt);
			fclose(FLength);

			LiberaPlano(64, 64, &Bloque);
		
			for (int n = 0; n < numeroDePlanos; n++) {
				for (int i = 0; i < altoBloque; i++) {
					delete [] PlanoDeBits[n][i];
				}
				delete [] PlanoDeBits[n];
			}
			delete [] PlanoDeBits;
		
			for(int i = 0; i < altoBloque; i++)
			{
				delete [] signo[i];
				delete [] significativo[i];
				delete [] codificado[i];
				delete [] refinado[i];
			}
			delete [] signo;
			delete [] significativo;
			delete [] codificado;
			delete [] refinado;
		}
	}else if (cod_deco == 1) {
		InicializaLectura(ficheroBinario);
		FCtxt = fopen(ficheroContexto, "rb");
		FLength = fopen(ficheroLength, "rb");

		anchoBloque = getc(FLength);
		altoBloque = getc(FLength);
		nivel = getc(FLength);
		subbanda = getc(FLength);

		// Leemos el numero de planos de bits que se han creado
		numeroDePlanos = getc(FLength);
		
		// Declarar la memoria de los planos de bits
		PlanoDeBits = new char **[numeroDePlanos];
		for (int n = 0; n < numeroDePlanos; n++) {
			PlanoDeBits[n] = new char *[altoBloque];
			for (int i = 0; i < altoBloque; i++) {
				PlanoDeBits[n][i] = new char[anchoBloque];
			}

		}

		// Acontinuacion reservamos la memoria para todas las matrices auxiliares,
		// convertimos la matriz de bloques a valor absoluto
		// y calculamos el valor maximo del bloque para saber
		// el numero de planos de bits que vamos a necesitar

		signo = new bool*[altoBloque];
		significativo = new bool*[altoBloque];
		codificado = new bool*[altoBloque];

		for (int i = 0; i < altoBloque; i++) {
			signo[i] = new bool[anchoBloque];
			significativo[i] = new bool[anchoBloque];
			codificado[i] = new bool[anchoBloque];
			for (int j = 0; j < anchoBloque; j++) {
				significativo[i][j] = codificado[i][j] = false;
			}
		}

		// Comienza la decodificacion
		for (int n = numeroDePlanos - 1; n >= 0; n--) {
			bitsPropagacion = bitsRefinamiento = bitsLimpieza = bitsGenProp
					= bitsGenRef = bitsGenLimp = 0;
			
			ParteAlta = getc(FLength);
			ParteBaja = getc(FLength);
			bitsPropagacionCod = ParteAlta * 256 + ParteBaja;

			ParteAlta = getc(FLength);
			ParteBaja = getc(FLength);
			bitsRefinamientoCod = ParteAlta * 256 + ParteBaja;

			ParteAlta = getc(FLength);
			ParteBaja = getc(FLength);
			bitsLimpiezaCod = ParteAlta * 256 + ParteBaja;

			cout << "Comienza la decodificacion del plano " << n << endl;
			// Propagacion
			cout << "Empieza propagacion ... ";
			for (int k = 0; k < altoBloque; k = k + 4) {
				for (int j = 0; j < anchoBloque; j++) {
					for (int i = k; i < k + 4; i++) {
						if (!significativo[i][j]
								&& obtenerVecinosSignificativos(
										significativo, anchoBloque, altoBloque,
										i, j, &h, &v, &d)) {
							// Leemos un bit
							PlanoDeBits[n][i][j] = LeeBit();
							// Leer contexto asociado bit
							// FALTA!!!
							// contexto = getc(Fichero de contexto);

							if (PlanoDeBits[n][i][j]) {
								signo[i][j] = LeeBit();
							}

							// Leer contexto asociado signo
							// FALTA!!!
							// contexto = getc(Fichero de contexto);

							// Marcamos el bit como que ya está codificado
							codificado[i][j] = true;

							// Aumentamos el contador de bit codificados en la fase de propagacion
							bitsPropagacion++;
						}
					}
				}
			}
			cout << "Bits decodificados " << bitsPropagacion
					<< ", se codificaron " << bitsPropagacionCod << endl;

			// Refinamiento

			cout << "Empieza refinado ... ";
			for (int k = 0; k < altoBloque; k = k + 4) {
				for (int j = 0; j < anchoBloque; j++) {
					for (int i = k; i < k + 4; i++) {
						if (!codificado[i][j] && significativo[i][j]) {
							// Leemos un bit
							PlanoDeBits[n][i][j] = LeeBit();

							// Leemos el bit de contexto
							// contexto = getc(FCtxt);

							// Marcamos el bit como que ya esta codificado
							codificado[i][j] = true;

							bitsRefinamiento++;
						}
					}
				}
			}
			cout << "Bits decodificados " << bitsRefinamiento
					<< ", se codificaron " << bitsRefinamientoCod << endl;

			// Limpieza
			cout << "Empieza limpieza ... ";
			for (int k = 0; k < altoBloque; k = k + 4) {
				for (int j = 0; j < anchoBloque; j++) {
					for (int i = k; i < k + 4; i++) {
						if (!codificado[i][j]) {
							PlanoDeBits[n][i][j] = LeeBit();

							// Leemos el contexto asociado al bit
							// contexto = getc(FCtxt)

							if (PlanoDeBits[n][i][j]) {
								// Leer contexto asociado signo
								// FALTA!!!
								// contexto = getc(Fichero de contexto);
								signo[i][j] = LeeBit();
								// Marcamos el bit como significativo
								significativo[i][j] = true;
							}
							bitsLimpieza++;
						} else {
							// Deshacemos la matriz de codificados porque
							// va a comenzar la codificacíon de un nuevo plano
							codificado[i][j] = false;
						}
					}
				}
			}
			cout << "Bits codificados " << bitsLimpieza << ", se codificaron "
					<< bitsLimpiezaCod << endl;

			cout << "Total de bits codificados " << bitsLimpieza
					+ bitsPropagacion + bitsRefinamiento << endl;
		}

		FinalizaLectura();
		fclose(FCtxt);
		fclose(FLength);

		// Convertimos los planos de bits al Bloque
		ReservaPlano(anchoBloque, altoBloque, &Bloque);

		for(int i = 0; i < altoBloque; i++)
		{
			for(int j = 0; j < anchoBloque; j++)
			{
				Bloque[i][j] = 0;
				for(int n = numeroDePlanos - 1; n >= 0 ; n--)
				{
					if(PlanoDeBits[n][i][j])
					{
						Bloque[i][j] += (int) pow(2.0,n);
					}
				}
					if(signo[i][j])
						Bloque[i][j] = (-1) * Bloque[i][j];
			}
		}
		
		GuardaBloque("test/lenaCod.bl1", anchoBloque, altoBloque, nivel, subbanda,  Bloque);
		
			for (int n = 0; n < numeroDePlanos; n++) {
				for (int i = 0; i < altoBloque; i++) {
					delete [] PlanoDeBits[n][i];
				}
				delete [] PlanoDeBits[n];
			}
			delete [] PlanoDeBits;

			for(int i = 0; i < altoBloque; i++)
			{
				delete [] signo[i];
				delete [] significativo[i];
				delete [] codificado[i];
			}
			delete [] signo;
			delete [] significativo;
			delete [] codificado;
	} 
	else{
		cout << "No hemos hecho nada" << endl;
	}
	return 0;
}

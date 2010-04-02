#ifndef FichBitsH
#define FichBitsH

typedef struct tagTFichBits
{
  unsigned char salida_byte;
  unsigned char entrada_byte;
  int pos,quedan;
  FILE *fich;
} TFichBits;

// Rutinas para escribir en fichero
int InicializaEscritura(char *nombre);
void EscribePalabra(int nbits, int palabra); // escribe una palabra de nbits en el fichero
void EscribeBit(int bit); // escribe un bit en el fichero
void FinalizaEscritura();

// Rutinas para leer de fichero
int InicializaLectura(char *nombre);
int LeePalabra(int nbits); // lee una palabra de nbits del fichero
int LeeBit(); // lee un bit del fichero
void FinalizaLectura();

#endif

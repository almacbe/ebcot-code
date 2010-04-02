#include <stdio.h>
#include "FichBits.h"

static TFichBits FichES;

//
// Rutinas para escribir en fichero
//

int InicializaEscritura(char *nombre)
{
  if ((FichES.fich=fopen(nombre,"wb"))==NULL) return 1;
  FichES.salida_byte = 0x00;
  FichES.pos=8;
  return 0;
}

// escribe una palabra de nbits en el fichero
void EscribePalabra(int nbits, int palabra)
{ 
  while (nbits>FichES.pos) 
  {
		nbits-=FichES.pos;
		FichES.salida_byte |= (palabra>>nbits);		
		putc((int)FichES.salida_byte,FichES.fich);
		FichES.pos=8; 
		FichES.salida_byte=0;
  }
  FichES.pos-=nbits;
  FichES.salida_byte |= (palabra<<FichES.pos);
}

// escribe un bit en el fichero
void EscribeBit(int bit)
{
  EscribePalabra(1,bit);
}

void FinalizaEscritura()
{
  if (FichES.pos!=8) putc((int)FichES.salida_byte,FichES.fich);
  fclose(FichES.fich);
}

//
// Rutinas para leer de fichero
//

int InicializaLectura(char *nombre)
{
  if ((FichES.fich=fopen(nombre,"rb"))==NULL) return 1;
  FichES.quedan=FichES.entrada_byte = 0;
  FichES.entrada_byte=getc(FichES.fich);
  FichES.quedan=8;
  return 0;
}

// lee una palabra de nbits del fichero
int LeePalabra(int nbits)
{
  int f,palabra=0;
  for (f=0;f<nbits;f++)
    palabra=(palabra<<1)|LeeBit();
  return palabra;
}

// lee un bit del fichero
int LeeBit()
{
  int bit;
  if (FichES.quedan==0)
  {
		FichES.entrada_byte=getc(FichES.fich);
		FichES.quedan=8;
  }
  bit=(FichES.entrada_byte&0x80)>>7;
  FichES.entrada_byte<<=1;
  FichES.quedan--;
  return bit;
}

void FinalizaLectura()
{
  fclose(FichES.fich);
}
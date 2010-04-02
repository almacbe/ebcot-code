#include <stdio.h>
#include <stdlib.h>
#include "ImagenES.h"

//
//  RUTINAS PARA RESERVA DE MEMORIA
//

void ReservaPlano(int ancho, int alto, int ***Plano)
{
  *Plano=(int **)malloc(alto*sizeof(int *));
  for (int f=0;f<alto;f++)
    *((*Plano)+f)=(int *)malloc(ancho*sizeof(int));
}

void LiberaPlano(int ancho, int alto, int ***Plano)
{
  for (int f=0;f<alto;f++) free(*((*Plano)+f)); free(*Plano);
}

void ReservaPlano(int ancho, int alto, float ***Plano)
{
  *Plano=(float **)malloc(alto*sizeof(float *));
  for (int f=0;f<alto;f++)
    *((*Plano)+f)=(float *)malloc(ancho*sizeof(float));
}

void LiberaPlano(int ancho, int alto, float ***Plano)
{
  for (int f=0;f<alto;f++) free(*((*Plano)+f)); free(*Plano);
}

//
//  RUTINAS PARA LEER BLOQUES DE DATOS
//

void LeeBloque(FILE *fich,int tam, int *PuntBufferAux)
{
	fread(PuntBufferAux,sizeof(int),tam,fich);  
}

void GuardaBloque(FILE *fich,int tam, int *PuntBufferAux)
{
	fwrite(PuntBufferAux,sizeof(int),tam,fich);
}

void LeeBloque(FILE *fich,int tam, float *PuntBufferAux)
{
	fread(PuntBufferAux,sizeof(float),tam,fich);  
}

void GuardaBloque(FILE *fich,int tam, float *PuntBufferAux)
{
	fwrite(PuntBufferAux,sizeof(float),tam,fich);
}

void LeeBloqueDeByte(FILE *fich,int tam, int *PuntBufferAux)
{
	for (int f=0;f<tam;f++) *PuntBufferAux++=(unsigned char)getc(fich);
}

void GuardaBloqueEnByte(FILE *fich,int tam, int *PuntBufferAux)
{
	for (int f=0;f<tam;f++) 
	{
		if (*PuntBufferAux<0) putc(0,fich); else if (*PuntBufferAux>255) putc(255,fich); else putc(*PuntBufferAux,fich);
		PuntBufferAux++;
	}
}

//
//  RUTINAS PARA CARGAR/GUARDAR PLANOS DE DATOS
//

void CargaPlano(FILE *fichero, int ancho, int alto, int **Plano)
{
  for (int f=0;f<alto;f++) LeeBloque(fichero, ancho, Plano[f]);
}

void GuardaPlano(FILE *fichero, int ancho, int alto, int **Plano)
{
  for (int f=0;f<alto;f++) GuardaBloque(fichero, ancho, Plano[f]);  
}

void CargaPlano(FILE *fichero, int ancho, int alto, float **Plano)
{
  for (int f=0;f<alto;f++) LeeBloque(fichero, ancho, Plano[f]);
}

void GuardaPlano(FILE *fichero, int ancho, int alto, float **Plano)
{
  for (int f=0;f<alto;f++) GuardaBloque(fichero, ancho, Plano[f]);  
}

void CargaPlanoDeByte(FILE *fichero, int ancho, int alto, int **Plano)
{
  for (int f=0;f<alto;f++) LeeBloqueDeByte(fichero, ancho, Plano[f]);
}

void GuardaPlanoEnByte(FILE *fichero, int ancho, int alto, int **Plano)
{
  for (int f=0;f<alto;f++) GuardaBloqueEnByte(fichero, ancho, Plano[f]);  
}

//
//  RUTINAS PARA CARGAR/GUARDAR FICHEROS
//

int CargaRawRGB(char *Nombre, int ancho, int alto, int **R, int **G, int **B)
{
  FILE *fich;

  fich=fopen(Nombre,"rb");
  if (fich==NULL) return 1;
  CargaPlanoDeByte(fich, ancho, alto, R);
  CargaPlanoDeByte(fich, ancho, alto, G);
  CargaPlanoDeByte(fich, ancho, alto, B);
  fclose(fich);
  return 0;
}

int GuardaRawRGB(char *Nombre, int ancho, int alto, int **R, int **G, int **B)
{
  FILE *fich;

  fich=fopen(Nombre,"wb");
  if (fich==NULL) return 1;
  GuardaPlanoEnByte(fich, ancho, alto, R);
  GuardaPlanoEnByte(fich, ancho, alto, G);
  GuardaPlanoEnByte(fich, ancho, alto, B);
  fclose(fich);
  return 0;
}

int CargaYCbCr420(char *Nombre, int ancho, int alto, float **Y, float **Cb420, float **Cr420)
{
  FILE *fich;

  fich=fopen(Nombre,"rb");
  if (fich==NULL) return 1;
  CargaPlano(fich, ancho, alto, Y);
  CargaPlano(fich, ancho/2, alto/2, Cb420);
  CargaPlano(fich, ancho/2, alto/2, Cr420);
  fclose(fich);
  return 0;
}

int GuardaYCbCr420(char *Nombre, int ancho, int alto, float **Y, float **Cb420, float **Cr420)
{
  FILE *fich;

  fich=fopen(Nombre,"wb");
  if (fich==NULL) return 1;
  GuardaPlano(fich, ancho, alto, Y);
  GuardaPlano(fich, ancho/2, alto/2, Cb420);
  GuardaPlano(fich, ancho/2, alto/2, Cr420);
  fclose(fich);
  return 0;
}

int CargaDWT420(char *Nombre, int ancho, int alto, float **Y, float **Cb420, float **Cr420)
{
  return CargaYCbCr420(Nombre, ancho, alto, Y, Cb420, Cr420);
}

int GuardaDWT420(char *Nombre, int ancho, int alto, float **Y, float **Cb420, float **Cr420)
{
  return GuardaYCbCr420(Nombre, ancho, alto, Y, Cb420, Cr420);
}

int CargaDWT420q(char *Nombre, int ancho, int alto, int **Y, int **Cb420, int **Cr420)
{
  FILE *fich;

  fich=fopen(Nombre,"rb");
  if (fich==NULL) return 1;
  CargaPlano(fich, ancho, alto, Y);
  CargaPlano(fich, ancho/2, alto/2, Cb420);
  CargaPlano(fich, ancho/2, alto/2, Cr420);
  fclose(fich);
  return 0;
}

int GuardaDWT420q(char *Nombre, int ancho, int alto, int **Y, int **Cb420, int **Cr420)
{
  FILE *fich;

  fich=fopen(Nombre,"wb");
  if (fich==NULL) return 1;
  GuardaPlano(fich, ancho, alto, Y);
  GuardaPlano(fich, ancho/2, alto/2, Cb420);
  GuardaPlano(fich, ancho/2, alto/2, Cr420);
  fclose(fich);
  return 0;
}

int CargaBloque(char *Nombre, int *ancho, int *alto, int *nivel, int *subbanda, int **Bloque)
{
  FILE *fich;

  fich=fopen(Nombre,"rb");
  if (fich==NULL) return 1;

  *ancho=getc(fich);
  *alto=getc(fich);
  *nivel=getc(fich);
  *subbanda=getc(fich);
  CargaPlano(fich, *ancho, *alto, Bloque);
  fclose(fich);
  return 0;
}

int GuardaBloque(char *Nombre, int ancho, int alto, int nivel, int subbanda, int **Bloque)
{
  FILE *fich;

  fich=fopen(Nombre,"wb");
  if (fich==NULL) return 1;

  putc(ancho,fich);
  putc(alto,fich);
  putc(nivel,fich);
  putc(subbanda,fich);
  GuardaPlano(fich, ancho, alto, Bloque);
  fclose(fich);
  return 0;
}



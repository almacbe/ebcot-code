#ifndef ImagenESH
#define ImagenESH

#define LL 0
#define HL 1
#define LH 2
#define HH 3

//  RUTINAS PARA RESERVA DE MEMORIA

void ReservaPlano(int ancho, int alto, int ***Plano);
void LiberaPlano(int ancho, int alto, int ***Plano);

void ReservaPlano(int ancho, int alto, float ***Plano);
void LiberaPlano(int ancho, int alto, float ***Plano);

//  RUTINAS PARA CARGAR/GUARDAR FICHEROS

int CargaRawRGB(char *Nombre, int ancho, int alto, int **R, int **G, int **B);
int GuardaRawRGB(char *Nombre, int ancho, int alto, int **R, int **G, int **B);

int CargaYCbCr420(char *Nombre, int ancho, int alto, float **Y, float **Cb420, float **Cr420);
int GuardaYCbCr420(char *Nombre, int ancho, int alto, float **Y, float **Cb420, float **Cr420);

int CargaDWT420(char *Nombre, int ancho, int alto, float **Y, float **Cb420, float **Cr420);
int GuardaDWT420(char *Nombre, int ancho, int alto, float **Y, float **Cb420, float **Cr420);

int CargaDWT420q(char *Nombre, int ancho, int alto, int **Y, int **Cb420, int **Cr420);
int GuardaDWT420q(char *Nombre, int ancho, int alto, int **Y, int **Cb420, int **Cr420);

int GuardaBloque(char *Nombre, int ancho, int alto, int nivel, int subbanda, int **Bloque);
int CargaBloque(char *Nombre, int *ancho, int *alto, int *nivel, int *subbanda, int **Bloque);

#endif

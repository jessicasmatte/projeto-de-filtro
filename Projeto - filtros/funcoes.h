#ifndef FUNCOES_H
#define FUNCOES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "pixel.h" //separado para deixar funcoes.h apenas as funcoes real

FILE *imagemA;
typedef struct{
    int r;
    int g;
    int b;
} pixel; //definindo as cores para pegar na matriz

enum selecionar_opcao {Binarizar = 1, Cinza, Blurring, Sharpening, Rotacionar, Ampliar, Reduzir, Borda, Negativo, Espelhar, Altorelevo, Sepia, 
  Sair}opcao;

int i,j,r,g,b,lar, alt, cormax;//variveis de altura, largura e cor max da img	

pixel **newImg;
pixel **newImg2;

int matriz_Sharpening[3][3] = {
            {0, -1, 0},
            {-1, 5,-1},
            {0, -1, 0}
    };
int matriz_blurring[3][3] = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}
    };
int matriz_borda[3][3] = {
            {-1,-1,-1},
            {-1, 8,-1},
            {-1,-1,-1}
    };
int matriz_relevo[3][3] = {
            {-2,-1, 0},
            {-1, 1, 1},
            { 0, 1, 2}
    };

void menu(FILE *imagemA); // Funcao do menu com as opcoes pro usuario

void alocar_img(FILE *imagemA); // Funcao para alocar imagem

void Binarizar_img(char *nome_saida,pixel **newImg,int lar, int alt, int cormax); // Funcao de binarizar

void preto_branco(char *nome_saida,pixel **newImg,int lar, int alt, int cormax); //Funcao de escala de cinza

void Rotacionar_img(char *nome_saida,pixel **newImg,int lar, int alt, int cormax, float graus); // Funcao de rotacionar imagem

int Ampliar_img(char *nome_saida,pixel **newImg,int lar, int alt, int cormax, int ampliar, int k); // Funcao de ampliar
 
int Reduzir_img(char *nome_saida,pixel **newImg,int lar, int alt, int cormax, int reduzir, int k); // Funcao de reduzir os pixels

void convulacao(char *nome_saida,pixel **newImg,int lar, int alt, int cormax,int opcao);

void printar(char *nome_saida,pixel **newImg,int lar, int alt, int cormax);

void negativo(char *nome_saida,pixel **newImg,int lar, int alt, int cormax); // Funcao de por em negativo

void espelhar(char *nome_saida,pixel **newImg,int lar, int alt, int cormax); // Funcao de espelhar

void auto_relevo(char *nome_saida,pixel **newImg,int lar, int alt, int cormax); // Funcao de auto relevo

void sepia(char *nome_saida,pixel **newImg,int lar, int alt, int cormax); // Funcao de auto relevo

#endif
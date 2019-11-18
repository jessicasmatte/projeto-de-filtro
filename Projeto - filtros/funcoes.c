#include "funcoes.h"

void menu(FILE *imagemA){
	int ampliar, reduzir, opcao;
	float graus;
	char nome_saida[20];
	
	
	printf("O que deseja fazer?\n");

	printf("1. Binarizar.\n");
	printf("2. Escala de cinza\n");
	printf("3. Blurring\n");
	printf("4. Sharpening\n");
	printf("5. Rotacionar\n");
	printf("6. Ampliar\n");
	printf("7. Reduzir\n");
	printf("8. Borda\n");
	printf("9. Negativo\n");\
	printf("10. Espelhar\n");
	printf("11. Alto relevo\n");
	printf("12. Sepia\n");
	printf("13. Sair\n");
	
	scanf("%d", &opcao);

	if(opcao==Binarizar){
		alocar_img(imagemA);
		printf("Digite o nome de saida da imagem(sem .ppm).\n");
			scanf("%s",nome_saida);
			strcat(nome_saida, ".ppm");
		Binarizar_img(nome_saida,newImg,lar, alt,cormax);
	}
	if(opcao==Cinza){
		alocar_img(imagemA);
		printf("Digite o nome de saida da imagem(sem .ppm).\n");
			scanf("%s",nome_saida);
			strcat(nome_saida, ".ppm");
		preto_branco(nome_saida,newImg,lar, alt,cormax);
		printar(nome_saida,newImg,lar,alt,cormax);
	}
	if(opcao==Rotacionar){
		printf("Quantos graus?(90, 180 ou 270).\n");
			scanf("%f", &graus);
		
		if (graus == 90 || graus == 180 || graus == 270)
		{	alocar_img(imagemA);
			printf("Digite o nome de saida da imagem(sem .ppm).\n");
				scanf("%s",nome_saida);
				strcat(nome_saida, ".ppm");
			Rotacionar_img(nome_saida,newImg,lar, alt,cormax,graus);
		} 
		else{
			printf("Valor invalido.\n");
			menu(imagemA);
		}
			
		
		}
	if(opcao==Ampliar){
		printf("Quantas vezes deseja ampliar? (Max de 4x)\n");
		scanf("%d", &ampliar);
	
		if(ampliar >0 && ampliar < 5){
		alocar_img(imagemA);
		printf("Digite o nome de saida da imagem(sem .ppm).\n");
				scanf("%s",nome_saida);
				strcat(nome_saida, ".ppm");
		int k=0;
		Ampliar_img(nome_saida,newImg,lar, alt,cormax, ampliar, k);
	}
	else{
		printf("Valor invalido.\n");
		menu(imagemA);
		}
	}
	if(opcao==Reduzir){
		printf("Quantas vezes deseja reduzir? (Max de 4x)\n");
		scanf("%d", &reduzir);

		if(reduzir >0 && reduzir < 5){
		alocar_img(imagemA);
		printf("Digite o nome de saida da imagem(sem .ppm).\n");
				scanf("%s",nome_saida);
				strcat(nome_saida, ".ppm");
			int k =0;
		Reduzir_img(nome_saida,newImg,lar, alt,cormax, reduzir, k);
		//printar(nome_saida,newImg,lar,alt,cormax);
	}
	else{
		printf("Valor invalido.\n");
		menu(imagemA);
		}

	}
	if(opcao==Blurring || opcao==Sharpening || opcao==Borda || opcao==Altorelevo){
		alocar_img(imagemA);
			printf("Digite o nome de saida da imagem(sem .ppm).\n");
				scanf("%s",nome_saida);
				strcat(nome_saida, ".ppm");
		convulacao(nome_saida,newImg,lar, alt,cormax, opcao);
		printar(nome_saida,newImg,lar,alt,cormax);
	}
	if(opcao==Negativo){
		alocar_img(imagemA);
		printf("Digite o nome de saida da imagem(sem .ppm).\n");
			scanf("%s",nome_saida);
			strcat(nome_saida, ".ppm");
		negativo(nome_saida,newImg,lar, alt,cormax);
		printar(nome_saida,newImg,lar,alt,cormax);
	}
	if(opcao==Espelhar){
		alocar_img(imagemA);
		printf("Digite o nome de saida da imagem(sem .ppm).\n");
			scanf("%s",nome_saida);
			strcat(nome_saida, ".ppm");
		espelhar(nome_saida,newImg,lar, alt,cormax);
		printar(nome_saida,newImg,lar,alt,cormax);
	}
	if(opcao==Sepia){
		alocar_img(imagemA);
		printf("Digite o nome de saida da imagem(sem .ppm).\n");
			scanf("%s",nome_saida);
			strcat(nome_saida, ".ppm");
		sepia(nome_saida,newImg,lar, alt,cormax);
		printar(nome_saida,newImg,lar,alt,cormax);
	}
	if(opcao==Sair){
		exit(0);
	}
}
void alocar_img(FILE *imagemA){
	char ignore[1000];
	char tipo[3];
	int i,j,r,g,b; //Salvando variaveis
	int *vLar,*valt, *vCor; //salvando como ponteiros
	vLar = &lar; //valor da largura/linha
	valt = &alt; //valor altura/coluna
	vCor = &cormax; //valor de cor maxima da imagem
	
		fgets(ignore, sizeof ignore, imagemA);
		while(ignore[0] == '#') {
			fgets(ignore, sizeof ignore, imagemA);
		}
		sscanf(ignore, "%s", tipo);

		fgets(ignore, sizeof ignore, imagemA);
		while(ignore[0] == '#') {
			fgets(ignore, sizeof ignore, imagemA);
		}
		sscanf(ignore, "%d %d", vLar, valt);

		fgets(ignore, sizeof ignore, imagemA);
		while(ignore[0] == '#') {
			fgets(ignore, sizeof ignore, imagemA);
		}
		sscanf(ignore, "%d", vCor);
		//pega os valores de altura, largura e cormax ignorando comentarios na imagem

	newImg = (pixel**) malloc(sizeof(pixel*)*alt);
		for(i =0; i < alt; i++){
			newImg[i] = (pixel*) malloc(sizeof(pixel)*lar);
		}//alocando memoria de acordo com o tamanho da imagem
			
		for(i=0; i< alt; i++){ //verificando linha
			for(j=0; j < lar; j++){ //verificando coluna
				fscanf(imagemA, "%d %d %d", &newImg[i][j].r, &newImg[i][j].g, &newImg[i][j].b);//salvando valores por r g b;
				
			}
		}
}
//fim
void Binarizar_img(char *nome_saida,pixel **newImg,int lar, int alt, int cormax){
	
	int aux = 0, cor, limite; //declarando variaveis

	printf("Digite um valor para o threshold\n");
	scanf("%d", &limite); //salvando valor para o limitrofe
	
	for(i=0; i< alt; i++){ //verificando linha
		for(j=0; j < lar; j++){ //verificando coluna
			aux = newImg[i][j].r; //salvando os valores de rgb para o aux
			aux = newImg[i][j].g;					
			aux = newImg[i][j].b;
			
		if(aux>limite){//se o valor do pixel for maior que o threshhold
		cor=255;//define como valor maximo
		}
		else{
		cor=0;//define como valor minimo
		}

		newImg[i][j].r = cor; //salvando valores para imprimir
		newImg[i][j].g = cor;
		newImg[i][j].b = cor;
		}
	}
		printar(nome_saida,newImg,lar,alt,cormax);
}
//fim
void preto_branco(char *nome_saida,pixel **newImg,int lar, int alt, int cormax){	
	

	for(i=0; i< alt; i++){ //verificando linha
		for(j=0; j < lar; j++){ //verificando coluna
		newImg[i][j].r = (newImg[i][j].r + newImg[i][j].g + newImg[i][j].b)/3;
		newImg[i][j].g = newImg[i][j].r;
		newImg[i][j].b = newImg[i][j].r;
		}
	}
}
//fim
void Rotacionar_img(char *nome_saida,pixel **newImg,int lar, int alt, int cormax, float graus){

FILE *arq_saida;
arq_saida = fopen(nome_saida,"w+");
		
	if(graus == 90){
	fprintf(arq_saida,"P3\n%d %d\n%d\n",alt,lar,cormax); //abeçalho da imagem//
		
	for(j = lar -1; j >=0; j--){ //verificando coluna
		for(i = 0; i < alt; i++){ //verificando linha
		fprintf(arq_saida,"%d\n", newImg[i][j].r);
		fprintf(arq_saida,"%d\n", newImg[i][j].g);
		fprintf(arq_saida,"%d\n", newImg[i][j].b);
		}
	}
	printf("Sucesso!!!\n");
	}
	if(graus == 180){
	fprintf(arq_saida,"P3\n%d %d\n%d\n",lar,alt,cormax); //abeçalho da imagem//
	
	for(i = alt-1; i >= 0; i--){ //verificando linha
		for(j = lar-1; j >= 0; j--){ //verificando coluna
		fprintf(arq_saida,"%d\n", newImg[i][j].r);
		fprintf(arq_saida,"%d\n", newImg[i][j].g);
		fprintf(arq_saida,"%d\n", newImg[i][j].b);
		}
	}
	printf("Sucesso!!!\n");
	}
			
	if(graus == 270){
	fprintf(arq_saida,"P3\n%d %d\n%d\n",alt,lar,cormax); //abeçalho da imagem//
	
	for(j = 0; j < lar -1; j++){ //verificando coluna
		for(i = alt-1; i >= 0; i--){ //verificando linha
		fprintf(arq_saida,"%d\n", newImg[i][j].r);
		fprintf(arq_saida,"%d\n", newImg[i][j].g);
		fprintf(arq_saida,"%d\n", newImg[i][j].b);
		}
	}
				printf("Sucesso!!!\n");
	}

	}
//fim
int Ampliar_img(char *nome_saida,pixel **newImg,int lar, int alt, int cormax, int ampliar, int k){
	
	
	if(k < ampliar){
	
	pixel **newImg2;
	int *vLar,*valt;
	vLar = &lar;
	valt = &alt;
	
		
	*vLar = 2*lar;
	*valt = 2*alt;
	newImg2 = (pixel**) malloc(sizeof(pixel*)*alt);
	for(i =0; i < alt; i++){
		newImg2[i] = (pixel*) malloc(sizeof(pixel)*lar);
	} //alocando memoria para matriz auxiliar
	
			
		int m,l;
			for(i=0; i< alt; i++){ //verificando linha
				for (m =0; m < 2; m++){
					for(j=0; j < lar; j++){ //verificando coluna
						for(l = 0; l < 2; l++){
							newImg2[i][j].r = newImg[i/2][j/2].r;
							newImg2[i][j].g = newImg[i/2][j/2].g;
							newImg2[i][j].b = newImg[i/2][j/2].b;
						}
					}
				}	
			}

	newImg = (pixel**) malloc(sizeof(pixel*)*alt);
	for(i =0; i < alt; i++){
		newImg[i] = (pixel*) malloc(sizeof(pixel)*lar);
	} //alocando memoria para matriz auxiliar
			for(i=0; i< alt; i++){ //verificando linha
				for(j=0; j < lar; j++){ //verificando coluna
						newImg[i][j].r = newImg2[i][j].r;
						newImg[i][j].g = newImg2[i][j].g;
						newImg[i][j].b = newImg2[i][j].b;
				}
			}
	return Ampliar_img(nome_saida,newImg,lar, alt,cormax,ampliar,k+1);
	}
	else{
			printar(nome_saida,newImg,lar,alt,cormax);
	}
}
//fim
int Reduzir_img(char *nome_saida,pixel **newImg,int lar, int alt, int cormax, int reduzir, int k){
	
	if(k < reduzir){
	pixel **newImg2;
	int *vLar,*valt;
	vLar = &lar;
	valt = &alt;
	
	*vLar = lar/2;
	*valt = alt/2;
	
	newImg2 = (pixel**) malloc(sizeof(pixel*)*alt);
	for(i = 0; i < alt; i++){
	newImg2[i] = (pixel*) malloc(sizeof(pixel)*lar);
	} //alocando memoria para matriz auxiliar

    	for (i = 0; i < alt; i++){
			for (j = 0; j < lar; j++){;//estabelecendo valores de incremento para aux como 0
			newImg2[i][j].r = (newImg[i*2][j*2].r + newImg[i*2+1][j*2+1].r + newImg[i*2][j*2+1].r + newImg[i*2+1][j*2].r)/4;         				
			newImg2[i][j].g = (newImg[i*2][j*2].g + newImg[i*2+1][j*2+1].g + newImg[i*2][j*2+1].g + newImg[i*2+1][j*2].g)/4; 
			newImg2[i][j].b = (newImg[i*2][j*2].b + newImg[i*2+1][j*2+1].b + newImg[i*2][j*2+1].b + newImg[i*2+1][j*2].b)/4;
			//guarda os valores da cor ao aux para escrever no arquivo
			}
		}
	newImg = (pixel**) malloc(sizeof(pixel*)*alt);
	for(i =0; i < alt; i++){
	newImg[i] = (pixel*) malloc(sizeof(pixel)*lar); //alocando memoria
	}
	for (i = 0; i < alt; i++){
		for (j = 0; j < lar; j++){//estabelecendo valores de incremento para aux como 0
		newImg[i][j].r = newImg2[i][j].r;                 			
		newImg[i][j].g = newImg2[i][j].g; //guarda os valores da cor ao aux para escrever no arquivo
		newImg[i][j].b = newImg2[i][j].b;
		}
	}

	return Reduzir_img(nome_saida,newImg,lar, alt,cormax,reduzir,k+1);
	
	}
	else{
	printar(nome_saida,newImg,lar,alt,cormax);
	}
}	
//fim
void convulacao(char *nome_saida,pixel **newImg,int lar, int alt, int cormax,int opcao){
	int divisor;
	int auxr,auxg,auxb,k,m;
	int matriz_covulacao[3][3];

	if(opcao == 4){
		for(i = 0; i < 3 ; i++){
			for(j = 0; j < 3 ; j++){
			matriz_covulacao[i][j]= matriz_Sharpening[i][j];
			}
		}
	divisor = 1;
	}
	if(opcao == 3){
		for(i = 0; i < 3 ; i++){
			for(j = 0; j < 3 ; j++){
			matriz_covulacao[i][j]= matriz_blurring[i][j];
			}
		}
	divisor = 9;
	}
	if(opcao == 8){
		for(i = 0; i < 3 ; i++){
			for(j = 0; j < 3 ; j++){
			matriz_covulacao[i][j] = matriz_borda[i][j];
			}
		}
	divisor = 1;
	}
	if(opcao == 11){
		for(i = 0; i < 3 ; i++){
			for(j = 0; j < 3 ; j++){
			matriz_covulacao[i][j]= matriz_relevo[i][j];
			}
		}
	divisor = 1;
	}
	newImg2 = (pixel**) malloc(sizeof(pixel*)*alt);
	
	for(i =0; i < alt; i++){
		newImg2[i] = (pixel*) malloc(sizeof(pixel)*lar);
	} //alocando memoria
	
	
			
	for(i=0; i < alt; i++){ //verificando linha
		for(j=0; j < lar; j++){ //verificando coluna		
			if (i == 0 || i == (alt-1) || j == 0 || j == (lar-1)){ //Definindo valor para bordas
			newImg2[i][j].r = newImg[i][j].r;
			newImg2[i][j].g = newImg[i][j].g;
			newImg2[i][j].b = newImg[i][j].b;	
			}
			else{	 
			auxr = 0;
            		auxg = 0;
           		auxb = 0;

	for(k=0;k<3;k++){
		for(m=0;m<3;m++){
                auxr += (newImg[i-1 + k][j-1 + m].r * matriz_covulacao[k][m]);
                auxg += (newImg[i-1 + k][j-1 + m].g * matriz_covulacao[k][m]); 
                auxb += (newImg[i-1 + k][j-1 + m].b * matriz_covulacao[k][m]);
                }
        }
			newImg2[i][j].r = auxr/divisor;
			newImg2[i][j].g = auxg/divisor;
			newImg2[i][j].b = auxb/divisor; 
			}

	if (newImg2[i][j].r > 255){// caso o valor max ultrapasse o min e max estabelecido			
	newImg2[i][j].r = 255;
	}
	if (newImg2[i][j].r < 0 ){	
	newImg2[i][j].r = 0;
	} //para g
	if (newImg2[i][j].g > 255){
	newImg2[i][j].g = 255;
	}
	if (newImg2[i][j].g < 0 ){
	newImg2[i][j].g = 0;
	}// para b
	if (newImg2[i][j].b > 255){
	newImg2[i][j].b = 255;
	}
	if (newImg2[i][j].b < 0 ){
	newImg2[i][j].b = 0;
	}			
		}
					
	}
	if(opcao == 8){
		for(i=0; i < alt; i++){ //verificando linha
			for(j=0; j < lar; j++){ //verificando coluna
			newImg[i][j].r = newImg2[i][j].r; 
			newImg[i][j].g = newImg2[i][j].g;
			newImg[i][j].b = newImg2[i][j].b;
			}
		}
	preto_branco(nome_saida,newImg,lar, alt,cormax);
		for(i=0; i < alt; i++){ //verificando linha
			for(j=0; j < lar; j++){ //verificando coluna
			newImg2[i][j].r = newImg[i][j].r; 
			newImg2[i][j].g = newImg[i][j].g;
			newImg2[i][j].b = newImg[i][j].b;
			}
		}
		
	}
	
		for(i=0; i < alt; i++){ //verificando linha
			for(j=0; j < lar; j++){ //verificando coluna
			newImg[i][j].r = newImg2[i][j].r; //escrevendo valores salvos no arquivo
			newImg[i][j].g = newImg2[i][j].g;
			newImg[i][j].b = newImg2[i][j].b;
			}
		}
}
//fim
void printar(char *nome_saida,pixel **newImg,int lar, int alt, int cormax){

FILE *arq_saida;
arq_saida = fopen(nome_saida,"w+");
				
fprintf(arq_saida,"P3\n%d %d\n%d\n",lar,alt,cormax); //abeçalho da imagem//

			
	for(i=0; i< alt; i++){ //verificando linha
		for(j=0; j < lar; j++){ //verificando coluna			
		fprintf(arq_saida,"%d\n", newImg[i][j].r);
		fprintf(arq_saida,"%d\n", newImg[i][j].g);
		fprintf(arq_saida,"%d\n", newImg[i][j].b);
		}
	}

free(newImg);
fclose(arq_saida);
printf("Sucesso!!!\n");
}
//fim
void negativo(char *nome_saida,pixel **newImg,int lar, int alt, int cormax){	

	for(i=1; i< alt-1; i++){ //verificando linha
		for(j=0; j < lar; j++){ //verificando coluna		
		newImg[i][j].r = 255-newImg[i][j].r; //subtrai da imagem o valor max para pegar o valor oposto. Caso seja branco, fica preto, por ex
		newImg[i][j].g = 255-newImg[i][j].g;
		newImg[i][j].b = 255-newImg[i][j].b;
		}
	}
}
//fim
void espelhar(char *nome_saida,pixel **newImg,int lar, int alt, int cormax){	
	newImg2 = (pixel**) malloc(sizeof(pixel*)*alt);
	
	for(i =0; i < alt; i++){
		newImg2[i] = (pixel*) malloc(sizeof(pixel)*lar);
	} //alocando memoria
	
	for(i=0; i< alt; i++){ //verificando linha
		for(j=1; j < lar-1; j++){ //inicializando assim por conta da borda		
		newImg2[i][j].r = newImg[i][lar-j].r; // Subtrai da lagura o pixel atual para pegar pixel que estaria do outro lado da imagem
		newImg2[i][j].g = newImg[i][lar-j].g;
		newImg2[i][j].b = newImg[i][lar-j].b;
		}
	}
	for(i=0; i < alt; i++){ //verificando linha
			for(j=0; j < lar; j++){ //verificando coluna
			newImg[i][j].r = newImg2[i][j].r; 
			newImg[i][j].g = newImg2[i][j].g;
			newImg[i][j].b = newImg2[i][j].b;
			}
		}
}
//fim
void sepia(char *nome_saida,pixel **newImg,int lar, int alt, int cormax){	

	for(i=0; i< alt; i++){ //verificando linha
		for(j=0; j < lar; j++){ //verificando coluna		
		newImg[i][j].r = newImg[i][j].r*1.0; //multiplicando pelo valor da cor
		newImg[i][j].g = newImg[i][j].g*0.965;
		newImg[i][j].b = newImg[i][j].b*0.806;
		}
	}
}
//fim

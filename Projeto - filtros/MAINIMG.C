#include "funcoes.c"

int main(){

	FILE *imagemA;
	char tipo[3], nomeimagem[50];	

		printf("Digite o nome da imagem\n");
		scanf("%s", nomeimagem);
		strcat(nomeimagem, ".ppm");//salvando final para nao precisar escrever ppm

	imagemA = fopen(nomeimagem, "r+"); // abrindo imagem
		if(imagemA==NULL){ //verificar se o arquivo abre
			printf("Erro ao abrir imagem!\n");
		}
		else{
			printf("Sucesso!\n");
		}
			fgets(tipo, 3, imagemA);
		if(strcmp("P3", tipo) != 0){ // se for diferente, avisa ao usuario e não abrir imagem
   			printf("tipo informado nao e P3.\n");
		exit(0);
		}
		else {	
			
			//confirma imagem como P3 e vai chamar a funcao menu para saber o que deseja fazer
		menu(imagemA);	
}
return 0;
}

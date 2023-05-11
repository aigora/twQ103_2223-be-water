#include<stdio.h>

int main(){
	char fichero;
	FILE *fichconductimetria;
	fichconductimetria=fopen("Conductimetria.txt","r");
	
	if(fichconductimetria==NULL){
		
		printf("Error en la apertura del ficghero\n");
	}
	
	while(((fichero=fgetc(fichconductimetria)))!=EOF){
		printf("%c",fichero);
	}
	fclose(fichconductimetria);
}

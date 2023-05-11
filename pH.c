#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
	
	setlocale (LC_CTYPE,"spanish");

	FILE *ficheropH;
	char fichero;
	ficheropH=fopen("pH.txt","r");
	
	if(ficheropH==NULL){
		printf("Error en la apertura del fichero. Es posible que no exista\n");
	}
	
	while(((fichero=fgetc(ficheropH)))!=EOF){
			printf("%c",fichero);
	
	}
	
		
	
	fclose(ficheropH);
}

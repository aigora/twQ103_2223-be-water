#include<stdio.h>

struct TnombreFichero{
	int anyo;
	int mes;
	char barrio [100];

};

struct Tfuentes{
	float pH;
	int conductividad;
	int turbidez;
	int coliformes;
};

void imprimirnombreFichero(struct TnombreFichero nombreFichero) {
	printf("%d%d_%s", nombreFichero.anyo,nombreFichero.mes,nombreFichero.barrio);
}

void anyadirdatos(){
	struct TnombreFichero nombreFichero ;
	struct Tfuentes fuentes [50];
	int i, nfuentes;
	char nombreArchivo [100];
	
	do{
	printf("Introduzca el anyo del estudios:\n");
	scanf("%d", &nombreFichero.anyo);
    } while (nombreFichero.anyo < 0); //nos aseguramos que no añadan anyos negativos
    
    do{
	printf("Introduzca el mes del estudio:\n");
	scanf("%d", &nombreFichero.mes);
	} while (nombreFichero.mes < 1 || nombreFichero.mes>12);//nos aseguramos que introduzca un mes real
	
	printf("Introduzca el barrio del estudio (Por favor, introducir la primera letra en mayuscula).:\n");
	scanf("%s", &nombreFichero.barrio);
	
	imprimirnombreFichero(nombreFichero);
	sprintf(nombreArchivo, "%d%d_%s.txt", nombreFichero.anyo, nombreFichero.mes, nombreFichero.barrio);
	
	FILE * fentrada;
	FILE * fsalida;
	
	//1.Creamos fichero
	fentrada = fopen (nombreArchivo,"w");
	if (fentrada == NULL){
		printf("\nError en la apertura de ficheros\n");
		return 1;
	} else{
		printf("\nArchivo creado con exito.");
	}
	
	system("pause");
    system("cls");
    
    do{
    	printf("Introduzca el numero de fuentes:\n");
    	scanf("%d", &nfuentes);
	}while (nfuentes<1);
	
	fprintf(fentrada,"Parametros\t pH\t Conductivida\t Turbidez\t Coliformes\n");
	for  (i=0; i<nfuentes; i++){
		fflush(stdin);
		do{
			printf("Introduce el pH de la fuente %d\n", i+1);
    		scanf("%f", &fuentes[i].pH);
		}while (fuentes[i].pH<0 || fuentes[i].pH>14);//nos aseguramos que el pH introducido sea válido
    	printf("Introduce la conductividad %d\n", i+1);
    	scanf("%d", &fuentes[i].conductividad);
    	printf("Introduce la turbidez de la fuente %d\n", i+1);
    	scanf("%d", &fuentes[i].turbidez);
    	printf("Introduce los coliformes de la fuente %d\n", i+1);
    	scanf("%d", &fuentes[i].coliformes);
    	fprintf(fentrada, "Fuente_%d\t%.2f\t%d\t%d\t%d\n", i+1, fuentes[i].pH, fuentes[i].conductividad, fuentes[i].turbidez, fuentes[i].coliformes);
	}
    fclose(fentrada);
}


//cuerpo del programa

int main (){
	int opcion;
	
	do {
        printf("Bienvenido al Programa be water. Gracias por usar nuestros servicios. \n");
        printf("1. ANYADIR DATOS\n");
        printf("2. COMPARAR Y ANALIZAR DATOS\n");
        printf("3. VER EVOLUCION\n");
        printf("4. SALIR\n");
        
		do{
        	printf("Introduce una opcion:\n");
        	fflush( stdin );
        	scanf( "%c", &opcion);
        } while ( opcion < '1' || opcion > '4' );
        
        
        switch ( opcion )
        {
            case '1': 
				system("cls");
        		// incluir lo de crear ficheros
        		printf("ANYADIR DATOS\n");
        		anyadirdatos();
        		system("pause");
        		system("cls");
            break;
            
            case '2':
            	system("cls");
        		printf("COMPARAR Y ANALIZAR DATOS\n");
        		system("pause");
        		system("cls");
        	break;
        	
        	case '3':
        		system("cls");
        		printf("VER EVOLUCION \n");
        		system("pause");
        		system("cls");
        	break;
        }
	} while ( opcion != '4' );
	
	return 0;
	
}

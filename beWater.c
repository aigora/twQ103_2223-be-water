#include<stdio.h>
#include <stdlib.h>
#include <locale.h> //para ñadir tildes y la letra ñ


struct TnombreFichero{
	int anyo;
	int mes;
	char barrio [100];

};

struct Tfuentes{
	char nombre [100]; 
	float pH;
	int conductividad;
	int turbidez;
	int coliformes;
};

void imprimirnombreFichero(struct TnombreFichero nombreFichero) {
	printf("%d%d_%s", nombreFichero.anyo,nombreFichero.mes,nombreFichero.barrio);
}

int anyadirdatos(){
	int mesfichero;
	int anyofichero;
	char barriofichero [100];
	struct Tfuentes fuentes [50];
	int i, nfuentes;
	char nombreArchivo [100];
	char fichero;
	
	//nos aseguramos que todos los ficheros tengan el mismo nombre.
	
	do{
	printf("Introduzca el año del estudios:\n");
	scanf("%d", &anyofichero);
    } while (anyofichero < 0); //nos aseguramos que no añadan años negativos
    
    do{
	printf("Introduzca el mes del estudio:\n");
	scanf("%d", &mesfichero);
	} while (mesfichero < 1 || mesfichero>12);//nos aseguramos que introduzca un mes real
	
	printf("Introduzca el barrio del estudio (Por favor, introducir la primera letra en mayúscula).:\n");
	scanf("%s", &barriofichero);
	
	sprintf(nombreArchivo, "%d%d_%s.txt", anyofichero, mesfichero, barriofichero);//metemos los datos en una variable para nombrar el fichero
	
	FILE * fentrada;
	
	//Creamos fichero
	fentrada = fopen (nombreArchivo,"w");
	if (fentrada == NULL){
		printf("\nError en la apertura de ficheros\n");
		return 1;
	} else{
		printf("\nArchivo creado con éxito.");
	}
	
	system("pause");
    system("cls");
    
    do{
    	printf("Introduzca el número de fuentes:\n");
    	scanf("%d", &nfuentes);
	}while (nfuentes<1);
	
	fprintf(fentrada,"Parametros\t pH\t Conductivida\t Turbidez\t Coliformes\n");
	for  (i=0; i<nfuentes; i++){
		fflush(stdin);
		do{
			printf("Introduce el pH de la fuente %d\n", i+1);
    		scanf("%f", &fuentes[i].pH);
		}while (fuentes[i].pH<0 || fuentes[i].pH>14);//nos aseguramos que el pH introducido sea válido
		
    	printf("Introduce la conductividad de la fuente %d\n", i+1);
    	scanf("%d", &fuentes[i].conductividad);
    	printf("Introduce la turbidez de la fuente %d\n", i+1);
    	scanf("%d", &fuentes[i].turbidez);
    	printf("Introduce los coliformes de la fuente %d\n", i+1);
    	scanf("%d", &fuentes[i].coliformes);
    	fprintf(fentrada, "Fuente_%d\t%.2f\t%d\t%d\t%d\n", i+1, fuentes[i].pH, fuentes[i].conductividad, fuentes[i].turbidez, fuentes[i].coliformes);
	}
    fclose(fentrada);
    
    printf("\n Los datos han sido guardados en la base de datos. \n");
    
	fentrada = fopen(nombreArchivo, "r");
 
    if(fentrada == NULL){
       printf("	Error en la apertura del fichero\n");
       return 0;
    }

    while(((fichero = fgetc(fentrada))) != EOF) {
        printf("%c", fichero);
    }
	
	fclose(fentrada);
     
}

int analizardatos (){
	struct TnombreFichero nombreFichero ;
	char nombreArchivo [100];
	char fichero;
	int opcion1;
	int opcion2, opcion3, opcion4, opcion5;
	
	FILE * fentrada;
	FILE * fsalida;
	
	do{
	printf("Introduzca el año del estudios:\n");
	scanf("%d", &nombreFichero.anyo);
    } while (nombreFichero.anyo < 0); //nos aseguramos que no añadan años negativos
    
    do{
	printf("Introduzca el mes del estudio (entre 1 y 12):\n");
	scanf("%d", &nombreFichero.mes);
	} while (nombreFichero.mes < 1 || nombreFichero.mes>12);//nos aseguramos que introduzca un mes real
	
	printf("Introduzca el barrio del estudio (Por favor, introducir la primera letra en mayúscula).:\n");
	scanf("%s", &nombreFichero.barrio);
	
	sprintf(nombreArchivo, "%d%d_%s.txt", nombreFichero.anyo, nombreFichero.mes, nombreFichero.barrio);
	
	fentrada = fopen(nombreArchivo, "r");//buscamos el fichero
	
    if(fentrada == NULL){
       printf("	Error en la apertura del fichero. Este fichero no existe en la base de datos. Si desea añadirlo dirígase al menú y pulse la opción 1. \n");
       return 0;
    }//si el fichero no existe indicamos al usuario que cree el fichero.
    
	printf("\n El fichero contiene los siguientes datos:\n ");
	printf("\n");
	
    while(((fichero = fgetc(fentrada))) != EOF) {
        printf("%c", fichero);
    }
	
//	fclose(fentrada); aun no se si hay que cerrarlo
	
	system("pause");
	
	system("cls");
	
	
	do{
		printf("A continuación, indique el dato que desee saber:\n");
		printf("1. Saber valores máximos y mínimos de los parámetros.\n");
		printf("2. Calcular la media de un parámetro.\n");
		printf("3. Ordenar los parámetros de menor a mayor.\n");
		printf("4. Ordenar los parámetros de mayor a menor");
		printf("5. Volver al menú principal");
		
		do{
        	printf("Introduce una opcion:\n");
        	fflush( stdin );
        	scanf( "%c", &opcion1);
        } while ( opcion1 < '1' || opcion1 > '5' );
        
		
		switch (opcion1)
		{
			case '1':
				system("cls");
				do{
					printf("Elija una opción: \n");
					printf("1. Calcular el máximo de un parámetro.\n");
					printf("2. Calcular el mínimo de un parámetro.\n");
					scanf("%d", &opcion2);
				}while(opcion2 != 1 || opcion2 !=2);
			break;
			
		case '2':
				system("cls");
				do{
					printf("Elija el parámetro para calcular la media opción: \n");
					printf("1. pH\n");
					printf("2. Conductividad.\n");
					printf("3. Turbidez\n");
					printf("4. Coloides");
					scanf("%d", &opcion3);
				}while(opcion3 < 1 || opcion3 >4);
			break;
			
			case '3':
				system("cls");
				do{
					printf("Elija el parámetro para ordenarlo de menor a mayor: \n");
					printf("1. pH\n");
					printf("2. Conductividad.\n");
					printf("3. Turbidez\n");
					printf("4. Coloides");
					scanf("%d", &opcion4);
				}while(opcion4 < 1 || opcion4 >4);
			break;
			
			case '4':
				system("cls");
				do{
					printf("Elija el parámetro para ordenarlo de menor a mayor: \n");
					printf("1. pH\n");
					printf("2. Conductividad.\n");
					printf("3. Turbidez\n");
					printf("4. Coloides");
					scanf("%d", &opcion5);
				}while(opcion5 < 1 || opcion5 >4);
			break;
		}
	} while (opcion1 != '5');
	
	return 0;
     
}
int guia() {
    char opciong; // opción de las guías

    do {
        printf("Seleccione una opción: \n");
        printf("1. pH\n");
        printf("2. Conductividad\n");
        printf("3. Turbidez\n");
        printf("4. Coloides\n");
        printf("5. Volver al menú principal\n");

        do {
            printf("Introduce una opción:\n");
            fflush(stdin);
            scanf(" %c", &opciong);
        } while (opciong < '1' || opciong > '5');

        switch (opciong) {
            case '1':
                ficheroph();
                system("pause");
                system("cls");
                break;

            case '2':
                ficheroconduct();
                system("pause");
                system("cls");
                break;

            case '3':
                system("pause");
                system("cls");
                break;

            case '4':
                system("pause");
                system("cls");
                break;
        }
    } while (opciong != '5');

    return 0;
}



int ficheroph() {
    FILE *ficheropH;
    int caracter;

    ficheropH = fopen("pH.txt", "r");

    if (ficheropH == NULL) {
        printf("Error en la apertura del fichero. Es posible que no exista\n");
        return 1;
    }

    printf("Contenido del archivo pH.txt:\n");

    while ((caracter = fgetc(ficheropH)) != EOF) {
        printf("%c", caracter);
    }

    fclose(ficheropH);

    return 0;
}





int ficheroconduct(){
	char fichero2;
	int caracter;
	FILE *fichconductimetria;
	fichconductimetria=fopen("Conductimetria.txt","r");
	
	if(fichconductimetria==NULL){
		
		printf("Error en la apertura del ficghero\n");
	}
    /*	while ((caracter = fgetc(ficheropH)) != EOF) {
        printf("%c", caracter);
    }*/
	while((caracter=fgetc(fichconductimetria))!=EOF){
		printf("%c",caracter);
	}
	fclose(fichconductimetria);
	return 0;
}
	

//cuerpo del programa

int main (){
	setlocale(LC_ALL, "spanish");
	int opcion;
	int i;
	char textph [10000];
	
	do {
        printf("Bienvenido al Programa BE WATER. Gracias por usar nuestros servicios. A continuación, indique lo que desee realizar \n");
        printf("1. AÑADIR DATOS\n");
        printf("2. ANALIZAR DATOS\n");
        printf("3. VER EVOLUCIÓN\n");
        printf("4. GUÍA DE PARÁMETROS\n");
        printf("5. SALIR\n");
        
		do{
        	printf("Introduce una opcion:\n");
        	fflush( stdin );
        	scanf( "%c", &opcion);
        } while ( opcion < '1' || opcion > '5' );
        
        
        switch ( opcion )
        {
            case '1': 
				system("cls");
        		printf("\t \t \t || AÑADIR DATOS || \n");
        		printf("\n");
        		anyadirdatos();
        		system("pause");
        		system("cls");
            break;
            
            case '2':
            	system("cls");
        		printf("\t \t \t || ANALIZAR DATOS || \n");
        		printf("\n");
        		analizardatos();
        		system("pause");
        		system("cls");
        	break;
        	
        	case '3':
        		system("cls");
        		printf("\t \t \t || VER EVOLUCIÓN || \n");
        		system("pause");
        		system("cls");
        	break;
        	
        	case '4':
        		system("cls");
        		printf("\t \t \t ||  GUIA DE PARAMETROS || \n");
        		printf("Nuestro objetivo es que todo el mundo use BE WATER sabiendo cómo funciona los parámetros de las fuentes. \nA continuación, tendrás más información de los diferentes parámetros.\n");
        		guia();
        		system("pause");
        		system("cls");
        	break;
        }
	} while ( opcion != '5' );
	
	return 0;
	
}

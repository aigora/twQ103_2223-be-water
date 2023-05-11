#include<stdio.h>
#include <stdlib.h>
#include <locale.h> //para ñadir tildes y la letra ñ
#include<string.h>


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
	struct TnombreFichero nombreFichero ;
	struct Tfuentes fuentes [50];
	int i, nfuentes;
	char nombreArchivo [100];
	char fichero;
	
	//nos aseguramos que todos los ficheros tengan el mismo nombre.
	
	do{
	printf("Introduzca el año del estudios:\n");
	scanf("%d", &nombreFichero.anyo);
    } while (nombreFichero.anyo < 0); //nos aseguramos que no añadan años negativos
    
    do{
	printf("Introduzca el mes del estudio:\n");
	scanf("%d", &nombreFichero.mes);
	} while (nombreFichero.mes < 1 || nombreFichero.mes>12);//nos aseguramos que introduzca un mes real
	
	printf("Introduzca el barrio del estudio (Por favor, introducir la primera letra en mayúscula).:\n");
	scanf("%s", &nombreFichero.barrio);
	
	imprimirnombreFichero(nombreFichero);
	sprintf(nombreArchivo, "%d%d_%s.txt", nombreFichero.anyo, nombreFichero.mes, nombreFichero.barrio);//metemos los datos en una variable para nombrar el fichero
	
	FILE * fentrada;
	FILE * fsalida;
	
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
	float maxpH;
	
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
       printf("	Error en la apertura del fichero. Este fichero no existe en la base de datos. Si desea añdirlo dirígase al menú y pulse la opción 1. \n");
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
					printf("Se le mostrará a continuación los valores máximos y mínimos de pH\n");
					//printf("Elija una opción: \n");
					//printf("1. Calcular el máximo de un parámetro.\n");
					//printf("2. Calcular el mínimo de un parámetro.\n");
					//scanf("%d", &opcion2);
						//if(opcion1=='1'){
					max(fentrada);
						printf("El valor maximo de pH = %.2f, y corresponde a la fuente %s\n",maxpH, nombreFichero);

			//	}
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

void max(FILE *fentrada){
	//struct TnombreFichero nombreFichero ;
	struct Tfuentes fuentes [50];
	int i=0;
    //float max,min;
    char nombreFichero[200];
    float maxpH=0;
    
    
    printf("Introduce el nombre del fichero que contiene los datos\n");
	scanf("%s",nombreFichero);
	fentrada = fopen(nombreFichero,"r");
	
	if(fentrada==NULL){
		printf("Error en la apertura del fichero. Es posible que el fichero que estás buscando no exista\n");
		return 0;
	}
	while(fscanf(fentrada,"%s %f",fuentes[i].nombre,&fuentes[i].pH)!=EOF){
		printf("%s %f \n", fuentes[i].nombre,fuentes[i].pH);
		if(fuentes[i].pH>maxpH){
			maxpH=fuentes[i].pH;
			strcpy(nombreFichero,fuentes[i].nombre);
		}
		i++;
	}
	fclose(fentrada);
 	//printf("El valor maximo de pH = %.2f, y corresponde a la fuente %s\n",maxpH, nombreFichero);
    
}

//cuerpo del programa

int main (){
	setlocale(LC_ALL, "spanish");
	int opcion;
	
	do {
        printf("Bienvenido al Programa be water. Gracias por usar nuestros servicios. A continuación, indique lo que desee realizar \n");
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
        		system("pause");
        		system("cls");
        	break;
        }
	} while ( opcion != '5' );
	
	return 0;
	
}


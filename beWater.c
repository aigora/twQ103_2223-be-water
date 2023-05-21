#include<stdio.h>
#include <stdlib.h>
#include <locale.h> //para añadir tildes y la letra ñ


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

float maximopH(struct Tfuentes fuentes[],int nfuentes);
void ordenarParametrosmayoramenor(struct Tfuentes fuentes[], int nfuentes, int opcion);
void ordenarParametros(struct Tfuentes fuentes[], int nfuentes, int opcion);
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
	float pHmax;
	int posmax;
	
	//nos aseguramos que todos los ficheros tengan el mismo nombre.
	
	do{
	printf("Introduzca el a?o del estudios:\n");
	scanf("%d", &anyofichero);
    } while (anyofichero < 0); //nos aseguramos que no a?adan a?os negativos
    
    do{
	printf("Introduzca el mes del estudio:\n");
	scanf("%d", &mesfichero);
	} while (mesfichero < 1 || mesfichero>12);//nos aseguramos que introduzca un mes real
	
	printf("Introduzca el barrio del estudio (Por favor, introducir la primera letra en may?scula).:\n");
	scanf("%s", &barriofichero);
	
	sprintf(nombreArchivo, "%d%d_%s.txt", anyofichero, mesfichero, barriofichero);//metemos los datos en una variable para nombrar el fichero
	
	FILE * fentrada;
	
	//Creamos fichero
	fentrada = fopen (nombreArchivo,"w");
	if (fentrada == NULL){
		printf("\nError en la apertura de ficheros\n");
		return 1;
	} else{
		printf("\nArchivo creado con ?xito.");
	}
	
	system("pause");
    system("cls");
    
    do{
    	printf("Introduzca el n?mero de fuentes:\n");
    	scanf("%d", &nfuentes);
	}while (nfuentes<1);
	
	fprintf(fentrada,"Parametros\t pH\t Conductivida\t Turbidez\t Coliformes\n");
	for  (i=0; i<nfuentes; i++){
		fflush(stdin);
		do{
			printf("Introduce el pH de la fuente %d\n", i+1);
    		scanf("%f", &fuentes[i].pH);
		}while (fuentes[i].pH<0 || fuentes[i].pH>14);//nos aseguramos que el pH introducido sea v?lido
		
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
	struct Tfuentes fuentes[100];
	int i;
	char nombreArchivo [100];
	char fichero;
	int opcion1;
	int opcion2, opcion3, opcion4, opcion5;
	int nfuentes;
	float pHmax;
	int maxpos,maxpos1,maxpos2,maxpos3;
	int minpos,minpos1,minpos2,minpos3;
	int conductividadmax,turbidezmax,coliformesmax;
	int contador=0;
    float minpH,mincond,minturb, mincol;
	
	FILE * fentrada;
	FILE * fsalida;
	
	do{
	printf("Introduzca el a?o del estudios:\n");
	scanf("%d", &nombreFichero.anyo);
    } while (nombreFichero.anyo < 0); //nos aseguramos que no a?adan a?os negativos
    
    do{
	printf("Introduzca el mes del estudio (entre 1 y 12):\n");
	scanf("%d", &nombreFichero.mes);
	} while (nombreFichero.mes < 1 || nombreFichero.mes>12);//nos aseguramos que introduzca un mes real
	
	printf("Introduzca el barrio del estudio (Por favor, introducir la primera letra en may?scula).:\n");
	scanf("%s", &nombreFichero.barrio);
	
	sprintf(nombreArchivo, "%d%d_%s.txt", nombreFichero.anyo, nombreFichero.mes, nombreFichero.barrio);
	
	fentrada = fopen(nombreArchivo, "r");//buscamos el fichero
	
    if(fentrada == NULL){
       printf("	Error en la apertura del fichero. Este fichero no existe en la base de datos. Si desea a?adirlo dir?gase al men? y pulse la opci?n 1. \n");
       return 0;
    }//si el fichero no existe indicamos al usuario que cree el fichero.
    
	printf("\n El fichero contiene los siguientes datos:\n ");
	printf("\n");
	
   	// Ignorar la primera l?nea ya que es el encabezado y no nos sirve
	char buffer[1024];
    fgets(buffer, 1024, fentrada);
    	
    i=0;
    contador=0;
    while (fscanf(fentrada, "%s %f %d %d %d\n", fuentes[i].nombre, &fuentes[i].pH, &fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes) != EOF) {
        printf("%s %.2f %d %d %d\n", fuentes[i].nombre, fuentes[i].pH, fuentes[i].conductividad, fuentes[i].turbidez, fuentes[i].coliformes);
        i++;
        contador++;                
    } //guardamos los datos en el struct
	
	fclose(fentrada);
	
	system("pause");
	
	system("cls");
	
	
	do{
		printf("A continuación, indique el dato que desee saber:\n");
		printf("1. Saber valores máximos y mínimos de los parámetros.\n");
		printf("2. Calcular la media de un parámetro.\n");
		printf("3. Ordenar los parámetros de menor a mayor.\n");
		printf("4. Ordenar los parámetros de mayor a menor\n");
		printf("5. Volver al menú principal\n");
		
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
					printf("Elija una opci?n: \n");
					printf("1. Calcular el máximo de un parámetro.\n");
					printf("2. Calcular el mínimo de un parámetro.\n");
					scanf("%d", &opcion2);
					
					if(opcion2==1){
						
						fentrada = fopen(nombreArchivo, "r");
						printf("Has elegido calcular el máximo\n");
						char buffer[1024];
					    fgets(buffer, 1024, fentrada);
					    
					    pHmax= 0.0;
					    conductividadmax=0;
						maxpos=0;
						
					    for (i = 0; i < contador; i++) {
					        fscanf(fentrada, "%s %f %d %d %d\n", fuentes[i].nombre, &fuentes[i].pH, &fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes);
					        
					        // Buscar el mayor pH
					        if (fuentes[i].pH > pHmax) {
					            pHmax= fuentes[i].pH;
					            
					            maxpos= i;
					        }
					    }
					        
						conductividadmax = fuentes[0].conductividad;
					    maxpos1 = 0;
					
					    for (i = 1; i < contador; i++) {
					        if (fuentes[i].conductividad > conductividadmax) {
					            conductividadmax = fuentes[i].conductividad;
					            maxpos1 = i;
					        }
					    }
					    
					    turbidezmax=fuentes[0].turbidez;
					    maxpos2=0;
					    
					    for (i = 1; i < contador; i++) {
					        if (fuentes[i].turbidez > turbidezmax) {
					            turbidezmax = fuentes[i].turbidez;
					            maxpos2 = i;
					        }
					    }
					    
					    coliformesmax=fuentes[0].coliformes;
					    maxpos3=0;
					    
					     
					    for (i = 1; i < contador; i++) {
					        if (fuentes[i].coliformes > coliformesmax) {
					            coliformesmax = fuentes[i].coliformes;
					            maxpos3 = i;
					        }
					    }
					    
						printf("La fuente con el mayor pH es:\n");
						printf("%s %.2f %d %d %d\n", fuentes[maxpos].nombre, fuentes[maxpos].pH, fuentes[maxpos].conductividad, fuentes[maxpos].turbidez, fuentes[maxpos].coliformes);
						printf("La fuente con mayor conductividad es:\n");
					    printf("%s %.2f %d %d %d\n", fuentes[maxpos1].nombre, fuentes[maxpos1].pH, fuentes[maxpos1].conductividad, fuentes[maxpos1].turbidez, fuentes[maxpos1].coliformes);
					    printf("La fuente con mayor turbidez es:\n");
					    printf("%s %.2f %d %d %d\n", fuentes[maxpos2].nombre, fuentes[maxpos2].pH, fuentes[maxpos2].conductividad, fuentes[maxpos2].turbidez, fuentes[maxpos2].coliformes);    				
						printf("La fuente con mayor coliformes es:\n");
					    printf("%s %.2f %d %d %d\n", fuentes[maxpos3].nombre, fuentes[maxpos3].pH, fuentes[maxpos3].conductividad, fuentes[maxpos3].turbidez, fuentes[maxpos3].coliformes); 
						
						break; 
					    } if (opcion2 == 2 ){
					    	char buffer[1024];
					    	fgets(buffer, 1024, fentrada);
					    
					    	minpH = fuentes[0].pH;
						    minpos = 0;
						    
						    for (i = 0; i < contador; i++) {
						        fscanf(fentrada, "%s %f %d %d %d\n", fuentes[i].nombre, &fuentes[i].pH, &fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes);
						        
						        // Buscar el menor pH
						        if (fuentes[i].pH < minpH) {
						            minpH = fuentes[i].pH;
						            minpos = i;
						        }
						    }
						    
							mincond = fuentes[0].conductividad;
						    minpos1 = 0;
						    
						    for (i = 0; i < contador; i++) {
						        fscanf(fentrada, "%s %f %d %d %d\n", fuentes[i].nombre, &fuentes[i].pH, &fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes);
						        
						        if (fuentes[i].conductividad < mincond) {
						            mincond = fuentes[i].conductividad;
						            minpos1 = i;
						        }
						    }
						    
						    minturb= fuentes[0].turbidez;
						    minpos2=0;
						    for (i = 0; i < contador; i++) {
						        fscanf(fentrada, "%s %f %d %d %d\n", fuentes[i].nombre, &fuentes[i].pH, &fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes);
						        
						        if (fuentes[i].turbidez < minturb) {
						            minturb = fuentes[i].turbidez;
						            minpos2 = i;
						        }
						    }
						    
						    mincol= fuentes[0].coliformes;
						    minpos3=0;
						    for (i = 0; i < contador; i++) {
						        fscanf(fentrada, "%s %f %d %d %d\n", fuentes[i].nombre, &fuentes[i].pH, &fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes);
						        
						        if (fuentes[i].coliformes < mincol) {
						            mincol = fuentes[i].coliformes;
						            minpos3 = i;
						        }
						    }
						    
						    printf("La fuente con el menor pH es:\n");
						    printf("%s %.2f %d %d %d\n", fuentes[minpos].nombre, fuentes[minpos].pH, fuentes[minpos].conductividad, fuentes[minpos].turbidez, fuentes[minpos].coliformes);
						    printf("La fuente con el menor conductividad es:\n");
						    printf("%s %.2f %d %d %d\n", fuentes[minpos1].nombre, fuentes[minpos].pH, fuentes[minpos1].conductividad, fuentes[minpos1].turbidez, fuentes[minpos1].coliformes);
						    printf("La fuente con el menor turbidez es:\n");
						    printf("%s %.2f %d %d %d\n", fuentes[minpos2].nombre, fuentes[minpos2].pH, fuentes[minpos].conductividad, fuentes[minpos2].turbidez, fuentes[minpos2].coliformes);
						    printf("La fuente con el menor coliformes es:\n");
						    printf("%s %.2f %d %d %d\n", fuentes[minpos3].nombre, fuentes[minpos3].pH, fuentes[minpos].conductividad, fuentes[minpos3].turbidez, fuentes[minpos3].coliformes);
						    
						}
					    
					
				}while(opcion2 != 1 || opcion2 !=2);
					break;
			
		case '2':
				system("cls");
				do{
					printf("Elija el parámetro para calcular la media opciónn: \n");
					printf("1. pH\n");
					printf("2. Conductividad.\n");
					printf("3. Turbidez\n");
					printf("4. Coloides\n");
					scanf("%d", &opcion3);
				}while(opcion3 < 1 || opcion3 >4);
			break;
			
			case '3':
				system("cls");
				do{
					printf("Elija el par?metro para ordenarlo de menor a mayor: \n");
					printf("1. pH\n");
					printf("2. Conductividad.\n");
					printf("3. Turbidez\n");
					printf("4. Coloides\n");
					scanf("%d", &opcion4);
				}while(opcion4 < 1 || opcion4 >4);
				
				 ordenarParametros(fuentes, contador, opcion4);
				     printf("Par?metros ordenados de menor a mayor:\n");

				 for (i = 0; i < contador; i++) {
                printf("%s %.2f %d %d %d\n", fuentes[i].nombre, fuentes[i].pH, fuentes[i].conductividad, fuentes[i].turbidez, fuentes[i].coliformes);
            }
            return 0;
			break;
			
			case '4':
				system("cls");
				do{
					printf("Elija el par?metro para ordenarlo de menor a mayor: \n");
					printf("1. pH\n");
					printf("2. Conductividad.\n");
					printf("3. Turbidez\n");
					printf("4. Coloides\n");
					scanf("%d", &opcion5);
				}while(opcion5 < 1 || opcion5 >4);
				
				ordenarParametrosmayoramenor(fuentes, contador, opcion4);
                for (i = 0; i < contador; i++) {
                printf("%s %.2f %d %d %d\n", fuentes[i].nombre, fuentes[i].pH, fuentes[i].conductividad, fuentes[i].turbidez, fuentes[i].coliformes);
            }
			return 0;	
			break;
		}
	} while (opcion1 != '5');
	
	return 0;
     
}

void ordenarParametrosmayoramenor(struct Tfuentes fuentes[], int nfuentes, int opcion) {
    int i, j;
    struct Tfuentes temp;

    for (i = 0; i < nfuentes - 1; i++) {
        for (j = i + 1; j < nfuentes; j++) {
            if (opcion == 1) {
                if (fuentes[i].pH < fuentes[j].pH) {
                    temp = fuentes[i];
                    fuentes[i] = fuentes[j];
                    fuentes[j] = temp;
                }
            } else if (opcion == 2) {
                if (fuentes[i].conductividad < fuentes[j].conductividad) {
                    temp = fuentes[i];
                    fuentes[i] = fuentes[j];
                    fuentes[j] = temp;
                }
            } else if (opcion == 3) {
                if (fuentes[i].turbidez < fuentes[j].turbidez) {
                    temp = fuentes[i];
                    fuentes[i] = fuentes[j];
                    fuentes[j] = temp;
                }
            } else if (opcion == 4) {
                if (fuentes[i].coliformes < fuentes[j].coliformes) {
                    temp = fuentes[i];
                    fuentes[i] = fuentes[j];
                    fuentes[j] = temp;
                }
            }
        }
    }
}
void ordenarParametros(struct Tfuentes fuentes[], int nfuentes, int opcion) {
    int i, j;
    struct Tfuentes temp;

    for (i = 0; i < nfuentes - 1; i++) {
        for (j = i + 1; j < nfuentes; j++) {
            switch (opcion) {
                case 1:
                    if (fuentes[i].pH < fuentes[j].pH) {
                        temp = fuentes[i];
                        fuentes[i] = fuentes[j];
                        fuentes[j] = temp;
                    }
                    break;

                case 2:
                    if (fuentes[i].conductividad < fuentes[j].conductividad) {
                        temp = fuentes[i];
                        fuentes[i] = fuentes[j];
                        fuentes[j] = temp;
                    }
                    break;

                case 3:
                    if (fuentes[i].turbidez < fuentes[j].turbidez) {
                        temp = fuentes[i];
                        fuentes[i] = fuentes[j];
                        fuentes[j] = temp;
                    }
                    break;

                case 4:
                    if (fuentes[i].coliformes < fuentes[j].coliformes) {
                        temp = fuentes[i];
                        fuentes[i] = fuentes[j];
                        fuentes[j] = temp;
                    }
                    break;
            }
        }
    }
}

int guia() {
    char opciong; // opción de las guías

    do {
        printf("Seleccione una opci?n: \n");
        printf("1. pH\n");
        printf("2. Conductividad\n");
        printf("3. Turbidez\n");
        printf("4. Coloides\n");
        printf("5. Volver al men? principal\n");

        do {
            printf("Introduce una opci?n:\n");
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
            	fichturbidez();
                system("pause");
                system("cls");
                break;

            case '4':
            	fichcoloides();
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
    printf("\n");

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
   
	while((caracter=fgetc(fichconductimetria))!=EOF){
		printf("%c",caracter);
	}
	printf("\n");
	fclose(fichconductimetria);
	return 0;
}

int fichturbidez(){
	char fichero3;
	FILE *ficheroturbidez;
	
	ficheroturbidez=fopen("turbidez.txt","r");
	
	if(ficheroturbidez==NULL){
		printf("Error en la apertura del fichero\n");
	}
		while(((fichero3=fgetc(ficheroturbidez)))!=EOF){
		printf("%c",fichero3);
	}
	fclose(ficheroturbidez);
	printf("\n");
	return 0;
}

int fichcoloides(){
	char fichero4;
	
	FILE *ficherocoloides;
	
	ficherocoloides=fopen("Coliformes.txt","r");
	if(ficherocoloides==NULL){
		printf("Error en la apertura del fichero\n");
	}
		while(((fichero4=fgetc(ficherocoloides)))!=EOF){
		printf("%c",fichero4);
	}
	fclose(ficherocoloides);
	printf("\n");
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
        printf("3. GUíA DE PARÁMETROS\n");
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
        		printf("\t \t \t ||  GUIA DE PARAMETROS || \n");
        		printf("Nuestro objetivo es que todo el mundo use BE WATER sabiendo cómo funciona los parámetros de las fuentes. \nA continuación, tendrás más información de los diferentes parámetros.\n");
        		guia();
        		system("pause");
        		system("cls");
        	break;
        }
	} while ( opcion != '4' );
	
	return 0;
	
}

#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/
int obtenlinea(void);
void copia(void);
void voltea(int longitud);

/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0){
        if( longitud > max){
          max = longitud;
          copia();
          }

        // imprime todas las lineas que cumplen la condicion de tener mas de 80 caracteres
        if( longitud > 60){
            printf("Linea mayor de 60 \n");
            printf("%s \n",linea);
            //copia();
        }

        // imprime lineas volteadas
        voltea(longitud);

    }//cierra el while
    if(max > 0)
        printf("linea mas larga: \n %s \n", linea_max);
return 0;
}

/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
    int c;
    int i,j=0;
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++){
      // condicion para remover espacios en blanco
        if (c!=' '){
            linea[j] = c;
            j++;
        }
      //linea[i] = c;
    }

    if(c == '\n'){
        linea[j] = c;
        j++;
    }
    linea[j]='\0'; //este caracter es necesario para almacenar strings
    return j;
}

/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void){
    char *i,*j;
    extern char linea[], linea_max[];
    i=&linea[0];
    j=&linea_max[0];
    while(*i != '\0'){
        *j = *i;
        i++;
        j++;
    }
}

void voltea(int longitud){
    extern char linea[];
    char linea_volteada[longitud];
    int i;
    for(i=0;i<=longitud;i++){
        linea_volteada[longitud-i-1]=linea[i];
    }
    linea_volteada[longitud+1]='\0';
    printf("%s \n",linea_volteada);
}

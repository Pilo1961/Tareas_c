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
        voltea(longitud);
        
    }
    if(max > 0)
        printf("linea max: %s", linea_max);
return 0;
}
 
/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
    int c;
    int i;
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++)
        linea[i] = c;
    if(c == '\n'){
        linea[i] = c;
        i++;
    }
    linea[i]='\0'; //este caracter es necesario para almacenar strings
    return i;
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
    printf("%s",linea_volteada);
}

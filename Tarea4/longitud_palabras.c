
#include<stdio.h>
int longitud_string(char *s){
    int i=0;
    while(*s != '\0'){
        s++;
        i++;
        if(i>500){
            printf("Salida forzada");
            break;
        }
    }
return i;
}

int main(){
    char str1[100];
    int i=0;
    printf("Longitud de las cadenas en el archivo:\n" );

    while(scanf("%s", str1)!=EOF){
        printf("%s: %d \n", str1,longitud_string(str1));
        i++;
        if(i>500){
            printf("Salida forzada");
            break;
        }
    }
}

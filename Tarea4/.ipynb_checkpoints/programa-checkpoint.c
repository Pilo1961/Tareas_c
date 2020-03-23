#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *duplica_string(char *s){  
    char *p;
    p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    return p;
}

char *voltea_string(char *s){  
    char *v;
    int i,len;
    v = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
    len=strlen(s);
    s=s+len-1;
    for(i=0;i<=strlen(s)+1;i++){
        //duda si comento el printf se queda en un ciclo, por que?
        strncpy(v,s,1);
        //printf("%s \n",v);  
        s--; 
        v++;
    }   
    return v-len;
}


int main(void){
    char *s;
    s = (char*)malloc(1);
    s= "Campos verdes";
    printf("%ld \n",strlen(s));
    
    char *s_duplicado;
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    free(s_duplicado);

    char *s_volteado;
    s_volteado = voltea_string(s);
    printf("%s\n", s_volteado);
    free(s_volteado);
    
    void free(void* s);

    return 0;
}

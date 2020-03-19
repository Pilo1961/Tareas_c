
#include <stdio.h>
int main(void){
    int c,i=0;
    printf("Introduce un texto para contar caracteres.\n");
    do{
      c = getchar();
      i++;
    }while(c!=10);//c=10 indica la tecla enter en codigo ASCII
    printf("El texto tiene %d caracteres.\n",i-1);
    return 0;
}

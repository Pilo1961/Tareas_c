
#include <stdio.h>
int main(void){
  int c, i=0;
  do{
    c = getchar();
    if(c==10) i++;
  } while(c != EOF);
  printf("El archivo tiene %d lineas\n",i);
  return 0;
}

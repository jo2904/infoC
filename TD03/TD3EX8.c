#include <stdio.h>

int main(){
  int a, min=1000000, max=0;
  printf("entrer vos nombre (fin de la serie si n<0)\n");
  while(1){
  scanf("%d", &a);
  if (a<0)
   break;
  if (min>a)
    min = a;
  if (max<a)
    max = a;
  }
  printf("min= %d\n", min);
  printf("max= %d\n", max);
  }

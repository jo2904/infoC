#include <stdio.h>

int main(){
  int i;
  printf("x= ");
  scanf("%d", &i);
  if( i < 0){
    i = -i;
  }
  printf("|x| = %d\n", i);
 }


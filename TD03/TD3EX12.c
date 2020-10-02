#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int i, a, b, c;
  srand(time(NULL));
  
  do{
  printf("borne inf=");
  scanf("%d", &a);
  printf("borne sup=");
  scanf("%d", &b);
  }while(a>b);
  
  for(i=0;i<10;i=i+1){
    do{
    c = (int)((float)b*rand()/RAND_MAX);
    }while(a>c);
    printf("%d\n", c);
  }
  
  return(0);
  }

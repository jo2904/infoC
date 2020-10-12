#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int myRand(int a, int b){
  int c;
  do{
  c = (int)((float)b*rand()/RAND_MAX);
  }while(a>c);
  return c;
}

int main(){
  int a, b;
  printf("min et max ?");
  scanf("%d %d", &a, &b);
  printf("%d", myRand(a, b));
}

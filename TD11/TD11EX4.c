#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SommeRec(int n){
  if(n==1){
    return 1;
  }
  return SommeRec( n - 1 ) + n;
}

unsigned long puissanceRec(unsigned long valeur, short n){
  if(n ==1){
    return valeur;
  }
  return puissanceRec(valeur, n-1) * valeur;
}

int DivEucRec( int a, int b){
  if(a-b < b){
    return a-b;
  }
  return DivEucRec(a-b, b);
}

int main(){
  printf("%ld\n", puissanceRec(5, 5));
  return 0;
}

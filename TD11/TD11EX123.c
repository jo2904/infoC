#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int SommeRec(int n){
  if(n > 1){
    return SommeRec( n - 1 ) + n;
  }
  else{
    return 1;
  }
}

unsigned long puissanceRec(unsigned long valeur, short n){
  if(n > 1){
    return puissanceRec(valeur, n-1) * valeur;
  }
  else{
    return valeur;
  }
}

int DivEucRec( int a, int b){
  if(a-b < b){
    return a-b;
  }
  else{
    return DivEucRec(a-b, b);
  }
}

int main(){
  printf("%d\n", DivEucRec(43, 5));
  return 0;
}

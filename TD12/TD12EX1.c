#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int dicotomie(int n,int min, int max){
  x = max/2;
  printf("test de la valeur: %d", x);
  if(x == n){
    return x;
  }
  else if(x > n){
    return dicotomie(n, x, max);
  }
  else if(x < n){
    return dicotomie(n, min, x);
  }
}

int main(){
  srand(time(NULL));

  int alea = rand() % 50001;

  printf("%d", dicotomie(alea, 0, 50000));
}

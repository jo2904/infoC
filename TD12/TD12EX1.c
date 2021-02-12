#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dicotomie(int n,int min, int max){
  int x = (max+min);
  x = x /2;
  if(x > n){
    return dicotomie(n, min, x);
  }

  if(x < n){
    return dicotomie(n, x, max);
  }

  return x;
}

int main(){
  srand(time(NULL));

  int alea = rand()%50000+1;
  printf("%d", dicotomie(alea, 0, 50000));
}

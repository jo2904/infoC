#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int estImpair(int a);

int estPair(int a){
  if(a == 0){
    return 0;
  }
  return estImpair(a-2);
}

int estImpair(int a){
  if(a < 0){
    return 1;
  }
  return estPair(a-2);
}

int main() {
  printf("%d\n", estPair(5));
  return 0;
}

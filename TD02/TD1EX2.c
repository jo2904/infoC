#include <stdio.h>

#define N 121

int main(){
  int nb;
  nb = N/100;
  nb = nb + ((N -nb*100) / 10) * 10;
  nb += 100 * (N % ((N / 10) * 10));
  printf("Nombre magique : %d\n", nb);
  return 0;
}

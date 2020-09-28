#include <stdio.h>

int main(){

  float prix = 18.95;
  float  monnaie;
  float rendue;
  printf("Prix: %.2f\n", prix);
  printf("Vous donnez: ");  
  scanf("%f", &monnaie);
  rendue = monnaie - prix ;
  printf("Rendue: %.2f\n", rendue);
  return 0;
}

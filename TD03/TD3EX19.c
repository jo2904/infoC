#include <stdio.h>

int main(){
  char rendue[5];
  int monnaie;
  printf("monnaie a rendre ?");
  scanf("%d", &monnaie);
  
  rendue[1] = monnaie/100;
  monnaie = monnaie%100;
  rendue[2] = monnaie/10;
  monnaie = monnaie%10;
  rendue[3] = monnaie/5;
  monnaie = monnaie%5;
  rendue[4] = monnaie/2;
  monnaie = monnaie%2;
  rendue[5] = monnaie/1;
  monnaie = monnaie%1;
  
  printf("Je dois rendre %d billets de 100€, %d billets de 10€, %d billets de 5€, %d pieces de 2€, %d pieces de 1€ et il reste %d €", rendue[1], rendue[2], rendue[3], rendue[4], rendue[5], monnaie);
  }

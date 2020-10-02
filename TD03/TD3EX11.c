#include <stdio.h>

int main(){
  int n, i;
  float  somme=0.0f;
  printf("n= ");
  scanf("%d", &n);
  for(i=1; i<=n; i++){
    somme = somme + (1.f/i);
  }
  printf("la somme est égale à %f", somme);
}

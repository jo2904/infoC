#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int taille(int tableau[]){
  int i=0;
  while(tableau[i] != '\0'){
    i++;
  }
  return i;
}

void tri_rapide(int *tableau, int deb, int fin){
  int pivot, i, j;
  pivot = deb;
  i = deb;
  j = fin;

  while(i<j){
    if(tableau[j] < tableau[i]){
      int temp = tableau[i];
      tableau[i] = tableau[j];
      tableau[j] = temp;
    }
    if(pivot == i){
      j--;
    }
    if(pivot == j){
      i++;
    }

    tri_rapide(tableau, deb, pivot-1);
    tri_rapide(tableau, pivot+1, fin);
  }
}


int main(){
  int tableau[] = {4, 11, 8, 5, 6, 2, 1, 0};
  for(int i = 0; i<8; i++){
    printf("%d ", tableau[i]);
  }
  printf("\n" );

  tri_rapide(tableau, 0, taille(tableau));

  for(int i = 0; i<8; i++){
    printf("%d ", tableau[i]);
  }
}

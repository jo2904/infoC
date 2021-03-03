#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* AllocTab(int n){
  return calloc(n, sizeof(int));
}

void RandTab(int * tab, int n, int a, int b){
  for(int i = 0; i<n; i++){
    tab[i] = (rand() % (b - a + 1)) + a;
  }
}

int** AllocMat(int Ligne, int Colonne){
  int ** M = calloc(Ligne, sizeof(int*));
  for(int i =0; i<Ligne; i++){
    M[i] = (int*) calloc(Colonne, sizeof(int));
  }
  return M;
}

void RandMat(int **tab, int Ligne, int Colonne, int a, int b){
  for(int i =0; i<Ligne; i++){
    for(int j = 0; j<Colonne; j++){
      tab[i][j] = (rand() % (b - a + 1)) + a;
    }
  }
}
int main(){
  srand(time(NULL));
  int n = 4, *tab;
  tab = AllocTab(n);
  RandTab(tab, n, 0, 10);
  for(int i =0; i<n; i++){
    printf("%d\n", tab[i]);
  }
  free(tab);

  int Ligne = 4, Colonne = 5, **tab2;
  tab2 = AllocMat(Ligne, Colonne);
  RandMat(tab2, Ligne, Colonne, 0, 10);
  for(int i =0; i<Ligne; i++){
    for(int j = 0; j<Colonne; j++){
      printf("%d ", tab2[i][j]);
    }
    printf("\n");
  }
  free(tab2);
}

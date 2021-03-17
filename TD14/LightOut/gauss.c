#include <stdio.h>
#include <stdlib.h>

#include "matrice.h"
#include "gauss.h"

void clean_stdin(void){
	int c;
	do{c = getchar();
	}
	while (c !='\n'&& c != EOF);
}

int transposition (int *l1, int *l2, int n){
  for(int i = 0; i < n; i++){
    int temp = l1[i];
    l1[i] = l2[i];
    l2[i] = temp;
  }
  return 1;
}


int transvection (int *l1, int *l2, int n){
  for(int i = 0; i < n; i++){
    l1[i] = (l1[i]  + l2[i]) % 2;
  }
  return 1;
}


int gaussAuto (int ** matrice, int ligne , int colonne){
  int L = 0;

  for(int j = 0; j < colonne; j++){
    int e = -1;
    int indice = -1;

    for(int i = L; i < ligne; i++){ //recherche de e
      if(matrice[i][j] != 0){
        indice = i;
        break;
      }
    }

    if(indice != -1){

      transposition(matrice[indice], matrice[L], colonne);

			for(int i = 0; i < L; i++){
				if(matrice[i][j] !=0){
					 transvection(matrice[i], matrice[L], colonne);
				}
      }

      for(int i = L+1; i < ligne; i++){
				if(matrice[i][j] !=0){
					 transvection(matrice[i], matrice[L], colonne);
				}
			}
      L++;

    }

  }
}

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

int dilatation (int *l, int n, int lambda){
  for(int i = 0; i<n; i++){
    l[i] = l[i] * lambda;
  }
  return 1;
}

int transvection (int *l1, int *l2, int n, int lambda){
  for(int i = 0; i < n; i++){
    l1[i] = l1[i]  + lambda * l2[i];
  }
  return 1;
}


int gaussManuel (int ** matrice, int ligne , int colonne){
  char chois;
  int l1, l2, lambda;
  int exit = 0;

  while(exit == 0){
    chois = 0;
    printf("\nQuelle action ?\n>Echange (E)\n>Dilatation (D)\n>Transvection (T)\n>q pour quitter\n" );
    scanf("%c", &chois); //probleme scanf attend plus de rep
    clean_stdin();

    if(chois == 69 || chois == 101){
      printf("l1 <=> l2 ?\n");
      scanf("%d %d", &l1, &l2);
      clean_stdin();
      printf("Echange de ligne  %d et ligne %d\n", l1, l2 );
      transposition(matrice[l1-1], matrice[l2-1], colonne);
    }
    if(chois == 68 || chois == 100){
      printf("l1 * lambda ?\n" );
      scanf("%d %d", &l1, &lambda );
      clean_stdin();
      printf("Multiplication de la ligne %d par %d\n", l1, lambda);
      dilatation(matrice[l1-1], colonne, lambda);
    }
    if(chois == 84 || chois == 116){
      printf("l1 + l2 * lambda\n" );
      scanf("%d %d %d", &l1, &l2, &lambda);
      clean_stdin();
      printf("On ajoute %d * l%d à l%d\n", lambda, l2, l1);
      transvection(matrice[l1-1], matrice[l2-1], colonne, lambda);
    }
    if(chois == 81 || chois == 113){
      exit = 1;
    }
    affMat(matrice, ligne, colonne);
  }

  return 1;
}

int gaussAuto (int ** matrice, int ligne , int colonne){
  int L = 0;

  for(int j = L; j < colonne-1; j++){
    int e = 0;
    int indice;

    for(int i = L; i < ligne; i++){ //recherche de e
      if(matrice[i][j] != 0){
        e = matrice[i][j];
        indice = i;
        break;
      }
    }

    if(e != 0){

      transposition(matrice[indice], matrice[L], colonne);

      for(int i = L+1; i < ligne-1; i++){
        transvection(matrice[i], matrice[L], colonne, -matrice[i][j]/matrice[L][j]);
      }
      L++;
      affMat(matrice, ligne, colonne);
    }

  }
}

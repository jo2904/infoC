#include <stdio.h>
#include <stdlib.h>

#include "matrice.h"
#include "gauss.h"

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
    printf("\nQuelle action ?\n>Echange (E)\n>Dilatation (D)\n>Transvection (T)\n>q pour quitter\n" );
    scanf("%d\n", &chois); //problkeme scanf attend plus de rep

    if(chois == 69 || chois == 101){
      printf("l1 l2 ?");
      scanf("%d %d\n", &l1, &l2);
      printf("Echange de ligne  %d et ligne %d\n", l1, l2 );
      transposition(matrice[l1-1], matrice[l2-1], colonne);
    }
    if(chois == 68 || chois == 100){
      printf("l1 lambda ?\n" );
      scanf("%d %d\n", &l1, &lambda );
      printf("Multiplication de la ligne %d par %d\n", l1, lambda);
      dilatation(matrice[l1-1], colonne, lambda);
    }
    if(chois == 84 || chois == 116){
      printf("l1 l2 lambda" );
      scanf("%d %d %d\n", &l1, &l2, &lambda);
      printf("On ajoute %d * l%d à l%d\n", lambda, l2, l1);
      transvection(matrice[l1-1], matrice[l2-1], colonne, lambda);
    }
    if(chois == 81 || chois == 113){
      exit = 1;
    }
    else{
      printf("Aucun chois sélectionner\n");
    }
    affMat(matrice, ligne, colonne);
  }

  return 1;
}

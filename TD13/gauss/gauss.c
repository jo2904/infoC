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
    l[i] = l[i] * 1/lambda;
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

int gaussAuto (int **matrice, int ligne, int colonne){
	int LigneSelect = -1;
	int ColonneSelect = -1;
	int pivot = -1;
	for(int i = 0; i< ligne; i++){
		//recherche ligne avec le moins de zéro
		for(int j = 0; j <colonne; j++){
			for(int h =i; h <ligne; h++){
				if(matrice[h][j] != 0){
					LigneSelect = h;
					break;
				}
			}
		}
		//echange ligne select et ligne i
		printf("echange ligne %d et ligne %d\n", i, LigneSelect);
		transposition(matrice[i], matrice[LigneSelect], colonne);
		affMat(matrice, ligne, colonne);

		//select pivot
		for(int j = 0; j < colonne; j++){
			if(matrice[i][j] != 0){
				pivot = matrice [i][j];
				ColonneSelect = j;
				printf("%d\n", pivot );
				break;
			}
		}

		//divise ligne i par pivot
		printf("on divise la ligne %d par %d\n", i, pivot);
		dilatation(matrice[i], colonne, pivot);
		affMat(matrice, ligne, colonne);

		//simplification
		for(int j  = i+1; j <ligne; j++){
			printf("la ligne %d devient L%d + %d * L%d\n", j, j, -matrice[j][ColonneSelect] , i);
			transvection(matrice[j], matrice[i], colonne, -matrice[j][ColonneSelect]);
		}
		affMat(matrice, ligne, colonne);

	}
}

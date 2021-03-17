#include <stdio.h>
#include <stdlib.h>



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

int **  lireMatrice(FILE * fichier, int ligne, int colonne){
  fscanf(fichier, "\n");
  printf("ouverture de la matrice \n" );
	int ** matrice = AllocMat(ligne, colonne);
	for(int i = 0; i<ligne; i++){
		for(int j = 0; j<colonne; j++){
			fscanf (fichier, "%d", &matrice[i][j]);
		}
    //fscanf(fichier, "\n");
	}
  fclose(fichier);
	return matrice;
}

void affMat(int ** matrice, int ligne, int colonne){
  for(int i = 0; i<ligne; i++){
    for(int j = 0; j<colonne; j++){
      if(matrice[i][j] != 0){
        printf("1");
      }
      else{
        printf(".");
      }
    }
    printf("\n");
  }
  printf("\n" );
}

void affSol(int ** matrice, int ligne, int colonne){
  int h = 0;
  for(int i = 0; i <3; i++){
    for(int j = 0; j <3; j++){
      if(matrice[h][colonne-1] != 0){
        printf("1");
      }
      else{
        printf(".");
      }
      h++;
    }
    printf("\n");
  }
  printf("\n" );
}

#include <stdio.h>
#include <stdlib.h>

#include "matrice.h"
#include "gauss.h"

int main(int argc, char const *argv[]){
	int ligne, colonne; //def variable

	FILE * fichier = NULL; // def fichier
	fichier = fopen(argv[1], "r");
	if (fichier == NULL){ // si fichier pas ouvert
		printf("Veuillez donner un fichier\n");
		return -1;
	}
	fscanf(fichier, "%d %d", &ligne, &colonne); // on recup ligne et colonne

  int ** matrice = lireMatrice(fichier , ligne, colonne); //def matrice

	printf("Matrice init:\n");
  affMat(matrice, ligne, colonne);

  gaussAuto(matrice, ligne, colonne);

	printf("Matrice fin:\n");
  affMat(matrice, ligne, colonne);

	printf("Solution:\n");
	affSol(matrice, ligne, colonne);

  free(matrice);
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int * p = calloc(10, sizeof(int));
  free(p);

  FILE * fichier = NULL; // def fichier
  fichier = fopen(argv[1], "w");
  if (fichier == NULL){ // si fichier pas ouvert
    printf("Veuillez donner un fichier\n");
    return -1;
  }

  fclose(fichier);
  return 0;
}

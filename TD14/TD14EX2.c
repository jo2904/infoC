#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char chois;
  FILE * fichier = NULL;

  //ouverture de l'image
  fichier = fopen(argv[1], "w");

  if (fichier != NULL){ // si fichier pas ouvert
    printf("Un fichier existe déjà, il sera ecrasé,\nvoulez vous continuer (Y, N) ?  ");
    scanf("%c", &chois );
    if(chois != 89){
      printf("Au revoir\n");
      return 1;
    }
  }

  printf("plus de fichier ;)\n");
  fclose(fichier);
  return 0;
}

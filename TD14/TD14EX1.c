#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char mode[] = "rb";
  FILE * image = NULL;

  //ouverture de l'image
  image = fopen(argv[1], mode);

  //determination de la taille du fichier
  fseek (image, 0, SEEK_END); //place le pointeur à la fin du fichier
  long taille_image = ftell (image); //retourner la position du pointeur

  printf("taille du fichier %s: %ld octets\n", argv[1], taille_image);

  fclose(image);
  return 0;
}

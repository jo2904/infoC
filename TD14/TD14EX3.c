#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  FILE * fichier1, * fichier2;

  fichier1 = fopen(argv[1], "r");
  fichier2 = fopen(argv[2], "w");

  if(fichier1 == NULL){
    printf("le fichier %s ne peut pas être ouvert\n", argv[1]);
    return 1;
  }

  //determination de la taille du fichier
  fseek (fichier1, 0, SEEK_END); //place le pointeur à la fin du fichier
  long taille_fichier = ftell (fichier1); //retourner la position du pointeur
  rewind (fichier1); //replace le pointeu au début

  int * temp = malloc (taille_fichier);

  fread(temp, 1, taille_fichier, fichier1);
  fwrite(temp, 1, taille_fichier, fichier2);

  free(temp);
  fclose(fichier1);
  fclose(fichier2);
  return 0;
}

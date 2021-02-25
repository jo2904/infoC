#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "libbmp.h"
#include "tri.h"

int main(int argc, char const *argv[]){
  Image *MonFichier;
  MonFichier = readImage(argv[1]);

  printf("%d\n", MonFichier->size);

  clock_t debut = clock();
  triRapide(MonFichier->pix, 0, MonFichier->size, 1); // lexicometrie
  //triRapide(MonFichier->pix, 0, MonFichier->size, 2); // Somme R+G +B
  //triRapide(MonFichier->pix, 0, MonFichier->size, 3); // Brillance H
  //triRapide(MonFichier->pix, 0, MonFichier->size, 4); // Brillance Y

  //tri_bulle(MonFichier->pix, MonFichier->size, 1); //lexicometrie
  //tri_bulle(MonFichier->pix, MonFichier->size, 2); //somme R+ G +B
  //tri_bulle(MonFichier->pix, MonFichier->size, 3);  //brillance H
  //tri_bulle(MonFichier->pix, MonFichier->size, 4);  //Brillance Y

  //triSelection(MonFichier->pix, MonFichier->size, 1); //lexicometrie
  //triSelection(MonFichier->pix, MonFichier->size, 2); //somme R+ G +B
  //triSelection(MonFichier->pix, MonFichier->size, 3);  //brillance H
  //triSelection(MonFichier->pix, MonFichier->size, 4);  //Brillance Y

  //triInsertion(MonFichier->pix, MonFichier->size, 1); //lexicometrie
  //triInsertion(MonFichier->pix, MonFichier->size, 2); //somme R+ G +B
  //triInsertion(MonFichier->pix, MonFichier->size, 3);  //brillance H
  //triInsertion(MonFichier->pix, MonFichier->size, 4);  //Brillance Y

  clock_t fin = clock();

  float delta = (fin - debut) / CLOCKS_PER_SEC;
  printf("%.2f s\n", delta);
  writeImage (MonFichier, "here.bmp");

  return 0;
}

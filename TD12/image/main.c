#include <stdio.h>
#include <stdlib.h>

#include "libbmp.h"
#include "tri.h"

int main(int argc, char const *argv[]) {
  Image *MonFichier;
  MonFichier = readImage(argv[1]);

  printf("%d\n", MonFichier->size);
  triRapide(MonFichier->pix, 0, MonFichier->size);

  writeImage (MonFichier, "here.bmp");

  return 0;
}

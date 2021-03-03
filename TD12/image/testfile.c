#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *pfile = NULL;
  char txt;

  pfile = fopen("test.txt", "r");
  if (!pfile)
  {
    printf("Impossible d'ouvrir le doc");
    return 0;
  }
 char text[20];
 txt = fgetc(pfile);
  while (txt != EOF) {
    printf("%c", txt );
    strcat(text, txt);
    txt = fgetc(pfile);

  }
  printf("\n%s\n", text);
  //fprintf(pfile, "tests" );
  fclose(pfile);


  return 0;
}

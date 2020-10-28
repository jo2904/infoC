#include <stdio.h>

int main(int argc, char **argv){
  printf("nombre d'argument: %d\n", argc);
  printf("Votre prénom est %s\n", argv[1]);
  printf("Votre nom est %s\n", argv[2]);
}

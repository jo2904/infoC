#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//calcule de A^b mod (n)

int int_to_bianire(int nbr, int * n_bin){
  int  i;
  for(i=0; nbr > 0; i++){
    n_bin[i] = nbr%2;
    nbr = nbr/2;
  }
  int j = i;

  printf("Le nombre b en binaire est = ");
  for(i=i-1; i >= 0; i--){
    printf("%d",n_bin[i]);
  }
  printf("\n" );

  return j;
}

int main(int argc, char const *argv[]) {
  int A = 351, b = 17, n = 437;
  int b_bin[20];

  int taille = int_to_bianire(b, b_bin);

  int result[20] = {0};
  result[0] = A;

  for(int i = 1; i < taille; i++){
    result[i] = (result[i-1] * result[i-1]) % n;
  }

  int final = 1;
  for(int i = taille; i >= 0; i--){
    if(b_bin[i] == 1){
      final = final * result[i];
    }
  }
  final = final % n;

  printf("Le resultat final de %d ^ %d mod(%d) est %d\n", A, b, n, final );


  return 0;
}

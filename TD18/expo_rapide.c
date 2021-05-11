#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//calcule de A^b mod (n)
//fait depuis un code en python inspiré de cette vidéo
// https://www.youtube.com/watch?v=i93Mqa6pVds

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
  //on def les variables
  int A = 1337, b = 73, n = 4242;
  int b_bin[20];

  //on recup le bin de b et la nb de char du bin
  int taille = int_to_bianire(b, b_bin);

  //on init un tableau
  int result[20] = {0};
  result[0] = A;

  //on calcule le resultat du resultat précedent au carré mod n
  //on init avec a
  for(int i = 1; i < taille; i++){
    result[i] = (result[i-1] * result[i-1]) % n;
  }

  //on calcule le produit de 1 dans le bianire
  int final = 1;
  for(int i = taille; i >= 0; i--){
    if(b_bin[i] == 1){
      final = final * result[i];
    }
  }

  //on calcule le result od n
  final = final % n;

  printf("Le resultat final de %d ^ %d mod(%d) est %d\n", A, b, n, final );


  return 0;
}

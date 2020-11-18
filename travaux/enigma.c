#include <stdio.h>
#include <string.h>

char permut_id[26] = "abcdefghiklmnopqrstuvwxyz";

int Encrypt(char lettre) {
  return lettre - 97;
}

int Permutation(int lettre, int i){
  return (lettre+25-i)-25+1;
}

int main(){
  char string[20] ="test";
  int taille = strlen(string);

  char permut[6][2];
  for(int i = 0; i<6; i++){
    scanf("%s %s",  &permut[i][0], &permut[i][1]);
  }

  for(int j = 0; j<taille ; j++){
    printf("%d ", Encrypt(string[j]));
  }
}

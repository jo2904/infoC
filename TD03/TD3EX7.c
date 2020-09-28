#include <stdio.h>

int main(){

  int a, b, c=3;
  do{
  printf("joueur 1: donner un nombre entre 1 et 5\n");
  scanf("%d", &a);
  }while(a>=5 && a<=1);
  system ("clear");
  while(c>0){
    printf("joueur 2: donner un nombre entre 1 et 5\n");
    scanf("%d", &b);
    if (a==b){
      printf("WIN!!\n");
      break;
    }
    else{
      printf("echec\n");
      system ("clear");
      c--;
    }
  }
  if (c==0)
    printf("la réponse était %d", a);
}

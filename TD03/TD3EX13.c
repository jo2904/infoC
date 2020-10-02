#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  srand(time(NULL));
  int a, b, c, d, f=3;
  
  do{
  printf("borne inf=");
  scanf("%d", &a);
  printf("borne sup=");
  scanf("%d", &b);
  }while(a>b);
  
  printf("nombre d'essaie=");
  scanf("%d", &f);
  
  do{
    c = (int)((float)b*rand()/RAND_MAX);
    }while(a>c);
  system ("clear");
  
  while(f>0){
    printf("joueur 2: donner un nombre entre 1 et 5\n");
    scanf("%d", &d);
    
    if (c==d){
      printf("WIN!!\n");
      break;
    }
    else{
      printf("echec\n");
      f--;
    }
  }
  
  if (f==0)
    printf("la réponse était %d", a);
}

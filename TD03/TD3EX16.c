#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int a, c, i;
  srand(time(NULL));
  
  //nombre colonne
  printf("NbColonne=");
  scanf("%d", &a);  
  
  while(1){
    for(i=0; i<=a; i++){
        //gérere 1 ou 0
        c = rand()%2;
        if(c==1){
          printf("*");
        }
        else{
          printf(" ");
        }

    }
    printf("\n");
    }
}

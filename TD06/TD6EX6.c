#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void AfficheMatrice (int mat[][10], int n){
   int i, j;
   for(i=0; i<n; i++){
      for(j=0; j<10; j++){
         printf("%d ", mat[i][j]);
      }
   printf("\n");
   }
}

void RemplirMatrice(int mat[][10], int n){
   int i, j;
   srand(time(NULL));
   for(i=0; i<n; i++){
      for(j=0; j<10; j++){
         mat[i][j] = rand()%2401+100;
      }
   }
}

int main(){
   int mat[3][10];
   int n = 3;
   RemplirMatrice( mat, n);
   AfficheMatrice( mat, n);
}

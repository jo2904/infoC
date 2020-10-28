#include <stdio.h>
#include <time.h> 
#include <math.h>
#include <stdlib.h>

float TirageAleatoire (int N){
    N = rand() % N;
    N = rand()%(N*100 - 100) + 100;
    return (float)N/100;
}

int EstInscrit (float N){
   float x = TirageAleatoire(N), y = TirageAleatoire(N), d = sqrt(((x-(N/2))*(x-(N/2)))+(y-(N/2))*(y-(N/2)));
   if(d<=N/2){
      printf("x %f.2, y %f.2, d %f.2\n ", x, y, d);
      return 1;}
   else{
      printf("0");
      return 0;}
}

int main(){
   srand(time(NULL));
   int N, n, i, j=0;
   printf("N, n ");
   scanf("%d %d", &N, &n);
   for(i=0; i<n; i++){
      j = j + EstInscrit(N);
   }
   printf("pi = %f\n", (float)4*(j/i));
}

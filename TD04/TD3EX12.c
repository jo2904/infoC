#include <stdio.h>

float racine(float A, float c, float n){
   float un = c;
   int i;
   for(i=0; i<=n; i=i+1){
       un = (1/2)*(un+(A/un));
   }
   return un;
}

float racineAuto (float A, float c, float s){
    float un = c;
    while(un-(1/2)*(un+(A/un))>s){
        un = (1/2)*(un+(A/un));
    }
    return un;
}

int main(){
   float A, c, n, s;
   printf("A, c, n, s");
   scanf("%f %f %f %f", &A, &c, &n, &s);
   printf("un = %f\n", racine(A, c, n));
   printf("un2 = %f\n", racineAuto(A, c, s));
}

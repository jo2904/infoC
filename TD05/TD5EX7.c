#include <stdio.h>
#include <math.h>

int Miror(int N){
  int b, n=0;
  while(N>0){
    b= N%10;
    N= (N-b)/10;
    n= (n*10)+b;
  }
  return n;
}

int nbIteration(int j){
   int i = 0;
   while(j != Miror(j)){
       printf("%d ", j);
       j = j + Miror(j);
       i += 1;
       }
   return i;
}

int main(){
   int i;
   float moyenne;
   for(i =20; i<1000; i+=1){
      printf("%f", moyenne);
      moyenne = ( moyenne + nbIteration(i) ) /2;
   }
   printf("%f", moyenne);
}

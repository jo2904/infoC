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

int NbDigit(int N){
  int b, i=0;
  while(N>0){
    b= N%10;
    N= (N-b)/10;
    i +=1;
  }
  return i;
}

int Palindromize(int N){
  int N2;
  N2 = N * pow(10, NbDigit(N));
  N2 += Miror(N);
  return N2;
}

int main(){
  int N; 
  printf("N= ");
  scanf("%d", &N);
  printf("%d\n", Miror(N));
  printf("%d\n", NbDigit(N));
  printf("%d\n", Palindromize(N));
}

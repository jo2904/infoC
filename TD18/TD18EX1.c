#include <stdio.h>
#include <stdlib.h>


int Miror(int N){
  int b, n=0;
  while(N>0){
    b= N%10;
    N= (N-b)/10;
    n= (n*10)+b;
  }
  return n;
}

int main(int argc, char const *argv[]) {
  printf("%d\n", Miror(45698));
  return 0;
}

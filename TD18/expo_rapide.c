#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  int g = 1337, e = 73;
  int res = 1;
  int n  =2;

  while(e>0){
    if(e / 2 == 1){
      res = res * g%n;
    }
    g = g*g;
    e = e/2%n;
  }

  printf("%d\n", res);

  return 0;
}

//test git and visual

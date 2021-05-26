#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  int g = 1337, e = 73;
  int res = 1;

  while(e>0){
    if(e / 2 == 1){
      res = res * g;
    }
    g = g*g;
    e = e/2;
  }

  printf("%d\n", res);

  return 0;
}

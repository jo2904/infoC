#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int PGCD(int a, int b){
  if(a%b == 0){
    return b;
  }
  else{
    return PGCD(b, a%b);
  }
}


int main() {
  printf("%d\n", PGCD(119, 544));
}

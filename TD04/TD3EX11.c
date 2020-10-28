#include <stdio.h>

int main(){
  int i, C = 20 , V = 4;
  for(i=0; i<18; i++){
    if(i%4 == 0)
      C = (C*(V-1)/V);
    if(i == 14)
      printf("A 23h30: %d°\n", C);
    if(i == 17)
      printf("A 00h15: %d°\n", C);
  }
}

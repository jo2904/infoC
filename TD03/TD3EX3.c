#include <stdio.h>

int main(){
  int test = 0;
  printf ("Quel age avez vous?\n");
  scanf ("%d", &test);
  if (test<=3)
    printf ("On n'est pas des idiots!\n");
  if (test>=4 && test<=32)
    printf ("Jeunot!\n");
  if (test>=33 && test<=50)
    printf("Ca passe encore\n");
  else
    printf("Sorry\n");
    
}
